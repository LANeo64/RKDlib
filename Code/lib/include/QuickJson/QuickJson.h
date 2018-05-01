#ifndef QUICKJSON_H
#define QUICKJSON_H

#include <vector>
#include <string>
#include <sstream>
#include <ctime>

#include "mbed.h"

class QuickJson {
private:
    std::vector<QuickJson*> m_fields;
    std::string m_fieldName;
    std::string m_fieldValue;
    
    QuickJson( std::string );
    QuickJson( std::string, std::string );
    
    std::string getName();
    std::string getValue();
    bool add( std::string, std::string );
    int getIndex( std::string );
    
public:
    QuickJson();
    std::string serialize();
    
    bool addField( std::string, std::string );
    bool addField( std::string );
    bool addField( std::string, int );
    bool addField( int );
    bool addField( std::string, unsigned long long );
    bool addField( unsigned long long );
    bool addField( std::string, bool );
    bool addField( bool );
    bool addField( std::string, double );
    bool addField( double );
    bool addField( std::string, std::time_t );
    bool addField( std::time_t );
    bool addField( std::string, char* );
    bool addField( char* );
    bool addField( std::string, const char* );
    bool addField( const char* );
    
    QuickJson* addNode( std::string );
    QuickJson* getChild( std::string );
    std::vector<QuickJson*> getChildren();
    
    QuickJson* ParseString( const char* );
    QuickJson* ParseString( std::string );
};

#endif //QUICKJSON_H