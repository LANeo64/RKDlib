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
    m_flags["col"] = false;
    m_flags["com"] = false;
    m_flags["int"] = false;
    m_flags["sep"] = false;
    m_level = 0;
    m_reading = true;
    m_good = true;
    m_line = "";
}

QuickJsonParser::QuickJsonParser( const QuickJsonParser& orig ) {
}

QuickJsonParser::~QuickJsonParser( ) {
}

void QuickJsonParser::Append(char c) {
    m_good = SetState(c);
    if(m_good) {
        Digest(c);
    }
}

void QuickJsonParser::Digest(char c){
    
}

bool QuickJsonParser::SetState(char c){
    switch( c ) {
        case '{':
            m_good = EnterObject();
            break;
        case '}':
            m_good = LeaveObject();
            break;
        case '[':
            m_good = EnterArray();
            break;
        case ']':
            m_good = LeaveArray();
            break;
        case ',':
            m_good = Comma();
            break;
        case ':':
            m_good = Colon();
            break;
        case '"':
            
            break;
        case ' ':
        case '\t':
        case '\n':
        case '\r':
            break;
        default:
            break;
    }
}

// ### informating functions ###################################################
bool QuickJsonParser::Bottom() {
    
}

bool QuickJsonParser::Good() {
    return m_good;
}

bool QuickJsonParser::Jump() {
    
}

bool QuickJsonParser::Reading() {
    return m_reading;
}

bool QuickJsonParser::Done() {
    
}

// ### state functions #########################################################
bool QuickJsonParser::EnterObject() {
    if(
            m_flags["key"] ||
            (m_flags["val"] && !m_flags["int"]) ||
            (m_flags["col"] && m_flags["sep"]) ||
            (m_flags["arr"] && m_flags["com"] && m_flags["sep"]) ||
            m_flags["obj"]
            ) {
        return true;
    } else {
        return false;
    }
}

bool QuickJsonParser::LeaveObject() {
    if(m_flags["val"] && m_flags["int"]) {
        
    }
    if(
            m_flags["obj"] ||
            m_flags["key"] ||
            (m_flags["val"] && !m_flags["int"]) ||
            ){
        return true;
    } else {
        return false;
    }
}

bool QuickJsonParser::EnterArray() {
    if(){
        return true;
    } else {
        return false;
    }
}

bool QuickJsonParser::LeaveArray() {
    if(){
        return true;
    } else {
        return false;
    }
}

bool QuickJsonParser::EnterValue() {
    if(){
        return true;
    } else {
        return false;
    }
}

bool QuickJsonParser::LeaveValue() {
    if(){
        return true;
    } else {
        return false;
    }
}

bool QuickJsonParser::EnterKey() {
    if(){
        return true;
    } else {
        return false;
    }
}

bool QuickJsonParser::LeaveKey() {
    if(){
        return true;
    } else {
        return false;
    }
}

bool QuickJsonParser::Colon() {
    if(){
        return true;
    } else {
        return false;
    }
}

bool QuickJsonParser::Comma() {
    if(){
        return true;
    } else {
        return false;
    }
}


    
    
    /*
    if( m_flags["key"] ){
        if(c == '"') {
            m_flags["key"] = false;
            m_key = m_line;
            m_line.clear();
        } else {
            m_line.append(1, c);
        }
    }
    
    if( m_flags["val"] ){
        if(c == '"') {
            m_flags["val"] = false;
            m_value = m_line;
            m_line.clear();
        } else {
            m_line.append(1, c);
        }
    }
    
    if( m_flags["obj"] ){
        if(c == '"') {
            m_flags["key"] = true;
            m_flags["obj"] = false;
        } else if(c == ':'){
            m_flags["colon"] = true;
        }
    }
    
}
*/
