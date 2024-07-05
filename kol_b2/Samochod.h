#pragma once
#include "numer_rejestracyjny.h"
#include <iostream>
class Samochod
{
protected:
	static Num_rej ostatni;
	static void przypisanie_ost(Samochod s);


	Num_rej rejestracja;
	int licznik;
	Dopuszczenie dopuszczenie;
	Wlasciciel wlasciciel;
public:
	Samochod();
	Samochod(Num_rej r, int l, Dopuszczenie d, Wlasciciel w);
	~Samochod();
	
	void set_rejestracja(Num_rej r);
	void set_rejestracja(char* tab);
	void set_rejestracja(int* tab);
	void set_licznik(int l);
	void set_dop(Dopuszczenie d);
	void set_wlasciciel(Wlasciciel w);

	Num_rej get_rej();
	int get_licznik();
	Dopuszczenie get_dop();
	Wlasciciel get_wlasciciel();

	virtual double zasieg();

	double war_sam(Samochod s, double war_p);

	bool operator==(const Samochod& s) const;
	bool operator!=(const Samochod& s) const;
};

