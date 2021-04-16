#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

struct cup {
    string type;
    string handle;
    double volume;
    string color;
    void Out();
};
struct MyStack {
    struct Node {
        cup data;
        Node* prev;
    };
    Node* Top = NULL;
    int Count;
    bool Push(cup);
    bool Pop(cup&);
    void info();
};
bool MyStack::Push(cup data)
{
    if (!Top)
    {
        Top = new Node;
        Top->prev = NULL;
        Count = 1;
    }
    else
    {
        Node* temp;
        temp = new Node;
        temp->prev = Top;
        Top = temp;
        Count++;
    }
    Top->data = data;
    return true;
}
bool MyStack :: Pop(cup& data) {
    if (!Top) return false;
    Node* temp = Top->prev; 
    data = Top->data; 
    delete Top; 
    Top = temp;
    Count--; 
    return true;
}

void MyStack :: info() {
    if (!Top)
        cout << "--->Stack is empty" << endl;
    else 
    {
        cout << endl << "Stack info: " << endl;
        cout << "\tStack size =" << Count << endl;
        Top->data.Out();
            //cout << "\tTop data ="<< Top->data << endl << endl;
    }
}

void cup::Out() {
    cout << "Type is: " << type
        << " A handle cup is: " << handle 
        <<"Volume is:"<<volume
        <<"Color is:"<<color<< endl;
}

bool GetFile(MyStack& Stack);

struct Product {
    int volume;
    double price;
    void Out();
};

void Product::Out() {
    cout << "\nКоличество = " << volume << ' ' << "Цена = " << price << endl;
}

struct MyQueue {
    struct Node {
        Product data;
        Node* next;
    };
    int remain;
    double profit = 0;
    Node* First = NULL;
    int Count = 0;
    bool Push(Product);
    bool Pop(Product&);
    void Info();
    int Sell(int, double, bool);
};

bool MyQueue::Push(Product data) {
    if (!First) {
        First = new Node;
        First->next = NULL;
        First->data = data;
        Count = 1;
        remain = First->data.volume;
    }
    else {
        Node* temp;
        temp = First;
        while (temp->next != NULL) temp = temp->next;
        temp->next = new Node;
        temp->next->data = data;
        remain += temp->next->data.volume;
        temp->next->next = NULL;
        Count++;
    }
    return true;
};
bool MyQueue::Pop(Product& data) {
    if (!First) return false;
    Node* temp = First->next;
    data = First->data;
    remain -= First->data.volume;
    delete First;
    First = temp;
    Count--;
    return true;
}

void MyQueue::Info() {
    if (!First) {
        cout << "--->Очередь пуста" << endl;
        cout << "\nОстаток = " << remain << "\nДоход = " << profit;
    }
    else {
        cout << endl << "Информация: " << endl;
        cout << "\tРазмер очереди = " << Count << endl;
        //cout << "YeFirst data" << First->data << endl << endl;
        First->data.Out();

        cout << "\nОстаток = " << remain << "\nДоход = " << profit;
    }
}

