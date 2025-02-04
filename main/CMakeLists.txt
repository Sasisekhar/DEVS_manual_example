# Link main file to executable namee
add_executable(counter_tester main_counter_tester.cpp)
add_executable(counter_coupled main_counter.cpp)


# Add required libraries and include directories
target_include_directories(counter_tester PRIVATE "." "include" $ENV{CADMIUM})
target_include_directories(counter_coupled PRIVATE "." "include" $ENV{CADMIUM})

# set c++ standard
target_compile_options(counter_tester PUBLIC -std=gnu++2b)
target_compile_options(counter_coupled PUBLIC -std=gnu++2b)