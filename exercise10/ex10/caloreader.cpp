// Dani van Enk, 11823526

// include used header
#include "caloreader.h"

// caloreader constructor from file
CaloReader::CaloReader(const char *infile): 
        _file(infile), _calo(nullptr) {

    // check if the file fails and throw exception if needed
    if (_file.fail()) {
        std::string mess("CaloReaderException: Could not open "
            "file with the name ");
        throw CaloReaderException(mess.append(infile));
    }

    // define word
    std::string word;

    // read word from file
    word = readWord<std::string>();

    // check if definition
    checkWord(word, "BEGIN_CALO_DEF");

    // read another word
    word = readWord<std::string>();

    // check if it defines size
    checkWord(word, "SIZE");

    // read out calorimeter sizes
    int sizex = readWord<int>();
    int sizey = readWord<int>();

    // set new calorimeter with read sizes
    _calo = new Calorimeter(sizex, sizey);

    // set IDs to celss in calorimeter
    while (1) {

        // try to read an ID from file else throw exception and rollback word
        try {
            setCellIDfromFile();
        } catch (CaloReaderException err) {
            word = err.at();
            break;
        }
    }

    // check if end of defition
    checkWord(word, "END_CALO_DEF");

}

// read a word (template)
template <class T>
T CaloReader::readWord() {

    // define a word (template)
    T word;

    // make sure word can be read from file else throw exception
    if (!(_file >> word)) {
        throw CaloReader::CaloReaderException("CaloReaderException: "
            "Could not read word");
    }

    return word;
};

// check if read word is the word you expect
void CaloReader::checkWord(std::string word, const char* keyword) {

    // check if word is given word else throw exception
    if (word != keyword) {
        std::string mess("CaloReaderException: Could find ");
        throw CaloReader::CaloReaderException(mess.append(keyword), word);
    }
}

// read CellID from file
void CaloReader::setCellIDfromFile() {

    // read word from file
    std::string word = readWord<std::string>();

    // check if it is a position
    checkWord(word, "POSITION");

    // read ID and x/y position
    int ID = readWord<int>();
    int posx = readWord<int>();
    int posy = readWord<int>();

    // set the id to it's correct position
    _calo->grid().cell(posx, posy)->setReadoutID(ID);
}

// read CellEnergy from file
void CaloReader::setCellEnergyfromFile() {

    // read word from file
    std::string word = readWord<std::string>();

    // check if it is an enegry definition
    checkWord(word, "ENERGY");

    // read CellID and Energy
    int ID = readWord<int>();
    double energy = readWord<double>();

    // set energy to cell with ID
    _calo->grid().findCellByID(ID)->setEnergy(energy);
}

// read an event from file
bool CaloReader::readEvent() {

    // check if file fails else throw exception or return false if eof()
    if (_file.fail()) {
        throw CaloReaderException("CaloReaderException: File is not valid"
            " to read");
    } else if (_file.eof()) {
        return false;
    }

    // clear all energies from the calogird
    _calo->grid().clear();

    // read a word
    std::string word = readWord <std::string>();

    // check if it starts defining an event else return false
    try {
        checkWord(word, "BEGIN_EVENT");
    } catch (CaloReaderException err) {
        return false;
    }

    // read energy from file else throw exception rollback word if that's the case
    while (1) {
        try {
            setCellEnergyfromFile();
        } catch (CaloReaderException err) {
            word = err.at();
            break;
        }
    }

    // check if it ends defining an event else return false
    try {
        checkWord(word, "END_EVENT");
    } catch (CaloReaderException err) {
        return false;
    }

    return true;
}