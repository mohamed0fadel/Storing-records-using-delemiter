#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Student {
	char id[5];
	char fname[10];
	char address[25];
};
void main() {
	ofstream out("data.txt", ios::binary);
	Student student;
	int num = 0;
	cout << "enter the umber of records : ";
	cin >> num;
	cout << "_____________________________________\n";
	for (int i = 1; i <= num; i++) {
		cout << "enter student | " << " | id      : ";
		cin >> student.id;
		cout << "enter student | " << " | fname   : ";
		cin >> student.fname;
		cout << "enter student | " << " | address : ";
		cin.ignore();
		cin.getline(student.address, sizeof(student.address));
		char record[42];
		strcpy_s(record, student.id);
		strcat_s(record, "|");
		strcat_s(record, student.fname);
		strcat_s(record, "|");
		strcat_s(record, student.address);
		strcat_s(record, "|");
		strcat_s(record, "#");
		out.write(record, strlen(record));
		cout << "_____________________________________\n";
	}
	out.close();
	ifstream in("data.txt", ios::binary);
	Student stu;

	while (in.getline(stu.id, sizeof(student.id), '|')){
		in.getline(stu.fname, sizeof(student.fname), '|');
		in.getline(stu.address, sizeof(student.address), '|');
		in.seekg(1, ios::cur);
		cout << "student id      : " << stu.id << endl;
		cout << "student name    : " << stu.fname << endl;
		cout << "student address : " << stu.address << endl;
		cout << "_____________________________________\n";
	}
	in.close();

	system("pause");
}