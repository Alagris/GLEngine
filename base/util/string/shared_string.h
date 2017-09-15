#ifndef STRING_H
#define STRING_H
#include <memory>
namespace gle {

    /**A simple wrapper around c-style string.
    Has fixed size but mutable characters and
     is very memory-lightweight (easy to copy).
     All copies of this object share the same
     data, so if one is modified, all others
     are too. It's not null terminated but
     nothing stops the user of this class from
     doing so. */
    class SharedString
    {
      public:
        SharedString():m_size(0),m_data(nullptr){}
        SharedString(const unsigned int size):m_size(size),m_data(new char[size]) {}
        SharedString(const unsigned int size,const char * const string);
        virtual ~SharedString() {}
        inline const unsigned int getSize() const {
            return m_size;
        }
        inline const char getChar(const unsigned int index) const {
            return m_data.get()[index];
        }
        inline void setChar(const unsigned int index,const unsigned char c) {
            m_data.get()[index]=c;
        }
        inline char & at(const unsigned int index) {
            return m_data.get()[index];
        }
        inline char * getArrayPtr() {
            return m_data.get();
        }
        inline const char & at(const unsigned int index) const{
            return m_data.get()[index];
        }
        inline const char *const getArrayPtr()const {
            return m_data.get();
        }
        inline char & operator[](const unsigned int index) {
            return at(index);
        }
        inline const char & operator[](const unsigned int index) const{
            return at(index);
        }
      protected:

      private:
        unsigned int m_size;
        std::shared_ptr<char[]> m_data;

    };
}

#endif // STRING_H
