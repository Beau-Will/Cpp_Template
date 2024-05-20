//
// Created by Beau on 2024/5/20.
//

#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#endif //DATA_STRUCTURE_H

#include <vector>

namespace beau {
    template<typename T1,typename T2 = std::vector<T1>>
    class Stack {
    private:
        T2 values;
    public:
        void push(T1 value);
        T1 top();
        T1 pop();
        bool empty();
        int size();
    };

    template<typename T1, typename T2>
    void Stack<T1, T2>::push(T1 value) {
        values.emplace_back(value);
    }

    template<typename T1, typename T2>
    T1 Stack<T1, T2>::top() {
        return values.back();
    }

    template<typename T1, typename T2>
    T1 Stack<T1, T2>::pop() {
        T1 tmp = values.back();
        values.pop_back();
        return tmp;
    }

    template<typename T1, typename T2>
    bool Stack<T1, T2>::empty() {
        return values.empty();
    }

    template<typename T1, typename T2>
    int Stack<T1, T2>::size() {
        return values.size();
    }
}


