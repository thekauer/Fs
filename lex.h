#pragma once
#include <vector>
#include <string>
#include "compatibility.h"
#include "hashed_string.h"
#include <fstream>
#include "errcodes.h"
#include <iostream>
#include "source.h"
#include <memory>
#include <variant>


//indentation should be a part of it
class SourceLocation {
    public:
    FSFile& file;
    int line,col,indent;
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


void cerror(int code,const SourceLocation& sl,const std::string& msg);

struct Lexem {
    enum type_ : unsigned char{
        Kw,
        Id,
        Op,
        Lit
    } type;
    Lexem(type_ type) : type(type){};
};

struct Kw  :Lexem{
    enum kw_ : unsigned char {
        NotAKw,
        Fn
    }kw;
    Kw(kw_ kw) :kw(kw),Lexem(Lexem::Kw){};
}; 
struct Id : Lexem {
    HashedString id;
    enum type_ : unsigned char {    
    CamelCaseIdent,
    IllCaseIdent,
    SnakeCaseIdent
    } type;
    Id(HashedString id,type_ type) : id(id),type(type),Lexem(Lexem::Id){};
};
struct Op : Lexem {
    enum op_ : unsigned char {
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
    Li,
    Gi
    } op;
    Op(op_ op) :op(op),Lexem(Lexem::Op){};
    Op(unsigned char ch) : op(static_cast<op_>(ch)),Lexem(Lexem::Op){};
};

struct Lit : Lexem {
    enum type_ :unsigned char {
        Char=0,
        String,
        I32,
        I16,
        I64,
        Bool,
        Float,
        Double,
        USize,
        U8,
        U16,
        U32,
        U64
    } type;
    std::variant<char,
                 std::string,
                 i32,
                 i16,
                 i64,
                 bool,
                 float,
                 double,
                 ptr,
                 u8,
                 u16,
                 u32,
                 u64
                 > val;


    template<typename T>
    Lit(T s) : val(s),Lexem(Lexem::Lit){type = static_cast<type_>((unsigned char)val.index());};

};





class Lexer {
public:
    SourceLocation sl;
    HashedString hs;
    std::vector<std::unique_ptr<Lexem>> lexems;
    Lexer(SourceLocation sl) : sl(sl){lex();};
    char lex_escape(const char esc);
    std::unique_ptr<Lexem> advance_token();
    void lex();
};


Kw::kw_ is_kw(const HashedString& hs);

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
    Identifier=32,
    LitChar,
    Gi,
    Li,
    LitInt,
    LitDouble,
};