#pragma once

#include <sstream>
#include <cstring>
#include <cvt/wstring>
#include <codecvt>
#include "native/shared/ahocrsk.h"

namespace libtranslate
{
	AhoCorasick words;
	AhoCorasick phrase;

	std::vector<std::string> words_replace;
	std::vector<std::string> phrase_replace;

    public ref class Translator sealed
    {
    public:
		Translator::Translator(const Platform::Array<byte>^ Words);

		Translator::Translator(const Platform::Array<byte>^ Words, const Platform::Array<byte>^ Phrase);

		[Windows::Foundation::Metadata::DefaultOverloadAttribute]
		Platform::String^ Translate( Platform::String^ Text );

		Platform::Array<byte>^ Translate( const Platform::Array<byte>^ Utf8Bytes );
    };
}