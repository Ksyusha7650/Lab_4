#include "Interface.h"

using namespace std;
using namespace filesystem;

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


bool show_or_try(void) {
	cout << "��� ����, ����� �������� ����� ������� 1." << endl;
	cout << "��� ����, ����� �������������� ��������� ������� 2." << endl;
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
}

void output_file(string_convert& text, int& text_size) {
	text_size = 0;
	cout << "������� ���� ����� � �������." << endl
				<< "�������: C:\\\\�����1(���� ����������)\\\\�����2(���� ����������)\\\\...\\\\�������� �����.txt " << endl
				<< "���� ������� ������ �������� �����, ���� �� � ����� ����� �������."
				<< endl;
					const int SIZE_NAME = 256;
					string name = "";
					while (true) {
					cin >> name;
					fstream output_file_text(name);
						 error_code ec;
							 if (!is_regular_file(name, ec)) {
								 cout << "����� �������� ������������ ��������. ��������� ����." << endl;
								 ec.clear();
							 }
							 else break;
				   }
					string str;
					ifstream read_size(name);
					while (getline(read_size, str)) 
					{                      
						text_size++;
					}
					read_size.close();
					fstream output_file_text(name);
					//cout << text_size << endl;
					text.set_size(text_size);
					for (int i = 0; i < text_size; i++) {
						getline(output_file_text, text[i]);
					}
			}



//void create_file(int mode, Points_class& point_arr, res_points_class& res_point_arr, int& size, int& radius, Point& center) {
//	if (mode == READ_SIZE) {
//	here: cout << "������� ���� �����, �� �������� ������� ������." << endl
//		<< "�������: C:\\\\�����1(���� ����������)\\\\�����2(���� ����������)\\\\...\\\\�������� �����.txt " << endl
//		<< "���� ������� ������ �������� �����, ���� �� � ����� ����� �������."
//		<< endl;
//		  const int SIZE_NAME = 256;
//		  string name = "";
//		  cin >> name;
//		  fstream output_file(name);
//		  int AMOUNT_DATA = 1;
//		  for (int i = 0; i < AMOUNT_DATA; i++) {
//			  if (!(output_file >> size)) {
//				  cout << "������������ ������." << endl;
//				  output_file.close();
//				  goto here;
//				  break;
//			  }
//		  }
//		  for (int i = 0; i < AMOUNT_DATA; i++) {
//			  output_file >> size;
//		  }
//		  cout << "�������� ���������� �����: " << size << endl;
//		  output_file.close();
//	}
//	else if (mode == READ_POINTS) {
//	here_2: cout << "������� ���� �����, �� �������� ������� ������." << endl
//		<< "�������: C:\\\\�����1(���� ����������)\\\\�����2(���� ����������)\\\\...\\\\�������� �����.txt " << endl
//		<< "���� ������� ������ �������� �����, ���� �� � ����� ����� �������."
//		<< endl;
//			const int SIZE_NAME = 256;
//			string name = "";
//			cin >> name;
//			fstream output_file(name);
//			output_file_points file_points;
//			int AMOUNT_DATA = 3 * (size + 1) + 1;
//			file_points.set_size(AMOUNT_DATA);
//			for (int i = 0; i < AMOUNT_DATA; i++) {
//				if (!(output_file >> file_points[i])) {
//					cout << "������������ ������." << endl;
//					output_file.close();
//					goto here_2;
//					break;
//				}
//			}
//			for (int i = 0; i < AMOUNT_DATA; i++) {
//				output_file >> file_points[i];
//			}
//			int j = 0;
//			for (int i = 0; i < size; i++) {
//				point_arr[i].x = file_points[j];
//				point_arr[i].y = file_points[j + 1];
//				point_arr[i].z = file_points[j + 2];
//				j += 3;
//			}
//			radius = file_points[size * 3];
//			center.x = file_points[AMOUNT_DATA - 3];
//			center.y = file_points[AMOUNT_DATA - 2];
//			center.z = file_points[AMOUNT_DATA - 1];
//			output_file.close();
//	}
//	else {
//	path:cout << "������� ���� �����, � ������� ��������� ������." << endl << "�������: C:\\\\�����1(���� ����������)\\\\"
//		"�����2(���� ����������)\\\\...\\\\�������� �����.txt " << endl << "���� ������� ������ �������� �����, ����� �� ����� � ����� ����� �������."
//		<< endl;
//		 const int SIZE_NAME = 256;
//		 string name = "";
//		 cin >> name;
//		 if (ifstream(name)) {
//			 bool rewrite = true;
//			 cout << "���� ��� ����������." << endl;
//			 cout << "������� 0 ��� ����, ����� ������������ ������������ ����." << endl;
//			 cout << "������� 1 ��� ����, ����� ��������� ����." << endl;
//		 repeat: rewrite = get_int();
//			 switch (rewrite) {
//			 case 0: cout << "�� ������� ����� ������������ ����." << endl;
//				 break;
//			 case 1: cout << "�� ������� ����� ��������� ����." << endl;
//				 goto path;
//				 break;
//			 default:
//				 cout << "������� 1, ���� 2";
//				 goto repeat;
//			 }
//		 }
//		 ofstream result_file(name, ofstream::app);
//		 error_code ec;
//		 if (!is_regular_file(name, ec)) {
//			 cout << "����� �������� ������������ ��������. ��������� ����." << endl;
//			 ec.clear();
//			 goto path;
//		 }
//		 result_file.clear();
//		 switch (mode) {
//		 case DATA:
//			 result_file << size << " ";
//			 for (int i = 0; i <= size; i++) {
//				 result_file << point_arr[i].x << " " << point_arr[i].y << " " << point_arr[i].z << " ";
//				 if (i == size)  result_file << radius << " " << center.x << " " << center.y << " " << center.z << " ";
//			 }
//			 break;
//		 case RESULT:
//			 result_file
//				 << "��������� ���������. " << endl
//				 << "������������ ������ � ������������ �����:" << endl;
//			 for (int i = 0; i < res_point_arr.get_size(); i++) {
//				 if (res_point_arr[i] == 1) {
//					 result_file << "�����" << i << "� ������������: " << point_arr[i].x << " ; " << point_arr[i].y << " ; " << point_arr[i].z
//						 << " - ��������." << endl;
//				 }
//				 else {
//					 result_file << "�����" << i << " � ������������: " << point_arr[i].x << " ; " << point_arr[i].y << " ; " << point_arr[i].z
//						 << " - �� ��������." << endl;
//				 }
//			 }
//			 cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
//
//			 break;
//		 }
//		 result_file.close();
//	}
//}

