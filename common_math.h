//
// Created by Beau on 2024/5/20.
//

#ifndef BEAU_MATH_H
#define BEAU_MATH_H

#endif //BEAU_MATH_H

using i64 = long long;
using i128 = __int128;

namespace beau {
    template<typename T1,typename T2>
    std::common_type_t<T1,T2> max(T1 num1,T2 num2) {
        return num1<num2?num2:num1;
    }

    template<typename T,typename... Ts>
    std::common_type_t<T,Ts...> max(T num,Ts... nums) {
        return num<max(nums...)?max(nums...):num;
    }

    template<typename T1,typename T2>
    std::common_type_t<T1,T2> min(T1 num1,T2 num2) {
        return num1>num2?num2:num1;
    }

    template<typename T,typename... Ts>
    std::common_type_t<T,Ts...> min(T num,Ts... nums) {
        return num>min(nums...)?min(nums...):num;
    }

    template<typename T>
    T abs(T num) {
        return num<0?-1*num:num;
    }

    template<typename T1,typename T2>
    std::common_type_t<T1,T2> gcd(T1 num1,T2 num2) {
        if(num2>num1) return gcd(num2,num1);
        return num2==0?num1:gcd(num2,num1%num2);
    }

    template<typename T,typename... Ts>
    std::common_type_t<T,Ts...> gcd(T num,Ts... nums) {
        return gcd(gcd(nums...),num);
    }

    template<typename T1,typename T2>
    std::common_type_t<T1,T2> lcm(T1 num1,T2 num2) {
        return num1/gcd(num1,num2)*num2;
    }

    template<typename T,typename... Ts>
    std::common_type_t<T,Ts...> lcm(T num,Ts... nums) {
        return lcm(lcm(nums...),num);
    }

    template<typename T>
    bool isPrimeNumber(T num) {
        if(num<2) return false;
        for(T i = 2;i<=num/i;i++) if(num%i==0) return false;
        return true;
    }
}
