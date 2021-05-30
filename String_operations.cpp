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

void output_text(string_convert& res_text, int res_text_size, string& name, int mode) {
	cout << "��������� ���������� �����?" << endl
		<< "�������� ����� ����:" << endl;
	cout << "[1] - ���������" << endl << "[2] - ����������" << endl;
	bool save_text = false;
	while (true) {
		int save = get_int();
		if (save == YES) {
			save_text = true;
			break;
		}
		else if (save == NO) {
			cout << "�� ������� ���������� ����������." << endl;
			cout << "- - - - - - - - - -" << endl;
			break;
		}
		else cout << "������� ���� 1, ���� 2." << endl;
	}
	if (save_text){
	cout << "���� ��������� ���������� �����?" << endl;
	if (mode == FILE_INPUT) {
		cout << "�������� ����� ����:" << endl;
		cout << "[1] - � ��� �� ����" << endl << "[2] - � ������ ����" << endl;
		int choice = get_int();
		while (true) {
			if (choice == SAME) break;
			if (choice == ANOTHER) {
				result_file_name(name);
				break;
			}
			else cout << "������� ���� 1, ���� 2" << endl;
		}
	}
	else result_file_name(name);
	ofstream result_file(name);
	result_file.clear();
	const int FIRST_EMPTY_ELEMENT = 0;
	const int SECOND_EMPTY_ELEMENT = 2;
	for (int index = 0; index < res_text_size; index++) {
		string line = res_text[index];
		if (line[0] == '-') {
			line.erase(0, SECOND_EMPTY_ELEMENT);
			line.insert(0, "� ");
		}
		result_file << line << endl;
	}
	cout << "������ ���������." << endl;
	cout << "- - - - - - - - - -" << endl;
}
}