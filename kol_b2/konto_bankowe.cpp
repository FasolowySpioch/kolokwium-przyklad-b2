#include "Konto_Bankowe.h"

int Konto_Bankowe::licznik_aktywnych = 0;

Konto_Bankowe::Konto_Bankowe() {
	strcpy_s(this->klient.imie, "Adam");
	strcpy_s(this->klient.nazwisko, "Nowak");
	this->aktywnosc = Aktywnosc::nieaktywny;
	this->stan_konta = 0.0;
	for (int i = 0; i < 26; i++) { this->numer_konta[i] = 0; }

	licz_aktywne(*this);
}
Konto_Bankowe::Konto_Bankowe(Klient k, Aktywnosc a, double sk, int* nk) {
	set_klient(k);
	set_aktywnosc(a);
	set_stan_konta(sk);
	set_numer_konta(nk);
	
	licz_aktywne(*this);
}
Konto_Bankowe::~Konto_Bankowe() { if (licznik_aktywnych != 0) licznik_aktywnych--; }

Klient Konto_Bankowe::get_klient() { return this->klient; }
Aktywnosc Konto_Bankowe::get_aktywnosc() { return this->aktywnosc; }
double Konto_Bankowe::get_stan_konta() { return this->stan_konta; }
int* Konto_Bankowe::get_numer_konta() { return this->numer_konta; }

void Konto_Bankowe::set_klient(Klient k) { this->klient = k; }
void Konto_Bankowe::set_klient(const char* i, const char* n) {
	strcpy_s(this->klient.imie, i);
	strcpy_s(this->klient.nazwisko, n);
}
void Konto_Bankowe::set_aktywnosc(Aktywnosc a) { this->aktywnosc = a; licz_aktywne(*this); }
void Konto_Bankowe::set_stan_konta(double sk) {
	if (sk > 1000000.0) { this->stan_konta = 1000000.0; }
	else if (sk == NULL) { this->stan_konta = 0.0; }
	else { this->stan_konta = sk; }
}
void Konto_Bankowe::set_numer_konta(int* nk) {
	for (int i = 0; i < sizeof(nk) / sizeof(int) && i < 26; i++) {
		if (nk[i] != NULL) {
			this->numer_konta[i] = nk[i];
		}
		else {
			this->numer_konta[i] = 0;
		}
	}
	for (int i = sizeof(nk) / sizeof(int); i < 26; i++) {
		if (nk[i] != NULL) {
			this->numer_konta[i] = nk[i];
		}
		else {
			this->numer_konta[i] = 0;
		}
	}
}

void Konto_Bankowe::wypisz_aktywne() {
	std::cout << "AKTYWNE KONTA: " << Konto_Bankowe::licznik_aktywnych << std::endl;
}
void Konto_Bankowe::licz_aktywne(Konto_Bankowe kb) {
	if (kb.aktywnosc == Aktywnosc::aktywny) {
		if (licznik_aktywnych == NULL) { licznik_aktywnych = 1; }
		licznik_aktywnych++;
	}
	else {
		if (licznik_aktywnych == NULL) licznik_aktywnych = 0; 
		if (licznik_aktywnych != 0) licznik_aktywnych--;
	}
}