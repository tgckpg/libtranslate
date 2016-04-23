#pragma once

#include "IsUTF8.h"

#include <sstream>
#include <cvt/wstring>
#include <codecvt>

std::string ConvWithInst(const unsigned char* byte_arr, int tLength
	, void match_byte6(unsigned char const*, int, char const* &, int &)
	, void match_byte5(unsigned char const*, int, char const* &, int &)
	, void match_byte4(unsigned char const*, int, char const* &, int &)
	, void match_byte3(unsigned char const*, int, char const* &, int &)
	, void match_byte2(unsigned char const*, int, char const* &, int &)
	, void match_ascii(unsigned char const*, int, char const* &, int &)
);