#include "shared_string.h"
namespace gle {
    SharedString::SharedString(const unsigned int size,const char * const string):SharedString(size) {
        for(unsigned int i=0; i<size; i++)setChar(i,string[i]);
    }
}
