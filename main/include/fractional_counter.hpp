#ifndef FRACTIONAL_COUNTER_HPP
#define FRACTIONAL_COUNTER_HPP

#include"cadmium/modeling/devs/coupled.hpp"
#include"int_to_float.hpp"
#include"counter.hpp"

using namespace cadmium;

struct fractional_counter: public Coupled {

  Port<int> incrementIn;
  Port<float> countOut;

  fractional_counter(const std::string& id): Coupled(id){
    incrementIn = addInPort<int>("incrementIn");  
    countOut = addOutPort<float>("countOut");

    auto counter_model = addComponent<counter>("counter model");
    auto intToFloat_model = addComponent<int_to_float>("int to float model");

    addCoupling(incrementIn, counter_model -> increment_in);
    addCoupling(counter_model -> count_out, intToFloat_model -> inIntegers);
    addCoupling(intToFloat_model -> outFloat, countOut);
  }

};


#endif