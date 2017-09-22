#ifndef DEEP_COPY_POINTER_H
#define DEEP_COPY_POINTER_H
#include <memory>
namespace gle {
//    namespace {
//
//    }

    template<typename T>
    class DeepCopyPointer
    {
      public:
        ////////////////////////////
        //getters
        ////////////////////////////
        inline T *const get() {
            return m_ptr;
        }
        inline const T *const get()const {
            return m_ptr;
        }
        inline T & getRef() {
            return *get();
        }
        inline const T & getRef()const {
            return *get();
        }
        inline T & operator->() {
            return *m_ptr;
        }
        inline const T & operator->()const {
            return *m_ptr;
        }
        ////////////////////////////
        //key functions
        ////////////////////////////

        void copy(const T * const other) {
            if (this->m_ptr == other) return;
            if(other==nullptr) {
                //due to previous if statement
                //we can be sure that our m_ptr
                //is not null
                delete m_ptr;
                m_ptr=nullptr;
            } else {
                T * tmp_ptr = m_ptr;
                m_ptr=new T(*other);
                if(tmp_ptr)delete tmp_ptr;
            }
        }
        /**Sets pointer without performing deep copy.
        Use it with caution. It will delete previously
        set pointer*/
        void set(T * const ptr) {
            delete m_ptr;
            m_ptr=ptr;
        }

        ////////////////////////////
        //constructors/destructors
        ////////////////////////////
        /**Initializes pointer without performing deep copy*/
        DeepCopyPointer(T * const ptr=nullptr):m_ptr(ptr) {}
        DeepCopyPointer(const T& other) {
            copy(&other);
        }
        DeepCopyPointer(const DeepCopyPointer& other):DeepCopyPointer(other.getRef()) {}
        virtual ~DeepCopyPointer() {
            delete m_ptr;
        }

        ////////////////////////////
        //setters
        ////////////////////////////


        inline DeepCopyPointer& operator=(T *const other) {
            copy(other);
            return *this;
        }
        inline DeepCopyPointer& operator=( DeepCopyPointer<T>& other) {
            return operator=(other.get());
        }
        inline DeepCopyPointer& operator=( T& other) {
            return operator=(&other);
        }



      protected:

      private:
        T * m_ptr;
    };





}
#endif // DEEP_COPY_POINTER_H
