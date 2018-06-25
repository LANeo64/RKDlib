//
// Created by grena on 28.05.2018.
//

#ifndef CODE_BLOKSTAV_HPP
#define CODE_BLOKSTAV_HPP

class BlokStav {
public:
    BlokStav(bool stav, bool napajeni, bool zkrat, bool dcc);
    BlokStav(bool stav, bool napajeni, bool zkrat, bool dcc, int sekce);
    SetSekce(int key, bool val);
    GetSekce(int key);
    SetStav(bool val);
    GetStav();
    AddSouprava(string souprava);
    RemSouprava(int key);
    RemSouprava(string name);

private:
    bool m_stav;
    std::vector<bool> m_sekce;
    bool m_napajeni;
    bool m_zkrat;
    bool m_dcc;
    std::vector<string> m_soupravy;
};

#endif //CODE_BLOKSTAV_HPP
