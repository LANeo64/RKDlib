/* 
 * File:   main.cpp
 * Author: LANeo
 *
 * Created on 1. května 2018, 13:49
 */

#include "curlpp/cURLpp.hpp"
#include "curlpp/Easy.hpp"
#include "curlpp/Options.hpp"

#include "QuickJson/QuickJson.h"

#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

using namespace std;
using namespace curlpp::options;

/*
 * 
 */
int main(int argc, char** argv) {
    std::ostringstream os;
    curlpp::options::WriteStream ws(&os);
    curlpp::options::Port myPort(5823);
    
    QuickJson* json;
    
    try {
        // That's all that is needed to do cleanup of used resources (RAII style).
        curlpp::Cleanup myCleanup;

        // Our request to be sent.
        curlpp::Easy myRequest;
        myRequest.setOpt(ws);
        myRequest.setOpt(myPort);

        // Set the URL.
        myRequest.setOpt<Url>("http://127.0.0.1/bloky");

        // Send request and get a result.
        // By default the result goes to standard output.
        myRequest.perform();
        std::cout << myRequest;
        os << myRequest;
        json = new QuickJson::ParseString(os.str());
        
        //std::cout << myRequest;
    } catch (curlpp::RuntimeError & e) {
        std::cout << e.what() << std::endl;
    } catch (curlpp::LogicError & e) {
        std::cout << e.what() << std::endl;
    }
    //std::cout << "krtek" << std::endl;
    return 0;
}

