
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

void ex1() {
    string bufer[10];
    int max = 0;
    ifstream file("doc1.txt");
    if (file.is_open()) {
        int i = 1;
        string get;
        while (!file.eof()) {
            getline(file, get);
            bufer[i] = get;
            i = i + 1;
            max = i;
        }
        file.close();
    } else {
        cout << "Файл не открыт!\n" << endl;
    }

    for (int i = 0; i < max; i++) {
        cout << bufer[i] << "\n";
    }
}

void ex2() {
    cout << "Массив, состоящий из 1000 случайных чисел:\n\n";
    int array[1000];

    for (int i = 0; i < 1000; i++) {
        array[i] = 1 + rand() % 1000;
        cout << setw(5) << array[i] << setw(5);
    }
}

void ex3() {

    int array[1000];

    for (int i = 0; i < 1000; i++) {
        array[i] = 1 + rand() % 1000;
    }
    ofstream Endfile("doc.txt");
    if (Endfile.is_open()) {
    } else {
        cout << "Файл не открыт!\n";
    }
    for (int i = 0; i < 1000; i++) {
        Endfile << array[i] << "\n";
    }
    Endfile.close();

    int mass[1000];
    string st;
    int i = 0;

    ifstream rate("doc.txt");
    if (rate.is_open()) {
    } else {
        cout << "Файл не открыт!\n";
    }

    while (!rate.eof()) {
        getline(rate, st);
        mass[i] = atoi(st.c_str());
        i = i + 1;
    }
    rate.close();

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000 - i; j++) {
            if (mass[j] < mass[j + 1])
            {
                int temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }
        }
    }


    for (i = 0; i < 1000; i++) {
        cout << setw(5) << mass[i] << setw(5);
    }
    cout << "\n";
}

int fact(int n)
{
    if (n == 0) {
        return 1;
    }
    else {
        return n * fact(n - 1);
    }
}

void fmax() {
    int b = 1;
    while (fact(b) != 0) {
        b = b + 1;
    }
    cout << "Максимальное n для которого факториал числа может быть вычислен для чисел типа integer: " << b - 1 << ".\n\n";
}


int main()
{

    setlocale(0, "");

    int ex;
    cout << "Укажите номер задания: ";
    cin >> ex;

    switch (ex) {
    case(1):
        cout << "Задание 1\n\n";
        ex1();
        break;

    case(2):
        cout << "\n\nЗадание 2\n\n";
        ex2();
        break;

    case(3):
        cout << "\n\nЗадание 3\n\n";
        ex3();
        break;

    case(5):
        cout << "\n\nЗадание 5\n\n";
        int n;
     
        cout << "Введите целое положительное число, для которого будет посчитан факториал: ";
        cin >> n;
        if (n < 0) {
            cout << "\nВведенное число не соответствует условию.\n";
        } else {
            cout << "\nФакториал числа " << n << " = " << fact(n) << "\n\n";
        }
        fmax();
        break;

    default: 
        cout << "\nУказан неправильный номер.\n";
        break;
    }
    return 0;
}
