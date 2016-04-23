#include "pch.h"
#include "Chinese.h"

using namespace libtranslate;
using namespace Platform;

String^ Chinese::Traditional(String^ Text)
{
	stdext::cvt::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
	std::string stringUtf8 = convert.to_bytes(Text->Data());

	const char* out_phrase;
	int step_size = 0;
	int tLength = stringUtf8.length();

	std::stringstream conv_stream;
	const unsigned char* byte_arr = (const unsigned char*)(char *)stringUtf8.c_str();

	// Phase 1, translate words
	std::string s = ConvWithInst(
		byte_arr, tLength
		, match_wt_byte6, match_wt_byte5
		, match_wt_byte4, match_wt_byte3
		, match_wt_byte2, match_wt_ascii
	);

	byte_arr = (const unsigned char*)s.c_str();

	// Phase 2, translate phrases
	s = ConvWithInst(
		byte_arr, tLength
		, match_pt_byte6, match_pt_byte5
		, match_pt_byte4, match_pt_byte3
		, match_pt_byte2, match_pt_ascii
	);

	std::wstring wid_str = convert.from_bytes(s);
	const wchar_t* w_char = wid_str.c_str();

	return ref new Platform::String(w_char);
}
