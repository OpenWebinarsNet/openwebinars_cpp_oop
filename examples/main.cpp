#include <iostream>
#include "memoria.hpp"
#include "estructuras.hpp"
#include "clases.hpp"
#include "herencia.hpp"

int main() {
    std::cout << "Memory management examples" << std::endl;
    all_memory_examples();
    std::cout << "Structures management examples" << std::endl;
    all_structures_examples();
    std::cout << "Class management examples" << std::endl;
    class_example();
    std::cout << "Inheritance examples" << std::endl;
    LimitRunApp().run_test_app();
    return 0;
}