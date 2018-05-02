#include "QuickJson.h"
//#include "../../include/QuickJson/QuickJson.h"

QuickJson::QuickJson( std::string value ) {
    m_fieldName = "";
    m_fieldValue = value;
};

QuickJson::QuickJson( std::string name, std::string value ) {
    m_fieldName = name;
    m_fieldValue = value;
};

std::string QuickJson::getName() {
    return m_fieldName;
}

std::string QuickJson::getValue() {
    return m_fieldValue;
}

bool QuickJson::add( std::string name, std::string value ) {
    bool nameEmpty = ( m_fieldName.compare( "" ) == 0 ) ? true : false;
    bool valueEmpty = ( m_fieldValue.compare( "" ) == 0 ) ? true : false;
    bool keyEmpty = ( name.compare( "" ) == 0 ) ? true : false;
    bool sameName = ( m_fieldName.compare( name ) == 0 ) ? true : false;
    bool empty = m_fields.empty();

    if( nameEmpty && valueEmpty ) {
        // I am root node!
        if( keyEmpty ) {
            return false;
        } else {
            int index;
            if( ( index = getIndex( name ) ) == -1 ) {
                m_fields.push_back( new QuickJson( name, value ) );
            } else {
                m_fields.at( index )->add( "", value );
            }
        }
    } else if( !nameEmpty && valueEmpty && !empty ) {
        // I am an array
        if( keyEmpty ) {
            m_fields.push_back( new QuickJson( value ) );
        } else {
            int index;
            if( ( index = getIndex( name ) ) == -1 ) {
                m_fields.push_back( new QuickJson( name, value ) );
            } else {
                m_fields.at( index )->add( "", value );
            }
        }
    } else if( !nameEmpty && valueEmpty && empty ) {
        // I am an empty node
        if( keyEmpty ) {
            m_fieldValue = value;
        } else {
            m_fields.push_back( new QuickJson( name, value ) );
        }
    } else if( !nameEmpty && !valueEmpty && empty ) {
        // I am a node
        m_fields.push_back( new QuickJson( m_fieldValue ) );
        m_fieldValue = "";
        if( keyEmpty ) {
            m_fields.push_back( new QuickJson( value ) );
        } else {
            m_fields.push_back( new QuickJson( name, value ) );
        }
    } else {
        // I am a boogeyman!! BOOO!
        //printf("\r\n\r\nBoogeyman found!!!\r\n\r\n");
        return false;
    }
    return true;
}

int QuickJson::getIndex( std::string name ) {
    int key = -1;
    for( int i = 0; i < m_fields.size(); i++ ) {
        if( m_fields.at( i )->getName().compare( name ) == 0 ) {
            key = i;
            break;
        }
    }
    return key;
}

QuickJson::QuickJson() {
    m_fieldName = "";
    m_fieldValue = "";
}

