#ifndef SAMPLE_TOP_HPP
#define SAMPLE_TOP_HPP

#include"cadmium/modeling/devs/coupled.hpp"
#include"MyAtomic.hpp"
#include"counter.hpp"

using namespace cadmium;

struct top: public Coupled {

  Port<int> incrementIn;
  Port<float> countOut;

  top(const std::string& id): Coupled(id){
    incrementIn = addInPort<int>("incrementIn");  
    countOut = addOutPort<float>("countOut");

    auto counter_model = addComponent<counter>("counter model");
    auto MyAtomic_model = addComponent<MyAtomic>("int to float model");

    addCoupling(incrementIn, counter_model -> increment_in);
    addCoupling(counter_model -> count_out, MyAtomic_model -> inIntegers);
    addCoupling(MyAtomic_model -> outFloat, countOut);
  }

};


#endif