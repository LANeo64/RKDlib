/* 
 * File:   IR.h
 * Author: LANeo
 *
 * Created on 28. června 2018, 11:34
 */

#ifndef IR_H
#define	IR_H

#include "TratovyObjekt.h"
#include "MTB.hpp"

class IR {
public:
    IR( std::string name, int id, TratovyTyp typ, MTB* _mtb );
    IR( const IR& orig );
    virtual ~IR( );
    
    MTB* GetMTB();
    
private:
    MTB* m_mtb;
};

#endif	/* IR_H */

