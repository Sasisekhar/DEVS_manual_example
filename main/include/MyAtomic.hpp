#ifndef MY_ATOMIC_HPP
#define MY_ATOMIC_HPP

#include <iostream>
#include "cadmium/modeling/devs/atomic.hpp" //Cadmium header

using namespace cadmium; //This tells the compiler we are dealing with Cadmium

struct MyAtomicState{
	int sv1;
	float sv2;
  bool input_arrived;
  
  explicit MyAtomicState(): sv1(0), sv2(0.0), input_arrived(false) {}
};


//This part is required to tell cadmium how to print out your state set. As you can see,
//we are asking cadmium to print {count: <count value>, increment: <increment value>}
std::ostream& operator<<(std::ostream &out, const MyAtomicState& state) {
  out  << "{sv1: " << state.sv1 << ", sv2: " << state.sv2 << "}"; 
  return out;
}

//Here we see the atomic model being defined
class MyAtomic: public Atomic<MyAtomicState> {
  public:
    // We expose input and output ports of our model as public attributes.
    Port<int> inIntegers;  
    Port<float> outFloat;


    MyAtomic(std::string id): Atomic<MyAtomicState>(id, MyAtomicState()) {
        inIntegers = addInPort<int>("inIntegers");  //Add the input port
        outFloat = addOutPort<float>("outFloat");   //Add the output port
    }

    //internal transition function
    void internalTransition(MyAtomicState& state) const override {
      state.sv2 = (float) state.sv1 * 0.1;
      state.input_arrived = false;
    }


    // external transition
    void externalTransition(MyAtomicState& state, double e) const override {
      if(!inIntegers->empty()){
        state.sv1 = inIntegers -> getBag().back();
        state.input_arrived = true;	
      }
    }
        
       
    // output function
    void output(const MyAtomicState& state) const override {
      // Here, we can add message to output ports.
      outFloat->addMessage(state.sv2);
    }


    // time_advance function
    [[nodiscard]] double timeAdvance(const MyAtomicState& state) const override {     
      if(state.input_arrived) {
        return 0;
      } else {
        return std::numeric_limits<double>::infinity();
      }
    }
};


#endif