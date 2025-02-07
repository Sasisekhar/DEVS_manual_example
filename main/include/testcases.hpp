#ifndef TESTCASES_HPP
#define TESTCASES_HPP

#include "cadmium/modeling/devs/coupled.hpp" //cadmium header
#include "cadmium/lib/iestream.hpp"          //IEStream header

using namespace cadmium;

struct testcases: public Coupled {

    //The ports
    Port<int> increment_out;
    Port<bool> direction_out;
    
    testcases(const std::string& id): Coupled(id){
        //setting the ports as output ports
        increment_out = addOutPort<int>("increment out");
        direction_out = addOutPort<bool>("direction out");
        
        //adding the IEStream models
        auto increment_file = addComponent<lib::IEStream<int>>("increment file", "/absolute path/");
        auto countUp_file = addComponent<lib::IEStream<bool>>("countUp file", "/absolute path/");

        //performing the EOC
        addCoupling(increment_file->out, increment_out);
        addCoupling(countUp_file->out, direction_out);
    }

};


#endif