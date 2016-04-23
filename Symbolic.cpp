#include "pch.h"
#include "Symbolic.h"

using namespace libtranslate;
using namespace Platform;

String^ Symbolic::ToVertical(String^ Text)
{
	stdext::cvt::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
	std::string stringUtf8 = convert.to_bytes(Text->Data());

	const char* out_phrase;
	int step_size = 0;
	int tLength = stringUtf8.length();

	const unsigned char* byte_arr = (const unsigned char*)(char *)stringUtf8.c_str();

	std::string constr = ConvWithInst(
		byte_arr, tLength
		, match_w_byte6, match_w_byte5
		, match_w_byte4, match_w_byte3
		, match_w_byte2, match_w_ascii
	);

	std::wstring wid_str = convert.from_bytes(constr);
	const wchar_t* w_char = wid_str.c_str();

	return ref new Platform::String(w_char);
}
String^ Symbolic::PatchSyntax(String^ Text)
{
	stdext::cvt::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
	std::string stringUtf8 = convert.to_bytes(Text->Data());

	const char* out_phrase;
	int step_size = 0;
	int tLength = stringUtf8.length();

	const unsigned char* byte_arr = (const unsigned char*)(char *)stringUtf8.c_str();

	std::string constr = ConvWithInst(
		byte_arr, tLength
		, match_syn_byte6, match_syn_byte5
		, match_syn_byte4, match_syn_byte3
		, match_syn_byte2, match_syn_ascii
	);

	std::wstring wid_str = convert.from_bytes(constr);
	const wchar_t* w_char = wid_str.c_str();

	return ref new Platform::String(w_char);
}