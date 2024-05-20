//
// Created by Beau on 2024/5/20.
//

#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#endif //DATA_STRUCTURE_H

#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>

namespace beau {
    template<typename T1,typename T2 = std::vector<T1>>
    class Stack {
    private:
        T2 values;
    public:
        Stack() = default;
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

    using intStack = Stack<int>;
    using i64Stack = Stack<i64>;
    using charStack = Stack<char>;
    using stringStack = Stack<std::string>;
    using doubleStack = Stack<double>;

    template<typename T>
    using dequeStack = Stack<T,std::deque<T>>;

    using intDequeStack = dequeStack<int>;
    using i64DequeStack = dequeStack<i64>;
    using charDequeStack = dequeStack<char>;
    using stringDequeStack = dequeStack<std::string>;
    using doubleDequeStack = dequeStack<double>;

    template<typename T1,typename T2 = std::deque<T1>>
    class DoubleLinkedList {
    private:
        T2 values;
    public:
        DoubleLinkedList() = default;
        T2& getValues();
        void push_back(T1 value);
        void push_front(T1 value);
        void push(T1 value,int idx);
        T1 pop_back();
        T1 pop_front();
        T1 pop(int idx);
        bool empty();
        int size();
        void sort();
        void sort(int beginidx,int endidx);
        void merge(DoubleLinkedList<T1> other);
        int find(T1 value);
        void print();
        friend std::ostream& operator << (std::ostream& os,const DoubleLinkedList<T1>& list) {
            std::vector<T1> tmp(list.values.begin(),list.values.end());
            for(int i = 0;i<tmp.size();i++) os << tmp[i] << " \n"[i==tmp.size()-1];
            return os;
        }
    };

    template<typename T1, typename T2>
    T2& DoubleLinkedList<T1, T2>::getValues() {
        return values;
    }

    template<typename T1, typename T2>
    void DoubleLinkedList<T1, T2>::push_back(T1 value) {
        values.emplace_back(value);
    }

    template<typename T1, typename T2>
    void DoubleLinkedList<T1, T2>::push_front(T1 value) {
        values.emplace_front(value);
    }

    template<typename T1, typename T2>
    void DoubleLinkedList<T1, T2>::push(T1 value, int idx) {
        values.insert(values.begin()+idx,value);
    }

    template<typename T1, typename T2>
    T1 DoubleLinkedList<T1, T2>::pop_back() {
        T1 tmp = values.back();
        values.pop_back();
        return tmp;
    }

    template<typename T1, typename T2>
    T1 DoubleLinkedList<T1, T2>::pop_front() {
        T1 tmp = values.front();
        values.pop_front();
        return tmp;
    }

    template<typename T1, typename T2>
    T1 DoubleLinkedList<T1, T2>::pop(int idx) {
        T1 tmp = values[idx];
        values.erase(values.begin()+idx,values.begin()+idx+1);
        return tmp;
    }

    template<typename T1, typename T2>
    bool DoubleLinkedList<T1, T2>::empty() {
        return values.empty();
    }

    template<typename T1, typename T2>
    int DoubleLinkedList<T1, T2>::size() {
        return values.size();
    }

    template<typename T1, typename T2>
    void DoubleLinkedList<T1, T2>::sort() {
        std::vector<T1> tmp(values.begin(),values.end());
        std::sort(tmp.begin(),tmp.end());
        values.clear();
        std::copy(tmp.begin(),tmp.end(),std::back_inserter(values));
    }

    template<typename T1, typename T2>
    void DoubleLinkedList<T1, T2>::sort(int beginidx, int endidx) {
        std::vector<T1> tmp(values.begin(),values.end());
        std::sort(tmp.begin()+beginidx,tmp.begin()+endidx+1);
        values.clear();
        std::copy(tmp.begin(),tmp.end(),std::back_inserter(values));
    }

    template<typename T1, typename T2>
    void DoubleLinkedList<T1, T2>::merge(DoubleLinkedList<T1> other) {
        std::copy(other.getValues().begin(), other.getValues().end(), std::back_inserter(values));
    }

    template<typename T1, typename T2>
    int DoubleLinkedList<T1, T2>::find(T1 value) {
        std::vector<T1> tmp(values.begin(),values.end());
        return std::find(tmp.begin(),tmp.end(),value)-tmp.begin()+1;
    }

    template<typename T1, typename T2>
    void DoubleLinkedList<T1, T2>::print() {
        //deque不适合遍历，效率比较低下，这里赋值给vector进行遍历
        std::vector<T1> tmp(values.begin(),values.end());
        for(int i = 0;i<tmp.size();i++) std::cout << tmp[i] << " \n"[i==tmp.size()-1];
    }

    using intDoubleLinkedList = DoubleLinkedList<int>;
    using i64DoubleLinkedList = DoubleLinkedList<i64>;
    using charDoubleLinkedList = DoubleLinkedList<char>;
    using stringDoubleLinkedList = DoubleLinkedList<std::string>;
    using doubleDoubleLinkedList = DoubleLinkedList<double>;

}
