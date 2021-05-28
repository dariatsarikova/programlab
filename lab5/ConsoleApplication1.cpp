#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

struct flower {
	string color;
	int quantity;
	bool type;
	double weight;
	void Out();
};
void flower::Out() {
	cout << "Color is: " << color<<" "
		<< " A quantity flower is: " << quantity<<" "
		<< "Type is: " << type<<" "
		<< "Weight is: " << weight<< endl;
}
struct DLList
{
	struct Node
	{
		flower data;
		Node* next;
		Node* prev;
	};
	Node* F = NULL;
	Node* L = NULL;
	Node* C = NULL;
	int count;
	void Out();
	void Info();
	void Clear();
	bool MoveNext();
	bool MovePrev();
	bool MoveFirst();
	bool MoveLast();
	bool Init(flower);
	bool AddNext(flower);
	bool AddPrev(flower);
	bool AddFirst(flower);
	bool AddLast(flower);
	bool Del(flower&);
	bool DelNext(flower&);
	bool DelPrev(flower&);
	bool DelFirst(flower&);
	bool DelLast(flower&);
};
void DLList :: Out()
{
	if (!F)
	{
		cout << "List is empty" << endl; 
		return;
	}
	Node* temp = F; cout << "List: ";
		do
		{
			temp->data.Out();
			temp = temp->next;
	    }while (temp);
		 cout << endl;
}

void DLList::Info()
{
	if (count)
		cout << "List node count:"
		<< count << endl;
	else
		cout << "List is empty" << endl;
	if (C)
		cout << "Current node data: ";
		C->data.Out();
		cout << endl;
}

bool DLList :: MoveFirst()
{
	if (!F) return false;
	C = F;
	return true;
}

bool DLList::MoveLast()
{
	if (!L) return false;
	C = L;
	return true;
}

bool DLList::MoveNext()
{
if (!F) return false;
if (!C)
{
	C = F;
	return true;
};
if (!C->next) return false;
C = C->next;
return true;
}

bool DLList :: MovePrev()
{
if (!F) return false; 
if (!C)
{
	C = F; 
	return true;
}
if (!C->prev) return false;
C = C->prev; 
return true;
}

bool DLList::Init(flower data)
{
	if (!F)
	{
		F = new Node;
		L = F;
		C = F;
		F->prev = NULL;
		F->next = NULL;
		F->data = data;
		count = 1;
		return true;
	}
	else
		return false;
}

bool DLList::AddNext(flower data)
{
	if (!F) return Init(data);

	Node* temp = C->next;
	C->next = new Node;
	C->next->next = temp;
	C->next->prev = C;
	if (!temp)
		L = C->next;
	else
		temp->prev = C->next;
	C = C->next;
	C->data = data;
	count++;
	return true;
}

bool DLList::AddPrev(flower data)
{
	if (!F) return Init(data);

	Node* temp = C->prev;
	C->prev = new Node;
	C->prev->next = C;
	C->prev->prev = temp;
	if (!temp)
		F = C->prev;
	else
		temp->next = C->prev;
	C = C->prev; 
	C->data = data;
	count++; 
	return true;
}

bool DLList::AddFirst(flower data)
{
	if (MoveFirst()) 
		return AddPrev(data);
	else 
		return Init(data);
}

bool DLList::AddLast(flower data)
{
	if (MoveLast()) 
		return AddNext(data);
	else 
		return Init(data);
}

bool DLList::DelFirst(flower& data)
{
	if (!F) return false;
	if (C != F) MoveFirst();
	Node* temp = C->next;
	data = C->data;
	if (temp) temp->prev = NULL;
	delete C;
	C = temp;
	F = temp;
	count--;
	if (!temp) { L = NULL; return false; }
	return true;
}

bool DLList::DelLast(flower& data)
{
	if (!F) return false;
	if (C != L) MoveLast();
	Node* temp = C->prev;
	data = C->data;
	if (temp) temp->next = NULL;
	delete C;
	C = temp;
	L = temp;
	count--;
	if (!temp)
	{
		F = NULL; return false;
	}
	return true;
}

