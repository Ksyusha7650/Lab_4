#include "String_operations.h"
#define DASH 45

void check_string(string_convert& text, int text_size, string_convert& res_text, int& res_text_size) {
	const char dash = DASH;
	for (int index = 0; index < text_size; index++) {
		char sym = *text[index].begin();
		if (sym == dash)
			res_text_size++;
	}
	res_text.set_size(res_text_size);
	int index_current = 0;
	for (int index = 0; index < text_size; index++) {
		char sym = *text[index].begin();
		if (sym == dash) {
			res_text[index_current] = text[index];
			index_current++;

		}
	}
}

void output_text(string_convert& res_text, int res_text_size, string& name, int mode) {
	cout << "Куда сохранить измененный текст?" << endl;
	if (mode == FILE_INPUT) {
		cout << "Выберите пункт меню:" << endl;
		cout << "[1] - в тот же файл" << endl << "[2] - в другой файл" << endl;
		int choice = get_int();
		while (true) {
			if (choice == 1) break;
			if (choice == 2) {
				result_file_name(name);
				break;
			}

		}
	}
	else result_file_name(name);
	ofstream result_file(name);
	result_file.clear();
	for (int index = 0; index < res_text_size; index++) {
		result_file << res_text[index] << endl;
	}
}