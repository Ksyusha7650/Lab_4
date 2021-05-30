#include "Main.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	greetings();
	bool end = false;
	string_convert text, res_text;
	string name = "";
	do {
		int text_size = 0, mode = 0, res_size_text = 0;
		if (test_or_try()) run_tests();
		else {
			input_types(text, res_text, text_size, name, mode);
			check_string(text, text_size, res_text, res_size_text);
			results(res_text, res_size_text);
			output_text(res_text, res_size_text, name, mode);
		}
		end = end_program();
	} while (end != true);
}

