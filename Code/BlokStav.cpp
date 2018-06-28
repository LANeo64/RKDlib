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
    for(int i=0; i< sekce; i++){
        m_sekce.push_back(false);
    }
    //m_sekce = sekce;
}

void BlokStav::SetSekce(int key, bool val){
    m_sekce.at(key) = val;
}

bool BlokStav::GetSekce(int key){
    return m_sekce.at(key);
}

void BlokStav::SetStav(bool val){
    m_stav = val;
}

bool BlokStav::GetStav(){
    return m_stav;
}

void BlokStav::AddSouprava(std::string souprava){
    m_soupravy.push_back(souprava);
}

void BlokStav::RemSouprava(int key){
    m_soupravy.erase(m_soupravy.begin() + key);
}

void BlokStav::RemSouprava(std::string name) {
    for(std::vector<std::string>::iterator it = m_soupravy.begin(); it != m_soupravy.end(); it++ ){
        if((*it).compare(name)) {
            m_soupravy.erase(it);
        }
    }
}