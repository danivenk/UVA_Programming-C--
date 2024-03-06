// Dani van Enk, 11823526

// include used headers
#include "caloreader.h"
#include "caloreco.h"

// declare stream operators
std::ostream &operator<<(std::ostream &os,
    const CaloReader::CaloReaderException &cre);
std::ostream &operator<<(std::ostream &os, const Point p);

// define main with terminal arguments
int main(int argc, char *argv[]) {

    // make sure a filename is given
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;

        return 1;
    }

    // define a reader
    CaloReader *reader;

    // try to make a reader else catch error and print what
    try {
        reader = new CaloReader(argv[1]);
    } catch (CaloReader::CaloReaderException err) {
        std::cout << err << std::endl;
        return 2;
    }

    // define clusterfinder object
    CaloReco clustobj(reader->calo());

    // print initiation reading and print calori meter position
    std::cout << "Reading Calorimeter at " << reader->calo()->position();
    std::cout << std::endl;

    // print division line
    std::cout << std::setfill('#') << std::setw(79) << "#" << std::endl;
    std::cout << std::setfill(' ');

    // dump cellIDs to terminal
    reader->calo()->dumpReadoutMap();

    // read all events in file
    while(reader->readEvent()) {

        // print division line
        std::cout << std::setfill('#') << std::setw(79) << "#" << std::endl;
        std::cout << std::setfill(' ');

        // dump event to terminal
        reader->calo()->dumpEvent();

        // find the clusters from this event
        clustobj.findClusters();

        // print division line
        std::cout << std::setfill('#') << std::setw(79) << "#" << std::endl;
        std::cout << std::setfill(' ');

        // dump clusters to terminal
        reader->calo()->dumpClusterMap();

    }

    // delete allocated memory
    delete reader;

    return 0;
}

// define stream operator CaloReaderexception what to os
std::ostream &operator<<(std::ostream &os,
        const CaloReader::CaloReaderException &cre) {
    return (os << cre.what());
}

// define stream operator point position to os
std::ostream &operator<<(std::ostream &os, const Point p) {
    return (os << p.x() << ", " << p.y() << ", " << p.z());
}