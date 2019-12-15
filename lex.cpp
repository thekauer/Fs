#include "lex.h"

Keyword is_kw(const HashedString& hs) {
    static const int len=1;
    static const u32 Hashes[len]={HashedString::hash_str("fn")};
    static const Keyword Kws[len]={Fn};
    for(int i=0;i<len;i++) {
        if(Hashes[i]==hs.hash) {
            return Kws[i];
        }
    }
    return NotAKeyWord;
}

AstExpr parse_fn(SourceLocation& sl,const HashedString& kw) {
    HashedString hs;
    u8 token=advance_token(sl,hs);
    //not an identifier
    if(token>SnakeCaseIdent) {
        //error fn must be followed by function name
    }
    HashedString function_name=hs;
    //Add generic capability
    token=advance_token(sl,hs);
    if(token!=Lp) {
        //err expected (
    }
    token=advance_token(sl,hs);
    //Add Handle Args
    if(token==Rp)  parse_fn_body(sl);
}
AstExpr parse_fn_body(SourceLocation& sl) {
    HashedString hs;
    u8 token =advance_token(sl,hs);
    //token is an identifier
    if(token<LitChar) { //Handle fncall
        HashedString id=hs;
        token=advance_token(sl,hs);
        if(token==Lp) {
            //Handle args,generics
            token=advance_token(sl,hs);
            if(token==Rp) {
                //return fn call
                
            }
        }
    }
}

void parse(SourceLocation& sl) {
    HashedString hs;
    u8 token =advance_token(sl,hs);
    Keyword kw= is_kw(hs);
    switch(token) {
        case SnakeCaseIdent:
            if(kw!=NotAKeyWord) {
                
            } else { //its an identifier

            }
        default:
            break;

    }
}
//USEFUNCTIONS
//SKIP SPACES
//make this return an llvm::Value* and a hashedstring as well
unsigned char advance_token(SourceLocation& sl,HashedString& hs) {
    SourceLocation err_loc = sl;
    u8 c = eq[sl.pop()];
    int idc=0;//SAME AS sl.col.!!
    int val;//use llvm Value*
    double dval;
    bool f=false;
    std::string s;
    if(c<Quote) {
        return c;
    }
    switch (c)
    {

    case Zero:
        //implement binary,hex,octal literals
        break;
    case Number:
        while(eq[sl.peek()]>127 || eq[sl.peek()]==Dot) {
            if(eq[sl.peek()]==Dot)f=true;
            sl.pop();
        }
        s = std::string(err_loc.it,sl.it);
        if(!f) {
            //Implement long long numbers and float...
            val=std::stoi(s);
            return LitInt;

        }else {
            dval = std::stod(s);
            return LitDouble;
        }
        break;

        
    case N:
        sl.line++;
        sl.col=1;
        while(eq[sl.peek()]==Space) {
            idc++;
            auto t =sl.pop();
            if(eq[t]==Tab)cerror(ERR_BOTH_TABS_AND_SPACES,err_loc,"Don't mix tabs and spaces!");
        }
        while(eq[sl.peek()]==Tab) {
            idc++;
            auto t =sl.pop();
            if(eq[t]==Space)cerror(ERR_BOTH_TABS_AND_SPACES,err_loc,"Don't mix tabs and spaces!");
        }

        if(idc>sl.indent){sl.indent=idc;return Gi;}
        if(idc<sl.indent){sl.indent=idc;return Li;}
        break;
    case UcLetter:
      while(((eq[sl.peek()]>63)||eq[sl.peek()]==Underscore)&&sl.can_iter()) {
          sl.pop();
      }
        hs=HashedString(std::string(err_loc.it,sl.it));
        return CamelCaseIdent;
    
    case LcLetter:
    case Underscore:
        bool illcase;
      while((eq[sl.peek()]>63||eq[sl.peek()]==Underscore)&&sl.can_iter()) {
          if(eq[sl.peek()]==UcLetter)illcase=true;
          sl.pop();
      }
        hs=HashedString(std::string(err_loc.it,sl.it));
       //Warn Ill case
        return illcase?IllCaseIdent:SnakeCaseIdent;
	//handle Empty char
    case Apostrophe:
        u8 ch = eq[sl.pop()];
        if(ch==Backslash) {
            switch (sl.pop())
            {
            case 'r':
                ch='\r';
                break;
            case 'n':
                ch='\n';
                break;
            case '\\':
                ch='\\';
                break;
            case 'b':
                ch='\b';
                break;
            case '\'':
                ch='\'';
                break;
            case '\"':
                ch='\"';
                break;
            case 't':
                ch='\t';
                break;
            case 'v':
                ch='\v';
                break;
            default:
                cerror(ERR_UNKNOWN_ESCAPE,err_loc,"Unknown escape character.");
                break;
            }
        }
        if(eq[sl.pop()]!=Apostrophe) {
            cerror(ERR_TOO_LONG_CHAR_LITERAL,err_loc,"Char literal is too long.");
        }
        return LitChar;
    }
    return 0;
}
void cerror(int code,const SourceLocation& sl,const std::string& msg) {
    std::cout << "Error " + std::to_string(code) + " at line: " + std::to_string(sl.line) + " column: " + std::to_string(sl.col) + ". " + msg;
    std::exit(code);
}
void Compiler::compile(const std::string& path) {
    sm.open(path);
    SourceLocation sl(sm.sources[0]);
    //HashedString hs;
    //while(sl.can_iter())std::cout << (int)advance_token(sl,hs) << " ";
    parse(sl);
}

SourceLocation::SourceLocation(FSFile& file) : file(file),line(1),col(1),indent(0),it(file.code.begin()),end(file.code.end()) {
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
    it+=n+1;
    col++;
    prefetch(&it);
    current=next;
    next=nextnext;
    nextnext=*(it+2);
    return r;
}


INLINE bool SourceLocation::can_iter() {
    return it!=end;
}
