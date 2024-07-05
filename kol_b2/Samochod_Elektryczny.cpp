#include "Samochod_Elektryczny.h"
Samochod_Elektryczny::Samochod_Elektryczny() { this->stan_baterii = 0; }
Samochod_Elektryczny::Samochod_Elektryczny(Samochod s) : Samochod(s) { this->stan_baterii = 0; }
Samochod_Elektryczny::Samochod_Elektryczny(Samochod s, double b) : Samochod(s) { set_bateria(b); }

void Samochod_Elektryczny::set_bateria(double b) {
	if (b > 100) { this->stan_baterii = 100; }
	else if (b < 0) { this->stan_baterii = 0; }
	else { this->stan_baterii = b; }
}

double Samochod_Elektryczny::zasieg() {
	return 2.5 * stan_baterii;
}

