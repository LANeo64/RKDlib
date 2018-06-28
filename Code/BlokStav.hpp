//
// Created by grena on 28.05.2018.
//

#ifndef CODE_BLOKSTAV_HPP
#define CODE_BLOKSTAV_HPP

#include <string>
#include <vector>

class BlokStav {
public:
    BlokStav(bool stav, bool napajeni, bool zkrat, bool dcc);
    BlokStav(bool stav, bool napajeni, bool zkrat, bool dcc, int sekce);
    void SetSekce(int key, bool val);
    bool GetSekce(int key);
    void SetStav(bool val);
    bool GetStav();
    void AddSouprava(std::string souprava);
    void RemSouprava(int key);
    void RemSouprava(std::string name);

private:
    bool m_stav;
    std::vector<bool> m_sekce;
    bool m_napajeni;
    bool m_zkrat;
    bool m_dcc;
    std::vector<std::string> m_soupravy;
};

#endif //CODE_BLOKSTAV_HPP
