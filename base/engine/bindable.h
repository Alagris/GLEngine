#ifndef BINDABLE_H
#define BINDABLE_H

namespace gle {
    class Bindable
    {
      public:
        Bindable();
        virtual ~Bindable();
        virtual void bind()=0;
        virtual void unbind()=0;
      protected:

      private:
    };
}

#endif // BINDABLE_H
