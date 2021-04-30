
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
using namespace std;

struct Candy {
	string color;
	int kolvo;
	bool type;
	double weight;

	void Out();
	bool Seria(char*& data, int& n);
};
void Candy::Out() {
	cout << "\nColor = " << color << " Number of candies = " << kolvo << " Type = " << type << " Weight = " << weight << endl;
}
Candy DeSeria(char* data, int n);

void ClearBinaryFile() {
	fstream out("out.dat", ios::out | ios::binary);
	out.close();
}
void PrintBinaryFile(char* data, int n) {
	fstream out("out.dat", ios::app | ios::binary);
	out.write((char*)&n, sizeof(int));
	out.write(data, n);
	out.close();
}
bool InputBinaryFile() {
	fstream in("out.dat", ios::in | ios::binary);
	if (!in) {
		cout << "-->Error, there are no input binary file" << endl;
		return false;
	}

	int i = 1, n;
	Candy C;

	while (!in.eof()) {
		if (in.read((char*)&n, sizeof(int))) {
			cout << "\t - " << i << " - " << " seria length : " << n << endl << endl;
			char* data = new char[n];
			in.read(data, n);
			i++;
			C = DeSeria(data, n);
			C.Out();
			cout << "\n--------------\n";
			delete[] data;
		}
	}
	in.close();
	return true;
}
bool Candy::Seria(char*& data, int& n) {
	size_t s = color.size();

	int n0 = sizeof(size_t);
	int n1 = s;
	int n2 = sizeof(int);
	int n3 = sizeof(bool);
	int n4 = sizeof(double);

	n = n0 + n1 + n2 + n3 + n4;

	data = new char[n];

	char* d0 = reinterpret_cast<char*>(&s);
	char* d1 = const_cast<char*>(color.c_str());
	char* d2 = reinterpret_cast<char*>(&kolvo);
	char* d3 = reinterpret_cast<char*>(&type);
	char* d4 = reinterpret_cast<char*>(&weight);

	for (int i = 0; i < n0; i++) data[i] = d0[i];
	for (int i = 0; i < n1; i++) data[i + n0] = d1[i];
	for (int i = 0; i < n2; i++) data[i + n0 + n1] = d2[i];
	for (int i = 0; i < n3; i++) data[i + n0 + n1 + n2] = d3[i];
	for (int i = 0; i < n4; i++) data[i + n0 + n1 + n2 + n3] = d4[i];

	return true;
}
Candy DeSeria(char* data, int n) {
	Candy temp;
	int n0, n1, n2, n3, n4;
	n0 = sizeof(size_t);
	n2 = sizeof(int);
	n3 = sizeof(bool);
	n4 = sizeof(double);

	size_t s = *reinterpret_cast<size_t*>(data);
	n1 = s;

	string ss(data + n0, s);
	temp.color = ss;
	temp.kolvo = *reinterpret_cast<int*>(data + n0 + n1);
	temp.type = *reinterpret_cast<bool*>(data + n0 + n1 + n2);
	temp.weight = *reinterpret_cast<double*>(data + n0 + n1 + n2 + n3);

	return temp;
}
struct MyQueue {
	struct Node {
		int n; //Размер серии
		char* data; //Сама серия
		Node* next;
	};
	Node* First = NULL;
	int Count = 0;
	bool Push(char*, int);
	bool Pop(char*&, int&);
	void Info();
};
bool MyQueue::Push(char* data, int n) {
	if (!First) {
		First = new Node;
		First->next = NULL;
		First->data = new char[n];
		for (int i = 0; i < n; i++) {
			First->data[i] = data[i];
		}
		First->n = n;
		Count = 1;
	}
	else {
		Node* temp;
		temp = First;
		while (temp->next != NULL) temp = temp->next;
		temp->next = new Node;
		temp->next->next = NULL;
		temp->next->data = new char[n];
		for (int i = 0; i < n; i++) {
			temp->next->data[i] = data[i];
		}
		temp->next->n = n;
		Count++;
	}
	return true;
}
bool MyQueue::Pop(char*& data, int& n) {
	if (!First) return false;
	Node* temp = First->next;
	n = First->n;
	data = new char[n];

	for (int i = 0; i < n; i++) {
		data[i] = First->data[i];
	}
	delete First->data;
	delete First;
	First = temp;
	Count--;
	return true;
}
void MyQueue::Info() {
	if (!First) cout << "--->Queue is empty" << endl;
	else {
		cout << endl << "Queue info: " << endl;
		cout << "\tQueue size = " << Count << endl;
		//cout << "YeFirst data" << First->data << endl << endl;
		//First->data.Out();
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int key;
    int i = 0;
	MyQueue queue, Q;
	Candy b1, b2;
	char* data;
	int n;
	//начало работы с меню
	do
	{
		//выбор пункта меню
		cout << "Выберите номер задания (1-3) или нажмите 0 ";
		cin >> key;

		// выход из меню после ввода нуля
		if (key == 0)
		{
			cout << endl << "Ещё увидимся:)" << endl;
			break;
		}
		//запуск отдельных задач
		else if (key == 1)
		{
			cout << " < Задание " << key << " > " << endl;
			cout << "Добавление элемента в очередь" << endl << endl;
			queue.Info();
			cout << endl;
			
			cout << "Цвет: "; cin >> b1.color;
			cout << "Шоколадная?(писать 1 или 0): "; cin >> b1.type;
			cout << "Количество: "; cin >> b1.kolvo;
			cout << "Вес: "; cin >> b1.weight;
			b1.Out();
			cout << "\n--------------\n";
			b1.Seria(data, n);
			PrintBinaryFile(data, n);
			queue.Push(data, n);
			queue.Info();
			cout << "\n___________________________\n" << endl;
		}
		else if (key == 2)
		{
			cout << " < Задание " << key << " > " << endl << endl;
			cout << "Введите параметры выталкивания: " << endl;
			cout << "Цвет: "; cin >> b2.color;
			cout << "Шоколадная?(писать 1 или 0): "; cin >> b2.type;
			cout << "Количество: "; cin >> b2.kolvo;
			cout << "Вес: "; cin >> b2.weight;
			while (queue.Pop(data, n))
			{
				if (b1.color == b2.color && b1.kolvo == b2.kolvo && b1.type == b2.type && b1.weight == b2.weight && i == 0)
				{
					i = 1;
					Q.Pop(data, n);
				}
				else Q.Push(data, n);
			}
			while (Q.Pop(data, n)) 
			{
				queue.Push(data, n);
			}
			if (i == 0) cout << "Данной конфеты нет. " << endl;

			i = 0;
		}
		else if (key == 3)
		{
			cout << " < Задание " << key << " > " << endl;
			ClearBinaryFile();
			while (queue.Pop(data, n))
			{
				b1 = DeSeria(data, n);
				b1.Out();
				cout << "\n";
			}

			delete[] data;
			queue.Info();
		}
		else
		{
			cout << " -->Такого номера задания нет.:( Попробуйте другое." << endl;
			//обработка номера несуществующего задания
		}
	} while (key != 0);
	ClearBinaryFile();
	while (queue.Pop(data, n))
		queue.Pop(data, n);
	while (Q.Pop(data, n))
		Q.Pop(data, n);
	delete[] data;
	queue.Info();
	return 0;
}

