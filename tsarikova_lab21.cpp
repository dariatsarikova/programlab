

#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

void AddElementsend(int n, double*& arr);
void AddElementson(int n, double*& arr);
void AddElementsxz(int n, double*& arr);
void exitelementk(int n, double*& arr);
void exitelementon(int n, double*& arr);
void exitelementend(int n, double*& arr);
double *Addel(int n);
void input(int n, double* arr);
void exit(int n, double* arr);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int key,n;
    cout << "Введите количество элементов в массиве";
    cin >> n;

    //начало работы с меню
    do
    {
        //выбор пункта меню
        cout << "Выберите номер задания (1-6) или нажмите 0 ";
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
            double*arr=Addel(n);
            input(n, arr);
            AddElementsend(n,arr);
            n += 1;
            exit( n, arr);
            delete[] arr;
        }
        else if (key == 2)
        {
            cout << " < Задание " << key << " > " << endl;
            double* arr = Addel(n);
            input(n, arr);
            AddElementson( n, arr);
            n += 1;
            exit(n, arr);
            delete[] arr;
        }
        else if (key == 3)
        {
            cout << " < Задание " << key << " > " << endl;
            double* arr = Addel(n);
            input(n, arr);
            AddElementsxz(n, arr);
            n += 1;
            exit(n, arr);
            delete[] arr;
        }
        else if (key == 4)
        {
            cout << " < Задание " << key << " > " << endl;
            double* arr = Addel(n);
            input(n, arr);
            exitelementend(n, arr);
            n = n - 1;
            exit(n, arr);
            delete[] arr;
        }
        else if (key == 5)
        {
            cout << " < Задание " << key << " > " << endl;
            double* arr = Addel(n);
            input(n, arr);
            exitelementon(n, arr);
            n = n - 1;
            exit(n, arr);
            delete[] arr;
        }
        else if (key == 6)
        {
            cout << " < Задание " << key << " > " << endl;
            double* arr = Addel(n);
            input(n, arr);
            exitelementk(n, arr);
            exit(n, arr);
            delete[] arr;
        }
        else
        {
            cout << " -->Такого номера задания нет.:( Попробуйте другое." << endl;
            //обработка номера несуществующего задания
        }

    } while (key != 0);
    return 0;
}


void AddElementsend(int n,double*&arr)
{
        double* buff = new double[n + 1];
        for (int i = 0; i < n; i++)
        {
            buff[i] = arr[i];
        }
        buff[n+1] = 10.6;
        delete[] arr;
        arr = buff;
        n += 1;
}

void AddElementson(int n, double*& arr)
{
        double* buff = new double[n + 1];
        buff[0] = 10.6;
        for (int i = 1; i < n+1; i++)
        {
            buff[i] = arr[i];
        }
        delete[] arr;
        arr = buff;
        n += 1;
}

void AddElementsxz(int n, double*& arr)
{
    int index;
    cout << "index" << endl;
    cin >> index;
    if (index < 0 || index > n + 1)
    {
        cout << "Error" << endl;
    }
    else
    {
        double* buff = new double[n + 1];
        for (int i = 0; i < index; i++)
        {
            buff[i] = arr[i];
        }
        buff[index] = 10.6;
        for (int i = index + 1; i < n + 1; i++)
        {
            buff[i] = arr[i];
        }
        delete[] arr;
        arr = buff;
        n += 1;
    }
}
void exitelementk(int n, double*& arr)
{
    int index = 0;
    cout << "Введите  index: ";
    cin >> index;
    if (index < 0 || index >= n - 1)
    {
        cout << "Ошибка! Боюсь вы ввели неверные данные." << endl;
    }
    else
    {
        double* buff = new double[n - 1];
        for (int i = 0; i < index; i++)
        {
            buff[i] = arr[i];
        }
        for (int i = index; i < n; i++)
        {
            buff[i] = arr[i + 1];
        }
        delete[] arr;
        arr = buff;
        n -= 1;
    }
}

void exitelementon(int n, double*& arr)
{
        double* buff = new double[n - 1];
        for (int i = 0; i < n-1; i++)
        {
            buff[i] = arr[i+1];
        }
        delete[] arr;
        arr = buff;
        n =n- 1;
}

void exitelementend(int n, double*& arr)
{
    double* buff = new double[n - 1];
    for (int i = 0; i < n-1; i++)
    {
        buff[i] = arr[i];
    }
    delete[] arr;
    arr = buff;
    n =n- 1;
}

double *Addel(int n)
{
    double* arr = new double[n];
    return arr;
}

void input(int n, double* arr)
{
    ofstream f;
    f.open("massive.txt", ios::out | ios_base::trunc);
    int o = 0;
    do {
        arr[o] = rand() % 5 + 0.1 * (o + 1);
        f << arr[o] << endl;
        o = o + 1;
    } while (o < n);
    f.close();
}

void exit(int n, double* arr)
{
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
}

