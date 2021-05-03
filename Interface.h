#pragma once
#include "Main.h"
#include "String_operations.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <filesystem>
#include <Windows.h>


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
	END, CONTINUE,
	MANUAL = 1, GENERATE, FILE_INPUT,
	YES = 1, NO,
	DATA, RESULT, READ_SIZE, READ_POINTS,
	TEST = 1, TRY
};

int get_int();
double get_double();
void greetings();
//void input_types(Points_class& arr_point, res_points_class& res_arr_point, int size, int& mode, int& radius, Point& center);
bool show_or_try();
bool end_program();
void output_file(string_convert& text, int& text_size);
//void size_arr(int& size, Points_class& point_arr, res_points_class& res_point_arr);
//void create_file(int mode, Points_class&  arr_point, res_points_class& res_arr_point, int& size, int& radius, Point& center);
//void saving_results(Points_class& point_arr, res_points_class& res_point_arr);
//void save_data(Points_class& point_arr, int radius, Point center, res_points_class& res_t);#pragma once
