#pragma once

#include "IsUTF8.h"
#include "SymConv.h"
#include "SynPatchConv.h"
#include "Conv.h"

#include <sstream>
#include <cvt/wstring>
#include <codecvt>

namespace libtranslate
{
    public ref class Symbolic sealed
    {
    public:
		static Platform::String^ ToVertical(Platform::String^ Text);
		static Platform::String^ PatchSyntax(Platform::String^ Text);
		static Platform::Array<byte>^ Symbolic::PatchSyntax(const Platform::Array<byte>^ Utf8Bytes);
    };
}
