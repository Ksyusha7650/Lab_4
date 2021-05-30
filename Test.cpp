#include "Test.h"


bool Test1(void) {
	string_convert text, res_text, expected_res_text;
	int text_size = 0, res_size_text = 0, expected_res_size_text = 0;
	string name = "text_1.txt";
	expected_res_size_text = 2;
	expected_res_text.set_size(expected_res_size_text);
	expected_res_text[0] = "- Ah well eh?, said Gandalf. You look the same as ever, Frodo!";
	expected_res_text[1] = "- So do you, Frodo replied.";
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
	const int DASH_1 = -30;
	const int DASH_2 = -106;
	const int DASH = 45;
	const int FIRST_EMPTY_ELEMENT = 1;
	const int SECOND_EMPTY_ELEMENT = 2;
	int current_index = 0;
	for (int index = 0; index < quality_lines; index++) {
		getline(read_text, temporary_line);
		if (temporary_line != "") {
			if (temporary_line[0] != DASH)
				if (temporary_line[0] == DASH_1) {
					temporary_line[0] = DASH;
					temporary_line.erase(FIRST_EMPTY_ELEMENT, SECOND_EMPTY_ELEMENT);
				}
			if (temporary_line[0] == DASH_2)
				temporary_line[0] = DASH;
			text[current_index] = temporary_line;
			current_index++;
		}
	}
	output_file_text.close();
	read_text.close();
	check_string(text, text_size, res_text, res_size_text);
	int count_check = 0;
	if (res_size_text == expected_res_size_text) {
		for (int index = 0; index < res_size_text; index++) {
			if (expected_res_text[index] == res_text[index]) count_check++;
			else cout << index << endl;
		}
		if (count_check == res_size_text) return true;
		else {
			cout << "Тест 1 не пройден!" << endl;
			for (int index = 0; index < res_size_text; index++) {
				cout << "Ожидалась такая строчка: " << expected_res_text[index] << endl;
				cout << "Получилась  такая точка: " << res_text[index] << endl;
			}
			return false;
		}
	}
	else {
		cout << "Тест 1 не пройден!" << endl;
		cout << "Ожидаемое количество строчек: " << expected_res_size_text << endl;
		cout << "Полученное количество строчек: " << res_size_text << endl;
		return false;
	}
}

bool Test2(void) {
	string_convert text, res_text, expected_res_text;
	int text_size = 0, res_size_text = 0, expected_res_size_text = 0;
	string name = "text_2.txt";
	expected_res_size_text = 9;
	expected_res_text.set_size(expected_res_size_text);
	expected_res_text[0] = "- Damn you! This is my bed. And my room!";
	expected_res_text[1] = "- Your room? You sure?, Keycase said stupidly.";
	expected_res_text[2] = "- You lousy drunk! Of course I'm sure it's my room!";
	expected_res_text[3] = "- This 's 614?";
	expected_res_text[4] = "- You stupid jerk! it's 641.";
	expected_res_text[5] = "- Sorry ol' man. Guess 's my mistake. Frorn under his arm Keycase took the newspaper,"
		" carried to convey the impression of having come in from the street. Heresa mornin' paper.";
	expected_res_text[6] = "- Special livery.";
	expected_res_text[7] = "- I don't want your goddam newspaper. Take it and get out!";
	expected_res_text[8] = "- Said I'm sorry ol' man. No need to get upset. I'm goin'.";
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
	const int DASH_1 = -30;
	const int DASH_2 = -106;
	const int DASH = 45;
	const int FIRST_EMPTY_ELEMENT = 1;
	const int SECOND_EMPTY_ELEMENT = 2;
	int current_index = 0;
	for (int index = 0; index < quality_lines; index++) {
		getline(read_text, temporary_line);
		if (temporary_line != "") {
			if (temporary_line[0] != DASH)
				if (temporary_line[0] == DASH_1) {
					temporary_line[0] = DASH;
					temporary_line.erase(FIRST_EMPTY_ELEMENT, SECOND_EMPTY_ELEMENT);
				}
			if (temporary_line[0] == DASH_2)
				temporary_line[0] = DASH;
			text[current_index] = temporary_line;
			current_index++;
		}
	}
	output_file_text.close();
	read_text.close();
	check_string(text, text_size, res_text, res_size_text);
	int count_check = 0;
	if (res_size_text == expected_res_size_text) {
		for (int index = 0; index < res_size_text; index++) {
			if (expected_res_text[index] == res_text[index]) count_check++;
			else cout << index << endl;
		}
		if (count_check == res_size_text) return true;
		else {
			cout << "Тест 2 не пройден!" << endl;
			for (int index = 0; index < res_size_text; index++) {
				cout << "Ожидалась такая строчка: " << expected_res_text[index] << endl;
				cout << "Получилась  такая точка: " << res_text[index] << endl;
			}
			return false;
		}
	}
	else {
		cout << "Тест 2 не пройден!" << endl;
		cout << "Ожидаемое количество строчек: " << expected_res_size_text << endl;
		cout << "Полученное количество строчек: " << res_size_text << endl;
		return false;
	}
}

