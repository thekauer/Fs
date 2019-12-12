#include "lex.h"

unsigned char advance_token(SourceLocation& sl,int indent) {
    u8 c = eq[sl.peek()];
    if(c<Quote) {
        return eq[sl.pop()];
    }
    switch (c)
    {

    case UcLetter:
        while(eq[sl.peek(1)]&ISLETTER||eq[sl.peek(1)]&ISNUMBER||eq[sl.peek(1)]==Underscore) {
            sl.pop();
        }
        return CamelCaseIdent;
    
    case LcLetter:
    case Underscore:
        bool illcase;
        while(eq[sl.peek(1)]&ISLETTER||eq[sl.peek(1)]&ISNUMBER||eq[sl.peek(1)]==Underscore) {
            if(eq[sl.pop()]==UcLetter) illcase=true;
        }
        return illcase?IllCaseIdent:SnakeCaseIdent;

    case Apostrophe:
        u8 ch = eq[sl.pop(1)];
        if(eq[sl.pop()]!=Apostrophe) {
            cerror(ERR_TOO_LONG_CHAR_LITERAL,sl,"Char literal is too long.");
        }
        return LitChar;
    }

}
void cerror(int code,const SourceLocation& sl,const std::string& msg) {
    std::cout << "Error " + std::to_string(code) + " at line: " + std::to_string(sl.line) + " column: " + std::to_string(sl.col) + ". " + msg;
    std::exit(code);
}
void Compiler::compile(const std::string& path) {
    sm.open(path);
    SourceLocation sl(sm.sources[0]);
    std::cout << (int)advance_token(sl,0) << (int)advance_token(sl,0);
}

SourceLocation::SourceLocation(FSFile& file) : file(file),line(1),col(1),it(file.code.begin()),end(file.code.end()) {
    current=*it;
    next=*(it+1);
    nextnext=*(it+2);

}

void error(int code,const std::string& msg) {
    std::cout << "Error: " + std::to_string(code) + " " + msg;
    std::exit(code);
}

void SourceManager::open(const std::string& path) {
    std::ifstream in(path);
    std::string code((std::istreambuf_iterator<char>(in)),std::istreambuf_iterator<char>());
    in.close();
    sources.push_back(FSFile(path,code+"\0\0\0"));
}
/*
void SourceManager::open_(std::experimental::filesystem::path path) {
    using namespace std::experimental::filesystem;
    if(!exists(path)) {
        error(ERR_FILE_NOT_EXISTS,path.concat(" does not exists."));
    }
    if(path.extension()!="fs") {
        error(ERR_ONLY_FS_FILES,"Only files with .fs extension are allowed!");
    }
    std::ifstream in(path);
    std::string code((std::istreambuf_iterator<char>(in)),std::istreambuf_iterator<char>());
    in.close();
    sources.push_back(FSFile(path,code));
}
*/
INLINE constexpr char SourceLocation::peek(const int n) {
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

INLINE char SourceLocation::peek_nth(int n) {
    return *it+n;
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
    current=next;
    next=nextnext;
    nextnext=*(it+2);
    return r;
}


INLINE bool SourceLocation::can_iter() {
    return it!=end;
}