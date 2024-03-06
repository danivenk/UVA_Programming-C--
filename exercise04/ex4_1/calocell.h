// Dani van Enk, 11823526

// check if already included
#ifndef CALOCELL_H
#define CALOCELL_H

// define a cell in the meter grid
class CaloCell {

    // define constructors and destructors
    public:
        CaloCell(double energy = -1, int id = -1) { init(energy, id); };
        ~CaloCell(){};

    // define energy, id and init fuction
    private:
        double _energy;
        int _id;

        void init(double energy, int id);

    // getters and setters for the id and energy
    public:
        double get_energy() const { return _energy; };
        bool set_energy(double energy);
        int get_id() const { return _id; };
        bool set_id(int id);
};

#endif