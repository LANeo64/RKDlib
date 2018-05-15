/* 
 * File:   MTB.cpp
 * Author: LANeo
 * 
 * Created on 1. května 2018, 13:58
 */

#include "MTB.hpp"

MTB::MTB( int board, int port ) {
    m_port = port;
    m_board = board;
}

MTB::MTB(const MTB& orig) {
    m_port = orig.m_port;
    m_board = orig.m_board;
}

MTB::~MTB() {
}

