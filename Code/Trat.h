/* 
 * File:   Trat.h
 * Author: LANeo
 *
 * Created on 28. června 2018, 11:34
 */

#ifndef TRAT_H
#define	TRAT_H

#include "TratovyObjekt.h"

class Trat: public TratovyObjekt {
public:
    Trat( std::string name, int id, TratovyTyp typ );
    Trat( const Trat& orig );
    virtual ~Trat( );
private:

};

#endif	/* TRAT_H */

