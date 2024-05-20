//
// Created by Beau on 2024/5/20.
//

#ifndef ADVANCED_MATH_H
#define ADVANCED_MATH_H

#endif //ADVANCED_MATH_H

#include "common_math.h"

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

}