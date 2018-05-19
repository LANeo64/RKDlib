/*
Created by Ace_Liver, 2018.
*/


#ifndef VLAK_STAV_H
#define VLAK_STAV_H
#include "Includes.h";
#include "Najeto.cpp";

class VlakStav
{
private:
	int m_rychlostStupne;
	int m_rychlostKmph;
	bool m_smer;
	bool m_stavFunkci[29];
	string m_stanoviste;
	Najeto m_najetoVpred;
	Najeto m_najetoVzad;

public:
	VlakStav(int spdS, int spdK, bool smer, string stanoviste);
	~VlakStav();	

	void inicNajeto();

	void setNajetoVpred(int metry, int bloky);
	Najeto getNajetoVpred();

	void setNajetoVzad(int metry, int bloky);	
	Najeto getNajetoVzad();

	void setFunction(int key, bool value);
	bool getFunction(int key);

	void setSmer(bool smer);
	bool getSmer();
	
	void setSpeedStupne(int stupen);
	void setSpeedKmph(int kmph);
	int getSpeedStupne();
	int getSpeedKmph();

	void printInfoConsole();
};


#endif	// !VLAK_STAV_H