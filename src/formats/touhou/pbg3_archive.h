#ifndef FORMATS_TOUHOU_PBG3_ARCHIVE_H
#define FORMATS_TOUHOU_PBG3_ARCHIVE_H
#include "formats/archive.h"

namespace Formats
{
    namespace Touhou
    {
        class Pbg3Archive final : public Archive
        {
        public:
            Pbg3Archive();
            ~Pbg3Archive();
        protected:
            bool is_recognized_internal(File &) const override;
            void unpack_internal(File &, FileSaver &) const override;
        private:
            struct Priv;
            std::unique_ptr<Priv> p;
        };
    }
}

#endif
