#include <iostream>
#include <cassert>
#include "../headers/task_1.hpp"

int test_1(){
    assert(choosing_cleaner(6, 10));
    if (choosing_cleaner(6, 10) != 0){
        std::cout << "test 1 failed" << std::endl;
        return 1;
    }
    return 0;
}

int test_2(){
    if (choosing_cleaner(1, 2) != 0){
        std::cout << "test 2 failed" << std::endl;
        return 1;
    }
    return 0;
}

int test_3(){
    if (choosing_cleaner(10, 81) != 9){
        std::cout << "test 3 failed" << std::endl;
        return 1;
    }
    return 0;
}

int main(){
    assert(test_1);
    assert(test_2);
    assert(test_3);

    std::cout << "Tests completed successfully!" << std::endl;

    return 0;
}