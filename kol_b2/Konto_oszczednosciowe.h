#pragma once
#include "konto_bankowe.h"
#include <iomanip> 

class Konto_Oszczednosciowe : public Konto_Bankowe {
private: 
	double stopa_oprocentowania;
public:
	Konto_Oszczednosciowe();
	Konto_Oszczednosciowe(Konto_Bankowe kb);
	Konto_Oszczednosciowe(Konto_Bankowe kb, double so);
	~Konto_Oszczednosciowe();

	double get_stopa_oprocentowania();

	void set_stopa_oprocentowania(double so);
	void prognoza_za_rok() override;
};

