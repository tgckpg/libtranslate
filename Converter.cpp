#include "pch.h"

void match_w_byte6(unsigned char const* str, int start, char const* &out, int &step_size)
{
  step_size = 0;

}
void match_w_byte5(unsigned char const* str, int start, char const* &out, int &step_size)
{
  step_size = 0;

}
void match_w_byte4(unsigned char const* str, int start, char const* &out, int &step_size)
{
  step_size = 0;

}
void match_w_byte3(unsigned char const* str, int start, char const* &out, int &step_size)
{
  step_size = 0;
  if( str[start + 0] == 239 )
  {
    if( str[start + 1] == 189 )
    {
      if( str[start + 2] == 157 )
      {
        out = "︸";
        step_size = 2;
      }
      else if ( str[start + 2] == 155 )
      {
        out = "︷";
        step_size = 2;
      }
    }
    else if ( str[start + 1] == 188 )
    {
      if( str[start + 2] == 141 )
      {
        out = "︱";
        step_size = 2;
      }
      else if ( str[start + 2] == 137 )
      {
        out = "︶";
        step_size = 2;
      }
      else if ( str[start + 2] == 136 )
      {
        out = "︵";
        step_size = 2;
      }
    }
    else if ( str[start + 1] == 185 )
    {
      if( str[start + 2] == 154 )
      {
        out = "︶";
        step_size = 2;
      }
      else if ( str[start + 2] == 153 )
      {
        out = "︵";
        step_size = 2;
      }
    }
  }
  else if ( str[start + 0] == 227 && str[start + 1] == 128 )
  {
    if( str[start + 2] == 149 )
    {
      out = "︺";
      step_size = 2;
    }
    else if ( str[start + 2] == 148 )
    {
      out = "︹";
      step_size = 2;
    }
    else if ( str[start + 2] == 145 )
    {
      out = "︼";
      step_size = 2;
    }
    else if ( str[start + 2] == 144 )
    {
      out = "︻";
      step_size = 2;
    }
    else if ( str[start + 2] == 143 )
    {
      out = "﹄";
      step_size = 2;
    }
    else if ( str[start + 2] == 142 )
    {
      out = "﹃";
      step_size = 2;
    }
    else if ( str[start + 2] == 141 )
    {
      out = "﹂";
      step_size = 2;
    }
    else if ( str[start + 2] == 140 )
    {
      out = "﹁";
      step_size = 2;
    }
    else if ( str[start + 2] == 139 )
    {
      out = "︾";
      step_size = 2;
    }
    else if ( str[start + 2] == 138 )
    {
      out = "︽";
      step_size = 2;
    }
    else if ( str[start + 2] == 137 )
    {
      out = "﹀";
      step_size = 2;
    }
    else if ( str[start + 2] == 136 )
    {
      out = "︿";
      step_size = 2;
    }
  }
  else if ( str[start + 0] == 226 && str[start + 1] == 128 )
  {
    if( str[start + 2] == 166 )
    {
      out = "⋮";
      step_size = 2;
    }
    else if ( str[start + 2] == 148 )
    {
      out = "︱";
      step_size = 2;
    }
    else if ( str[start + 2] == 147 )
    {
      out = "︱";
      step_size = 2;
    }
  }

}
void match_w_byte2(unsigned char const* str, int start, char const* &out, int &step_size)
{
  step_size = 0;

}
void match_w_ascii(unsigned char const* str, int start, char const* &out, bool &step_size)
{
  step_size = false;
  if( str[start + 0] == 126 )
  {
    out = "≀";
    step_size = true;
  }
  else if ( str[start + 0] == 125 )
  {
    out = "︸";
    step_size = true;
  }
  else if ( str[start + 0] == 123 )
  {
    out = "︷";
    step_size = true;
  }
  else if ( str[start + 0] == 122 )
  {
    out = "ｚ";
    step_size = true;
  }
  else if ( str[start + 0] == 121 )
  {
    out = "ｙ";
    step_size = true;
  }
  else if ( str[start + 0] == 120 )
  {
    out = "ｘ";
    step_size = true;
  }
  else if ( str[start + 0] == 119 )
  {
    out = "ｗ";
    step_size = true;
  }
  else if ( str[start + 0] == 118 )
  {
    out = "ｖ";
    step_size = true;
  }
  else if ( str[start + 0] == 117 )
  {
    out = "ｕ";
    step_size = true;
  }
  else if ( str[start + 0] == 116 )
  {
    out = "ｔ";
    step_size = true;
  }
  else if ( str[start + 0] == 115 )
  {
    out = "ｓ";
    step_size = true;
  }
  else if ( str[start + 0] == 114 )
  {
    out = "ｒ";
    step_size = true;
  }
  else if ( str[start + 0] == 113 )
  {
    out = "ｑ";
    step_size = true;
  }
  else if ( str[start + 0] == 112 )
  {
    out = "ｐ";
    step_size = true;
  }
  else if ( str[start + 0] == 111 )
  {
    out = "ｏ";
    step_size = true;
  }
  else if ( str[start + 0] == 110 )
  {
    out = "ｎ";
    step_size = true;
  }
  else if ( str[start + 0] == 109 )
  {
    out = "ｍ";
    step_size = true;
  }
  else if ( str[start + 0] == 108 )
  {
    out = "ｌ";
    step_size = true;
  }
  else if ( str[start + 0] == 107 )
  {
    out = "ｋ";
    step_size = true;
  }
  else if ( str[start + 0] == 106 )
  {
    out = "ｊ";
    step_size = true;
  }
  else if ( str[start + 0] == 105 )
  {
    out = "ｉ";
    step_size = true;
  }
  else if ( str[start + 0] == 104 )
  {
    out = "ｈ";
    step_size = true;
  }
  else if ( str[start + 0] == 103 )
  {
    out = "ｇ";
    step_size = true;
  }
  else if ( str[start + 0] == 102 )
  {
    out = "ｆ";
    step_size = true;
  }
  else if ( str[start + 0] == 101 )
  {
    out = "ｅ";
    step_size = true;
  }
  else if ( str[start + 0] == 100 )
  {
    out = "ｄ";
    step_size = true;
  }
  else if ( str[start + 0] == 99 )
  {
    out = "ｃ";
    step_size = true;
  }
  else if ( str[start + 0] == 98 )
  {
    out = "ｂ";
    step_size = true;
  }
  else if ( str[start + 0] == 97 )
  {
    out = "ａ";
    step_size = true;
  }
  else if ( str[start + 0] == 94 )
  {
    out = "＾";
    step_size = true;
  }
  else if ( str[start + 0] == 93 )
  {
    out = "︺";
    step_size = true;
  }
  else if ( str[start + 0] == 92 )
  {
    out = "＼";
    step_size = true;
  }
  else if ( str[start + 0] == 91 )
  {
    out = "︹";
    step_size = true;
  }
  else if ( str[start + 0] == 90 )
  {
    out = "Ｚ";
    step_size = true;
  }
  else if ( str[start + 0] == 89 )
  {
    out = "Ｙ";
    step_size = true;
  }
  else if ( str[start + 0] == 88 )
  {
    out = "Ｘ";
    step_size = true;
  }
  else if ( str[start + 0] == 87 )
  {
    out = "Ｗ";
    step_size = true;
  }
  else if ( str[start + 0] == 86 )
  {
    out = "Ｖ";
    step_size = true;
  }
  else if ( str[start + 0] == 85 )
  {
    out = "Ｕ";
    step_size = true;
  }
  else if ( str[start + 0] == 84 )
  {
    out = "Ｔ";
    step_size = true;
  }
  else if ( str[start + 0] == 83 )
  {
    out = "Ｓ";
    step_size = true;
  }
  else if ( str[start + 0] == 82 )
  {
    out = "Ｒ";
    step_size = true;
  }
  else if ( str[start + 0] == 81 )
  {
    out = "Ｑ";
    step_size = true;
  }
  else if ( str[start + 0] == 80 )
  {
    out = "Ｐ";
    step_size = true;
  }
  else if ( str[start + 0] == 79 )
  {
    out = "Ｏ";
    step_size = true;
  }
  else if ( str[start + 0] == 78 )
  {
    out = "Ｎ";
    step_size = true;
  }
  else if ( str[start + 0] == 77 )
  {
    out = "Ｍ";
    step_size = true;
  }
  else if ( str[start + 0] == 76 )
  {
    out = "Ｌ";
    step_size = true;
  }
  else if ( str[start + 0] == 75 )
  {
    out = "Ｋ";
    step_size = true;
  }
  else if ( str[start + 0] == 74 )
  {
    out = "Ｊ";
    step_size = true;
  }
  else if ( str[start + 0] == 73 )
  {
    out = "Ｉ";
    step_size = true;
  }
  else if ( str[start + 0] == 72 )
  {
    out = "Ｈ";
    step_size = true;
  }
  else if ( str[start + 0] == 71 )
  {
    out = "Ｇ";
    step_size = true;
  }
  else if ( str[start + 0] == 70 )
  {
    out = "Ｆ";
    step_size = true;
  }
  else if ( str[start + 0] == 69 )
  {
    out = "Ｅ";
    step_size = true;
  }
  else if ( str[start + 0] == 68 )
  {
    out = "Ｄ";
    step_size = true;
  }
  else if ( str[start + 0] == 67 )
  {
    out = "Ｃ";
    step_size = true;
  }
  else if ( str[start + 0] == 66 )
  {
    out = "Ｂ";
    step_size = true;
  }
  else if ( str[start + 0] == 65 )
  {
    out = "Ａ";
    step_size = true;
  }
  else if ( str[start + 0] == 61 )
  {
    out = "‖";
    step_size = true;
  }
  else if ( str[start + 0] == 45 )
  {
    out = "︱";
    step_size = true;
  }
  else if ( str[start + 0] == 41 )
  {
    out = "︶";
    step_size = true;
  }
  else if ( str[start + 0] == 40 )
  {
    out = "︵";
    step_size = true;
  }

}