#include "klient.h"
#include <cstring>

class Konto_Bankowe {
private:
	Klient klient;
	Aktywnosc aktywnosc;
	double stan_konta;
	int numer_konta[26];
public:
	Konto_Bankowe() {
		strcpy(klient.imie, "Adam");
		strcpy(klient.nazwisko, "Nowak");
		aktywnosc = Aktywnosc::nieaktywny;
		stan_konta = 0.0;
		for (int i = 0; i < 26; i++) { numer_konta[i] = 0; }
	}
	Konto_Bankowe(Klient k, Aktywnosc a, double sk, int* nk) {
		klient = k;
		aktywnosc = a;
		stan_konta = sk;
		set_numer_konta(nk);
	}
	~Konto_Bankowe() {}

	//gettery
	Klient get_klient() { return klient; }
	Aktywnosc get_aktywnosc() { return aktywnosc; }
	double get_stan_konta() { return stan_konta; }
	int* get_numer_konta() { return numer_konta; }
	//settery
	void set_klient(Klient k) { klient = k; }
	void set_klient(char* i, char* n) { strcpy(klient.imie, i); strcpy(klient.nazwisko, n); }
	void set_aktywnosc(Aktywnosc a) { aktywnosc = a; }
	void set_stan_konta(double sk) {
		if (sk > 1000000.0) { stan_konta = 100000.0; }
		else if (sk < 0) { stan_konta = 0; }
		else { stan_konta = sk; }
	}
	void set_numer_konta(int* nk) {
		if (sizeof(nk) / sizeof(int) < 26) {
			for (int i = 0; i < sizeof(nk) / sizeof(int); i++) {
				numer_konta[i] = nk[i];
			}
			for (int i = sizeof(nk) / sizeof(int); i < 26; i++) { numer_konta[i] = 0; }
		}
		else {
			for (int i = 0; i < 26; i++) { numer_konta[i] = nk[i]; }
		}
	}
};