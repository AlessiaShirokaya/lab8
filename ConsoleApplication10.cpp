// ConsoleApplication10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <locale.h>
#include <string>
#include <Windows.h>
#include <iomanip>

using namespace std;

struct spisok {
	string text;
	struct spisok* past; // Структура — это, некое объединение различных переменных(даже с разными типами данных), которому можно присвоить имя
	struct spisok* next;
};
class Tranzaction {
private:
	spisok* first;
public:
	Tranzaction() { // группа последовательных операций, которые представляют логическую единицу работы с данныит
		first = nullptr;
	}
	void add(int current, string d) {
		spisok* q = first;
		int number = 0;
		while (number < current - 1) {
			q = q->next;
			++number;
		}
		spisok* temp = new spisok;
		temp->text = d;
		if (q) {
			temp->past = q;
			q->next = temp;
		}
		else {

			temp->past = nullptr;
		}
		temp->next = nullptr;
		while (temp->past != nullptr) {
			temp = temp->past;
		}
		first = temp;
	}
	string show(int element) {
		spisok* current = first;
		int number = 0;
		while (current != NULL && number < element - 1) {
			current = current->next;
			++number;
		}
		return current->text;
	}
};
int main()
{
	system("chcp 1251");
	system("cls");
	string x;
	int current = 1;
	cout << "Напишите строку: " << endl;
	cin >> x;
	Tranzaction* writer = new Tranzaction();
	writer->add(0, x);
	int comand = 1;
	int number = 1;
	while (comand != 0)
	{
		cout << "Введите номер команды:" << endl;
		cout << "1 - Отмена" << endl;
		cout << "2 - Востановление" << endl;
		cout << "3 - Новая строка" << endl;
		cout << "0 - Выход" << endl;
		cout << "> ";
		cin >> comand;
		if (comand == 1)
		{
			if (current > 1) {
				--current;
				cout << writer->show(current) << endl;
			}
			else {
				cout << "1-ый элемент" << endl;
			}
		}
		if (comand == 2)
		{
			if (current < number) {
				++current;
				cout << writer->show(current) << endl;
			}
			else {
				cout << "Это последний элемент" << endl;
			}
		}
		if (comand == 3)
		{
			cout << "Введите новую строку:";
			string str_new;
			cin >> str_new;
			number = current + 1;
			writer->add(current, str_new);
			current++;
		}
	}
	return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
