#pragma once
#include "klient.h"
#include <cstring>
#include <iostream>

class Konto_Bankowe{
private: 
	static int licznik_aktywnych;

	Klient klient;
	Aktywnosc aktywnosc;
	double stan_konta;
	int numer_konta[26];

	static void licz_aktywne(Konto_Bankowe kb);
public:
	Konto_Bankowe();
	Konto_Bankowe(Klient k, Aktywnosc a, double sk, int* nk);
	~Konto_Bankowe();

	Klient get_klient();
	Aktywnosc get_aktywnosc();
	double get_stan_konta();
	int* get_numer_konta();

	void set_klient(Klient k);
	void set_klient(const char* i, const char* n);
	void set_aktywnosc(Aktywnosc a);
	void set_stan_konta(double sk);
	void set_numer_konta(int* nk);

	static void wypisz_aktywne();

	virtual void prognoza_za_rok();
};

