#pragma once
void match_pt_byte6(unsigned char const* str, int start, char const* &out, int &step_size);
void match_pt_byte5(unsigned char const* str, int start, char const* &out, int &step_size);
void match_pt_byte4(unsigned char const* str, int start, char const* &out, int &step_size);
void match_pt_byte3(unsigned char const* str, int start, char const* &out, int &step_size);
void match_pt_byte2(unsigned char const* str, int start, char const* &out, int &step_size);
void match_pt_ascii(unsigned char const* str, int start, char const* &out, int &step_size);

void match_wt_byte6(unsigned char const* str, int start, char const* &out, int &step_size);
void match_wt_byte5(unsigned char const* str, int start, char const* &out, int &step_size);
void match_wt_byte4(unsigned char const* str, int start, char const* &out, int &step_size);
void match_wt_byte3(unsigned char const* str, int start, char const* &out, int &step_size);
void match_wt_byte2(unsigned char const* str, int start, char const* &out, int &step_size);
void match_wt_ascii(unsigned char const* str, int start, char const* &out, int &step_size);
