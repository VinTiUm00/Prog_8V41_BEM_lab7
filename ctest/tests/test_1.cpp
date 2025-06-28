#include <cassert>
#include "../../headers/task_1.hpp"

void ctest_1(){
    assert(choosing_cleaner(6, 12) == 3);
}

int main(){
    ctest_1();
    system("pause");
    return 0;
}