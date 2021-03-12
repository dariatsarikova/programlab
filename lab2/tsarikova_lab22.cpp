

#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void transpon(int** M1, int** M2, int n);
void getrand(double** M, int n, int a, int b);
int Getr();
void NewPam(double**& M, int n);
void deleted(double**& M, int n);
bool Getisfile(double** M, int n, const char* name);
void printed(double** M, int n, const char* name);
void Mult(int** M1, int** M2, int** res, int n1, int n2);
void triangmatr(double** A, double** B, int n);
void solve(double** A, double* x, int n);
void printedvect(double* M, int n, const char* name);
double opred(double** M, int n);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int key;

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
            int n,m;
            cout << " < Задание " << key << " > " << endl;
            n=Getr();
            m = n + 1;
            double* x = new double[n];
            double** A;
            NewPam(A, n);
            if (!Getisfile(A, n, "file.txt"))
                return 0;
            printed(A, n, "A");
            solve(A, x, n);
            printedvect(x, n, "x");
            deleted(A, n);
            delete[]x; x = NULL;
        }
        else if (key == 2)
        {
            int n,m;
            cout << " < Задание " << key << " > " << endl;
            n = Getr();
            m = n + 1;
            double* x = new double[n];
            double** A;
            NewPam(A, n);
            if (!Getisfile(A, n, "file2.txt"))
                return 0;
            printed(A, n, "A");
            solve(A, x, n);
            printedvect(x, n, "x");
            deleted(A, n);
            delete[]x; x = NULL;
        }
        else if (key == 3)
        {
            int n;
            cout << " < Задание " << key << " > " << endl;
            n = Getr();
            double* x = new double[n];
            double** A;
            NewPam(A, n);
            getrand(A, n, 1, 10);
            if (!Getisfile(A, n, "file3.txt"))
                return 0;
            printed(A, n, "A");
            solve(A, x, n);
            printedvect(x, n, "x");
            deleted(A, n);
            delete[]x; x = NULL;
        }
        else if (key == 4)
        {
            int n;
            double res,res2=1.0;
            cout << " < Задание " << key << " > " << endl;
            n = Getr();
            if (n == 2)
            {
                double* x = new double[n];
                double** A;
                NewPam(A, n);
                if (!Getisfile(A, n, "file4.txt"))
                    return 0;
                res = A[0][0]*A[1][1]+A[0][1]*A[1][0];
                cout << "Определитель матрицы =" << res << endl;
                deleted(A, n);
            }
            else
            {
                double* x = new double[n];
                double** A;
                NewPam(A, n);
                if (!Getisfile(A, n, "file4.txt"))
                    return 0;
                res = opred(A, n);
                cout << "Определитель матрицы =" << res << endl;
                deleted(A, n);
            }
        }
        else if (key == 5)
        {
            cout << " < Задание " << key << " > " << endl;
        }
        else
        {
            cout << " -->Такого номера задания нет.:( Попробуйте другое." << endl;
            //обработка номера несуществующего задания
        }

    } while (key != 0);
    return 0;
}

void transpon(int** M1, int** M2, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n+1; j++)
            M1[i][j] = M2[j][i];
}

void getrand(double** M, int n, int a, int b)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n+1; j++)
            M[i][j] = rand() % (b - a - 1) + a;
    printed(M, n, "file3.txt");
}

int Getr()
{
    double n;
    do
    {
        cout << "Введите (целое,положительное) значение т.е. размерность матрицы." << endl;
        cin >> n;
        if (n <= 0 || (n - (int)n))
            cout << "Ошибка, вы ввели некоректное число размерности. Напоминаем, значение должно быть целым и положительным." << endl;
    } while (n <= 0 || (n - (int)n));
    return n;
}

void NewPam(double**& M, int n)
{
    cout << "Выделение памяти под расширенную матрицу" << endl;
    M = new double* [n];
    for (int i = 0; i < n; i++)
        M[i] = new double[n + 1];
}

void deleted(double**& M, int n)
{
    cout << "Освобождение памяти из под матрицы" << endl;
    for (int i = 0; i < n; i++)
        delete[]M[i];
    delete[]M;
}

bool Getisfile(double** M, int n, const char* name)
{
    ifstream f(name);
    if (!f)
    {
        cout << "Ошибка, файла не существует" << endl;
            return false;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            f >> M[i][j];
    f.close();
    return true;
}

void printed(double** M, int n, const char* name)
{
    ofstream f(name);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
            f << setw(5) << M[i][j];
        f << endl;
    }
    f << endl;
    f.close();
}

void Mult(int** M1, int** M2, int** res, int n1, int n2)
{
    int s;
    if (n1 + 1 != n2)
    {
        cout << "Ошибка, матрица задана не корректно" << endl;
        return;
    }
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2 + 1; j++)
        {
            s = 0;
            for (int k = 0; k < n1 + 1; k++)
                s += M1[i][k] * M2[k][j];
            res[i][j] = s;
        }
}

void triangmatr(double** A, double** B, int n)
{
    double koef;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            B[i][j] = A[i][j];
    for (int k = 0; k < n; k++)
        for (int i = k + 1; i < n; i++)
        {
            koef = -1. * B[i][k] / B[k][k];
            for (int j = k; j < n + 1; j++)
                B[i][j] = B[i][j] + B[k][j] * koef;
        }
    printed(B, n, "B");
}

void solve(double** A, double* x, int n)
{

    double res = 0;
    double** B;
    NewPam(B, n);
    triangmatr(A, B, n);
    for (int i = n - 1; i >= 0; i--)
    {
        res = 0;
        for (int j = i + 1; j <= n - 1; j++)
            res = res - x[j] * B[i][j];
        res += B[i][n];
        x[i] = res / B[i][i];
    }
    deleted(B, n);
}

void printedvect(double* M, int n, const char* name)
{
    ofstream f(name);
    for (int i = 0; i < n; i++)
        f  << M[i]<<endl;
    f << endl;
    f.close();
}

double opred(double** A, int n)
{
    double res = 1.0;
    double** B;
    NewPam(B, n);
    triangmatr(A, B, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n+1; j++)
        {
            if (i == j)
                res = res * B[i][j];
            cout << res;
        }
    deleted(B, n);
    return res;
}
