#ifndef COUNTER_TESTER_HPP
#define COUNTER_TESTER_HPP

#include "cadmium/modeling/devs/coupled.hpp"
#include "counter.hpp"
#include "testcases.hpp"

using namespace cadmium;

struct counter_tester: public Coupled {
    
    counter_tester(const std::string& id): Coupled(id){
        auto counter_model = addComponent<counter>("counter model");
        auto testcases_model = addComponent<testcases>("testcases model");

        addCoupling(testcases_model->increment_out, counter_model->increment_in);
        addCoupling(testcases_model->direction_out, counter_model->direction_in);
    }

};


#endif