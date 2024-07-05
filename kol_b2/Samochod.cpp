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
}
void Samochod::set_licznik(int l) { this->licznik = l; }
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