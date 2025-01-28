#include <limits> //Required for infinity
#include "include/top.hpp"
#include "cadmium/simulation/root_coordinator.hpp"
#include "cadmium/simulation/logger/stdout.hpp"
#include "cadmium/simulation/logger/csv.hpp"

using namespace cadmium;

int main() {

	auto model = std::make_shared<top> ("top");
	auto rootCoordinator = RootCoordinator(model);

	rootCoordinator.setLogger<STDOUTLogger>(";");

	rootCoordinator.start();
	rootCoordinator.simulate(10.0);
	rootCoordinator.stop();	

	return 0;
}