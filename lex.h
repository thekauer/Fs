#pragma once
#include <vector>
#include <string>
#include "compatibility.h"
#include "hashed_string.h"
#include <fstream>
#include "ercodes.h"
#include <iostream>

void error(int code,const std::string& msg);
struct FSFile {
    const std::string path;
    const std::string code;
    FSFile(const std::string path,const std::string code) :path(path),code(code){};
};
class SourceManager {
public:
    std::vector<FSFile> sources;
    SourceManager()=default;
    void open(const std::string& path);
    //void open_(std::experimental::filesystem::path path);
};
class Compiler {
 std::vector<std::string> Warnings,Lints;
 SourceManager sm;
 struct CompilerOptions {
     
 };
 public:
  Compiler() : sm(SourceManager()){};
  void compile(const std::string& path);
};


//indentation should be a part of it
class SourceLocation {
    public:
    FSFile& file;
    int line,col;
    char current,next,nextnext;
    std::string::const_iterator it,end;
    SourceLocation(FSFile& file);
    INLINE constexpr char peek(const int n=0);
    INLINE char pop(int n=0);
    INLINE bool can_iter();
    INLINE char peek_();
    INLINE char peek_next();
    INLINE char peek_nextnext();
    INLINE char peek_nth(int n);
};
class AstExpr {
    public:
    virtual ~AstExpr();
};

void cerror(int code,const SourceLocation& sl,const std::string& msg);
unsigned char advance_token(SourceLocation& sl,int indent,HashedString*hs=nullptr);
void parse(SourceLocation& sl);
typedef AstExpr(*parser_fn)(const SourceLocation&,int,HashedString*);

enum Keyword :unsigned char
{
    NotAKeyWord,
    Fn,
};
Keyword is_kw(const HashedString& hs);

enum Eq : unsigned char {
    Not=1,
    Hashtag,
    Mod,
    Lp,
    Rp,
    Mul,
    Add,
    Sub,
    Comma,
    Dot,
    Div,
    DoubleDot,
    SemiColon,
    Gt, //<
    Lt, // >
    Eq,
    Questionmark, 
    Backslash,
    Lb, //[
    Rb,// ]
    Underscore,
    Triangle, //^
    Lc, //{
    Rc, //}
    Or,
    Neg, //~
    Null,
    Space,
    Tab,
    And,
    //parsing required
    Quote,
    Apostrophe,
    Cr, // carrige return
    N, //ascii 10 == 0xA
    LcLetter=64,
    UcLetter=65,
    Zero=129,
    Number=128
};
static const int ISLETTER=64,ISNUMBER=128;
static const unsigned eq[128] = {Null,0,0,0,0,0,0,0,0,0,N,0,0,Cr,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                Space,Not,Quote,Hashtag,0,Mod,And,Apostrophe,Lp,Rp,Mul,Add,Comma,Sub,Dot,Div,
                                Zero,Number,Number,Number,Number,Number,Number,Number,Number,Number,DoubleDot,SemiColon,Lt,Eq,Gt,Questionmark,
                                0,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,
                                UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,UcLetter,Lb,Backslash,Rb,Triangle,Underscore,
                                0,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,
                                LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,LcLetter,Lc,Or,Rc,Neg};

enum Token:unsigned char {
    CamelCaseIdent=32,
    IllCaseIdent,
    SnakeCaseIdent,
    LitChar,
    Gi,
    Li,
    LitInt,
    LitDouble,
};