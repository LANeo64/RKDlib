/*
Created by Ace_Liver, 2018.
*/


#include "Vlak.h";


Vlak::Vlak(int add, string nazev, string majitel, string oznaceni, string trida)
{
	m_nazev = nazev;
	m_majitel = majitel;
	m_oznaceni = oznaceni;
	//...
}

Vlak::~Vlak()
{
	
}

void Vlak::setNote(string note)
{

}

void Vlak::setStav(VlakStav* stav)
{

}


VlakStav* Vlak::GetStav()
{
	return m_stav;
}

//void Vlak::setFuncName(FuncKey key, string name)

//string Vlak::getFuncName(FuncKey key)

int Vlak::getAddress() 
{
	return m_adresa;
}
