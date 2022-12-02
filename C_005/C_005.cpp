#include <iostream>
#define byte char
using namespace std;

//Задание 1. Написать следующие функции для работы с динамическим массивом :
//■ Функция распределения динамической памяти.
void* task01(int number_of_bytes)
{
    byte* arr = new byte[number_of_bytes];
    return arr;
}
//■ Функция инициализации динамического массива.
int* task02(int len)
{
    int* arr = new int[len];
    return arr;
}

//■ Функция печати динамического массива.
void task03(int* arr, int len)
{
    int* current;
    current = arr;
    while (current < arr + len)
    {
        cout << *current++ << ", ";
    }
    cout << endl;
}

//■ Функция удаления динамического массива.
void task04(int* arr)
{
    delete[] arr;
}

//■ Функция добавления элемента к концу массива.
int* task05(int* arr, int len, int el)
{
    int* arr2 = new int[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        *(arr2 + i) = *(arr + i);
    }
    *(arr2 + len) = el;
    return arr2;
}

//■ Функция вставки элемента по указанному индексу.
int* task06(int* arr, int len, int el, int index)
{
    int* arr2 = new int[len + 1];
    for (size_t i = 0; i < index; i++)
    {
        *(arr2 + i) = *(arr + i);
    }
    *(arr2 + index) = el;
    for (size_t i = index; i < len + 1; i++)
    {
        *(arr2 + 1 + i) = *(arr + i);
    }
    return arr2;

}

//■ Функция удаления элемента по указанному индексу.
int* task07(int* arr, int len, int index)
{
    int* arr2 = new int[len - 1];
    for (size_t i = 0; i < index; i++)
    {
        *(arr2 + i) = *(arr + i);
    }
    for (size_t i = index; i < len - 1; i++)
    {
        *(arr2 + i) = *(arr + i + 1);
    }
    return arr2;
}

//Задание 2. Написать функцию, получающую указатель на динамический массив и его размер.Функция должна удалить из массива все простые числа.
bool check(int num)
{
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int* task08(int* arr, int* len)
{
    int n = 0;
    int* arr2 = new int[n];
    for (size_t i = 0; i < *len; i++)
    {
        if (!check(*(arr + i)))
        {
            arr2 = task05(arr2, n++, *(arr + i));
        }
    }
    *len = n;
    return arr2;
}

//Задание 3. Написать функцию, получающую указатель на массив и его размер.Функция распределяет положительные, отрицательные и нулевые элементы в отдельные динамические массивы.
void task09(int* arr, int len, int** pArr, int* lenPArr, int** nArr, int* lenNArr, int** nullArr, int* lenNullArr)
{
    *pArr = new int[0];
    *nArr = new int[0];
    *nullArr = new int[0];
    *lenPArr = 0;
    *lenNArr = 0;
    *lenNullArr = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (*(arr+i) < 0)
        {
            *nArr = task05(*nArr, (*lenNArr)++, *(arr + i));
        }
        else if (*(arr + i) > 0)
        {
            *pArr = task05(*pArr, (*lenPArr)++, *(arr + i));
        }
        else
        {
            *nullArr = task05(*nullArr, (*lenNullArr)++, *(arr + i));
        }
    }
}

int main()
{
    srand(time(0));

    cout << "task 01" << endl;
    const int n1 = 9;
    int* p1_1;
    p1_1 = (int*)task01(n1 * sizeof(int));
    int* p1_2;
    p1_2 = p1_1;
    while (p1_2 < p1_1 + n1)
    {
        *p1_2++ = rand()%10;
    }
    task03(p1_1, n1);
    delete[] p1_1;

    cout << "task 02" << endl;
    const int n2 = 9;
    int* p2_1 = task02(9);
    int* p2_2;
    p2_2 = p2_1;
    while (p2_2 < p2_1 + n2)
    {
        *p2_2++ = rand() % 10;
    }
    task03(p2_1, n2);
    delete[] p2_1;

    cout << "task 03" << endl;
    int* p3 = new int[3]{ 1, 2, 3 };
    task03(p3, 3);
    delete[] p3;

    cout << "task 04" << endl;
    int* p4 = new int[3] { 1, 2, 3 };
    cout << *p4 << ", " << *p4 + 1 << ", " << *p4 + 2 << endl;
    task04(p4);
    cout << *p4 << ", " << *p4 + 1 << ", " << *p4 + 2 << endl;

    cout << "task 05" << endl;
    int* p5 = new int[3] {1, 2, 3};
    task03(p5, 3);
    p5 = task05(p5, 3, 4);
    task03(p5, 4);
    delete[] p5;

    cout << "task 06" << endl;
    int* p6 = new int[3] {1, 3, 4};
    task03(p6, 3);
    p6 = task06(p6, 3, 2, 1);
    task03(p6, 4);
    delete[] p6;

    cout << "task 07" << endl;
    int* p7 = new int[4] {1, 7, 2, 3};
    task03(p7, 4);
    p7 = task07(p7, 4, 1);
    task03(p7, 3);
    delete[] p7;

    cout << "task 08" << endl;
    int* n8 = new int(30);
    int* p8 = new int[*n8];
    for (size_t i = 0; i < *n8; i++)
    {
        *(p8 + i) = rand() % 10;
    }
    task03(p8, *n8);
    p8 = task08(p8, n8);
    task03(p8, *n8);

    cout << "task 09" << endl;
    const int n9 = 25;
    int* p9 = new int[n9];
    for (size_t i = 0; i < n9; i++)
    {
        *(p9 + i) =( rand() % 19) - 9;
    }
    task03(p9, n9);

    int* lenPArr = new int;
    int* lenNArr = new int;
    int* lenNullArr = new int;
    int** pArr = new int*;
    int** nArr = new int*;
    int** nullArr = new int*;
    task09(p9, n9, pArr, lenPArr, nArr, lenNArr, nullArr, lenNullArr);

    cout << "pArr" << endl;
    task03(*pArr, *lenPArr);
    cout << "nArr" << endl;
    task03(*nArr, *lenNArr);
    cout << "nullArr" << endl;
    task03(*nullArr, *lenNullArr);
}