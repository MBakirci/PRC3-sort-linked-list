#pragma once

#include "File.h"

class Dir
{
    public:
        Dir();
        // post: Dir is properly initialised with empty name
        Dir(std::string name);
        // post: Dir is properly initialised with given name

        virtual ~Dir();
        // post: recursively deletes all Dirs and values
        
        
        std::string getName() const;
        // post: dir name is returned
        void setName(std::string name);
        // post: new dir name is set
        Dir* getNext();
        // post: pointer to next dir is returned
        void setNext(Dir* dir);
        // post: pointer to the next dir is set

        Dir* getFirstSubdir();
        // post: pointer to the firstSubdir is returned
        void setFirstSubdir(Dir* dir);
        // post: pointer to the FirstSubdir is set

        File* getFirstFile();
        // post: pointer to the first file is returned
        void setFirstFile(File* firstFile);
        // post: pointer to the first file is set

        File* addFile(std::string filename);
        // post: - if first character of filename is a forward slash or '..':
        //         NULL is returned (only relative paths deeper into the tree
        //         are supported: "/path" and "../path" are not supported)
        //       - if filename contains a forward slash, the first directory in
        //         the chain is located, AddFile will be called on that
        //         directory and its result will be returned. If this first
        //         directory is not found: NULL is returned
        //       - if filename does not exist as file or directory:
        //         - file with filename is created and added to the back of the
        //           list
        //         - next pointer of last element is NULL
        //         - pointer to new file is returned
        //       - else: NULL is returned
        Dir* addDir(std::string dirname);
        // post: - if first character of dirname is a forward slash or '..':
        //         NULL is returned (only relative paths deeper into the tree
        //         are supported: "/path" and "../path" are not supported)
        //       - if dirname contains a forward slash, the first directory in
        //         the chain is located, AddDir will be called on that
        //         directory and its result will be returned. If this first
        //         directory is not found: NULL is returned
        //       - if dirname does not exist as file or directory on this level:
        //         - dir with dirname is created and added to the back of the list
        //         - next pointer of last element is NULL
        //         - pointer to new dir is returned
        //       - else: NULL is returned

        std::string toString(bool includeFileContents) const;
        // post: all dirnames and filenames are recursively printed
        
    private:
        std::string name;
        Dir* nextDir;       // next dir on same level

        Dir* firstSubdir;   // first dir in this dir
        File* firstFile;    // first file in this dir
};
