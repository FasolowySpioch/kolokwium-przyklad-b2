#include "Konto_Bankowe.h"
#include "Konto_Oszczednosciowe.h"

using namespace std;

int main()
{
	Konto_Bankowe kb;
	
	cerr << kb << endl;
	kb.set_aktywnosc(Aktywnosc::aktywny);
	cerr << kb << endl;
	kb += 200.12;
	cerr << kb << endl;

}

