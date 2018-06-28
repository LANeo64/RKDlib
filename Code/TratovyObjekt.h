/* 
 * File:   TratovyObjekt.h
 * Author: LANeo
 *
 * Created on 28. června 2018, 11:33
 */

#ifndef TRATOVYOBJEKT_H
#define	TRATOVYOBJEKT_H

#include <string>

#include "TratovyTyp.hpp"

class TratovyObjekt {
public:
    TratovyObjekt( std::string name, int id, TratovyTyp typ );
    TratovyObjekt( const TratovyObjekt& orig );
    virtual ~TratovyObjekt( );
    
    std::string GetNazev();
    int GetId();
    TratovyTyp GetType();
    
protected:
    std::string m_nazev;
    int m_id;
    TratovyTyp m_typ;
};

#endif	/* TRATOVYOBJEKT_H */

