// Dani van Enk, 11823526

// make sure caloreader is only included once
#ifndef CALOREADER_H
#define CALOREADER_H

// inlcude used libary and header
#include <fstream>
#include "calorimeter.h"

// define a Reader of a Calorimeter/Event
class CaloReader {
    private:

        // define a Calorimeter and file to read from
        Calorimeter* _calo;
        std::ifstream _file;

    public:

        // constructor using file and destructor
        CaloReader(const char* infile);
        ~CaloReader(){ delete _calo; };

        // define an Exception helper class
        class CaloReaderException {
            private:

                // define what the error is and at what word it happened
                std::string _what;
                std::string _errorword;

            public:

                // constructor from what and errorword/destructor
                CaloReaderException(std::string what, std::string errorword=NULL):
                    _what(what), _errorword(errorword) {};
                ~CaloReaderException(){};

                // what and at getters
                const char* what() const { return _what.c_str(); };
                std::string at() const { return _errorword; };
        };

    private:

        // read word (template)
        template <class T>
        T readWord();

        // check a string word against a string
        void checkWord(std::string word, const char *keyword);

        // set Cell ID/Energy from File
        void setCellIDfromFile();
        void setCellEnergyfromFile();

    public:

        // Calorimeter getter
        Calorimeter*& calo() { return _calo; };

        // read an Event from the file
        bool readEvent();
};

#endif