bool Test3(void) {
	string_convert text, res_text, expected_res_text;
	int text_size = 0, res_size_text = 0, expected_res_size_text = 0;
	string name = "text_3.txt";
	expected_res_size_text = 3;
	expected_res_text.set_size(expected_res_size_text);
	expected_res_text[0] = "- Tell us, Master, he said, about the Willow-man. What is he? I have never heard of him before.";
	expected_res_text[1] = "- No, don't!, said Merry and Pippin together, sitting suddenly upright. Not now! Not until the morning!";
	expected_res_text[2] = "- That is right!, said the old man. Now is the time for resting. Some things are ill to hear when the world's in shadow."
		" Sleep till the morning-light, rest on the pillow! Heed no nightly noise! Fear no grey willow!";
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
	const int DASH_1 = -30;
	const int DASH_2 = -106;
	const int DASH = 45;
	const int FIRST_EMPTY_ELEMENT = 1;
	const int SECOND_EMPTY_ELEMENT = 2;
	int current_index = 0;
	for (int index = 0; index < quality_lines; index++) {
		getline(read_text, temporary_line);
		if (temporary_line != "") {
			if (temporary_line[0] != DASH)
				if (temporary_line[0] == DASH_1) {
					temporary_line[0] = DASH;
					temporary_line.erase(FIRST_EMPTY_ELEMENT, SECOND_EMPTY_ELEMENT);
				}
			if (temporary_line[0] == DASH_2)
				temporary_line[0] = DASH;
			text[current_index] = temporary_line;
			current_index++;
		}
	}
	output_file_text.close();
	read_text.close();
	check_string(text, text_size, res_text, res_size_text);
	int count_check = 0;
	if (res_size_text == expected_res_size_text) {
		for (int index = 0; index < res_size_text; index++) {
			if (expected_res_text[index] == res_text[index]) count_check++;
			else cout << index << endl;
		}
		if (count_check == res_size_text) return true;
		else {
			cout << "Тест 3 не пройден!" << endl;
			for (int index = 0; index < res_size_text; index++) {
				cout << "Ожидалась такая строчка: " << expected_res_text[index] << endl;
				cout << "Получилась  такая точка: " << res_text[index] << endl;
			}
			return false;
		}
	}
	else {
		cout << "Тест 3 не пройден!" << endl;
		cout << "Ожидаемое количество строчек: " << expected_res_size_text << endl;
		cout << "Полученное количество строчек: " << res_size_text << endl;
		return false;
	}
}

bool Test4(void) {
	string_convert text, res_text, expected_res_text;
	int text_size = 0, res_size_text = 0, expected_res_size_text = 0;
	string name = "text_4.txt";
	expected_res_size_text = 13;
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
	const int DASH_1 = -30;
	const int DASH_2 = -106;
	const int DASH = 45;
	const int FIRST_EMPTY_ELEMENT = 1;
	const int SECOND_EMPTY_ELEMENT = 2;
	int current_index = 0;
	for (int index = 0; index < quality_lines; index++) {
		getline(read_text, temporary_line);
		if (temporary_line != "") {
			if (temporary_line[0] != DASH)
				if (temporary_line[0] == DASH_1) {
					temporary_line[0] = DASH;
					temporary_line.erase(FIRST_EMPTY_ELEMENT, SECOND_EMPTY_ELEMENT);
				}
			if (temporary_line[0] == DASH_2)
				temporary_line[0] = DASH;
			text[current_index] = temporary_line;
			current_index++;
		}
	}
	output_file_text.close();
	read_text.close();
	check_string(text, text_size, res_text, res_size_text);
	if (res_size_text == expected_res_size_text) {
		return true;
	}
	else {
		cout << "Тест 4 не пройден!" << endl;
		cout << "Ожидаемое количество строчек: " << expected_res_size_text << endl;
		cout << "Полученное количество строчек: " << res_size_text << endl;
		return false;
	}
}


void run_tests(void) {
	if (Test1() && Test2() && Test3() && Test4()) cout << "Все тесты пройдены!" << endl;
}
