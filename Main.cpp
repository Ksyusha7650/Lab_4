#include "Main.h"

using namespace std;
HANDLE handle;

int main()
{
	setlocale(LC_ALL, "Russian");
	greetings();
	bool end = false;
	string_convert text, res_text;
	int text_size = 0, mode = 0, res_size_text = 0;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned)time(NULL));
	do {
		output_file(text, text_size);
		check_string(text, text_size, res_text, res_size_text);
	    output_text(res_text, res_size_text);
		/*
		if (show_or_try()) run_tests();
		else {
			size_arr(size, point_arr, res_point_arr);
			input_types(point_arr, res_point_arr, size, mode, radius, center);
			output_arr(point_arr, radius, center);
			if (mode != Actions::FILE_INPUT)
				save_data(point_arr, radius, center, res_point_arr);
			check_inclusion(point_arr, radius, center, res_point_arr);
			res_output_arr(point_arr, res_point_arr, handle);
			saving_results(point_arr, res_point_arr);
			}*/

		end = end_program();
	} while (end != true);
}

