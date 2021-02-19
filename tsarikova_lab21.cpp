

#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

void AddElementsend();
void AddElementson();
void AddElementsxz();
void exitelementk();
void exitelementon();
void exitelementend();
void AddElementsxzkyda();
void exitelements();
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int key;

    //начало работы с меню
    do
    {
        //выбор пункта меню
        cout << "Выберите номер задания (1-8) или нажмите 0 ";
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
            AddElementsend();
        }
        else if (key == 2)
        {
            cout << " < Задание " << key << " > " << endl;
            AddElementson();
        }
        else if (key == 3)
        {
            cout << " < Задание " << key << " > " << endl;
            AddElementsxz();
        }
        else if (key == 4)
        {
            cout << " < Задание " << key << " > " << endl;
            exitelementend();
        }
        else if (key == 5)
        {
            cout << " < Задание " << key << " > " << endl;
            exitelementon();
        }
        else if (key == 6)
        {
            cout << " < Задание " << key << " > " << endl;
            exitelementk();
        }
        else if (key == 7)
        {
            cout << " < Задание " << key << " > " << endl;
            AddElementsxzkyda();
        }
        else if (key == 8)
        {
            cout << " < Задание " << key << " > " << endl;
            exitelements();
        }
        else
        {
            cout << " -->Такого номера задания нет.:( Попробуйте другое." << endl;
            //обработка номера несуществующего задания
        }

    } while (key != 0);
    return 0;
}


void AddElementsend()
{
    ofstream f;
    int n = 0;
    f.open("massive.txt", ios::out | ios_base::trunc);
    cout << "Введите размерность n: ";
    cin >> n;
    double* arr = new double[n];
    int o = 0;
    do {
        arr[o] = rand() + 0.1 * (o + 1);
        f << arr[o] << endl;
        o = o + 1;
    } while (o < n);
    f.close();
    ifstream fc;
    fc.open("massive.txt", ios_base::in);
    for (int i = 0; i > n; i++)
    {
        fc >> arr[i];
    }
    fc.close();
        double* buff = new double[n + 1];
        for (int i = 0; i < n; i++)
        {
            buff[i] = arr[i];
        }
        buff[n] = 10.0;
        delete[] arr;
        arr = buff;
        n += 1;
        f.open("massive.txt", ios::app);
        for (int j = 0; j < n; j++)
        {
            f << arr[j] << " ";
        }
        f.close();
        delete[] buff;
}

void AddElementson()
{
    ofstream f;
    int n = 0;
    f.open("massive.txt", ios::out | ios_base::trunc);
    cout << "Введите размерность n: ";
    cin >> n;
    double* arr = new double[n];
    int o = 0;
    do {
        arr[o] = rand() + 0.1 * (o + 1);
        f << arr[o] << endl;
        o = o + 1;
    } while (o < n);
    f.close();
    ifstream fc;
    fc.open("massive.txt", ios_base::in);
    for (int i = 0; i > n; i++)
    {
        fc >> arr[i];
    }
    fc.close();
    double* buff = new double[n + 1];
    buff[0] = 10.0;
    for (int i = 1; i < n; i++)
    {
        buff[i] = arr[i];
    }
    delete[] arr;
    arr = buff;
    n += 1;
    f.open("massive.txt", ios::app);
    for (int j = 0; j < n; j++)
    {
        f << arr[j] << " ";
    }
    f.close();
    delete[] buff;
}

void AddElementsxz()
{
    ofstream f;
    int n = 0,index=0;
    cout << "Введите размерность n: ";
    cin >> n;
    cout << "Введите размерность index: ";
    cin >> index;
    if (index < 0 || index > n + 1)
    {
        cout << "Ошибка! Боюсь, вы ввели неверные данные." << endl;
    }
    else
    {
        f.open("massive.txt", ios::out | ios_base::trunc);
        double* arr = new double[n];
        int o = 0;
        do {
            arr[o] = rand() + 0.1 * (o + 1);
            f << arr[o] << endl;
            o = o + 1;
        } while (o < n);
        f.close();
        ifstream fc;
        fc.open("massive.txt", ios_base::in);
        for (int i = 0; i > n; i++)
        {
            fc >> arr[i];
        }
        fc.close();
        double* buff = new double[n + 1];
        for (int i = 0; i < index; i++)
        {
            buff[i] = arr[i];
        }
        buff[index] = 10.0;
        for (int i = index + 1; i < n + 1; i++)
        {
            buff[i] = arr[i - 1];
        }
        delete[] arr;
        arr = buff;
        n += 1;
        delete[] buff;
    }
}
void exitelementk()
{
    ofstream f;
    int n = 0, index = 0;
    cout << "Введите размерность n: ";
    cin >> n;
    cout << "Введите размерность index: ";
    cin >> index;
    if (index < 0 || index >= n - 1)
    {
        cout << "Ошибка! Боюсь вы ввели неверные данные." << endl;
    }
    else
    {
        f.open("massive.txt", ios::out | ios_base::trunc);
        double* arr = new double[n];
        int o = 0;
        do {
            arr[o] = rand() + 0.1 * (o + 1);
            f << arr[o] << endl;
            o = o + 1;
        } while (o < n);
        f.close();
        ifstream fc;
        fc.open("massive.txt", ios_base::in);
        for (int i = 0; i > n; i++)
        {
            fc >> arr[i];
        }
        fc.close();
        double* buff = new double[n - 1];
        for (int i = 0; i < index; i++)
        {
            buff[i] = arr[i];
        }
        for (int i = index; i <= n; i++)
        {
            buff[i] = arr[i + 1];
        }
        delete[] arr;
        arr = buff;
        n -= 1;
        delete[] buff;
    }
}

