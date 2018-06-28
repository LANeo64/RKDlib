/* 
 * File:   TratUsek.h
 * Author: LANeo
 *
 * Created on 28. června 2018, 11:35
 */

#ifndef TRATUSEK_H
#define	TRATUSEK_H

#include "Usek.h"

class TratUsek: public Usek {
public:
    TratUsek( std::string name, int id, TratovyTyp typ, std::string zesilovac, bool smycka);
    TratUsek( const TratUsek& orig );
    virtual ~TratUsek( );
    
    bool GetSmycka();
    
private:
    bool m_smyckaUsek;
};

#endif	/* TRATUSEK_H */

