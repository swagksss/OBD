#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Classes.h"
using namespace std;

vector<Zakaz>offers;
vector<Zamovnik> zamovniki;

// Обновить информацию о заказах в файле
void Update_Zakazy() {
    ofstream file;
    file.open("zakazy.txt");
    if (file.is_open()) {
        for (int i = 0; i < offers.size(); i++) {
            file << zamovniki[i].name << "\t" << zamovniki[i].email << "\t" << zamovniki[i].telephone << "\t" <<
                offers[i].price << "\t" << offers[i].data_zamovlennya <<
                "\t" << offers[i].data_zakinchennya << "\t" <<
                offers[i].reklama_type << endl;
        }
    }
    else { cout << "Нельзя открыть файл!" << endl; }
}
// Обновить информацию о замовниках в файле
void Update_Zamovniki() {
    ofstream file;
    file.open("zamovniki.txt");
    if (file.is_open()) {
        for (int i = 0; i < offers.size(); i++) {
            file << i + 1 << "\t" << zamovniki[i].name << "\t" <<
                zamovniki[i].email << "\t" << zamovniki[i].telephone << endl;
        }
    }
    else { cout << "Нельзя открыть файл!" << endl; }
}
// Функция создания заказа и записывания его в файл
void Create_Offer() {
    fstream file;
    file.open("zakazy.txt");
    if (file.is_open()) {
        Zamovnik temp;
        Zakaz temp_zakaz;
        cout << "Введите имя заказчика : "; cin >> temp.name;
        cout << "Введите email: "; cin >> temp.email;
        cout << "Введите номер телефона: "; cin >> temp.telephone;
        temp_zakaz.imya_zamovnik = temp.name;
        cout << "Введите тип рекламы: "; cin >> temp_zakaz.reklama_type;
        cout << "Дата начала: "; cin >> temp_zakaz.data_zamovlennya;
        cout << "Дата окончания: "; cin >> temp_zakaz.data_zakinchennya;
        cout << "Введите цену заказа: "; cin >> temp_zakaz.price;
        cout << "Заказ создан!" << endl << endl;
        zamovniki.push_back(temp);
        offers.push_back(temp_zakaz);
        Update_Zakazy();
        Update_Zamovniki();
    }
    else {
        cout << "Нельзя открыть файл!" << endl;
    }
}
// Функция выведения меню замовника
void Menu_Zamovnik() {
    cout << "\t***Меню замовника рекламы***" << endl;
    cout << "1. Создать заказ" << endl;
    cout << "2. Просмотреть заказы" << endl;
    cout << "3. Просмотреть заказы" << endl;
    cout << "4. Изменить заказ" << endl;
    cout << "5. Удалить заказ" << endl;
    cout << "6. Просмотреть количество заказов" << endl;
    cout << "7. Выход" << endl;
}
// Функция выведения всех заказов
void Print_Zakazy() {
    for (int i = 0; i < offers.size(); i++) {
        cout << i + 1 << "\t" << offers[i].imya_zamovnik << "\t" << zamovniki[i].email << "\t" << zamovniki[i].telephone << "\t" <<
            offers[i].price << "_UAH\t" << offers[i].data_zamovlennya <<
            "\t" << offers[i].data_zakinchennya << "\t" <<
            offers[i].reklama_type << endl << endl;
    }
void Print_Zamovniki() {
    for (int i = 0; i < zamovniki.size(); i++) {
        cout << i + 1 << "\t" << zamovniki[i].imya_zamovnik << "\t" << zamovniki[i].email <<"\t" << zamovniki[i].telephone << "\t" <<
        zamovniki[i].price << "_UAH\t" << zamovniki[i].data_zamovlennya <<
            "\t" << zamovniki[i].data_zakinchennya << "\t" <<
        zamovniki[i].reklama_type << endl << endl;
    }
}
// Функция изменения заказа
void Modify_Offer() {
    int input;
    Print_Zakazy();
    cout << "Введите номер заказа который хотите изменить : ";
    cin >> input;
    input--;
    cout << "Вы выбрали: " << endl;
    cout << "\t" << offers[input].imya_zamovnik << "\t" << offers[input].price << "_UAH\t"
        << offers[input].data_zamovlennya << "\t" << offers[input].data_zakinchennya << "\t" << offers[input].reklama_type << endl << endl;

    cout << "Введите новый тип рекламы: "; cin >> offers[input].reklama_type;
    cout << "Введите дату начала : "; cin >> offers[input].data_zamovlennya;
    cout << "Введите дату окончания рекламы: "; cin >> offers[input].data_zakinchennya;
    cout << "Введите новую цену: "; cin >> offers[input].price;

    cout << "\tДанные изменены!" << endl;
    Update_Zakazy();

}
// Функция удаления заказа
void Delete_Offer() {
    int input;
    Print_Zakazy();
    cout << "\t Введите номер заказа , который желаете удалить: "; cin >> input;
    input--;
    offers.erase(offers.begin() + input);
    zamovniki.erase(zamovniki.begin() + input);
    Update_Zakazy();
    Update_Zamovniki();


}
// Подсчет кол-ва заказов записаных в файл
int Calculate_Offers() {
    ifstream file;
    char str[256];
    int i = 0;
    file.open("zakazy.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            file.getline(str, 256);
            i++;
        }
        return i;
    }
    else {
        cout << "Нельзя открыть файл \"zakazy.txt\"" << endl << endl;
    }
}
// ŒÒÌÓ‚ÌÓÂ ÏÂÌ˛
void Zamovnik_() {
    int input;
    while (true) {
        Menu_Zamovnik();
        cout << "Выберите функцию : ";
        cin >> input;
        switch (input)
        {
        case 1:
            Create_Offer();
            break;
        case 2:
            Print_Zakazy();
            break;
        case 3:
            Print_Zamovniki();
            break;
        case 3:
            Modify_Offer();
            break;
        case 4:
            Delete_Offer();
            break;
        case 5:
            cout << " Количество заказов: " << Calculate_Offers() - 1 << endl;
            break;
        case 6:
            cout << "\tДосвидания!" << endl << endl;
            return;
        default:
            cout << "Error!" << endl << endl;
        }
    }
}

