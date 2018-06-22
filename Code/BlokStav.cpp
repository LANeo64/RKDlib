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
    m_sekce.insert(m_sekce.begin() + key, val);
}

bool BlokStav::GetSekce(int key){
    return m_sekce[key];
}

void BlokStav::SetStav(bool val){
    m_stav = val;
}

bool BlokStav::GetStav(){
    return m_stav;
}

void BlokStav::AddSouprava(string souprava){
    m_soupravy.insert(m_soupravy.begin(), souprava);
}

void BlokStav::RemSouprava(int key){
    m_soupravy.erase(m_soupravy.begin() + key);
}

void BlokStav::RemSouprava(string name) {
    //zatim neni hotova trida pro soupravu...
}