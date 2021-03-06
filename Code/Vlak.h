/*
	Created by Ace_Liver, 2018.
*/

#ifndef VLAK_H
#define VLAK_H
#include "Includes.h";
#include "VlakStav.h";
#include "LokoClass.h";
#include "FuncKey.h";

class Vlak 
{
private:
	int m_adresa;
	string m_nazev;
	string m_majitel;
	string m_oznaceni;
	string m_poznamka;
	LokoClass m_trida;
	std::map<FuncKey, string> m_funkce_nazev;
	VlakStav* m_stav;
	

public:
	Vlak(int add, string nazev, string majitel, string oznaceni, LokoClass trida, VlakStav* stav);
	~Vlak();

	void setPoznamka(string poznamka);

	void setStav(VlakStav* stav);
	VlakStav* GetStav();
	
	void inicFuncName();
	void setFuncName(FuncKey key, string name);
	string getFuncName(FuncKey key);

	int getAddress();

	void printConsole();

};


#endif // !VLAK_H
