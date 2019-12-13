#pragma once
#ifndef __HASHED_STRING_H__
#define __HASHED_STRING_H__
#include <iostream>
#include "compatibility.h"
class HashedString {
public:
	u32 hash;
	std::string str;
	static u32 hash_str(std::string);
	HashedString()=default;
	HashedString(std::string str);
	void operator=(const HashedString&);
	bool operator==(const HashedString) const;
	bool operator!=(const HashedString) const;
};


#endif