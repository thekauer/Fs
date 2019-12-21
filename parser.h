#pragma once
#include "lex.h"
#include <memory>
#include "hashed_string.h"
#include "compatibility.h"
class AstExpr {
    public:

};

struct FnDecl : AstExpr {
    HashedString name;
    //args
    std::unique_ptr<AstExpr> body;
    FnDecl(const HashedString& name) : name(name){};
};

struct FnCall : AstExpr {
    HashedString name;
    //args
    FnCall(const HashedString& name) : name(name) {};
};







    template<typename T=Lexem>
    constexpr T* icast(Lexem* p) {
        return reinterpret_cast<T*>(p);
    }

class Iter {
public:
    using iterator = std::vector<std::unique_ptr<Lexem>>::const_iterator;
    
    Lexem *current,*next,*nextnext;
    iterator it,end;

    Iter(iterator beg,iterator end) : it(beg),end(end){
        
        current=it->get();
        next=(it+1)->get();
        nextnext=(it+2)->get();
    }; 
    INLINE bool can_iter(){
        return it!=end;
    };






    template<typename T=Lexem>
    INLINE constexpr T* peek(const int n=0){
    switch (n)
    {
    case 0:
        return icast<T>(peek_());
        break;
    case 1:
        return icast<T>(peek_next());
        break;
    case 2:
        return icast<T>(peek_nextnext());
        break;
    
    default:
        return icast<T>(peek_nth(n));
    }
    };
    
    template<typename T=Lexem>
    INLINE T* pop(int n=0) {
    T* r=peek<T>(n);
    it+=n+1;
    prefetch(&it);
    current=next;
    next=nextnext;
    nextnext=(it+2)->get();
    return r;
    };
    
    INLINE Lexem* peek_(){
        return current;
    };
    
    INLINE Lexem* peek_next(){
        return next;
    };
    
    INLINE Lexem* peek_nextnext(){
        return nextnext;
    };
    
    INLINE Lexem* peek_nth(int n){
        return (it+n)->get();
    };
};








class Parser {
    public:
    Iter it;
    //const std::vector<std::unique_ptr<Lexem>>& lexems;
    std::unique_ptr<AstExpr> root;
    //Parser(const std::vector<std::unique_ptr<Lexem>>& lexems) :lexems(lexems){};
    Parser(const std::vector<std::unique_ptr<Lexem>>& lexems) : it(lexems.begin(),lexems.end()),
    root(std::move(parse())){};
    std::unique_ptr<AstExpr> parse();
    std::unique_ptr<FnDecl> parse_fn();
    std::unique_ptr<AstExpr> parse_fn_body();//pass in function context(args,generics...) as well
    std::unique_ptr<FnCall> parse_fn_call();
    std::unique_ptr<AstExpr> parse_kw();
    std::unique_ptr<AstExpr> parse_id();
};