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
    bool Done();
    
    std::string Key();
    std::string Value();
    
private:
    std::string m_line;
    std::string m_key;
    std::string m_value;
    bool m_reading;
    bool m_good;
    std::vector<char> m_level;
    std::map<std::string, bool> m_flags;
    
    bool EnterObject();
    bool LeaveObject();
    bool EnterArray();
    bool LeaveArray();
    bool EnterValue();
    bool LeaveValue();
    bool EnterKey();
    bool LeaveKey();
    bool Colon();
    bool Comma();
    
    void Digest(char c);
    bool SetState(char c);

};

#endif	/* QUICKJSONPARSER_H */

