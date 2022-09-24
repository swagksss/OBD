#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Classes.h"
using namespace std;

vector<Zakaz>offers;
vector<Zamovnik> zamovniki;
void Update_Zakazy() {
    ofstream file;
    file.open("zakazy.txt");
    if (file.is_open()) {
        for (int i = 0; i < offers.size(); i++) {
            file << zamovniki[i].name << "\t" << zamovniki[i].email << "\t" << zamovniki[i].telephone << "\t" <<
                offers[i].price << "\t" << offers[i].data_zamovlennya <<
                "\t" << offers[i].data_zakinchennya << "\t" <<
                offers[i].reklama_type << endl << endl;
        }
    }
    else { cout << "Нелязя открыть файл!" << endl; }
}

void Update_Zamovniki() {
    ofstream file;
    file.open("zamovniki.txt");
    if (file.is_open()) {
        for (int i = 0; i < offers.size(); i++) {
            file << i << "\t" << zamovniki[i].name << "\t" <<
                zamovniki[i].email << "\t" << zamovniki[i].telephone << endl << endl;
        }
    }
    else { cout << "Нелязя открыть файл!" << endl; }
}

void Create_Offer() {
    fstream file;
    file.open("zakazy.txt");
    if (file.is_open()) {
        Zamovnik temp;
        Zakaz temp_zakaz;
        cout << "Введите ваше имя : "; cin >> temp.name;
        cout << "Введите email : "; cin >> temp.email;
        cout << "Введите номер телефона: "; cin >> temp.telephone;
        temp_zakaz.imya_zamovnik = temp.name;
        cout << "Введите тип рекламы : "; cin >> temp_zakaz.reklama_type;
        cout << "Дата начала : "; cin >> temp_zakaz.data_zamovlennya;
        cout << "Дата окончания : "; cin >> temp_zakaz.data_zakinchennya;
        cout << "Введите вашу цену : "; cin >> temp_zakaz.price;
        cout << "Заказ создан !" << endl << endl;
        zamovniki.push_back(temp);
        offers.push_back(temp_zakaz);
        Update_Zakazy();
        Update_Zamovniki();

    }
    else {
        cout << "Нелязя открыть файл!" << endl;
    }
}
void Menu_Zamovnik() {
    cout << "\t***Меню заказчика реклами***" << endl;
    cout << "1. Создать заказ" << endl;
    cout << "2. Просмотреть заказы˚" << endl;
    cout << "3. Изменить заказ" << endl;
    cout << "4. Выход" << endl;
}
void Print_Zakazy() {
    for (int i = 0; i < offers.size(); i++) {
        cout << offers[i].imya_zamovnik << "\t" << zamovniki[i].email << "\t" << zamovniki[i].telephone << "\t" <<
            offers[i].price << "\t" << offers[i].data_zamovlennya <<
            "\t" << offers[i].data_zakinchennya << "\t" <<
            offers[i].reklama_type << endl << endl;
    }
}
void Modify_Offer() {
    int input;
    Print_Zakazy();
    cout << "Введите номер заказа который хотите изменить : ";
    cin >> input;
    input--;
    cout << "Вы выбрали : " << endl;
    cout << "\t" << offers[input].imya_zamovnik << "\t" << offers[input].price << "UAH\t"
        << offers[input].data_zamovlennya << "\t" << offers[input].data_zakinchennya << endl << endl;
    cout << "Введите новое имя : "; cin >> offers[input].imya_zamovnik;
    cout << "Введите новую цену: "; cin >> offers[input].price;
    cout << "Введите дату начала : "; cin >> offers[input].data_zamovlennya;
    cout << "Введите дату окончания : "; cin >> offers[input].data_zakinchennya;
    cout << "Введите тип рекламы: "; cin >> offers[input].reklama_type;
    cout << "\tДанные изменены !" << endl;
    Update_Zakazy();

}
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
            Modify_Offer();
            break;
        case 4:
            cout << "Bye-bye";
            return;
        default:
            cout << "Error!" << endl << endl;

        }
    }
}
