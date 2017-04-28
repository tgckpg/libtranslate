#include "pch.h"
#include "Conv.h"

using namespace Platform;


std::string ConvWithInst(
	const unsigned char *byte_arr, int tLength
	, void match_byte6(unsigned char const *, int, char const *&, int &)
	, void match_byte5(unsigned char const *, int, char const *&, int &)
	, void match_byte4(unsigned char const *, int, char const *&, int &)
	, void match_byte3(unsigned char const *, int, char const *&, int &)
	, void match_byte2(unsigned char const *, int, char const *&, int &)
	, void match_ascii(unsigned char const *, int, char const *&, int &)
)
{
	const char* out_phrase;
	int step_size = 0;

	std::stringstream conv_stream;

	for ( int i = 0; i < tLength; i++ )
	{
		if ( is_utf8_byte6( byte_arr, i ) )
		{
			match_byte6( byte_arr, i, out_phrase, step_size );
			if ( 0 < step_size )
			{
				conv_stream << out_phrase;
			}
			else
			{
				// if word does not match, pad this word
				step_size = 5;
				conv_stream << byte_arr[ i ] << byte_arr[ i + 1 ] << byte_arr[ i + 2 ] << byte_arr[ i + 3 ] << byte_arr[ i + 4 ] << byte_arr[ i + 5 ];
			}
		}
		else if ( is_utf8_byte5( byte_arr, i ) )
		{
			match_byte5( byte_arr, i, out_phrase, step_size );
			if ( 0 < step_size )
			{
				conv_stream << out_phrase;
			}
			else
			{
				// if word does not match, pad this word
				step_size = 4;
				conv_stream << byte_arr[ i ] << byte_arr[ i + 1 ] << byte_arr[ i + 2 ] << byte_arr[ i + 3 ] << byte_arr[ i + 4 ];
			}
		}
		else if ( is_utf8_byte4( byte_arr, i ) )
		{
			match_byte4( byte_arr, i, out_phrase, step_size );
			if ( 0 < step_size )
			{
				conv_stream << out_phrase;
			}
			else
			{
				// if word does not match, pad this word
				step_size = 3;
				conv_stream << byte_arr[ i ] << byte_arr[ i + 1 ] << byte_arr[ i + 2 ] << byte_arr[ i + 3 ];
			}
		}
		else if ( is_utf8_byte3( byte_arr, i ) )
		{
			match_byte3( byte_arr, i, out_phrase, step_size );
			if ( 0 < step_size )
			{
				conv_stream << out_phrase;
			}
			else
			{
				// if word does not match, pad this word
				step_size = 2;
				conv_stream << byte_arr[ i ] << byte_arr[ i + 1 ] << byte_arr[ i + 2 ];
			}
		}
		else if ( is_utf8_byte2( byte_arr, i ) )
		{
			match_byte2( byte_arr, i, out_phrase, step_size );
			if ( 0 < step_size )
			{
				conv_stream << out_phrase;
			}
			else
			{
				// if word does not match, pad this word
				step_size = 1;
				conv_stream << byte_arr[ i ] << byte_arr[ i + 1 ];
			}
		}
		else if ( is_ascii( byte_arr, i ) )
		{
			match_ascii( byte_arr, i, out_phrase, step_size );
			if ( 0 < step_size )
			{
				conv_stream << out_phrase;
			}
			else
			{
				// if word does not match, pad this word
				conv_stream << byte_arr[ i ];
			}

			if ( step_size == 1 )
			{
				// i++ is handled in next loop
				// Set the step_size to 0
				step_size = 0;
			}
		}
		else
		{
			// Not a valid character, pad it
			step_size = 0;
			conv_stream << byte_arr[ i ];
		}
		i += step_size;
	}

	return conv_stream.str();
}
