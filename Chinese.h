#pragma once

#include "IsUTF8.h"
#include "CConv.h"
#include "Conv.h"

#include <sstream>
#include <cstring>
#include <cvt/wstring>
#include <codecvt>

namespace libtranslate
{
    public ref class Chinese sealed
    {
		static std::string Traditional( unsigned const char *, unsigned int tLength );
    public:
		static Platform::String^ Traditional( Platform::String^ Text );
		static Platform::Array<byte>^ Traditional( const Platform::Array<byte>^ Utf8Bytes );
    };
}
