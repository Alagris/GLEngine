#ifndef TEXTURE_H
#define TEXTURE_H
#include <FreeImage.h>
#include <memory>
namespace gle {
    /**This class is super cheap to copy*/
    class Texture
    {
      public:
        Texture():m_bitmap(nullptr,destructor){}
        Texture(const FREE_IMAGE_FORMAT format,const char *const textureFilePath): m_bitmap(new FIBITMAP*(),destructor) {
            *m_bitmap=FreeImage_Load(FIF_JPEG,textureFilePath);
        }
        virtual ~Texture(){}
        const FIBITMAP * const get()const {
            return *m_bitmap.get();
        }
        FIBITMAP *  get() {
            return *m_bitmap.get();
        }
      protected:
      private:
        static void destructor(FIBITMAP ** bmp) {
            if(bmp)if(*bmp)FreeImage_Unload(*bmp);
        }
        std::shared_ptr<FIBITMAP*> m_bitmap;
    };
}
#endif // TEXTURE_H
