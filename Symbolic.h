#pragma once

#include "IsUTF8.h"
#include "SymConv.h"

#include <sstream>
#include <cvt/wstring>
#include <codecvt>

namespace libtranslate
{
    public ref class Symbolic sealed
    {
    public:
        Symbolic();
		static Platform::String^ ToVertical(Platform::String^ Text);
    };
}
