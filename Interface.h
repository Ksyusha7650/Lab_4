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

class output_file_points {
private:
	int* file_arr_point;
	int file_arr_size;

public:
	int& operator[] (const int index) {
		return file_arr_point[index];
	}
	int get_size() {
		return file_arr_size;
	}
	void set_size(int size) {
		file_arr_size = size;
		file_arr_point = new int[file_arr_size];
	}

	~output_file_points() {
		delete[] file_arr_point;
	}
};

enum Actions {
	END = 1, CONTINUE,
	MANUAL = 1, FILE_INPUT,
	YES = 1, NO,
	TEST = 1, TRY
};

int get_int();
double get_double();
void greetings();
bool end_program();
void result_file_name(string& name);
bool test_or_try(void);
void input_types(string_convert& text, string_convert& res_text, int& text_size, string& name, int& mode);
void results(string_convert& res_text, int& res_size_text);
