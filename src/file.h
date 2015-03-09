#ifndef FILE_H
#define FILE_H
#include <boost/filesystem/path.hpp>
#include <string>
#include "file_io.h"
#include "io.h"

class File final
{
public:
    File(const boost::filesystem::path &path, const FileIOMode mode);
    File();
    ~File();
    IO &io;
    std::string name;
    void change_extension(const std::string new_extension);
    void guess_extension();
};

#endif
