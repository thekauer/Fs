#pragma once
#include "compatibility.h"


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


