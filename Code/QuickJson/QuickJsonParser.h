/* 
 * File:   QuickJsonParser.h
 * Author: LANeo
 *
 * Created on 27. června 2018, 2:40
 */

#ifndef QUICKJSONPARSER_H
#define	QUICKJSONPARSER_H

#include <vector>
#include <map>

class QuickJsonParser {
public:
    QuickJsonParser( );
    QuickJsonParser( const QuickJsonParser& orig );
    virtual ~QuickJsonParser( );
    
    void Append(char c);
    
    bool Bottom();
    bool Good();
    bool Jump();
    bool Reading();
    
    std::string Key();
    std::string Value();
    
private:
    std::string m_line;
    std::string m_key;
    std::string m_value;
    bool m_reading;
    std::vector<char> m_level;
    std::map<std::string, bool> m_flags;

};

#endif	/* QUICKJSONPARSER_H */

