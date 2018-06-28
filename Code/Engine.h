/* 
 * File:   Engine.h
 * Author: LANeo
 *
 * Created on 28. června 2018, 11:09
 */

#ifndef ENGINE_H
#define	ENGINE_H

#include "Kolejiste.h"
#include "HttpClient.h"
#include <vector>
#include <string>

class Engine {
public:
    Engine( );
    Engine( const Engine& orig );
    virtual ~Engine( );
    
    void init();
    void scan();
    
    std::vector<Vlak> GetVlaky(int id);
    GetBlok(int id);
    
    
    
private:
    Kolejiste* m_kolejiste;
    HttpClient* m_http;
    

};

#endif	/* ENGINE_H */

