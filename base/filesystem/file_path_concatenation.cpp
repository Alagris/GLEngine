#include "file_path_concatenation.h"
#include <cstring>
#include "shared_string.h"
namespace gle {

    const SharedString swapFileNameInPath(const char * const path,const char * const fileName) {
        unsigned int pathLen=0;
        for(unsigned int i=0; i<300; i++) {
            if(path[i]=='\0') {
                break;
            }
            if(path[i]=='/') {
                pathLen=i+1;
            }
        }
        const unsigned int fileNameLen=std::strlen(fileName);
        SharedString out(fileNameLen+pathLen+1);
        for(unsigned int i=0; i<pathLen; i++) {
            out[i]=path[i];
        }
        for(unsigned int i=0; i<fileNameLen; i++) {
            out[pathLen+i]=fileName[i];
        }
        out[fileNameLen+pathLen]='\0';
        return out;
    }
}
