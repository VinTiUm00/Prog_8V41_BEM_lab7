#include <iostream>
#include <cassert>
#include "../headers/task_2.hpp"

void test_1(){
    assert(path_exist(1, 2, 5, 10, 8));
}

void test_2(){
    assert(!path_exist(18, 6, 10, 2, 0));
}

void test_3(){
    assert(path_exist(12, 3, 1, 17, 20));
}

int main(){
    std::cout << "test_1..." << std::flush;
    test_1();
    std::cout << "OK" << std::endl;

    std::cout << "test_2..." << std::flush;
    test_2();
    std::cout << "OK" << std::endl;

    std::cout << "test_3..." << std::flush;
    test_3();
    std::cout << "OK" << std::endl;

    system("pause");
    return 0;
}