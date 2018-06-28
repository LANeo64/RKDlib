/*
Created by Ace_Liver, 2018.
*/
#include "Vlak.h"

Vlak::Vlak(int add, string nazev, string majitel, string oznaceni, LokoClass trida, VlakStav* stav)
{
	m_adresa = add;
	m_nazev = nazev;
	m_majitel = majitel;
	m_oznaceni = oznaceni;
	m_trida = trida;
	inicFuncName();
	setStav(stav);
}


Vlak::~Vlak()
{
	delete m_stav;	
}


void Vlak::setPoznamka(string poznamka)
{
	m_poznamka = poznamka;
}

void Vlak::setStav(VlakStav* stav)
{
	if (stav != nullptr)
		m_stav = stav;
	else
		throw "parameter \"stav\" is null";
}


VlakStav* Vlak::GetStav()
{
	return m_stav;
}


void Vlak::inicFuncName()
{
	FuncKey funkce[13] = {F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13};
	for (int i=0; i<13; i++)
		m_funkce_nazev[funkce[i]] = "";
}


void Vlak::setFuncName(FuncKey key, string name)
{
	m_funkce_nazev[key] = name;
}


string Vlak::getFuncName(FuncKey key)
{
	return m_funkce_nazev[key];
}


int Vlak::getAddress() 
{
	return m_adresa;
}


void Vlak::printConsole()
{
	cout << endl << endl;
	cout << "Info vlak" << endl;
	cout << "======================================" << endl;
	cout << "m_adresa: " << m_adresa << endl;
	cout << "m_nazev: " << m_nazev << endl;
	cout << "m_majitel: " << m_majitel << endl;
	cout << "m_oznaceni: " << m_oznaceni << endl;
	cout << "m_poznamka: " << m_poznamka << endl;
	cout << "m_trida: " << m_trida << endl;
	//cout << "m_funkce_nazev: " << m_funkce_nazev << endl;
	cout << "======================================" << endl;	
	cout << "STAV VLAKU - m_stav" << endl;
	cout << "======================================";
	m_stav->printInfoConsole();

}
