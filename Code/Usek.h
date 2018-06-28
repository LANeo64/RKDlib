/* 
 * File:   Usek.h
 * Author: LANeo
 *
 * Created on 28. června 2018, 11:35
 */

#ifndef USEK_H
#define	USEK_H

#include <vecotr>
#include <string>

#include "TratovyObjekt.h"
#include "MTB.hpp"
#include "BlokStav.hpp"

class Usek: public TratovyObjekt {
public:
    Usek( std::string name, int id, TratovyTyp typ, std::string zesilovac );
    Usek( const Usek& orig );
    virtual ~Usek( );
    
    bool JeObsazen();
    bool JeObsazen(int key);
    std::string GetZesilovac();
    int GetDelka();
    void SetStav(BlokStav* stav);
    BlokStav* GetStav();
    void PridejSekci(MTB* _mtb);
    
protected:
    std::vector<MTB*> m_mtb;
    int m_delka;
    std::string m_zesilovac;
    BlokStav* m_stav;
};

#endif	/* USEK_H */

