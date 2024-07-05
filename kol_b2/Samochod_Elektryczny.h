#pragma once
#include "Samochod.h"
class Samochod_Elektryczny : public Samochod
{
protected: 
	int stan_baterii;
public:
	Samochod_Elektryczny();
	Samochod_Elektryczny(Samochod s);
	Samochod_Elektryczny(Samochod s, double b);
	~Samochod_Elektryczny();

	double get_bateria();
	void set_bateria();

	double zasieg() override;
};

