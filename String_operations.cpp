#include "String_operations.h"


void check_string(string_convert& text, int text_size, string_convert& res_text, int& res_text_size) {
	const char DASH = 45;
	for (int index = 0; index < text_size; index++) {
		char sym = *text[index].begin();
		if (sym == DASH)
			res_text_size++;
	}
	res_text.set_size(res_text_size);
	int index_current = 0;
	for (int index = 0; index < text_size; index++) {
		char sym = *text[index].begin();
		if (sym == DASH) {
			res_text[index_current] = text[index];
			index_current++;

		}
	}
}

void output_text(string_convert& res_text, int res_text_size) {
	cout << "Сохранить измененный текст?" << endl
		<< "Выберите пункт меню:" << endl;
	cout << "[1] - сохранить" << endl << "[2] - пропустить" << endl;
	bool save_text = false;
	while (true) {
		int save = get_int();
		if (save == YES) {
			save_text = true;
			break;
		}
		else if (save == NO) {
			cout << "Вы выбрали пропустить сохранение." << endl;
			cout << "- - - - - - - - - -" << endl;
			break;
		}
		else cout << "Введите либо 1, либо 2." << endl;
	}
	if (save_text) {
		cout << "Куда сохранить измененный текст?" << endl;
		string name_path;
		char* name;
		size_t size_of_name;
		bool repeat = true;
		do {
			size_of_name = 0;
			repeat = false;
			cin >> name_path;
			size_of_name = name_path.size() + 1;
			name = new char[size_of_name];
			for (int index = 0; index < size_of_name; index++) {
				name[index] = static_cast <unsigned char> (name_path[index]);
			}
			name[size_of_name] = '\0';
			struct stat buff;
			if (!(stat(name, &buff))) {
				cout << "Такая папка уже существует, введите другое имя." << endl;
				repeat = true;
			}
		} while (repeat);
		_mkdir(name);
		for (int index = 0; index < res_text_size; index++) {
			string number = to_string(index+1);
			const int END = 9;
			size_t size_number = number.size();
			size_t size_of_name_file = size_of_name + END + size_number;
			char* name_file = new char[size_of_name_file];
			for (int index_sym = 0; index_sym < size_of_name - 1; index_sym++) {
				name_file[index_sym] = name[index_sym];
			}
			size_t index_name = size_of_name - 1;
			name_file[index_name] = '/';
			index_name++;
			name_file[index_name] = '/';
			index_name++;
			for (int index_sym = 0; index_sym < size_number; index_sym++) {
				name_file[index_sym + index_name] = static_cast <unsigned char> (number[index_sym]);
			}
			index_name++;
			name_file[index_name] = '.';
			index_name++;
			name_file[index_name] = 't';
			index_name++;
			name_file[index_name] = 'x';
			index_name++;
			name_file[index_name] = 't';
			index_name++;
			name_file[index_name] = '\0';
			cout << name_file << endl;
			ofstream result_file(name_file);
			result_file.clear();
			const int FIRST_EMPTY_ELEMENT = 0;
			const int SECOND_EMPTY_ELEMENT = 2;
				string line = res_text[index];
				if (line[0] == '-') {
					line.erase(0, SECOND_EMPTY_ELEMENT);
					line.insert(0, "– ");
				}
				result_file << line << endl;
				delete [] name_file;
		}
		cout << "Данные сохранены." << endl;
		cout << "- - - - - - - - - -" << endl;
	}
}