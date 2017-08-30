#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <vector>
//#include "FileReader.h"
namespace gle {
    bool readWholeFile(const char * const filePath,std::string & dataDestination);
    bool readWholeFile(const char * const filePath,std::vector<char> & dataDestination);
}
#endif // FILE_READER_H
