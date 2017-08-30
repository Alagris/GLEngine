#include "file_reader.h"
#include <string>
#include <fstream>
#include <vector>
#include <streambuf>

namespace gle {
    bool readWholeFile(const char * const filePath,std::vector<char> & dataDestination) {
        std::ifstream in(filePath);
        if(in.is_open()) {
            in.seekg(0, std::ios::end);
            const int size = in.tellg();
            if(size==-1) {
                return false;
            }
            in.seekg(0, std::ios::beg);
            dataDestination.reserve(size_t(size));
            in.read(dataDestination.data(), size);
            return bool(in);
        } else {
            return false;
        }
    }


    bool readWholeFile(const char * const filePath,std::string & dataDestination) {
        std::ifstream in(filePath);
        if(in.is_open()) {
            in.seekg(0, std::ios::end);
            int size = in.tellg();
            if(size==-1) {
                return false;
            }
            dataDestination.reserve(size_t(size));
            in.seekg(0, std::ios::beg);

            dataDestination.assign((std::istreambuf_iterator<char>(in)),
                                   std::istreambuf_iterator<char>());
            return bool(in);
        } else {
            return false;
        }
    }
}
