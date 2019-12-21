#include "lex.h"

Kw::kw_ is_kw(const HashedString& hs) {
    static const int len=1;
    static const u32 Hashes[len]={HashedString::hash_str("fn")};
    static const Kw::kw_ Kws[len]={Kw::Fn};
    for(int i=0;i<len;i++) {
        if(Hashes[i]==hs.hash) {
            return Kws[i];
        }
    }
    return Kw::NotAKw;
}
//USEFUNCTIONS
//SKIP SPACES
//make this return an llvm::Value* and a hashedstring as well
std::unique_ptr<Lexem> Lexer::advance_token() {
    SourceLocation err_loc = sl;
    u8 c = eq[sl.pop()];
    if(c<Quote) {
        return std::make_unique<Op>(c);
    }
    switch (c)
    {

    case Zero:
        //implement binary,hex,octal literals
        break;

        
    case N: {
        int idc=0;
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

        if(idc>sl.indent){sl.indent=idc;return std::make_unique<Op>(Op::Gi);}
        if(idc<sl.indent){sl.indent=idc;return std::make_unique<Op>(Op::Li);}
        break;
    }
    case UcLetter:
      while(((eq[sl.peek()]>63)||eq[sl.peek()]==Underscore)&&sl.can_iter()) {
          sl.pop();
      }
        hs=HashedString(std::string(err_loc.it,sl.it));
        return std::make_unique<Id>(hs,Id::CamelCaseIdent);
    
    case LcLetter:
    case Underscore:
        bool illcase;
      while((eq[sl.peek()]>63||eq[sl.peek()]==Underscore)&&sl.can_iter()) {
          if(eq[sl.peek()]==UcLetter)illcase=true;
          sl.pop();
      }
        hs=HashedString(std::string(err_loc.it,sl.it));
       //Warn Ill case
        return illcase?std::make_unique<Id>(hs,Id::IllCaseIdent):std::make_unique<Id>(hs,Id::SnakeCaseIdent);
	//handle Empty char
    case Apostrophe:
        u8 ch = eq[sl.pop()];
        if(ch==Backslash) {
           ch=lex_escape(sl.pop());
        }
        if(eq[sl.pop()]!=Apostrophe) {
            cerror(ERR_TOO_LONG_CHAR_LITERAL,err_loc,"Char literal is too long.");
        }
        return std::make_unique<Lit>(ch);
    }
    return 0;
}

void Lexer::lex() {
    while(sl.can_iter()) {
        lexems.emplace_back(advance_token());
    }
}

char Lexer::lex_escape(const char esc) {
    auto err_loc = sl;
     switch (esc)
            {
            case 'r':
                return '\r';
                break;
            case 'n':
                return '\n';
                break;
            case '\\':
                return '\\';
                break;
            case 'b':
                return '\b';
                break;
            case '\'':
                return '\'';
                break;
            case '\"':
                return '\"';
                break;
            case 't':
                return '\t';
                break;
            case 'v':
                return '\v';
                break;
            default:
                cerror(ERR_UNKNOWN_ESCAPE,err_loc,"Unknown escape character.");
                break;
            }
}

void cerror(int code,const SourceLocation& sl,const std::string& msg) {
    std::cout << "Error " + std::to_string(code) + " at line: " + std::to_string(sl.line) + " column: " + std::to_string(sl.col) + ". " + msg;
    std::exit(code);
}


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





SourceLocation::SourceLocation(FSFile& file) : file(file),line(1),col(1),indent(0),it(file.code.begin()),end(file.code.end()) {
    current=*it;
    next=*(it+1);
    nextnext=*(it+2);

}

