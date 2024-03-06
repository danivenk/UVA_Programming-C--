// Dani van Enk, 11823526

// make sure caloreco is only included once
#ifndef CALORECO_H
#define CALORECO_H

// included header
#include "calorimeter.h"

// define caloreco with calometer
class CaloReco {
    private:

        // define the meter
        Calorimeter* _meter;

    public:
    
        // constructor
        CaloReco(Calorimeter*& meter): _meter(meter) {};

        // find a cell with the highest energy not yet in a cluster
        CaloCell* findSeed();

        // find cluster, grow cluster and check if there are possible clusters left not idetified
        void findClusters();
        bool checkClustersAvailable();
        void growCluster(int ix, int iy, int clusid);
};

#endif