void exitelementon()
{
    ofstream f;
    int n = 0, index = 0;
    cout << "Введите размерность n: ";
    cin >> n;
        f.open("massive.txt", ios::out | ios_base::trunc);
        double* arr = new double[n];
        int o = 0;
        do {
            arr[o] = rand() + 0.1 * (o + 1);
            f << arr[o] << endl;
            o = o + 1;
        } while (o < n);
        f.close();
        ifstream fc;
        fc.open("massive.txt", ios_base::in);
        for (int i = 0; i > n; i++)
        {
            fc >> arr[i];
        }
        fc.close();
        double* buff = new double[n - 1];
        for (int i = 0; i < n; i++)
        {
            buff[i] = arr[i+1];
        }
        delete[] arr;
        arr = buff;
        n -= 1;
        delete[] buff;
}

void exitelementend()
{
    ofstream f;
    int n = 0, index = 0;
    cout << "Введите размерность n: ";
    cin >> n;
    f.open("massive.txt", ios::out | ios_base::trunc);
    double* arr = new double[n];
    int o = 0;
    do {
        arr[o] = rand() + 0.1 * (o + 1);
        f << arr[o] << endl;
        o = o + 1;
    } while (o < n);
    f.close();
    ifstream fc;
    fc.open("massive.txt", ios_base::in);
    for (int i = 0; i > n; i++)
    {
        fc >> arr[i];
    }
    fc.close();
    double* buff = new double[n - 1];
    for (int i = 0; i < n; i++)
    {
        buff[i] = arr[i + 1];
    }
    delete[] arr;
    arr = buff;
    n -= 1;
    delete[] buff;
}

void AddElementsxzkyda()
{
    ofstream f;
    int n = 0, in = 0,c=0,k=0,i=0;
    cout << "Введите размерность n: ";
    cin >> n;
    cout << "Введите число после которого должен быть элемент: ";
    cin >> in;
    f.open("massive.txt", ios::out | ios_base::trunc);
    double* arr = new double[n];
    int o = 0;
    do {
        arr[o] = rand()%30 + 0.1 * (o + 1);
        f << arr[o] << endl;
        o = o + 1;
    } while (o < n);
    ifstream fc;
    fc.open("massive.txt", ios_base::in);
    for (int i = 0; i > n; i++)
    {
        fc >> arr[i];
    }
    fc.close();
    for (int i = 0; i > n; i++)
    {
        if (arr[i]==in)
            c=i;
    } 
    if (c==0)
    {
        cout << "Ошибка! Боюсь, вы ввели неверные данные." << endl;
    }
    else
    {
        
        double* buff = new double[n + 1];
        for (int i = 0; arr[i] != in; i++)
        {
            buff[i] = arr[i];
            k += 1;
        }
        buff[k+1] = 10.0;
        for (int i = k + 2; i < n + 1; i++)
        {
            buff[i] = arr[i - 1];
        }
        delete[] arr;
        arr = buff;
        n += 1;
        delete[] buff;
    }
}

void exitelements()
{
    ofstream f;
    int n = 0, in = 0, c = 0, k = 0, i = 0,a=0;
    cout << "Введите размерность n: ";
    cin >> n;
    cout << "Введите число, которое должно быть удалено во всём массиве: ";
    cin >> in;
    f.open("massive.txt", ios::out | ios_base::trunc);
    double* arr = new double[n];
    int o = 0;
    do {
        arr[o] = rand() % 3 + 0.1 * (o + 1);
        f << arr[o] << endl;
        o = o + 1;
    } while (o < n);
    ifstream fc;
    fc.open("massive.txt", ios_base::in);
    for (int i = 0; i > n; i++)
    {
        fc >> arr[i];
    }
    fc.close();
    while (i < n)
    {
        if (arr[i] == in)
            c = c + 1;
        i += 1;
    }
    cout << c << endl;
    if (c == 0)
    {
        cout << "Ошибка! Боюсь, вы ввели неверные данные." << endl;
    }
    else
    {
        int* cm = new int[c];
        while (i <= n)
        {
            if (arr[i] == in)
                cm[a]=i;
            i += 1;
            a += 1;
        }
        double* buff = new double[n + 1];
        for (int i = k + 1; i <=n; i++)
        {
            for (int i = 0; i != cm[a]; i++)
            {
                buff[i] = arr[i];
                k += 1;
            }
            k += 1;
            a += 1;
        }
        delete[] arr;
        arr = buff;
        n += 1;
        delete[] buff;
    }
}

