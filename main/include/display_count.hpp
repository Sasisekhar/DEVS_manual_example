#ifndef DISPLAY_COUNT_HPP
#define DISPLAY_COUNT_HPP

#include"cadmium/modeling/devs/coupled.hpp"
#include"fractional_counter.hpp"
#include"display.hpp"

using namespace cadmium;

struct display_count: public Coupled {

  display_count(const std::string& id): Coupled(id){

    auto frac_counter = addComponent<fractional_counter>("fractional counter model");
    auto display_model = addComponent<display>("display model");

    addCoupling(frac_counter -> countOut, display_model -> display_in);
  }

};


#endif