void greetings() {
	cout << "��������� ��������� ������� ������ ����������." << endl << "������: 404." << endl << "�������: 22." << endl <<
		"������ ����� 4:" << endl <<
		"�������� � �������� ������ ��� ������� (������������ � ����� ������ � ������� �����). ��������� ������� � ��������� ��������� ������." << endl
		<< "������������ ������� ���������� ��������, ������������� � ������������� �������." << endl;
}

//void input_types(Points_class& arr_point, res_points_class& res_arr_point, int size, int& mode, int& radius, Point& center) {
//	cout << "�������� ������ ���������� ������� �����:" << endl << "������� 1 ��� ����� �������." << endl
//		<< "������� 2 ��� ��������� ��������� ���������." << endl << "������� 3 ��� ������������� �������� ������ �� �����." << endl;
//again: int menu_type = get_int();
//	mode = menu_type;
//	switch (menu_type) {
//	case MANUAL:
//		cout << "�� ������� ����� ����� �������." << endl;
//		cout << endl;
//		user_input(arr_point, radius, center);
//		break;
//	case GENERATE:
//		cout << "�� ������� ����� ���������." << endl;
//
//		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
//		break;
//	case FILE_INPUT:
//		cout << "�� ������� ����� ����� ������ �� �����." << endl;
//		create_file(READ_POINTS, arr_point, res_arr_point, size, radius, center);
//		break;
//	default:
//		cout << "������� ���� 1, ���� 2, ���� 3." << endl;
//		goto again;
//	}
//}

bool end_program() {
	cout << "��������� ���������? " << endl << "������� 0 ��� ����������." << endl << "������� 1 ��� �������." << endl;
again: int end = get_int();
	switch (end) {
	case END:
		cout << "��������� �����������..." << endl;
		break;
	case CONTINUE:
		cout << "�� ������� ��������� ���������: " << endl;
		break;
	default:
		cout << "������� ���� 0, ���� 1." << endl;
		goto again;
	}
	return !(end);
}


//void saving_results(Points_class& point_arr, res_points_class& res_point_arr) {
//	cout << "����a���� ���������� � ��������� �����?" << endl << "������� 1 ��� ����������." << endl << "������� 2, ����� ���������� ����������." << endl;
//	int size_t = 0, radius_t = 0;
//	Point center_t;
//	while (true) {
//		int save = get_int();
//		if (save == YES) {
//			create_file(RESULT, point_arr, res_point_arr, size_t, radius_t, center_t);
//			break;
//		}
//		else if (save == NO) {
//			cout << "�� ������� ���������� ����������." << endl;
//			break;
//		}
//		else cout << "������� ���� 1, ���� 2." << endl;
//
//	}
//}
//
//void save_data(Points_class& point_arr, int radius, Point center, res_points_class& res_t) {
//	int size_t = 0;
//	cout << "�� ������ ��������� ������? ������� 1 - ��� ����������, 2 - ��� �������� ����������." << endl;
//	while (true) {
//		int save = get_int();
//		if (save == YES) {
//			create_file(DATA, point_arr, res_t, size_t, radius, center);
//			cout << "������ ���������." << endl;
//			break;
//		}
//		else if (save == NO) {
//			cout << "�� ������� ���������� ����������." << endl;
//			break;
//		}
//		else cout << "������� ���� 1, ���� 2." << endl;
//	}
//}
