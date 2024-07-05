#include "Samochod.h"
Samochod::Samochod() {
	//srand(12);
	for (int i = 0; i < 5; i++) {
		this->rejestracja.Y[0] = 0;
	}
	licznik = 0;
	dopuszczenie = Dopuszczenie::niedop;
	strcpy_s(this->wlasciciel.imie, "Adam");
	strcpy_s(this->wlasciciel.nazwisko, "Nowak");

	przypisanie_ost(*this);
}
Samochod::Samochod(Num_rej r, int l, Dopuszczenie d, Wlasciciel w) {
	set_rejestracja(r);
	set_licznik(l);
	set_dop(d);
	set_wlasciciel(w);
}
void Samochod::set_rejestracja(Num_rej r) { this->rejestracja = r; }
void Samochod::set_rejestracja(char* tab) { strcpy_s(this->rejestracja.X, tab); }
void Samochod::set_rejestracja(int* tab) { 
	for (int i = 0; i < 5; i++) {
		this->rejestracja.Y[i] = tab[i];
	}

	przypisanie_ost(*this);
}
void Samochod::set_licznik(int l) { 
	if (l < 0) { this->licznik = 0; }
	if (l > 360000) { this->licznik = 360000; }
	else { this->licznik = l; }
}
void Samochod::set_dop(Dopuszczenie d) { this->dopuszczenie = d; }
void Samochod::set_wlasciciel(Wlasciciel w) { this->wlasciciel = w; }

Num_rej Samochod::get_rej() { return rejestracja; }
int Samochod::get_licznik() { return licznik; }
Dopuszczenie Samochod::get_dop() { return dopuszczenie; }
Wlasciciel Samochod::get_wlasciciel() { return wlasciciel; }

void Samochod::przypisanie_ost(Samochod s) {
	if (ostatni.Y[0] == NULL) {
		for (int i = 0; i < 5; i++) {
			ostatni.Y[i] = 0;
		}
	}
	else {
		for (int i = 0; i < 5; i++) {
			ostatni.Y[i]++;
		}
	}
}

double Samochod::zasieg() {
	return 800.0;
}

double Samochod::war_sam(Samochod s, double war_p) {
	if (war_p < 400) war_p = 400;
	if (s.dopuszczenie == Dopuszczenie::dop) { return (war_p - (0.1 * licznik)) * 1.0; }
	else{return (war_p - (0.1 * licznik)) * 0.2;}
}

bool Samochod::operator==(const Samochod& s) const {
	if (strcmp(rejestracja.X, s.rejestracja.X) && licznik - s.licznik <= 10 || licznik - s.licznik >=  ( - 10)) { return true; }
	else { return false; }
}
bool Samochod::operator!=(const Samochod& s) const {
	return !(*this == s);
}	