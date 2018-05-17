/*
Created by Ace_Liver, 2018.
*/


#include <iostream>;
#include "VlakStav.h"
#include "Vlak.h";
#include "LokoClass.h";

using namespace std;

int main()
{
	VlakStav* vl = new VlakStav(4,50,true,"oranzova");
	vl->printInfoConsole();
	vl->setFunction(5, true);
	vl->setFunction(8, true);
	vl->setFunction(9, true);
	vl->setFunction(10, true);
	vl->setFunction(28, true);
	vl->setNajetoVpred(15,23);
	vl->setNajetoVzad(4,10);
	vl->setSpeedKmph(8);
	vl->setSpeedStupne(2);
	vl->setSmer(false);
	vl->printInfoConsole();

	Vlak* vlacek = new Vlak(101110, "OS48501", "Ace", "nejake oznaceni", parni, vl);
	vlacek->setPoznamka("slusuje");
	vlacek->printConsole();

	system("pause");	
	return 0;
}