#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include <Windows.h>
#include "Main.h"
#include "Interface.h"
#include <direct.h>

using namespace std;

class string_convert {
private:
	string* text;
	int text_size;

public:
	string& operator[] (const int index) {
		return text[index];
	}
	int get_size() {
		return text_size;
	}
	void set_size(int size) {
		text_size = size;
		text = new string[text_size];
	}

	~string_convert() {
		delete[] text;
	}
};
void check_string(string_convert& text, int text_size, string_convert& res_text, int& res_text_size);
void output_text(string_convert& text, int text_size);