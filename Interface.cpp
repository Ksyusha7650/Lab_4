#include "Interface.h"


double get_double() {
	double input = 0;
	cin >> input;
	while (cin.fail()) {
		while ((getchar() != '\n'));
		cin.clear();
		cout << "Введите число." << endl;
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
		cout << "Введите число." << endl;
		cin >> input;
	}
	while (getchar() != '\n');
	return input;
}

void output_file(string_convert& text, int& text_size, string& name) {
	text_size = 0;
	cout << "Введите путь файла с текстом." << endl
		<< "Образец: C:\\\\Папка1(если необходимо)\\\\Папка2(если необходимо)\\\\...\\\\Название файла.txt " << endl
		<< "Либо введите просто название файла, если он в папке этого проекта."
		<< endl;
	while (true) {
		cin >> name;
		ofstream output_file_text(name, ofstream::app);
		error_code ec;
		if (!is_regular_file(name, ec)) {
			cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
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
		if (temporary_line != "") {                                         // Мишань, ты тут можешь начать менять символы как и я таким образом: 
			temporary_line[0] += move_code_to_ASCII;                        // for (int i = 0; i < temporary_line.length(); i++) {
			temporary_line.erase(empty_symbol_first, empty_symbol_second);  //	   temporary_line[i] += какое-то число; 
			text[current_index] = temporary_line;                           //                                        }
			current_index++;                                                //                                                          Мишик <3
		}
	}
	output_file_text.close();
	read_text.close();
}

void user_input(string_convert& text, int& text_size, string& name) {
	cout << "Введите текст." << endl
		<< "Для завершения ввода начните строку со знака точка (.)" << endl;
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
	cout << "Ввoд завершен" << endl;
}

void results(string_convert& res_text, int& res_size_text) {
	cout << "Результат программы: " << endl;
	for (int index = 0; index < res_size_text; index++) {
		cout << res_text[index] << endl;
	}
	cout << "- - - - - - - - - -" << endl;
}

void input_types(string_convert& text, string_convert& res_text, int& text_size, string& name, int& mode) {
	cout << "Выберите способ ввода текста." << endl
		<< "Выберите пункт меню: " << endl << "[1] - для ввода вручную" << endl
		<< "[2] - для ввода текста из файла" << endl;
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
		else cout << "Введите либо 1, либо 2." << endl;
	}
}



bool test_or_try(void) {
	cout << "Выберите пункт меню:" << endl;
	cout << "[1] - показать тесты" << endl;
	cout << "[2] - запустить программу" << endl;
	int mode = 0;
	while (!((mode == TEST) || (mode == TRY))) {
		mode = get_int();
		switch (mode) {
		case TEST: return true;
			break;
		case TRY: return false;
			break;
		default: cout << "Введите либо 1, либо 2." << endl;
		}
	}
	return true;
}

void result_file_name(string& name) {
path:cout << "Введите путь файла, в который запишутся данные." << endl << "Образец: C:\\\\Папка1(если необходимо)\\\\"
	"Папка2(если необходимо)\\\\...\\\\Название файла.txt " << endl << "Либо введите просто название файла, тогда он будет в папке этого проекта" << endl;
	 cin >> name;
	 if (ifstream(name)) {
		 cout << "Файл уже существует." << endl;
		 cout << "Выберите пункт меню:" << endl;
		 cout << "[0] - перезаписать существующий файл" << endl << "[1] - повторить ввод" << endl;
		 while (true) {
			 int rewrite = get_int();
			 if (rewrite == 0) {
				 cout << "Вы выбрали опцию перезаписать файл." << endl;
				 break;
			 }
			 if (rewrite == 1) {
				 cout << "Вы выбрали опцию повторить ввод." << endl;
				 goto path;
				 break;
			 }
			 else
				 cout << "Введите 1, либо 2";
		 }
	 }
	 ofstream result_file(name, ofstream::app);
	 error_code ec;
	 if (!is_regular_file(name, ec)) {
		 cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
		 ec.clear();
		 goto path;
	 }
	 result_file.close();
}


void greetings() {
	cout << "Программу выполнила Рухлова Ксения Алексеевна." << endl << "Группа: 404." << endl << "Вариант: 22." << endl <<
		"Задача номер 4:" << endl <<
		"Выделить в заданном тексте все диалоги (начинающиеся с новой строки и символа «тире»). Сохранить диалоги в отдельных текстовых файлах." << endl
		<< "Использовать правила построения диалогов, применяющиеся в русскоязычных текстах." << endl;
}


bool end_program() {
	cout << "Повторить программу? " << endl;
	cout << "Выберите пункт меню:" << endl
		<< "[1] - завершить программу" << endl << "[2] - повторить программу" << endl;
	while (true) {
		int end = get_int();
		switch (end) {
		case END:
			cout << "Программа завершается..." << endl;
			return true;
			break;
		case CONTINUE:
			cout << "Вы выбрали повторить программу: " << endl;
			return false;
			break;
		default:
			cout << "Введите либо 0, либо 1." << endl;
		}
	}
}

