#include "pch.h"
#include "Translator.h"

using namespace libtranslate;
using namespace Platform;

std::stringstream bytes_to_ss(const Platform::Array<byte>^ Table)
{
	std::string words_table((char*)Table->Data, Table->Length);
	std::stringstream words_ss(words_table);
	return words_ss;
}

Translator::Translator(const Platform::Array<byte>^ WordsTable)
{
	std::vector<std::string> _wsearch, _wreplace;

	AhoCorasick::ParseTable(bytes_to_ss(WordsTable), _wsearch, _wreplace);
	words = AhoCorasick(_wsearch);
	words_replace = _wreplace;
}

Translator::Translator(const Platform::Array<byte>^ WordsTable, const Platform::Array<byte>^ PhraseTable)
	:Translator(WordsTable)
{
	std::vector<std::string> _wsearch, _wreplace;

	AhoCorasick::ParseTable(bytes_to_ss(PhraseTable), _wsearch, _wreplace);
	phrase = AhoCorasick(_wsearch);
	phrase_replace = _wreplace;
}

String^ Translator::Translate(String^ Text)
{
	stdext::cvt::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
	std::string stringUtf8 = convert.to_bytes(Text->Data());

	std::stringstream ss = words.replace(stringUtf8, words_replace);

	if (phrase_replace.size())
	{
		ss = phrase.replace(ss.str(), phrase_replace);
	}

	std::wstring wid_str = convert.from_bytes(ss.str());
	const wchar_t* w_char = wid_str.c_str();

	return ref new Platform::String(w_char);
}

Platform::Array<byte>^ Translator::Translate(const Platform::Array<byte>^ Utf8Bytes)
{
	std::string stringUtf8(Utf8Bytes->begin(), Utf8Bytes->end());

	std::stringstream ss = words.replace(stringUtf8, words_replace);

	if (phrase_replace.size())
	{
		ss = phrase.replace(ss.str(), phrase_replace);
	}

	stringUtf8 = ss.str();
	Platform::Array<byte>^ OutputBytes = ref new Platform::Array<byte>((unsigned char *)stringUtf8.c_str(), stringUtf8.size());

	return OutputBytes;
}