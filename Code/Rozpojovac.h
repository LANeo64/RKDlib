/* 
 * File:   Rozpojovac.h
 * Author: LANeo
 *
 * Created on 28. června 2018, 11:35
 */

#ifndef ROZPOJOVAC_H
#define	ROZPOJOVAC_H

#include "TratovyObjekt.h"

class Rozpojovac: public TratovyObjekt {
public:
    Rozpojovac( std::string name, int id, TratovyTyp typ );
    Rozpojovac( const Rozpojovac& orig );
    virtual ~Rozpojovac( );
private:

};

#endif	/* ROZPOJOVAC_H */

