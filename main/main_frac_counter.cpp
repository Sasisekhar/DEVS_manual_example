#include <limits> //Required for infinity
#include "include/fractional_counter.hpp"
#include "cadmium/simulation/root_coordinator.hpp"
#include "cadmium/simulation/logger/stdout.hpp"
#include "cadmium/simulation/logger/csv.hpp"

using namespace cadmium;

int main() {

	auto model = std::make_shared<fractional_counter> ("fractional counter");
	auto rootCoordinator = RootCoordinator(model);

	// rootCoordinator.setLogger<STDOUTLogger>(";");
	rootCoordinator.setLogger<CSVLogger>("fractional_log_output.csv", ";");

	rootCoordinator.start();
	rootCoordinator.simulate(10.0);
	rootCoordinator.stop();	

	return 0;
}