#pragma once
#include<iostream>
using namespace std;
class Zamovnik {
public:
	int kod_zamovnika;
	string name;
	string email;
	string telephone;
};
class Zakaz {
public:
	string imya_zamovnik;
	string reklama_type;
	string data_zamovlennya;
	string data_zakinchennya;
	float price;
};
class Vykonavec {
public:
	int vykonavec_id;
	string name;
	string portpholio;
	string ad_type;
	string phone;
};
