#pragma once

#include <string>

#include "Dir.h"

class FileStructure
{
    public:
        FileStructure();
        // post: FileStructure object is properly initialised
        virtual ~FileStructure();
        // empty virtual destructor
        
        void loadFile(std::string filename, Dir& head);
        // post: if file with filename exists, its data is read, decoded and stored in a
        //       proper key/value tree.

        void saveFile(Dir& head, std::string filename) const;
        // post: if a file with filename can be created, head is recursively written it
    
    private:
        void fillFileBuffer(std::string& buffer, Dir* dir, std::string base) const;
        std::string getNextWord(const char* start, char** current, size_t size) const;
        void crypt(char* data, size_t size) const;
        void decrypt(char* data, size_t size) const;

        // private copy constructor and assignment operator to prevent making copies
        FileStructure(const FileStructure&) { /* do nothing */ };
        FileStructure& operator= (const FileStructure&) { return *this; };
};
