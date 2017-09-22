#ifndef MAX_H_INCLUDED
#define MAX_H_INCLUDED


namespace gle {
    template<typename T>
    inline void compareMax(const T val,T & max) {
        if(val>max)max=val;
    }
    template<typename T>
    inline const T max(const T a,const T b) {
        return a>b?a:b;
    }

}
#endif // MAX_H_INCLUDED
