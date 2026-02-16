cmake_minimum_required(VERSION 4.1)
project(CompilerConstruction_Lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(CompilerConstruction_Lab
        "Lab/Lab_01/Practice Task/Practice_Task_Even_a_Odd_b.cpp"
        "Lab/Lab_01/Practice Task/Practice_Task_goto.cpp"
        "Lab/Lab_01/Practice Task/Practice_Task_switch.cpp"
        Lab/Lab_01/Task1/Task_1_goto.cpp
        Lab/Lab_01/Task1/Task_1_switch.cpp
        Lab/Lab_01/Task2/Task_2_goto.cpp
        Lab/Lab_01/Task2/Task_2_switch.cpp
        Lab/Lab_02/Task/lexer.cpp
        Lab/Lab_03/Task/scanner.cpp
)
