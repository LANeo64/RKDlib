/* 
 * File:   SCOM.h
 * Author: LANeo
 *
 * Created on 28. června 2018, 11:34
 */

#ifndef SCOM_H
#define	SCOM_H

#include "TratovyObjekt.h"

class SCOM: public TratovyObjekt {
public:
    SCOM( std::string name, int id, TratovyTyp typ );
    SCOM( const SCOM& orig );
    virtual ~SCOM( );
private:

};

#endif	/* SCOM_H */

