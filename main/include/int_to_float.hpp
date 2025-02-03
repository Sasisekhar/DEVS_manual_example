#ifndef INT_TO_FLOAT_HPP
#define INT_TO_FLOAT_HPP

#include <iostream>
#include "cadmium/modeling/devs/atomic.hpp" //Cadmium header

using namespace cadmium; //This tells the compiler we are dealing with Cadmium

struct int_to_floatState{
	int int_value;
	float float_value;
  bool input_arrived;
  
  explicit int_to_floatState(): int_value(0), float_value(0.0), input_arrived(false) {}
};


//This part is required to tell cadmium how to print out your state set. As you can see,
//we are asking cadmium to print {int_value: /int_value value/, float_value: /float_value value/}
std::ostream& operator<<(std::ostream &out, const int_to_floatState& state) {
  out  << "{int_value: " << state.int_value << ", float_value: " << state.float_value << "}"; 
  return out;
}

//Here we see the atomic model being defined
class int_to_float: public Atomic<int_to_floatState> {
  public:
    // We expose input and output ports of our model as public attributes.
    Port<int> inIntegers;  
    Port<float> outFloat;


    int_to_float(std::string id): Atomic<int_to_floatState>(id, int_to_floatState()) {
        inIntegers = addInPort<int>("inIntegers");  //Add the input port
        outFloat = addOutPort<float>("outFloat");   //Add the output port
    }

    //internal transition function
    void internalTransition(int_to_floatState& state) const override {
      state.float_value = (float) state.int_value * 0.1;
      state.input_arrived = false;
    }


    // external transition
    void externalTransition(int_to_floatState& state, double e) const override {
      if(!inIntegers->empty()){
        state.int_value = inIntegers -> getBag().back();	
      }
      state.input_arrived = true;
    }
        
       
    // output function
    void output(const int_to_floatState& state) const override {
      outFloat->addMessage(state.float_value);
    }


    // time_advance function
    [[nodiscard]] double timeAdvance(const int_to_floatState& state) const override {     
      if(state.input_arrived) {
        return 0;
      } else {
        return std::numeric_limits<double>::infinity();
      }
    }
};


#endif