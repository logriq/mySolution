#include <iostream>
#include "Repository8.h"

int main() {

    Repository8<bool> bool_repo;
    bool_repo.set(0, true);
    bool_repo.set(2, true);
    bool_repo.set(4, false);

    std::cout << "Bool 0: " << bool_repo.get(0) << std::endl;
    std::cout << "Bool 2: " << bool_repo.get(2) << std::endl;
    std::cout << "Bool 4: " << bool_repo.get(4) << std::endl;
    std::cout << "Bool 7: " << bool_repo.get(7) << std::endl;

    Repository8<int> int_repo;
    int_repo.set(0, 10);
    int_repo.set(1, 20);

    std::cout << "Int 0: " << int_repo.get(0) << std::endl;
    std::cout << "Int 1: " << int_repo.get(1) << std::endl;

    return 0;
}