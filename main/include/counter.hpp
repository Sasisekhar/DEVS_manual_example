#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <iostream>
#include "cadmium/modeling/devs/atomic.hpp" //Cadmium header

using namespace cadmium; //This tells the compiler we are dealing with Cadmium

struct counterState {
    int count;
    int increment;
    bool countUp;
    double sigma;

    explicit counterState (): count(0), increment(1), countUp (true), sigma(1.0){}
};

//This part is required to tell cadmium how to print out your state set. As you can see,
//we are asking cadmium to print {count: /count value/, increment: /increment value/}
std::ostream& operator<<(std::ostream &out, const counterState& state) {
    out  << "{count: " << state.count << ", increment: " << state.increment << "}"; 
    return out;
}

//Here we see the atomic model being defined
class counter: public Atomic<counterState> {
    public:
    Port<bool> direction_in; //Input to set the direction of count
    Port<int> increment_in;  //Input to set the increment value
    Port<int> count_out;     //Outputs the count value

    counter(const std::string id) : Atomic<counterState>(id, counterState()) {
      count_out = addOutPort<int>("count_out"); //Set it to output port
      direction_in = addInPort<bool>("direction_in"); //Set it to input port
      increment_in = addInPort<int>("increment_in"); //Set it to input port
    }

    //Every ta(s) I want to either increment or decrement count by
    //the magnitude of state.increment.
    void internalTransition(counterState& state) const override {
      if(state.countUp) {
        state.count += state.increment;
      } else {
        state.count -= state.increment;
      } 
      state.sigma = 1.0;
    }

    // external transition
    void externalTransition(counterState& state, double e) const override {
        if(!direction_in->empty()){
          state.countUp = direction_in->getBag().back(); //I only care about the last value
        }
        if(!increment_in -> empty()) {
          state.increment = increment_in->getBag().back();
        }
        state.sigma -= e; //Why do you think this is significant?
    }
        
       
    // output function
    void output(const counterState& state) const override {
        count_out->addMessage(state.count);
    }

    // time_advance function
    [[nodiscard]] double timeAdvance(const counterState& state) const override {     
            return state.sigma;
    }
};


#endif