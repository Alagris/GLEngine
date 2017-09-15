#include "shared_string_helpers.h"
#include "shared_string.h"
#include "cstring"
namespace gle {
    const bool compare(const SharedString &s1,const char * const s2,const unsigned int s2Length) {
        if(s1.getSize()!=s2Length)return false;
        for(unsigned int i=0; i<s2Length; i++) {
            if(s1[i]!=s2[i])return false;
        }
        return true;
    }

    const bool compare(const SharedString &s1,const SharedString&s2) {
        return compare(s1,s2.getArrayPtr(),s2.getSize());
    }

    const bool compare(const SharedString &s1,const char * const s2) {
        return compare(s1,s2,std::strlen(s2));
    }
}
