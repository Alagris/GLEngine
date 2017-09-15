#ifndef FILE_PATH_CONCATENATION_H
#define FILE_PATH_CONCATENATION_H

namespace gle{
    class SharedString;
    const SharedString swapFileNameInPath(const char * const path,const char * const fileName);
}
#endif // FILE_PATH_CONCATENATION_H
