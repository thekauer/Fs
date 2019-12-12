#include <vector>
#include <string>
#include "compatibility.h"
#include <experimental/filesystem>
#include <fstream>

[[noreturn]] void error(int code,std::string msg);
class Compiler {
 std::vector<std::string> Warnings,Lints;
 SourceManager sm();
 struct CompilerOptions {
     
 };
  Compiler()=default;
  void Compile(std::experimental::filesystem::path path);
};

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


enum Eq : char {
    Discard=1,
    LcLetter,
    UcLetter,
    Not,
    Quote,
    Hashtag,
    Mod,
    Apostrophe,
    Lp,
    Rp,
    Mul,
    Add,
    Sub,
    Comma,
    Dot,
    Div,
    Number,
    DoubleDot,
    SemiColon,
    Gt, //<
    Lt, // >
    Eq,
    Questionmark, 
    Lb, //[
    Rb,// ]
    Underscore,
    Triangle, //^
    Lc, //{
    Rc, //}
    Or,
    Neg, //~
    Null,
    Cr, // carrige return
    N, //ascii 10 == 0xA
    Space,
    Tab,
    And
};

static const char eq[128] = {32,0,0,0,0,0,0,0,0,36,34,0,0,33,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,35,4,5,6,0,7,37,8,9,10,11,12,14,13,15,16,17,17,17,17,17,17,17,17,17,17,18,19,20,22,21,23,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,24,0,25,27,26,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,28,30,29,31,0};
