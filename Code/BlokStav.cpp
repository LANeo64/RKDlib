//
// Created by grena on 28.05.2018.
//
#include "BlokStav.hpp"

BlokStav::BlokStav(bool stav,  bool napajeni, bool zkrat, bool dcc){
    m_stav = stav;
    m_napajeni = napajeni;
    m_zkrat = zkrat;
    m_dcc = dcc;
}

BlokStav::BlokStav(bool stav, bool napajeni, bool zkrat, bool dcc, int sekce) {
    m_stav = stav;
    m_napajeni = napajeni;
    m_zkrat = zkrat;
    m_dcc = dcc;
    m_sekce = sekce;
}

void BlokStav::SetSekce(int key, bool val){

}

bool BlokStav::GetSekce(int key){

}

void BlokStav::SetStav(bool val){
    m_stav = val;
}

bool BlokStav::GetStav(){
    return m_stav;
}

void BlokStav::AddSouprava(string souprava){

}

void BlokStav::RemSouprava(int key){

}

void BlokStav::RemSouprava(string name) {

}