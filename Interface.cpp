#include "Interface.h"


double get_double() {
	double input = 0;
	cin >> input;
	while (cin.fail()) {
		while ((getchar() != '\n'));
		cin.clear();
		cout << "������� �����." << endl;
		cin >> input;
	}
	while (getchar() != '\n');
	return input;
}

int get_int() {
	int input = 0;
	cin >> input;
	while (cin.fail()) {
		while (getchar() != '\n');
		cin.clear();
		cout << "������� �����." << endl;
		cin >> input;
	}
	while (getchar() != '\n');
	return input;
}

void output_file(string_convert& text, int& text_size, string& name) {
	text_size = 0;
	cout << "������� ���� ����� � �������." << endl
		<< "�������: C:\\\\�����1(���� ����������)\\\\�����2(���� ����������)\\\\...\\\\�������� �����.txt " << endl
		<< "���� ������� ������ �������� �����, ���� �� � ����� ����� �������."
		<< endl;
	while (true) {
		cin >> name;
		ofstream output_file_text(name, ofstream::app);
		error_code ec;
		if (!is_regular_file(name, ec)) {
			cout << "����� �������� ������������ ��������. ��������� ����." << endl;
			ec.clear();
		}
		else break;
		output_file_text.close();
	}
	ifstream output_file_text(name);
	string temporary_line;
	int quality_lines = 0;
	while (getline(output_file_text, temporary_line))
	{
		if (!(temporary_line == ""))
			text_size++;
		quality_lines++;
	}

	text.set_size(text_size);
	ifstream read_text(name);
	const int move_code_to_ASCII = 75;
	const int empty_symbol_first = 1;
	const int empty_symbol_second = 2;
	int current_index = 0;
	for (int index = 0; index < quality_lines; index++) {
		getline(read_text, temporary_line);
		if (temporary_line != "") {                                         // ������, �� ��� ������ ������ ������ ������� ��� � � ����� �������: 
			temporary_line[0] += move_code_to_ASCII;                        // for (int i = 0; i < temporary_line.length(); i++) {
			temporary_line.erase(empty_symbol_first, empty_symbol_second);  //	   temporary_line[i] += �����-�� �����; 
			text[current_index] = temporary_line;                           //                                        }
			current_index++;                                                //                                                          ����� <3
		}
	}
	output_file_text.close();
	read_text.close();
}

void user_input(string_convert& text, int& text_size, string& name) {
	cout << "������� �����." << endl
		<< "��� ���������� ����� ������� ������ �� ����� ����� (.)" << endl;
	string_convert text_temporary;
	string line;
	text_size = 1;
	int new_text_size = 1;
	getline(cin, line);
	text.set_size(text_size);
	text[text_size - 1] = line;
	while (true) {
		getline(cin, line);
		if (line[0] != '.') {
			if (line != "") {
				new_text_size = text_size;
				new_text_size++;
				text_temporary.set_size(new_text_size);
				for (int index = 0; index < text_size; index++)
				{
					text_temporary[index] = text[index];
				}
				text_temporary[new_text_size - 1] = line;
				text_size = new_text_size;
				text.set_size(text_size);
				for (int index = 0; index < text_size; index++)
				{
					text[index] = text_temporary[index];
				}

			}
		}
		else break;
	}
	cout << "��o� ��������" << endl;
}

void results(string_convert& res_text, int& res_size_text) {
	cout << "��������� ���������: " << endl;
	for (int index = 0; index < res_size_text; index++) {
		cout << res_text[index] << endl;
	}
	cout << "- - - - - - - - - -" << endl;
}

void input_types(string_convert& text, string_convert& res_text, int& text_size, string& name, int& mode) {
	cout << "�������� ������ ����� ������." << endl
		<< "�������� ����� ����: " << endl << "[1] - ��� ����� �������" << endl
		<< "[2] - ��� ����� ������ �� �����" << endl;
	while (true) {
		mode = get_int();
		if (mode == MANUAL) {
			user_input(text, text_size, name);
			cout << "- - - - - - - - - - - -" << endl;
			break;
		}
		if (mode == FILE_INPUT) {
			output_file(text, text_size, name);
			cout << "- - - - - - - - - - - -" << endl;
			break;
		}
		else cout << "������� ���� 1, ���� 2." << endl;
	}
}



bool test_or_try(void) {
	cout << "�������� ����� ����:" << endl;
	cout << "[1] - �������� �����" << endl;
	cout << "[2] - ��������� ���������" << endl;
	int mode = 0;
	while (!((mode == TEST) || (mode == TRY))) {
		mode = get_int();
		switch (mode) {
		case TEST: return true;
			break;
		case TRY: return false;
			break;
		default: cout << "������� ���� 1, ���� 2." << endl;
		}
	}
	return true;
}

void result_file_name(string& name) {
path:cout << "������� ���� �����, � ������� ��������� ������." << endl << "�������: C:\\\\�����1(���� ����������)\\\\"
	"�����2(���� ����������)\\\\...\\\\�������� �����.txt " << endl << "���� ������� ������ �������� �����, ����� �� ����� � ����� ����� �������" << endl;
	 cin >> name;
	 if (ifstream(name)) {
		 cout << "���� ��� ����������." << endl;
		 cout << "�������� ����� ����:" << endl;
		 cout << "[0] - ������������ ������������ ����" << endl << "[1] - ��������� ����" << endl;
		 while (true) {
			 int rewrite = get_int();
			 if (rewrite == 0) {
				 cout << "�� ������� ����� ������������ ����." << endl;
				 break;
			 }
			 if (rewrite == 1) {
				 cout << "�� ������� ����� ��������� ����." << endl;
				 goto path;
				 break;
			 }
			 else
				 cout << "������� 1, ���� 2";
		 }
	 }
	 ofstream result_file(name, ofstream::app);
	 error_code ec;
	 if (!is_regular_file(name, ec)) {
		 cout << "����� �������� ������������ ��������. ��������� ����." << endl;
		 ec.clear();
		 goto path;
	 }
	 result_file.close();
}


void greetings() {
	cout << "��������� ��������� ������� ������ ����������." << endl << "������: 404." << endl << "�������: 22." << endl <<
		"������ ����� 4:" << endl <<
		"�������� � �������� ������ ��� ������� (������������ � ����� ������ � ������� �����). ��������� ������� � ��������� ��������� ������." << endl
		<< "������������ ������� ���������� ��������, ������������� � ������������� �������." << endl;
}


bool end_program() {
	cout << "��������� ���������? " << endl;
	cout << "�������� ����� ����:" << endl
		<< "[1] - ��������� ���������" << endl << "[2] - ��������� ���������" << endl;
	while (true) {
		int end = get_int();
		switch (end) {
		case END:
			cout << "��������� �����������..." << endl;
			return true;
			break;
		case CONTINUE:
			cout << "�� ������� ��������� ���������: " << endl;
			return false;
			break;
		default:
			cout << "������� ���� 0, ���� 1." << endl;
		}
	}
}

