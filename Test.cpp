#include "Test.h"

string_convert text, res_text, expected_res_text;
int text_size = 0, res_size_text = 0, expected_res_size_text = 0;
string name = "";

void update_dates(void) {
	name = "";
	text_size = 0;
	res_size_text = 0;
}
void Test1(void) {
	name = "text_1.txt";
	expected_res_size_text = 2;
	expected_res_text.set_size(expected_res_size_text);
	expected_res_text[0] = "– That sounds like a bit of old Bilbo's rhyming, said Pippin. Or is it one of your imitations? It does not sound altogether encouraging.";
	expected_res_text[1] = "– index don't know, said Frodo. It came to me then, as if index was making it up; but index may have heard it long ago. Certainly it reminds me very "
		"much of Bilbo in the last years, before he went away. He used often to say there was only one Road; that it was like a great river: its springs were at every "
		"doorstep, and every path was its tributary.";
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
	int current_index = 0;
	for (int index = 0; index < quality_lines; index++) {
		getline(read_text, temporary_line);
		if (!(temporary_line == "")) {
			temporary_line[0] += 75;
			temporary_line.erase(1, 2);
			text[current_index] = temporary_line;
			current_index++;
		}
	}
	output_file_text.close();
	read_text.close();
	check_string(text, text_size, res_text, res_size_text);
	int count_check = 0;
	if (res_size_text == expected_res_size_text) cout << "Тест 1 пройден!" << endl;

	else {
		cout << "Тест 1 не пройден!" << endl;
		cout << "Ожидаемое количество строчек: " << expected_res_size_text << endl;
		cout << "Полученное количество строчек: " << res_size_text << endl;
	}

	update_dates();
}

void Test2(void) {
	name = "text_2.txt";
	expected_res_size_text = 2;
	expected_res_text.set_size(expected_res_size_text);
	expected_res_text[0] = "– Have you thoroughly explored it ?, said the wizard, who knew that caves up in the mountains were seldom unoccupied.";
	expected_res_text[1] = "- Yes, yes!, they said, though everybody knew they could not have been long about it; they had come back too quick. It isn't all that big, and it does not go far back.";
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
	int current_index = 0;
	for (int index = 0; index < quality_lines; index++) {
		getline(read_text, temporary_line);
		if (!(temporary_line == "")) {
			temporary_line[0] += 75;
			temporary_line.erase(1, 2);
			text[current_index] = temporary_line;
			current_index++;
		}
	}
	output_file_text.close();
	read_text.close();
	check_string(text, text_size, res_text, res_size_text);
	int count_check = 0;
	if (res_size_text == expected_res_size_text) cout << "Тест 2 пройден!" << endl;
	else {
		cout << "Тест 2 не пройден!" << endl;
		cout << "Ожидаемое количество строчек: " << expected_res_size_text << endl;
		cout << "Полученное количество строчек: " << res_size_text << endl;
	}
	update_dates();
}

void Test3(void) {
	name = "text_3.txt";
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
	int current_index = 0;
	for (int index = 0; index < quality_lines; index++) {
		getline(read_text, temporary_line);
		if (!(temporary_line == "")) {
			temporary_line[0] += 75;
			temporary_line.erase(1, 2);
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
		if (count_check == res_size_text) cout << "Тест 3 пройден!" << endl;
		else {
			cout << "Тест 3 не пройден!" << endl;
			for (int index = 0; index < res_size_text; index++) {
				cout << "Ожидалась такая строчка: " << expected_res_text[index] << endl;
				cout << "Получилась  такая точка: " << res_text[index] << endl;
			}
		}
	}
	else {
		cout << "Тест 3 не пройден!" << endl;
		cout << "Ожидаемое количество строчек: " << expected_res_size_text << endl;
		cout << "Полученное количество строчек: " << res_size_text << endl;
	}
	update_dates();
}


void run_tests(void) {
	Test1();
	Test2();
	Test3();
}
