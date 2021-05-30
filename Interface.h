#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "Main.h"
#include "String_operations.h"

using namespace std;
using namespace filesystem;

class string_convert;

enum Actions {
	END = 1, CONTINUE,
	MANUAL = 1, FILE_INPUT,
	YES = 1, NO,
	TEST = 1, TRY,
	REWRITE=0, REPEAT,
	SAME = 1, ANOTHER = 2
};

int get_int();
double get_double();
void greetings();
bool end_program();
void result_file_name(string& name);
bool test_or_try(void);
void input_types(string_convert& text, string_convert& res_text, int& text_size, string& name, int& mode);
void results(string_convert& res_text, int& res_size_text);
