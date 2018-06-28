/* 
 * File:   Zamek.h
 * Author: LANeo
 *
 * Created on 28. června 2018, 11:36
 */

#ifndef ZAMEK_H
#define	ZAMEK_H

#include "TratovyObjekt.h"
#include "ZamekVal.hpp"

class Zamek: public TratovyObjekt {
public:
    Zamek( );
    Zamek( const Zamek& orig );
    virtual ~Zamek( );
        
private:
};

#endif	/* ZAMEK_H */

