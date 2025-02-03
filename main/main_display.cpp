#include <limits> //Required for infinity
#include "include/display_count.hpp"
#include "cadmium/simulation/root_coordinator.hpp"
#include "cadmium/simulation/logger/stdout.hpp"
#include "cadmium/simulation/logger/csv.hpp"

using namespace cadmium;

int main() {

	auto model = std::make_shared<display_count> ("counter display");
	auto rootCoordinator = RootCoordinator(model);

	// rootCoordinator.setLogger<STDOUTLogger>(";");
	rootCoordinator.setLogger<CSVLogger>("display_log_output.csv", ";");

	rootCoordinator.start();
	rootCoordinator.simulate(10.0);
	rootCoordinator.stop();	

	return 0;
}