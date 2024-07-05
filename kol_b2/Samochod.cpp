#include "Samochod.h"
Samochod::Samochod() {
	//srand(12);

}
Samochod::Samochod(Num_rej r, int l, Dopuszczenie d, Wlasciciel w) {
	set_rejestracja(r);
	set_licznik(l);
	set_dop(d);
	set_wlasciciel(w);
}
void Samochod::set_rejestracja(Num_rej r) { this->rejestracja = r; }
void Samochod::set_rejestracja(char* tab) { strcpy_s(this->rejestracja.X, tab); }
void Samochod::set_licznik(int l) { this->licznik = l; }
void Samochod::set_wlasciciel(Wlasciciel w) { this->wlasciciel = w; }

Num_rej Samochod::get_dop() { return dopuszczenie; }