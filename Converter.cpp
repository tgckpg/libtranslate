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
      if( str[start + 2] == 137 )
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
      out = "｜";
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
void match_w_ascii(unsigned char const* str, int start, char const* &out, int &step_size)
{
  step_size = 0;
  if( str[start + 0] == 125 )
  {
    out = "︸";
    step_size = 0;
  }
  else if ( str[start + 0] == 123 )
  {
    out = "︷";
    step_size = 0;
  }
  else if ( str[start + 0] == 93 )
  {
    out = "︺";
    step_size = 0;
  }
  else if ( str[start + 0] == 91 )
  {
    out = "︹";
    step_size = 0;
  }
  else if ( str[start + 0] == 61 )
  {
    out = "‖";
    step_size = 0;
  }
  else if ( str[start + 0] == 45 )
  {
    out = "︱";
    step_size = 0;
  }
  else if ( str[start + 0] == 41 )
  {
    out = "︶";
    step_size = 0;
  }
  else if ( str[start + 0] == 40 )
  {
    out = "︵";
    step_size = 0;
  }

}