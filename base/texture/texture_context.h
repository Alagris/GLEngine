#ifndef TEXTURE_CONTEXT_H
#define TEXTURE_CONTEXT_H
namespace gle {

    class TextureContext
    {
      public:
        TextureContext(const bool isFreeImageAsDynamicLibrary=false,const bool initializeErrorCallbacks=true);
        virtual ~TextureContext();
      protected:
      private:
        const bool m_isFreeImageAsDynamicLibrary;
    };
}

#endif // TEXTURE_CONTEXT_H
