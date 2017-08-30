#ifndef BASE_H
#define BASE_H

#include "renderable_interface.h"
namespace gle {
    class base: public RenderableInterface
    {
      public:
        base();
        ~base();

        void init(gle::Display & d);

        void update(gle::Display & d);

        void render(gle::Display & d);

        void destroy(gle::Display & d);
      protected:

      private:
    };
}
#endif // BASE_H
