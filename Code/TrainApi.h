/* 
 * File:   Engine.h
 * Author: LANeo
 *
 * Created on 28. června 2018, 11:09
 */

#ifndef TRAINAPI_H
#define	TRAINAPI_H

#include "Kolejiste.h"
#include "HttpClient.h"
#include <vector>
#include <string>

class TrainApi {
public:
    TrainApi( );
    TrainApi( const TrainApi& orig );
    virtual ~TrainApi( );
    
    void init();
    void scan();
    std::string diagnose();
    
    //std::vector<Vlak> GetVlaky(int id);
    //TratovyObjekt GetBlok(int id);
    
    TrainApi mujengin = TrainApi::Getinstance();
    mujengine.init();
    
    
    
private:
    Kolejiste* m_kolejiste;
    HttpClient* m_http;
    

};

#endif	/* TRAINAPI_H */

