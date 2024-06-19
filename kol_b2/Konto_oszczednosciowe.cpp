#include "Konto_oszczednosciowe.h"

Konto_Oszczednosciowe::Konto_Oszczednosciowe() { this->stopa_oprocentowania = 0.005; }
Konto_Oszczednosciowe::Konto_Oszczednosciowe(Konto_Bankowe kb) : Konto_Bankowe(kb) { this->stopa_oprocentowania = 0.005; }
Konto_Oszczednosciowe::Konto_Oszczednosciowe(Konto_Bankowe kb, double so) : Konto_Bankowe(kb) { set_stopa_oprocentowania(so); }
Konto_Oszczednosciowe::~Konto_Oszczednosciowe() {}

double Konto_Oszczednosciowe::get_stopa_oprocentowania() { return this->stopa_oprocentowania; }

void Konto_Oszczednosciowe::set_stopa_oprocentowania(double so) {
	if (so < 0.005) { this->stopa_oprocentowania = 0.005; }
	else if (so > 0.055) { this->stopa_oprocentowania = 0.055; }
	else { this->stopa_oprocentowania = so; }
}

void Konto_Oszczednosciowe::prognoza_za_rok(){
	double obl = get_stan_konta();
	obl *= (1 + stopa_oprocentowania);
	std::cout << "PROGNOZA STANU KONTA ZA ROK: " << std::fixed << std::setprecision(2) << obl << std::endl;
}