#pragma once
#include "numer_rejestracyjny.h"
#include <iostream>
class Samochod
{
protected:
	static Num_rej ostatni;
	
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
	void set_licznik(int l);
	void set_dop(Dopuszczenie d);
	void set_wlasciciel(Wlasciciel w);

};

