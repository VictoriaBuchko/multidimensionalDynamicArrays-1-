//ДЛЯ УДОБСТВА 2 ЗАДАНИЕ ЗАКОМЕНТИРОВАНО( 91 СТРОЧКА )

#include <iostream>
using namespace std;

//Задание 1. Транспонирование матрицы — это операция,
//после которой столбцы прежней матрицы становятся строками, а строки столбцами.Напишите функцию
//транспонирования матрицы.

// Функция для транспонирования матрицы
int** transMatrix(int** matrix, int rows, int cols, int** transposedMatrix) {


    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            transposedMatrix[j][i] = matrix[i][j];//меняем индексы столбцов со строками в цикле
        }
    }
    return transposedMatrix;
}

int main() {
    int rows = 3; // Строки
    int cols = 4; // Столбцы

    /*создаем двумерный массив
    Сначала создаётся одномерный массив указателей, а затем каждому элементу этого массива присваивается адрес одномерного массива*/
    int** matrix = new int* [rows];

    for (int i = 0; i < rows; i++) {

        matrix[i] = new int[cols];

        for (int j = 0; j < cols; j++) { //для понимания сразу инициализируем матрицу тут 

            matrix[i][j] = i + cols + j;
        }
    }


    int** transposedMatrix = new int* [cols];//создаем матрицу для результатов над 1 матрицой
    for (int i = 0; i < cols; i++) {

        transposedMatrix[i] = new int[rows];
    }

    transposedMatrix = transMatrix(matrix, rows, cols, transposedMatrix);

    // Вывод исходной матрицы
    cout << "Original matrix:" << endl;
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Вывод транспонированной матрицы
    cout << "Transposed matrix:" << endl;

    for (int i = 0; i < cols; i++) {

        for (int j = 0; j < rows; j++) {

            cout << transposedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // освобождение памяти
    for (int i = 0; i < rows; i++) {//очищаем память 1 матрицы
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < cols; i++) {//очищаем память 2 матрицы

        delete[] transposedMatrix[i];
    }
    delete[] transposedMatrix;

    return 0;
}


//Задание 2. Создайте динамический массив, хранящий
//в первой строке имя, а во второй — телефон.Организуйте поиск по имени и по номеру телефона и возможность
//ввода и изменения данных.

/*
void AddContact(char **names, char **phoneNumbers, int& contactCount, const int contact);
void FindContactByName(char** names, char** phoneNumbers, int contactCount);
void FindContactByNumber(char** names, char** phoneNumbers, int contactCount);
void EditContact(char **names, char **phoneNumbers, int contactCount);


int main() {
    setlocale(LC_CTYPE, "ukr");

    const int contact = 5; // Максимальное количество контактов
    int contactCount = 0; // Текущее количество контактов

    char** names = new char* [contact]; // Динамический массив для имен
    char** phoneNumbers = new char* [contact]; // Динамический массив для номеров телефонов

    for (int i = 0; i < contact; i++) {
        names[i] = new char[50];
        phoneNumbers[i] = new char[14];
    }

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить контакт\n";
        cout << "2. Найти контакт по имени\n";
        cout << "3. Найти контакт по номеру телефона\n";
        cout << "4. Изменить данные контакта\n";
        cout << "5. Выйти\n";

        int choice;
        cout << "Выберите действие: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            AddContact(names, phoneNumbers, contactCount, contact);
            break;

        case 2:
            FindContactByName(names, phoneNumbers, contactCount);
            break;

        case 3:
            FindContactByNumber(names, phoneNumbers, contactCount);
            break;

        case 4:
            EditContact(names, phoneNumbers, contactCount);
            break;

        case 5:
            // Освобождаем память
            for (int i = 0; i < contact; i++) {

                delete[] names[i];
                delete[] phoneNumbers[i];
            }
            delete[] names;
            delete[] phoneNumbers;
            return 0;

        default:
            cout << "Неверный выбор. Попробуйте еще раз\n\n";
        }
    }

    return 0;
}

void AddContact(char **names, char **phoneNumbers, int& contactCount, const int contact) {

    if (contactCount < contact) {//проверка на то возможно еще добавить номер 

        cout << "Введите имя: ";
        cin >> names[contactCount];

        cout << "Введите номер телефона: ";
        cin >> phoneNumbers[contactCount];

        contactCount++;
    }
    else {
        cout << "Достигнут максимальный лимит контактов\n";
    }

}

void FindContactByName(char **names, char **phoneNumbers, int contactCount) {

    if (contactCount > 0) {//проверка на наличие контактов 

        char searchName[50];//создаем масив для ввода имя для поиска
        cout << "Введите имя для поиска: ";
        cin >> searchName;

        bool found = false;
        for (int i = 0; i < contactCount; i++) {

            if (strcmp(names[i], searchName) == 0) {//метод (strcmp) равнивает две строки

                cout << "Найден контакт: " << names[i] << "\n" << phoneNumbers[i] << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Контакт с таким именем не найден\n";
        }
    }
    else {
        cout << "Нет добавленных контактов\n\n";
    }

}

void FindContactByNumber(char **names, char **phoneNumbers, int contactCount) {

    if (contactCount > 0) {//проверка на наличие контактов 

        char searchNumber[15];//создаем масив для ввода телефона для поиска
        cout << "Введите номер телефона для поиска: ";
        cin >> searchNumber;

        bool found = false;
        for (int i = 0; i < contactCount; i++) {

            if (strcmp(phoneNumbers[i], searchNumber) == 0) {//метод (strcmp) равнивает две строки

                cout << "Найден контакт: " << names[i] << "\n" << phoneNumbers[i] << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Контакт с таким номером телефона не найден\n\n";
        }
    }
    else {
        cout << "Нет добавленных контактов\n\n";
    }
}


void EditContact(char **names, char **phoneNumbers, int contactCount) {

    if (contactCount > 0) {//проверка на наличие контактов 

        char searchName[50];//создаем масив для ввода имя для поиска
        cout << "Введите имя контакта, данные которого вы хотите изменить: ";
        cin >> searchName;

        bool found = false;
        for (int i = 0; i < contactCount; i++) {

            if (strcmp(names[i], searchName) == 0) {//метод (strcmp) равнивает две строки

                cout << "Введите новое имя: ";
                cin >> names[i];

                cout << "Введите новый номер телефона: ";
                cin >> phoneNumbers[i];

                cout << "Данные контакта успешно изменены\n\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Контакт с таким именем не найден\n\n";
        }
    }
    else {
        cout << "Нет добавленных контактов\n\n";
    }

}


*/