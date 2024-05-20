//
// Created by Beau on 2024/5/20.
//

#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#endif //BIG_INTEGER_H

#include <string>
#include <vector>
#include <deque>

using i64 = long long;

namespace beau {
    template<typename T = std::vector<int>>
    class BigInteger {
    private:
        T value;
    public:
        BigInteger() = default;
        explicit BigInteger(std::string value_string);
        void add(BigInteger &B);
        void sub(BigInteger &B);
        void mul(int b);
        void mul(i64 b);
        void mul(BigInteger &B);
        void div(BigInteger &B);
        void div(BigInteger &B,int &r);
        int size();
        T& getValue();
        friend std::ostream& operator << (std::ostream& os,const BigInteger& num) {
            for(int i = num.value.size()-1;~i;i--) os<<num.value[i];
            return os;
        }
    };

    template<typename T>
    BigInteger<T>::BigInteger(std::string value_string) {
        for(int i = value_string.size()-1;~i;i--) value.emplace_back(value_string[i]^48);
    }

    template<typename T>
    void BigInteger<T>::add(BigInteger &B) {
        if(B.size()>this->size()) return B.add(*this);
        T B_value = B.getValue();
        T ans;
        int t = 0;
        for(int i = 0;i<value.size();i++) {
            t+=value[i];
            if(i<B_value.size()) t+=B_value[i];
            ans.emplace_back(t%10);
            t/=10;
        }
        if(t) ans.emplace_back(t);
        value.assign(ans.begin(),ans.end());
    }

    template<typename T>
    void BigInteger<T>::sub(BigInteger &B) {

    }

    template<typename T>
    void BigInteger<T>::mul(int b) {

    }

    template<typename T>
    void BigInteger<T>::mul(i64 b) {

    }

    template<typename T>
    void BigInteger<T>::mul(BigInteger &B) {

    }

    template<typename T>
    void BigInteger<T>::div(BigInteger &B) {

    }

    template<typename T>
    void BigInteger<T>::div(BigInteger &B, int &r) {

    }

    template<typename T>
    int BigInteger<T>::size() {
        return value.size();
    }

    template<typename T>
    T& BigInteger<T>::getValue() {
        return value;
    }
}
