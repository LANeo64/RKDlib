/* 
 * File:   Uvazka.h
 * Author: LANeo
 *
 * Created on 28. června 2018, 11:36
 */

#ifndef UVAZKA_H
#define	UVAZKA_H

#include "TratovyObjekt.h"

class Uvazka: public TratovyObjekt {
public:
    Uvazka( std::string name, int id, TratovyTyp typ );
    Uvazka( const Uvazka& orig );
    virtual ~Uvazka( );
private:

};

#endif	/* UVAZKA_H */

