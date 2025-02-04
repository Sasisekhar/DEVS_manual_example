#ifndef TESTCASES_HPP
#define TESTCASES_HPP

#include "cadmium/modeling/devs/coupled.hpp"
#include "cadmium/lib/iestream.hpp"

using namespace cadmium;

struct testcases: public Coupled {

    Port<int> increment_out;
    Port<bool> direction_out;
    
    testcases(const std::string& id): Coupled(id){
        increment_out = addOutPort<int>("increment out");
        direction_out = addOutPort<bool>("direction out");
        
        auto increment_file = addComponent<lib::IEStream<int>>("increment file", "/home/sasi/DEVS_manual_example/increment_test.txt");
        auto countUp_file = addComponent<lib::IEStream<bool>>("countUp file", "/home/sasi/DEVS_manual_example/countUp_test.txt");

        addCoupling(increment_file->out, increment_out);
        addCoupling(countUp_file->out, direction_out);
    }

};


#endif