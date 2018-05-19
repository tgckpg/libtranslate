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

void Translator::_tr_all_phases(std::string &text)
{
	unsigned int i = 0;
	do
	{
		std::stringstream ss = phases[i].replace(text, replace_phases[i]);
		size_t pos = ss.tellp();
		text = ss.str();
		text.resize(pos);
		i++;
	} while (i < phases.size());
}

Translator::Translator() { }

void Translator::AddTable(const Platform::Array<byte>^ Table)
{
	std::vector<std::string> _wsearch, _wreplace;
	AhoCorasick::ParseTable(bytes_to_ss(Table), _wsearch, _wreplace);

	if (_wreplace.size())
	{
		AhoCorasick ac(_wsearch);
		phases.push_back(ac);
		replace_phases.push_back(_wreplace);
	}
}

String^ Translator::Translate(String^ Text)
{
	if (Text == nullptr || Text->IsEmpty() || phases.empty())
		return Text;

	stdext::cvt::wstring_convert<std::codecvt_utf8<wchar_t>> convert;

	std::string stringUtf8 = convert.to_bytes(Text->Data());
	_tr_all_phases(stringUtf8);

	try
	{
		std::wstring wid_str = convert.from_bytes(stringUtf8);
		const wchar_t* w_char = wid_str.c_str();
		return ref new Platform::String(w_char);
	}
	catch (std::exception &e) {}
	return Text;
}

Platform::Array<byte>^ Translator::Translate(const Platform::Array<byte>^ Utf8Bytes)
{
	if (Utf8Bytes->Length == 0 || phases.empty())
		return (Platform::Array<byte>^) Utf8Bytes;

	std::string stringUtf8(Utf8Bytes->begin(), Utf8Bytes->end());
	_tr_all_phases(stringUtf8);

	Platform::Array<byte>^ OutputBytes = ref new Platform::Array<byte>((unsigned char *)stringUtf8.c_str(), stringUtf8.size());
	return OutputBytes;
}