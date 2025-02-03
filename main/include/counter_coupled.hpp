#ifndef COUNTER_COUPLED_HPP
#define COUNTER_COUPLED_HPP

#include"cadmium/modeling/devs/coupled.hpp"
#include"counter.hpp"

using namespace cadmium;

struct counter_coupled: public Coupled {

  counter_coupled(const std::string& id): Coupled(id){
    auto counter_model = addComponent<counter>("counter model");
  }

};


#endif