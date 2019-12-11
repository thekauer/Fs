#include <vector>
#include <string>
#include "compatibility.h"
#include <experimental/filesystem>
#include <fstream>

class SourceManager {
    std::vector<FSFile> sources;
public:
    SourceManager()=default;
    void open(std::experimental::filesystem::path path);
};

struct FSFile {
    std::experimental::filesystem::path path;
    std::string code;
};

class SourceLocation {
    FSFile& file;
    int line,col;
    char current,next,nextnext;
    std::string::const_iterator it;
    public:
    SourceLocation(FSFile& file);
    INLINE constexpr char peek(int n=0);
    INLINE char pop(int n=0);

    INLINE char peek_();
    INLINE char peek_next();
    INLINE char peek_nextnext();
    INLINE char peek_nth(int n);
};