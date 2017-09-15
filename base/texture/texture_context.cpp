#include "texture_context.h"
#include "texture_error_callbacks.h"
#include <FreeImage.h>
namespace gle {
    TextureContext::TextureContext(const bool isFreeImageAsDynamicLibrary,const bool initializeErrorCallbacks):
        m_isFreeImageAsDynamicLibrary(isFreeImageAsDynamicLibrary)
    {
        if(!m_isFreeImageAsDynamicLibrary) {
            FreeImage_Initialise();
        }
        if(initializeErrorCallbacks) {
            registerTextureErrorCallback();
        }

    }

    TextureContext::~TextureContext()
    {
        if(!m_isFreeImageAsDynamicLibrary) {
            FreeImage_DeInitialise();
        }
    }
}
