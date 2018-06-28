/*
Created by Ace_Liver, 2018.
*/

#include "VlakStav.h"


VlakStav::VlakStav(int spdS, int spdK, bool smer, string stanoviste)
{
	m_rychlostStupne = spdS;
	m_rychlostKmph = spdK;
	m_smer = smer;
	
	for (int i = 0; i < 29; i++)
		m_stavFunkci[i] = false;

	m_stanoviste = stanoviste;
	
	//nastavi defaultni 0,0
	inicNajeto();
	//setNajetoVpred(0,0);
	//setNajetoVzad(0,0);
}

VlakStav::~VlakStav()
{

}

void VlakStav::inicNajeto()
{
	setNajetoVpred(0,0);
	setNajetoVzad(0,0);
}

void VlakStav::setNajetoVpred(int metry, int bloky) 
{
	if (bloky >= 0)
		m_najetoVpred.bloky = bloky;

	if (metry >= 0)
		m_najetoVpred.metry = metry;
}

Najeto VlakStav::getNajetoVpred()
{
	return m_najetoVzad;
}

void VlakStav::setNajetoVzad(int metry, int bloky)
{
	if (bloky >= 0)
		m_najetoVzad.bloky = bloky;

	if (metry >= 0)
		m_najetoVzad.metry = metry;
}

Najeto VlakStav::getNajetoVzad()
{
	return m_najetoVpred;
}

void VlakStav::setFunction(int key, bool value)
{
	if (key >= 0 && key < 29)
		m_stavFunkci[key] = value;
}

bool VlakStav::getFunction(int key)
{
	if (key >= 0 && key < 29)
		throw "out_of_range";
	else
		return m_stavFunkci[key];
}

void VlakStav::setSmer(bool smer) 
{
	m_smer = smer;
}

bool VlakStav::getSmer()
{
	return m_smer;
}

//je treba horni hranice povolenych stupnu?
void VlakStav::setSpeedStupne(int stupen)
{
	if (stupen >= 0)
		m_rychlostStupne = stupen;
}

//je potreba horni hranice kmph?
void VlakStav::setSpeedKmph(int kmph)
{
	if (kmph >= 0)
		m_rychlostKmph = kmph;
}

int VlakStav::getSpeedStupne()
{
	return m_rychlostStupne;
}

int VlakStav::getSpeedKmph()
{
	return m_rychlostKmph;
}

void VlakStav::printInfoConsole()
{
	cout << endl;
	cout << "m_rychlostStupne: " << m_rychlostStupne << endl;
	cout << "m_rychlostKmph: " << m_rychlostKmph << endl;
	cout << "m_smer: " << m_smer << endl;
	cout << "m_stanoviste: " << m_stanoviste << endl;

	cout << "-----------------------------------" << endl;
	cout << "m_stavFunkci: " << endl;
	for (int i = 0; i < 29; i++)
		cout << i+1 << " ";
	
	cout << endl;

	string out;
	for (int i = 0; i < 29; i++)
	{
		if (i > 9)
			out = " ";
		else
			out = "";

		cout << out << m_stavFunkci[i] << " ";
	}

	cout << endl;
	
	cout << "-----------------------------------" << endl;
	cout << "Najeto vpred" << endl;
	cout << "bloky: " << m_najetoVpred.bloky << endl;
	cout << "metry: " << m_najetoVpred.metry << endl;

	cout << "-----------------------------------" << endl;
	cout << "Najeto vzad" << endl;
	cout << "bloky: " << m_najetoVzad.bloky << endl;
	cout << "metry: " << m_najetoVzad.metry << endl;

	cout << endl << endl;
}