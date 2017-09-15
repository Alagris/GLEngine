#ifndef MAX_H_INCLUDED
#define MAX_H_INCLUDED


namespace gle {
    template<typename T>
    inline void compareMax(const T val,T & max) {
        if(val>max)max=val;
    }
}
#endif // MAX_H_INCLUDED
