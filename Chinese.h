#pragma once

#include "IsUTF8.h"
#include "CConv.h"

#include <sstream>
#include <cstring>
#include <cvt/wstring>
#include <codecvt>

namespace libtranslate
{
    public ref class Chinese sealed
    {
    public:
		static Platform::String^ Traditional(Platform::String^ Text);
    };
}
