#include <limits>
#include "include/counter_coupled.hpp"
#include "cadmium/simulation/root_coordinator.hpp"
#include "cadmium/simulation/logger/stdout.hpp"
#include "cadmium/simulation/logger/csv.hpp"

using namespace cadmium;

int main() {

	auto model = std::make_shared<counter_coupled> ("counter_coupled");
	auto rootCoordinator = RootCoordinator(model);

	rootCoordinator.setLogger<STDOUTLogger>(";");
	// rootCoordinator.setLogger<CSVLogger>("counter_log_output.csv", ";");

	rootCoordinator.start();
	rootCoordinator.simulate(10.1);
	rootCoordinator.stop();	

	return 0;
}