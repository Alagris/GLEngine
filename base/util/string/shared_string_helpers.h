#ifndef SHARED_STRING_HELPERS_H
#define SHARED_STRING_HELPERS_H
namespace gle{
    class SharedString;

    const bool compare(const SharedString &s1,const char * const s2,const unsigned int s2Length);
    const bool compare(const SharedString &s1,const SharedString&s2);
    const bool compare(const SharedString &s1,const char * const s2);
}

#endif // SHARED_STRING_HELPERS_H
