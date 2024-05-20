//
// Created by Beau on 2024/5/20.
//

#ifndef ADVANCED_MATH_H
#define ADVANCED_MATH_H

#endif //ADVANCED_MATH_H

#include <iostream>
#include "common_math.h"
#include <vector>

namespace beau {
    template<typename T1 = i64,typename T2 = i64,typename T3 = i64>
    std::common_type_t<T1,T2,T3> quick_power(T1 a,T2 b,T3 p) {
        std::common_type_t<T1,T2,T3> ans = 1;
        while(b) {
            if(b&1) ans=ans*a%p;
            b>>=1;
            a=a*a%p;
        }
        return ans;
    }

    template<typename T1 = i64,typename T2 = i64>
    std::common_type_t<T1,T2> inverse_element(T1 a,T2 p) {
        return quick_power(a,p-2,p);
    }

    template<typename T>
    void euler_sieve(T n) {
        std::vector<T> minp, primes;
        minp.assign(n+1,0);
        primes.clear();
        for(T i = 2;i<=n;i++) {
            if(minp[i] == 0) {
                minp[i] = i;
                primes.emplace_back(i);
            }
            for(auto p:primes) {
                if(i*p>n) {
                    break;
                }
                minp[i*p] = p;
                if(p == minp[i]) {
                    break;
                }
            }
        }
    }
}