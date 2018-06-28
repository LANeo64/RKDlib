/* 
 * File:   main.cpp
 * Author: LANeo
 *
 * Created on 1. května 2018, 13:49
 */

#include "curlpp/cURLpp.hpp"
#include "curlpp/Easy.hpp"
#include "curlpp/Options.hpp"

#include "include/nlohmann/json.hpp"

#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

using namespace std;
using namespace curlpp::options;
using json = nlohmann::json;

/*
 * 
 */
int main(int argc, char** argv) {
    std::ostringstream os;
    curlpp::options::WriteStream ws(&os);
    curlpp::options::Port myPort(5823);

    json vlakjson;

    try {
        // That's all that is needed to do cleanup of used resources (RAII style).
        curlpp::Cleanup myCleanup;

        // Our request to be sent.
        curlpp::Easy myRequest;
        myRequest.setOpt(ws);
        myRequest.setOpt(myPort);

        // Set the URL.
        myRequest.setOpt<Url>("http://127.0.0.1/blokStav/150");

        // Send request and get a result.
        // By default the result goes to standard output.
        myRequest.perform();
        std::cout << myRequest;
        os << myRequest;
        vlakjson = json::parse(os.str());

        //std::cout << myRequest;
    } catch (curlpp::RuntimeError & e) {
        std::cout << e.what() << std::endl;
    } catch (curlpp::LogicError & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "krtek" << std::endl;
    std::cout << vlakjson.dump(4) << std::endl;

/*
    VlakStav* vl = new VlakStav(4, 50, true, "oranzova");
    vl->printInfoConsole();
    vl->setFunction(5, true);
    vl->setFunction(8, true);
    vl->setFunction(9, true);
    vl->setFunction(10, true);
    vl->setFunction(28, true);
    vl->setNajetoVpred(15, 23);
    vl->setNajetoVzad(4, 10);
    vl->setSpeedKmph(8);
    vl->setSpeedStupne(2);
    vl->setSmer(false);
    vl->printInfoConsole();

    Vlak* vlacek = new Vlak(101110, "OS48501", "Ace", "nejake oznaceni", parni, vl);
    vlacek->setPoznamka("slusuje");
    vlacek->printConsole();

*/

    return 0;
}

