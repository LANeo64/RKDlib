/* 
 * File:   Vyhybka.h
 * Author: LANeo
 *
 * Created on 28. června 2018, 11:35
 */

#ifndef VYHYBKA_H
#define	VYHYBKA_H

#include "TratovyObjekt.h"
#include "MTB.hpp"
#include "ZamekVal.hpp"

class Vyhybka: public TratovyObjekt {
public:
    Vyhybka( std::string name, int id, TratovyTyp typ, MTB* iP, MTB* iN, MTB* oP, MTB* oN, int usek, int spojka );
    Vyhybka( std::string name, int id, TratovyTyp typ, MTB* iP, MTB* iN, MTB* oP, MTB* oN, int usek, int spojka, int zamek, std::string zamPos );
    Vyhybka( const Vyhybka& orig );
    virtual ~Vyhybka( );
    
    bool PrepniA();
    bool PrepniB();
    bool Prepni();
    bool Stav();
    void Zamkni();
    void Odemkni();
    bool GetZamekVal();
    
private:
    MTB* m_inputPos;
    MTB* m_inputNeg;
    MTB* m_outputPos;
    MTB* m_outputNeg;
    int m_usek;
    int m_spojka;
    int m_zamek;
    ZamekVal m_zamekPoloha;
};

#endif	/* VYHYBKA_H */

