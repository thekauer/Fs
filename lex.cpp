#include "lex.h"


SourceLocation::SourceLocation(FSFile& file) : file(file),line(1),col(1),it(file.code.begin())  {

    

}

void SourceLocation::open(std::experimental::filesystem::path path) {
    using namespace std::experimental::filesystem;
    
}

INLINE constexpr char SourceLocation::peek(const int n=0) {
    switch (n)
    {
    case 0:
        return peek_();
        break;
    case 1:
        return peek_next();
        break;
    case 2:
        return peek_nextnext();
        break;
    
    default:
        return peek_nth(n);
    }
}

INLINE char SourceLocation::peek_() {
    return current;
}

INLINE char SourceLocation::peek_next() {
    return next;
}

INLINE char SourceLocation::peek_nextnext() {
    return nextnext;
}

INLINE char SourceLocation::pop(int n) {
    char r=peek(n);
    it+=n;
    col++;
    return r;
}