int MyQueue::Sell(int volume, double price, bool fsell) {
    //cout << "\nDebugging:\n" << volume << endl;
    Product temp;

    if (volume == 0) return true;


    if (price < First->data.price && fsell == true) {
        cout << "\nСлишком низкая цена\n";
        return false;
    }
    else {
        if (volume > remain) {
            cout << "\nНедостаточно товаров\n";
            return -1;
        }
        if (First->data.volume > volume) {
            First->data.volume -= volume;
            profit += (price - First->data.price) * volume;
            //profit += price * volume;
            remain -= volume;
            return 0;
        }
        else {
            profit += (price - First->data.price) * volume;
            volume -= First->data.volume;
            Pop(temp);
            return volume;
        }
    }
}
bool GetFile(MyQueue& Queue);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int key;

    do
    {
        //выбор пункта задания
        cout << "Выберите номер задания (1-2) или нажмите 0 ";
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
            int c;
            cout << " < Задание " << key << " > " << endl;
            int n=1;
            cup k,k1;
            MyStack S,s;
            GetFile(S);
            do
            {
                cout << "Выберите номер пункта меню (1-3) или нажмите 0 ";
                cin >> c;
                switch (c)
                {
                case 1:
                    cout << "Добавление элемента в стек" << endl;
                    S.info();
                    cout << "Введите новые данные" << endl;
                    cout << "Тип чашки: "; cin >> k1.type;
                    cout << "Наличие ручки(писать да или нет): "; cin >> k1.handle;
                    cout << "Объём чашки: ";cin>> k1.volume;
                    cout << "Цвет чашки: "; cin >> k1.color;
                    S.Push(k1);
                    S.info();
                    cout << "___________________________" << endl;
                    break;
                case 2:
                    cout << "Вытягивание элемента из стека" << endl;
                    cout << "Введите критерии вытягивания" << endl;
                    cout << "Тип чашки: "; cin >> k1.type;
                    cout << "Наличие ручки(писать да или нет): "; cin >> k1.handle;
                    cout << "Объём чашки: "; cin >> k1.volume;
                    cout << "Цвет чашки: "; cin >> k1.color;
                    while (S.Pop(k))
                    {
                        s.Push(k);
                        if (k.type == k1.type && k.handle == k1.handle && k.volume == k1.volume && k.color == k1.color)
                        {
                            s.Pop(k);
                            n = 0;
                        }
                    }
                    while (s.Pop(k))
                    {
                        S.Push(k);
                    }
                    if (n != 0)
                    {
                        cout << "Такой чашки в стеке нет" << endl;
                    }
                    S.info();
                    cout << "___________________________" << endl;
                    while (s.Pop(k))
                        k.Out();
                    cout << endl;
                    cout << "___________________________" << endl;
                    s.info();
                    break;
                case 3:
                    S.info();
                    while (S.Pop(k));
                    //cout << " " << k;
                    cout << endl;
                    cout << "___________________________" << endl;
                    S.info();
                    break;
                default:
                    cout << " Упс,такого номера у меня нет.:( Попробуйте другое." << endl;
                    break;
                }
            } while (c != 0);
            while (S.Pop(k));
            cout << endl;
            cout << "___________________________" << endl;
            S.info();
            while (s.Pop(k));
        }
        else if (key == 2)
        {
            cout << " < Задание " << key << " > " << endl;
            int n = 10, № = 0, kolvo;
            float cost;
            Product k;
            MyQueue Q;

            do {

                cout << "Количество товаров: ";
                cin >> kolvo; cout << "\nЦена товара: ";
                cin >> cost; cout << "\n\n";
                Product k = { kolvo, cost };
                Q.Push(k);
                cout << "Продолжить ввод товаров?\n\n0 - закончить.\n\nРешение: ";
                cin >> №; cout << "\n\n";
            } while (№ != 0);

            Q.Info();
            int sellc, sellp, selld;
            do {
                cout << "\n__________________\n";
                cout << "\nВведите кол-во товара на продажу (0 для выхода): ";
                cin >> sellc;
                if (sellc > 0) {
                    cout << "Введите стоимость продажи: ";
                    cin >> sellp;
                    if (sellp < 0) sellp = 0;
                    selld = Q.Sell(sellc, sellp, true);
                    while (selld > 0) {
                        selld = Q.Sell(selld, sellp, false);
                    }
                    Q.Info();
                }
            } while (sellc > 0);
            cout << "__________________";
            while (Q.Pop(k)) k.Out();
            cout << endl;
            Q.Info();
        }
        else
        {
            cout << " -->Такого номера задания нет.:( Попробуйте другое." << endl;
            //обработка номера несуществующего задания
        }

    } while (key != 0);
	return 0;
}

bool GetFile(MyStack& Stack) {
    ifstream F("stek.txt");
    if (!F) {
        cout << "Cant find file" << endl;
        return false;
    }
    cup k;

    while (F >> k.type >> k.handle>>k.volume>>k.color) {//Пока можем извлечь
        Stack.Push(k);
    }

    F.close();
    return true;
}

bool GetFile(MyQueue& Queue) {
    ifstream F("ochered.txt");
    if (!F) {
        cout << "Cant find file" << endl;
        return false;
    }
    Product k;

    while (F >> k.volume>>k.price) {//Пока можем извлечь
        Queue.Push(k);
    }

    F.close();
    return true;
}

