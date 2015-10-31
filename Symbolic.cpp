#include "pch.h"
#include "Symbolic.h"

#include "IsUTF8.h"
#include "Converter.h"

#include <sstream>
#include <cvt/wstring>
#include <codecvt>

using namespace VerticalTranslate;
using namespace Platform;

Symbolic::Symbolic()
{
}

String^ Symbolic::Convert(String^ Text)
{
	stdext::cvt::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
	std::string stringUtf8 = convert.to_bytes(Text->Data());

	char* byte_arr_c;
	const char* out_phrase;
	int step_size = 0;
	int tLength = stringUtf8.length();

	std::stringstream conv_stream;
	const unsigned char* byte_arr = (const unsigned char*)(char *) stringUtf8.c_str();


	for (int i = 0; i < tLength; i++)
	{
		if (is_utf8_byte6(byte_arr, i))
		{
			match_w_byte6(byte_arr, i, out_phrase, step_size);
			if (0 < step_size)
			{
				conv_stream << out_phrase;
			}
			else
			{
				// if word does not match, pad this word
				step_size = 5;
				conv_stream << byte_arr[i] << byte_arr[i + 1] << byte_arr[i + 2] << byte_arr[i + 3] << byte_arr[i + 4] << byte_arr[i + 5];
			}
		}
		else if (is_utf8_byte5(byte_arr, i))
		{
			match_w_byte5(byte_arr, i, out_phrase, step_size);
			if (0 < step_size)
			{
				conv_stream << out_phrase;
			}
			else
			{
				// if word does not match, pad this word
				step_size = 4;
				conv_stream << byte_arr[i] << byte_arr[i + 1] << byte_arr[i + 2] << byte_arr[i + 3] << byte_arr[i + 4];
			}
		}
		else if (is_utf8_byte4(byte_arr, i))
		{
			match_w_byte4(byte_arr, i, out_phrase, step_size);
			if (0 < step_size)
			{
				conv_stream << out_phrase;
			}
			else
			{
				// if word does not match, pad this word
				step_size = 3;
				conv_stream << byte_arr[i] << byte_arr[i + 1] << byte_arr[i + 2] << byte_arr[i + 3];
			}
		}
		else if (is_utf8_byte3(byte_arr, i))
		{
			match_w_byte3(byte_arr, i, out_phrase, step_size);
			if (0 < step_size)
			{
				conv_stream << out_phrase;
			}
			else
			{
				// if word does not match, pad this word
				step_size = 2;
				conv_stream << byte_arr[i] << byte_arr[i + 1] << byte_arr[i + 2];
			}
		}
		else if (is_utf8_byte2(byte_arr, i))
		{
			match_w_byte2(byte_arr, i, out_phrase, step_size);
			if (0 < step_size)
			{
				conv_stream << out_phrase;
			}
			else
			{
				// if word does not match, pad this word
				step_size = 1;
				conv_stream << byte_arr[i] << byte_arr[i + 1];
			}
		}
		else if (is_ascii(byte_arr, i))
		{
			match_w_ascii(byte_arr, i, out_phrase, step_size);
			if (0 < step_size)
			{
				conv_stream << out_phrase;
			}
			else
			{
				// if word does not match, pad this word
				step_size = 0;
				conv_stream << byte_arr[i];
			}
		}
		else
		{
			// Not a valid character, pad it
			step_size = 0;
			conv_stream << byte_arr[i];
		}
		i += step_size;
	}

	std::wstring wid_str = convert.from_bytes( conv_stream.str() );
	const wchar_t* w_char = wid_str.c_str();

	return ref new Platform::String(w_char);
}

