#pragma once

#include <sstream>
#include <cstring>
#include <cvt/wstring>
#include <codecvt>
#include "native/shared/ahocrsk.h"

namespace libtranslate
{
	std::vector<AhoCorasick> phases;
	std::vector<std::vector<std::string>> replace_phases;

	public ref class Translator sealed
	{
		std::string _tr_all_phases(std::string text);

	public:
		Translator::Translator();
		void Translator::AddTable(const Platform::Array<byte>^ Phase);

		[Windows::Foundation::Metadata::DefaultOverloadAttribute]
		Platform::String^ Translate(Platform::String^ Text);

		Platform::Array<byte>^ Translate(const Platform::Array<byte>^ Utf8Bytes);
	};
}