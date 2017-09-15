#include "texture_format_enum_to_string.h"
#include "switch_case_enum_to_string.h"
namespace gle {

    bool getNameOfEnum(const FREE_IMAGE_FORMAT format,std::string & outputDestination) {
        switch(format) {
                ENUM_CASE(FIF_UNKNOWN,outputDestination);
                ENUM_CASE(FIF_BMP,outputDestination);
                ENUM_CASE(FIF_ICO,outputDestination);
                ENUM_CASE(FIF_JPEG,outputDestination);
                ENUM_CASE(FIF_JNG,outputDestination);
                ENUM_CASE(FIF_KOALA,outputDestination);
                ENUM_CASE(FIF_LBM,outputDestination);
//                ENUM_CASE(FIF_IFF,outputDestination);
                ENUM_CASE(FIF_MNG,outputDestination);
                ENUM_CASE(FIF_PBM,outputDestination);
                ENUM_CASE(FIF_PBMRAW,outputDestination);
                ENUM_CASE(FIF_PCD,outputDestination);
                ENUM_CASE(FIF_PCX,outputDestination);
                ENUM_CASE(FIF_PGM,outputDestination);
                ENUM_CASE(FIF_PGMRAW,outputDestination);
                ENUM_CASE(FIF_PNG,outputDestination);
                ENUM_CASE(FIF_PPM,outputDestination);
                ENUM_CASE(FIF_PPMRAW,outputDestination);
                ENUM_CASE(FIF_RAS,outputDestination);
                ENUM_CASE(FIF_TARGA,outputDestination);
                ENUM_CASE(FIF_TIFF,outputDestination);
                ENUM_CASE(FIF_WBMP,outputDestination);
                ENUM_CASE(FIF_PSD,outputDestination);
                ENUM_CASE(FIF_CUT,outputDestination);
                ENUM_CASE(FIF_XBM,outputDestination);
                ENUM_CASE(FIF_XPM,outputDestination);
                ENUM_CASE(FIF_DDS,outputDestination);
                ENUM_CASE(FIF_GIF,outputDestination);
                ENUM_CASE(FIF_HDR,outputDestination);
                ENUM_CASE(FIF_FAXG3,outputDestination);
                ENUM_CASE(FIF_SGI,outputDestination);
                ENUM_CASE(FIF_EXR,outputDestination);
                ENUM_CASE(FIF_J2K,outputDestination);
                ENUM_CASE(FIF_JP2,outputDestination);
                ENUM_CASE(FIF_PFM,outputDestination);
                ENUM_CASE(FIF_PICT,outputDestination);
                ENUM_CASE(FIF_RAW,outputDestination);
                ENUM_CASE(FIF_WEBP,outputDestination);
                ENUM_CASE(FIF_JXR,outputDestination);
            default:
                outputDestination="unknown format";
                return false;
        }
        return true;
    }
}
