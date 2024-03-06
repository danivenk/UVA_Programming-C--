// Dani van Enk, 11823526

// include used libary
#include "caloreco.h"

// find the cell with the highest energy not yet in a cluster
CaloCell* CaloReco::findSeed() {

    // define the size of the grid and define the max_e cell and allocated bool
    std::tuple<int, int> size = _meter->grid().get_size();
    CaloCell* max_e = new CaloCell();
    bool alloc = true;

    // loop over the cells
    for (int i = 0; i < std::get<0>(size); i++) {
        for (int j = 0; j < std::get<1>(size); j++) {
            
            // check if the energy is more than 0 and it is not yet in a cluster
            if (_meter->grid().cell(i, j)->energy() > max_e->energy() &&
                    _meter->grid().cell(i, j)->clusterID() == 0) {

                // delete dynamically allocated cell before pointing to the highest energy cell
                if(alloc) {
                    delete max_e;
                    alloc = false;
                }

                // set max_e to current cell
                max_e = _meter->grid().cell(i, j);
            }
        }
    }

    return max_e;
}

// find all clusters in grid
void CaloReco::findClusters() {

    // define starting ClusterID to 0 and size of grid
    int ID = 0;
    std::tuple<int, int> size = _meter->grid().get_size();

    // loop over all cells and set clusterID to 0
    for (int i = 0; i < std::get<0>(size); i++) {
        for (int j = 0; j < std::get<1>(size); j++) {
            _meter->grid().cell(i, j)->setClusterID(ID);
        }
    }

    // loop over all clusters
    while(checkClustersAvailable()) {

        // find a cell with the higest energy not in a cluster
        CaloCell* highest = findSeed();

        // get the position of that cell
        std::tuple<int, int> pos = _meter->grid().findCellPosByID(highest->readoutID());

        // find all cells of this cluster
        growCluster(std::get<0>(pos), std::get<1>(pos), ++ID);

        // redirect pointer
        highest = nullptr;
    }
}

// check if there are possible clusters
bool CaloReco::checkClustersAvailable() {

    // define size of grid
    std::tuple<int, int> size = _meter->grid().get_size();

    // loop over all cells in the grid
    for (int i = 0; i < std::get<0>(size); i++) {
        for (int j = 0; j < std::get<1>(size); j++) {

            // define current cell
            CaloCell* cell = _meter->grid().cell(i, j);

            // check if cell is valid for cluster return true
            if (cell->energy() > 0 && cell->clusterID() == 0) {
                return true;
            }
        }
    }

    return false;
}

// grow cluster to include all cells of the cluster
void CaloReco::growCluster(int ix, int iy, int clusid) {
    
    // set the clusterID to this cell
    _meter->grid().cell(ix, iy)->setClusterID(clusid);

    // define xvalid and yvalid and neighbour offsets
    bool xvalid, yvalid;
    int dindex[3] = {-1, 0, 1};

    // loop over the offsets (x direction and y direction)
    for (int i: dindex) {
        for (int j: dindex) {

            // define neighbour cell
            CaloCell* neighbour = _meter->grid().cell(i + ix, j + iy);

            // check if cell is valid/within grid
            xvalid = i + ix >= 0 && i + ix < std::get<0>(_meter->grid().get_size());
            yvalid = j + iy >= 0 && j + iy < std::get<1>(_meter->grid().get_size());

            // if cell is valid grow from this cell (recursively)
            if (xvalid && yvalid && neighbour->energy() > 0 && neighbour->clusterID() == 0) {
                growCluster(i + ix, j + iy, clusid);
            }
        }
    }
}