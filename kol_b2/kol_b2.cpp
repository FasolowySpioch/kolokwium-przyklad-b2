#include "Konto_Bankowe.h"

using namespace std;

int main()
{
	Konto_Bankowe kb;
	Konto_Bankowe::wypisz_aktywne();
	kb.~Konto_Bankowe();
	Konto_Bankowe::wypisz_aktywne();

}

