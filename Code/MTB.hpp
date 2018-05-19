/* 
 * File:   MTB.hpp
 * Author: LANeo
 *
 * Created on 1. května 2018, 13:58
 */

#ifndef MTB_HPP
#define	MTB_HPP

class MTB {
public:
    MTB( int board, int port );
    MTB(const MTB& orig);
    virtual ~MTB();
private:
    int m_port;
    int m_board;

};

#endif	/* MTB_HPP */

