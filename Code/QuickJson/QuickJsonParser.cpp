/* 
 * File:   QuickJsonParser.cpp
 * Author: LANeo
 * 
 * Created on 27. června 2018, 2:40
 */

#include "QuickJsonParser.h"

QuickJsonParser::QuickJsonParser( ) {
    m_flags["key"] = false;
    m_flags["val"] = false;
    m_flags["obj"] = false;
    m_flags["arr"] = false;
    m_flags["colon"] = false;
    m_flags["comma"] = false;
    m_flags["int"] = false;
    m_reading = true;
    m_line = "";
}

QuickJsonParser::QuickJsonParser( const QuickJsonParser& orig ) {
}

QuickJsonParser::~QuickJsonParser( ) {
}

QuickJsonParser::Append(char c) {
    if( m_inKey ){
        if(c == '"') {
            m_inKey = false;
            m_key = m_line;
            m_line.clear();
        } else {
            m_line.append(1, c);
        }
    }
    
    if( m_inVal ){
        if(c == '"') {
            m_inVal = false;
            m_value = m_line;
            m_line.clear();
        } else {
            m_line.append(1, c);
        }
    }
    
    if( m_inObj ){
        if(c == ':')
    }
    
}

QuickJsonParser::Bottom() {
    
}

QuickJsonParser::Good() {
    
}

QuickJsonParser::Jump() {
    
}

QuickJsonParser::Reading() {
    return m_reading;
}