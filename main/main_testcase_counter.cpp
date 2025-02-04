#include <limits> //Required for infinity
#include "include/testcase_counter.hpp"
#include "cadmium/simulation/root_coordinator.hpp"
#include "cadmium/simulation/logger/stdout.hpp"
#include "cadmium/simulation/logger/csv.hpp"

using namespace cadmium;

int main() {

	auto model = std::make_shared<testcase_counter> ("testcase counter");
	auto rootCoordinator = RootCoordinator(model);

	rootCoordinator.setLogger<STDOUTLogger>(";");
	// rootCoordinator.setLogger<CSVLogger>("display_log_output.csv", ";");

	rootCoordinator.start();
	rootCoordinator.simulate(10.1);
	rootCoordinator.stop();	

	return 0;
}