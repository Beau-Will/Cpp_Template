#include <iostream>
#include "advanced_math.h"
#include "big_integer.h"
#include "data_structure.h"
#include "my_algorithm.h"

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

    beau::DoubleLinkedList<int> list;
    for(int i = 1;i<=10;i++) {
        list.push_back(i);
    }
    list.push(99,5);
    list.print();
    list.sort();
    list.print();

    beau::DoubleLinkedList<int> list2;
    for(int i = 100;i>=91;i--) {
        list2.push_back(i);
    }
    list.merge(list2);
    list.print();
    std::cout << list;
    std::cout << list.find(99) << '\n';

    std::cout << beau::isPrimeNumber(2) << std::endl;

    beau::BigInteger A("10000");
    beau::BigInteger B("99999");
    A.add(B);
    std::cout << A << '\n';

    std::array<int,1005> a,tmp;
    for(int i = 1;i<=100;i++) a[i] = 100-i+1;
    int ans = 0;
    beau::get_reverse_order_pairs<int,1005>(a,tmp,1,100,ans);
    std::cout << ans << '\n';
    // beau::merge_sort<int,1005>(a,tmp,1,100);
    // for(int i = 1;i<=100;i++) std::cout << a[i] << " \n"[i%10==0];

    ans = 0;
    std::vector<double> b(105,0),tmp2(105,0);
    for(int i = 1;i<=10;i++) b[i] = 3.14*(10-i+1);
    beau::get_reverse_order_pairs<double>(b,tmp2,1,10,ans);
    std::cout << ans << '\n';
    // beau::merge_sort<double>(b,tmp2,1,10);
    // for(int i = 1;i<=10;i++) std::cout << b[i] << " \n"[i%10==0];


    return 0;
}
