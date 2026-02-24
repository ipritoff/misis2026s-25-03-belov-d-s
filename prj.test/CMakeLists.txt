add_executable(complex_test complex_test.cpp "arrayd_test.cpp")
target_link_libraries(complex_test complex)

add_executable(rational_test rational_test.cpp "arrayd_test.cpp")
target_link_libraries(rational_test rational)

add_executable(stacka_test stacka_test.cpp "arrayd_test.cpp")
target_link_libraries(stacka_test stacka)

add_executable(arrayd_test arrayd_test.cpp)
target_link_libraries(arrayd_test arrayd)