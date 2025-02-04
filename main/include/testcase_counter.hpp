#ifndef TEST_CASE_COUNTER_HPP
#define TEST_CASE_COUNTER_HPP

#include "cadmium/modeling/devs/coupled.hpp"
#include "counter.hpp"
#include "testcases.hpp"

using namespace cadmium;

struct testcase_counter: public Coupled {
    
    testcase_counter(const std::string& id): Coupled(id){
        auto counter_model = addComponent<counter>("counter model");
        auto testcases_model = addComponent<testcases>("testcases model");

        addCoupling(testcases_model->increment_out, counter_model->increment_in);
        addCoupling(testcases_model->direction_out, counter_model->direction_in);
    }

};


#endif