#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <random>
#include <iostream>
#include "cadmium/modeling/devs/atomic.hpp"

using namespace cadmium;

struct displayState {
    float display_value;
    double sigma;
    //you can have as many state variables as you want/ need

    explicit displayState(): display_value(0.0), sigma(std::numeric_limits<double>::infinity()){
    }
};

#ifndef NO_LOGGING
std::ostream& operator<<(std::ostream &out, const displayState& state) {
    out  << "{display: " << state.display_value << "}";
    return out;
}
#endif

class display : public Atomic<displayState> {
    public:

    Port<float> display_in;

    display(const std::string id) : Atomic<displayState>(id, displayState()) {
        display_in = addInPort<float>("display input");
    }

    // internal transition
    void internalTransition(displayState& state) const override {
        state.sigma = std::numeric_limits<double>::infinity();
    }

    // external transition
    void externalTransition(displayState& state, double e) const override {
        if(!display_in->empty()) {
            state.display_value = display_in->getBag().back();
        }

        state.sigma = 0;
    }
    
    
    // output function
    void output(const displayState& state) const override { }

    // time_advance function
    [[nodiscard]] double timeAdvance(const displayState& state) const override {     
        return state.sigma;
    }
};

#endif