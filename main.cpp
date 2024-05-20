#include <iostream>
#include "beau_math.h"
#include "data_structure.h"

int main()
{
    std::cout << beau::gcd(10,short(5),20LL) << std::endl;
    std::cout << beau::lcm(10,short(5),20LL) << std::endl;

    beau::Stack<int> stk;
    for(int i = 1;i<=10;i++) stk.push(i);
    std::cout << stk.size() << ' ' << stk.empty() << std::endl;
    for(int i = 1;i<=5;i++) {
        std::cout << stk.pop() << '\n';
    }
    return 0;
}
