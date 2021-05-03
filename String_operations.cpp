#include "String_operations.h"
#define DASH 150

string ConvertWideToANSI(const std::wstring& wstr)
{
	int count = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.length(), NULL, 0, NULL, NULL);
	string str(count, 0);
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, &str[0], count, NULL, NULL);
	return str;
}

wstring ConvertAnsiToWide(const std::string& str)
{
	int count = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), NULL, 0);
	std::wstring wstr(count, 0);
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), &wstr[0], count);
	return wstr;
}

void check_string(string_convert& text, int text_size, string_convert& res_text, int& res_text_size) {
	for (int i = 0; i < text_size; i++) {
		//cout << text[i] << endl;
		int wchars_num = MultiByteToWideChar(CP_UTF8, 0, text[i].c_str(), -1, NULL, 0);
		wchar_t* wstr = new wchar_t[wchars_num];
		MultiByteToWideChar(CP_UTF8, 0, text[i].c_str(), -1, wstr, wchars_num);
		delete[] wstr;
		char sym = *text[i].begin();
		
		if (sym == DASH) {
			res_text_size++;
			res_text.set_size(res_text_size);
			res_text[res_text_size-1] = text[i];
		}
	}
	
}
void output_text(string_convert& res_text, int res_text_size) {
	cout << "Измененный текст:" << endl;
	for (int i = 0; i < res_text_size; i++) {
		cout << res_text[i] << endl;
	}
}