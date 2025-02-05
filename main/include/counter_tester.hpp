#ifndef COUNTER_TESTER_HPP
#define COUNTER_TESTER_HPP

#include "cadmium/modeling/devs/coupled.hpp" //cadmium header
#include "cadmium/lib/iestream.hpp"          //iestream header
#include "counter.hpp"                       //counter atomic model file

using namespace cadmium;

struct counter_tester: public Coupled {

  counter_tester(const std::string& id): Coupled(id){
    auto counter_model = addComponent<counter>("counter model");
    auto increment_file = addComponent<lib::IEStream<int>>("increment file", "/home/sasi/DEVS_manual_example/increment_test.txt");
    auto countUp_file = addComponent<lib::IEStream<bool>>("countUp file", "/home/sasi/DEVS_manual_example/countUp_test.txt");

    //Internal Couplings
    addCoupling(increment_file->out, counter_model->increment_in);
    addCoupling(countUp_file->out, counter_model->direction_in);
  }

};


#endif