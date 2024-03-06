// Dani van Enk, 11823526

// make sure a calocell is only included once
#ifndef CALOCELL_H
#define CALOCELL_H

// define a cell in a calogrid
class CaloCell {
public:

	// calocell constructor from energy and ID
	CaloCell(double energy = 0, int readoutID = 0) : _e(energy), _id(readoutID) {};

	// energy/ID/Cluster_ID getter
	double energy() const { return _e; };
	int readoutID() const { return _id; };
	int clusterID() const { return _cluster_id; };

	// energy/ID/Cluster_ID setter
	void setEnergy(double energy) { _e = energy; };
	void setReadoutID(int id) { _id = id; };
	void setClusterID(int id) { _cluster_id = id; };

private:

	// define energy, id & cluster id
	double _e;
	int _id;
	int _cluster_id;

};

#endif 
