#ifndef RENDERABLE_INTERFACE_H
#define RENDERABLE_INTERFACE_H

namespace gle {
    class Display;

    class RenderableInterface
    {
      public:
        RenderableInterface();
        virtual ~RenderableInterface();

        virtual void init(gle::Display & d)=0;

        virtual void update(gle::Display & d)=0;

        virtual void render(gle::Display & d)=0;

        virtual void destroy(gle::Display & d)=0;
      protected:

      private:
    };
}
#endif // RENDERABLE_INTERFACE_H
