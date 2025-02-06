#ifndef COUNTER_TESTER_HPP
#define COUNTER_TESTER_HPP

#include "cadmium/modeling/devs/coupled.hpp" //cadmium header
#include "cadmium/lib/iestream.hpp"          //iestream header
#include "counter.hpp"                       //counter atomic model file

using namespace cadmium;

struct counter_tester: public Coupled {

  counter_tester(const std::string& id): Coupled(id){
    auto counter_model = addComponent<counter>("counter model");
    auto increment_file = addComponent<lib::IEStream<int>>("increment file", "/absolute file path/");
    auto countUp_file = addComponent<lib::IEStream<bool>>("countUp file",  "/absolute file path/");

    //Internal Couplings
    addCoupling(increment_file->out, counter_model->increment_in);
    addCoupling(countUp_file->out, counter_model->direction_in);
  }

};


#endif