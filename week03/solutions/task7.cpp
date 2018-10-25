#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
	char name[20];
	int age;
};

void first() {
	int students;
	cin >> students;
	Student temp;
	char tempName[20];
	int tempAge;
	ofstream output("students.db", ios::binary);
	
	for (int i = 0; i < students; i++) {
		cin.ignore();
		cin.getline(tempName, 20);
		cin >> tempAge;

		strncpy(temp.name, tempName, 20);
		temp.age = tempAge;

		// Записваме чрез output съдържанието на temp, байт по байт, общо
		// толкова на брой байтове, колкото е голям запис от структурата, в случая 20 + 4
		output.write((const char*)&temp, sizeof(Student));
	}
	// Отново внимание към затварянето на файла след приключване на писането в него.
	output.close();

	ifstream input("students.db", ios::binary);
	// Докато мога да чета от input толквоа байта, колкото е големината на запис от
	// структурата, и да го записвам в temp
	while(input.read((char*)&temp, sizeof(Student)))
		cout << temp.name << " " << temp.age << endl;
	input.close();
}

void second() {
	ifstream input("students.db", ios::binary);
	string name;
	cin >> name;
	
	Student temp;
	bool found = false;
	while(input.read((char*)&temp, sizeof(Student))) {
		// Със string.c_str() преобразуваме string в char*
		if (!strcmp(temp.name, name.c_str())) {
			cout << temp.name << " " << temp.age << endl;
			found = true;
			break;
		}
	}
	
	if (!found)
		cout << "Student " << name << " not found." << endl;
	input.close();
}

void third() {
	fstream file("students.db", ios::binary | ios::in | ios::out);
	string name;
	int age;
	getline(cin, name);
	cin >> age;
	
	Student temp;
	while(file.read((char*)&temp, sizeof(Student))) {
		// Намираме търсения човек във файла
		if (!strcmp(temp.name, name.c_str())) {
			/* В момента ситуацията е следната
			 * -------------------------------
			 * |  abc  |   xyz   |   pqr   | ...
			 * ------------------^------------
			 *                   |
			 *  т.е. сме прочели xyz, което е търсеното, но указателят сочи към следващия запис.
			 *  За целта трябва да се върнем назад, за да презапишем xyz.
			 */
			temp.age = age;
			// Местим указателя на текущата позиция толкова байта назад спрямо
			// текущата позиция, колкото е големината на запис от структурата
			// Обърнете внимание на минуса
			/*
			 * -------------------------------
			 * |  abc  |   xyz   |   pqr   | ...
			 * --------^----------------------
			 *         |          
			 */
			file.seekp(-(int)sizeof(Student), ios::cur);
			file.write((const char*)&temp, sizeof(Student));
		}
	}

	file.clear();
	// Местим указателя в началото, защото в момента сме прочели всичко и сочим края на файла.
	file.seekp(0, ios::beg);
	while(file.read((char*)&temp, sizeof(Student)))
		cout << temp.name << " " << temp.age << endl;
	file.close();
}

bool sortStudent(Student const& first, Student const& second) {
	return strcmp(first.name, second.name) < 0;
}

void fourth() {
	ifstream input("students.db", ios::binary);
	vector<Student> students;
	Student temp;
	
	while(input.read((char*)&temp, sizeof(Student)))
		// Добавяме последния прочетен студент най-отзад във вектора.
		students.push_back(temp);
	input.close();
	
	// Стандартно сортиране в C++, приема начало на колецкия, която искаме да сортираме,
	// край и булева функция, която приема два аргумента и казва как да се сравнят.
	sort(students.begin(), students.end(), sortStudent);
	
	// Вече студентите във вектора са сортирани, можем да ги запишем във файла поред.
	ofstream output("students.db", ios::binary);
	for (int i = 0; i < students.size(); i++)
		output.write((const char*)&students[i], sizeof(Student));
	output.close();

	// Проверка
	input.open("students.db", ios::binary);
	while(input.read((char*)&temp, sizeof(Student)))
		cout << temp.name << " " << temp.age << endl;
	input.close();
}

int main() {
	//first();
	//second();
	//third();
	//fourth();
}