std::string QuickJson::serialize() {
    std::string result = "";
    if( ( m_fieldName.compare( "" ) == 0 ) && ( m_fieldValue.compare( "" ) == 0 ) ) { // I am root node
        result += "{";
        for( int i = 0; i < m_fields.size(); i++ ) {
            result += m_fields.at( i )->serialize();
            if( i != ( m_fields.size() - 1 ) ) {
                result += ",";
            }
        }
        result += "}";
    } else if( ( m_fieldName.compare( "" ) != 0 ) && ( m_fieldValue.compare( "" ) == 0 ) ) { // I am an array
        result += "\"";
        result += m_fieldName;
        result += "\":";
        if( m_fields.size() > 0 ) {
            if( m_fields.at( 0 )->getName().compare( "" ) == 0 ) { // I assume I am an array of values {val}
                result += "[";
                for( int i = 0; i < m_fields.size(); i++ ) {
                    if( m_fields.at( i )->getName().compare( "" ) == 0 ) { // I am a value. Hooray!
                        result += m_fields.at( i )->serialize();
                    } else {                                        // I am a node. Oooops!
                        result += "{";
                        result += m_fields.at( i )->serialize();
                        result += "}";
                    }
                    if( i != ( m_fields.size() - 1 ) ) {
                        result += ",";
                    }
                }
                result += "]";
            } else {                                         // I assume I am an array of nodes {"name":val}
                result += "{";
                for( int i = 0; i < m_fields.size(); i++ ) {
                    if( m_fields.at( i )->getName().compare( "" ) == 0 ) { // I am a value. Oooops!
                        std::ostringstream ss;
                        ss << i;
                        result += "\"node" + ss.str() + "\":";
                        result += m_fields.at( i )->serialize();
                    } else {                                        // I am a node. Hooray!
                        result += m_fields.at( i )->serialize();
                    }
                    if( i != ( m_fields.size() - 1 ) ) {
                        result += ",";
                    }
                }
                result += "}";
            }
        } else {
            result += "[]";
            //result += "{}";
        }
    } else if( ( m_fieldName.compare( "" ) != 0 ) && ( m_fieldValue.compare( "" ) != 0 ) ) { // I am a node {"name":val}
        result += "\"";
        result += m_fieldName;
        result += "\":";
        result += m_fieldValue;
    } else {    // I am an array member
        result += m_fieldValue;
    }
    return result;
}
bool QuickJson::addField( std::string name, std::string value ) {
    return add( name, value );
}

bool QuickJson::addField( std::string value ) {
    return add( "", value );
}

bool QuickJson::addField( std::string name, int value ) {
    std::ostringstream strs;
    strs << value;
    return add( name, strs.str() );
}

bool QuickJson::addField( int value ) {
    return addField( "", value );
}

bool QuickJson::addField( std::string name, unsigned long long value ) {
    std::ostringstream strs;
    strs << value;
    return add( name, strs.str() );
}

bool QuickJson::addField( unsigned long long value ) {
    return addField( "", value );
}

bool QuickJson::addField( std::string name, bool value ) {
    if( value ) {
        return add( name, "true" );
    } else {
        return add( name, "false" );
    }
}

bool QuickJson::addField( bool value ) {
    return addField( "", value );
}

bool QuickJson::addField( std::string name, double value ) {
    std::ostringstream strs;
    strs << value;
    return add( name, strs.str() );
}

bool QuickJson::addField( double value ) {
    return addField( "", value );
}

bool QuickJson::addField( std::string name, std::time_t value ) {
    std::ostringstream strs;
    strs << value;
    return add( name, strs.str() );
}

bool QuickJson::addField( std::time_t value ) {
    return addField( "", value );
}

bool QuickJson::addField( std::string name, char* value ) {
    std::ostringstream strs;
    strs << "\"";
    strs << std::string( value );
    strs << "\"";
    return add( name, strs.str() );
}

bool QuickJson::addField( char* value ) {
    return addField( "", value );
}

bool QuickJson::addField( std::string name, const char* value )
{
    std::ostringstream strs;
    strs << "\"";
    strs << std::string( value );
    strs << "\"";
    return add( name, strs.str() );
}

bool QuickJson::addField( const char* value ) {
    return addField( "", value );
}

QuickJson* QuickJson::addNode( std::string name ) {
    int index = getIndex( name );
    if( index == -1 ) {
        QuickJson* node = new QuickJson( name, "" );
        m_fields.push_back( node );
        return node;
    } else {
        return m_fields.at(index);
    }
}

QuickJson* QuickJson::getChild( std::string name ) {
    QuickJson* node = NULL;
    int index;
    if( ( index = getIndex( name ) ) != -1 ) {
        node = m_fields.at( index );
    }
    return node;
}

std::vector<QuickJson*> QuickJson::getChildren() {
    return m_fields;
}

QuickJson* QuickJson::ParseString( const char* str ) {
    return ParseString( std::string( str ) );
}

QuickJson* QuickJson::ParseString( std::string str ) {
    int len = str.length();
    return NULL;
}