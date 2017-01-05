#pragma once

#include <string>

class File
{
    public:
        File(std::string name);
        // post: File object is properly initialised
        virtual ~File();
        // empty virtual destructor

        std::string getName() const;
        // post: filename is returned
        void setName(std::string name);
        // post: filename is updated

        std::string getContent() const;
        // post: content is returned
        void setContent(std::string content);
        // post: content is updated

        File* getNext();
        // post: pointer to next file is returned
        void setNext(File* next);
        // post: pointer to next file is set

        std::string toString(std::string path, bool includeFileContents) const;
        // post: path + filename + newline character is returned, if includeFileContents is true
        //       the file contents are added in the following layout:
        //       path + filename + newline
        //       [ + newline
        //       file content + newline
        //       ] + newline
        
    private:
        std::string name;
        std::string content;
        File* next;
};