bool DLList::Del(flower& data)
{
	if (!F) return false; 
	if (!C) return false;
	if (C == F) return DelFirst(data);
	if (C == L) return DelLast(data);
	Node* temp = C->next;
	data = C->data;
	C->prev->next = C->next;
	C->next->prev = C->prev;
	delete C;
	C = temp; 
	count--;
	return true;
}

bool DLList :: DelNext(flower& data)
{
	if (!F) return false;
	if (!C) return false;
	if (MoveNext()) return Del(data); 
	return false;
}

bool DLList::DelPrev(flower& data)
{
	if (!F) return false;
	if (!C) return false;
	if (MovePrev()) return Del(data);
	return false;
}

void DLList::Clear()
{
	if (!MoveFirst())
	{
		cout << "List is empty" << endl;
		return;
	}
	flower k;
	while (Del(k));
}

bool GetFile(DLList& list1);

void input(DLList& list1);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int key;
	int c;
	flower f1;
	DLList list1;
	GetFile(list1);


	//начало работы с меню
	do
	{
		//выбор пункта меню
		cout << "Выберите номер задания (1-5) или нажмите 0 ";
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
			cout << "Выберите номер пункта меню (1-3) или нажмите 0. ";
			cin >> c;
			switch (c)
			{
			case 1:
				cout << "Введите новые данные" << endl;
				cout << "Цвет цветка: "; cin >> f1.color;
				cout << "Количество цветов: "; cin >> f1.quantity;
				cout << "Наличие листьев(писать 1 или 0): "; cin >> f1.type;
				cout << "Вес цветка: "; cin >> f1.weight;
				list1.AddFirst(f1);
				list1.Info();
				cout << "_______________________________" << endl;
				break;
			case 2:
				list1.Info();
				cout << "Введите новые данные" << endl;
				cout << "Цвет цветка: "; cin >> f1.color;
				cout << "Количество цветов: "; cin >> f1.quantity;
				cout << "Наличие листьев(писать 1 или 0): "; cin >> f1.type;
				cout << "Вес цветка: "; cin >> f1.weight;
				list1.AddLast(f1);
				list1.Info();
				cout << "_______________________________" << endl;
				break;
			case 3:
				list1.Info();
				int k;         //номер позиции
				cout << "Введите номер позиции на которую хотите добавить элемент" << endl;
				cin >> k;
				list1.MoveFirst();
				for (int i = 1; i != k; i++) //Переход курсора на k-ую позицию
					list1.MoveNext();
				cout << "Введите новые данные" << endl;
				cout << "Цвет цветка: "; cin >> f1.color;
				cout << "Количество цветов: "; cin >> f1.quantity;
				cout << "Наличие листьев(писать 1 или 0): "; cin >> f1.type;
				cout << "Вес цветка: "; cin >> f1.weight;
				list1.AddNext(f1); 
				list1.Info();
				cout << "_______________________________" << endl;
				break;
			default:
				cout << " Упс,такого номера у меня нет.:( Попробуйте другое." << endl;
				break;
			}
		}
		else if (key == 2)
		{
			cout << " < Задание " << key << " > " << endl;
			cout << "Выберите номер пункта меню (1-3) или нажмите 0. ";
			cin >> c;
			switch (c)
			{
			case 1:
				list1.Info();
				list1.DelFirst(f1);
				list1.Info();
				cout << "_______________________________" << endl;
				break;
			case 2:
				list1.Info();
				list1.DelLast(f1);
				list1.Info();
				cout << "_______________________________" << endl;
				break;
			case 3:
				list1.Info();
				int k;         //номер позиции
				cout << "Введите номер позиции с которой хотите удалить элемент" << endl;
				cin >> k;
				list1.MoveLast();
				for (int i = 1; i != k; i++) //Переход курсора на k-ую позицию
					list1.MovePrev();
				list1.Del(f1);
				list1.Info();
				cout << "_______________________________" << endl;
				break;
			default:
				cout << " Упс,такого номера у меня нет.:( Попробуйте другое." << endl;
				break;
			}
		}
		else if (key == 3)
		{
			cout << " < Задание " << key << " > " << endl;
			list1.MoveFirst();
			flower f2;
			int x = 0;
			int y = list1.count;
			cout << "Выберите номер пункта меню (1-2) или нажмите 0. ";
			cin >> c;
			switch (c)
			{
			case 1:
				while (x < y) {
					unsigned int q1, q2;
					for (unsigned short int i = x; i < y - 1; i++) {
						f1 = list1.C->data;
						f2 = list1.C->next->data;
						if (f1.type == 1) q1 = f1.quantity * 1024;
						else q1 = f1.quantity;
						if (f2.type == 1) q2 = f2.quantity * 1024;
						else q2 = f2.quantity;

						if (q1 > q2) {
							list1.C->next->data = f1;
							list1.C->data = f2;
						}

						list1.MoveNext();
					}
					y--;
					for (unsigned short int i = y; i > x + 1; i--) {
						f1 = list1.C->data;
						f2 = list1.C->prev->data;
						if (f1.type == 1) q1 = f1.quantity * 1024;
						else q1 = f1.quantity;
						if (f2.type == 1) q2 = f2.quantity * 1024;
						else q2 = f2.quantity;

						if (q1 < q2) {
							list1.C->prev->data = f1;
							list1.C->data = f2;
						}

						list1.MovePrev();
					}
					x++;
				}
				break;
			case 2:
				while (x < y) {
					for (unsigned short int i = x; i < y - 1; i++) {
						f1 = list1.C->data;
						f2 = list1.C->next->data;

						if (list1.C->data.color > list1.C->next->data.color) {
							list1.C->next->data = f1;
							list1.C->data = f2;
						}

						list1.MoveNext();
					}
					y--;
					for (unsigned short int i = y; i > x + 1; i--) {
						f1 = list1.C->data;
						f2 = list1.C->prev->data;

						if (list1.C->data.color < list1.C->prev->data.color) {
							list1.C->next->data = f1;
							list1.C->data = f2;
						}

						list1.MovePrev();
					}
					x++;
					break;
			default:
				cout << " Упс,такого номера у меня нет.:( Попробуйте другое." << endl;
				break;
				}
			}
		}
		else if (key == 4)
		{
			cout << " < Задание " << key << " > " << endl;
			list1.Info();
			list1.Clear();
			list1.Info();
			cout << "_________________________________" << endl;
		}
		else if (key == 5)
		{
			cout << " < Задание " << key << " > " << endl;
			input(list1);
		}
		else
		{
			cout << " -->Такого номера задания нет.:( Попробуйте другое." << endl;
			//обработка номера несуществующего задания
		}

	} while (key != 0);
	list1.Clear();
	list1.Info();
	return 0;
}

bool GetFile(DLList& list1)
{
	ifstream F("list.txt");
	if (!F) {
		cout << "Cant find file" << endl;
		return false;
	}
	flower f2;
	list1.Clear();
	F >> f2.color >> f2.quantity >> f2.type >> f2.weight;
	list1.Init(f2);
	list1.MoveNext();
	while (F >> f2.color >> f2.quantity >> f2.type >> f2.weight) {//Пока можем извлечь
		list1.AddNext(f2);
		list1.MoveNext();
	}
	F.close();
	return true;
}
void input(DLList& list1)
{
	ofstream f;
	f.open("list.txt", ios::out | ios_base::trunc);
	list1.MoveFirst();
	while (list1.count != 0) {
		f << list1.C->data.color << " ";
		f << list1.C->data.quantity << " ";
		if (list1.C->data.type == 1) f << " true ";
		else f << " fasle ";
		f << " ";
		f << list1.C->data.weight << endl;

		list1.MoveNext();
		list1.count--;
	}
	f.close();
}