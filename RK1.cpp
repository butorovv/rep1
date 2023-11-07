#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

int main() {
    
    int size;
    cout << "Enter the number of dishes: ";
    cin >> size;

    // Выделяем динамические массивы для имен и возрастов студентов
    char** names_of_dishes = new char*[size];
    int* number_of_servings = new int[size];
    float* cost_per_serving = new float[size];

    cin.ignore(); // очищаем буфер после ввода числа

    // Ввод имен и возрастов студентов
    for (int i = 0; i < size; ++i) {
        cout << "Enter the name of the dish " << i + 1 << ": ";
        char buffer[100];
        cin.getline(buffer, 100);
        names_of_dishes[i] = new char[strlen(buffer) + 1];
        strcpy(names_of_dishes[i], buffer);

        cout << "Enter the number of servings " << i + 1 << ": ";
        cin >> number_of_servings[i];
        
        cout << "Enter the cost per serving " << i + 1 << ": ";
        cin >> cost_per_serving[i];
        
        cin.ignore(); // очищаем буфер после ввода числа
    }

    // Сортировка блюд по алфавиту
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(names_of_dishes[j], names_of_dishes[j + 1]) > 0) {
                swap(names_of_dishes[j], names_of_dishes[j + 1]);
                swap(number_of_servings[j], number_of_servings[j + 1]);
                swap(cost_per_serving[j], cost_per_serving[j + 1]);
            }
        }
    }

    // Вывод отсортированного списка блюд
    cout << "\nSorted list of dishes:\n";
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ": " << names_of_dishes[i] << " - Quantity: " << number_of_servings[i] << ", Cost per serving: " << cost_per_serving[i] << endl;
    }

    // Вывод общей стоимости заказа
    cout << "\nTotal cost of all orders:";
    float total1;
    for (int i = 0; i < size; ++i) {
        total1 += number_of_servings[i]*cost_per_serving[i];
    }
    cout << " " << total1;
    

    // Освобождаем выделенную память
    for (int i = 0; i < size; ++i) {
        delete[] names_of_dishes[i];
    }
    delete[] names_of_dishes;
    delete[] number_of_servings;
    delete[] cost_per_serving;
    return 0;
}
