# Link main file to executable namee
add_executable(fractional_counter_display main_display.cpp)
add_executable(fractional_counter main_frac_counter.cpp)
add_executable(counter_coupled main_counter.cpp)


# Add required libraries and include directories
target_include_directories(fractional_counter_display PRIVATE "." "include" $ENV{CADMIUM})
target_include_directories(fractional_counter PRIVATE "." "include" $ENV{CADMIUM})
target_include_directories(counter_coupled PRIVATE "." "include" $ENV{CADMIUM})

# set c++ standard
target_compile_options(fractional_counter_display PUBLIC -std=gnu++2b)
target_compile_options(fractional_counter PUBLIC -std=gnu++2b)
target_compile_options(counter_coupled PUBLIC -std=gnu++2b)