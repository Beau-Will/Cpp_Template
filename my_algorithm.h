//
// Created by Beau on 2024/5/20.
//

#ifndef MY_ALGORITHM_H
#define MY_ALGORITHM_H

#endif //MY_ALGORITHM_H

#include <vector>
#include <array>

namespace beau {
    template<typename T1,int MAXN,typename T2 = std::array<T1,MAXN>,typename T3 = int>
    void merge_sort(T2& nums,T2& tmp,T3 l,T3 r) {
        if(l>=r) return;
        int mid = l+r>>1;
        merge_sort<T1,MAXN>(nums,tmp,l,mid),merge_sort<T1,MAXN>(nums,tmp,mid+1,r);
        T3 k = 0,i = l,j = mid+1;
        while(i<=mid&&j<=r){
            if(nums[i]<=nums[j]) tmp[k++] = nums[i++];
            else tmp[k++] = nums[j++];
        }
        while(i<=mid) tmp[k++] = nums[i++];
        while(j<=r) tmp[k++] = nums[j++];
        for(T3 i = l,j = 0;i<=r;i++,j++) nums[i] = tmp[j];
    }

    template<typename T1,typename T2 = std::vector<T1>,typename T3 = int>
    void merge_sort(T2& nums,T2& tmp,T3 l,T3 r) {
        if(l>=r) return;
        int mid = l+r>>1;
        merge_sort<T1>(nums,tmp,l,mid),merge_sort<T1>(nums,tmp,mid+1,r);
        T3 k = 0,i = l,j = mid+1;
        while(i<=mid&&j<=r){
            if(nums[i]<=nums[j]) tmp[k++] = nums[i++];
            else tmp[k++] = nums[j++];
        }
        while(i<=mid) tmp[k++] = nums[i++];
        while(j<=r) tmp[k++] = nums[j++];
        for(T3 i = l,j = 0;i<=r;i++,j++) nums[i] = tmp[j];
    }

    template<typename T1,int MAXN,typename T2 = std::array<T1,MAXN>,typename T3 = int,typename T4 = i64>
    void get_reverse_order_pairs(T2& nums,T2& tmp,T3 l,T3 r,T4 &ans) {
        if(l>=r) return;
        int mid = l+r>>1;
        merge_sort<T1,MAXN>(nums,tmp,l,mid),merge_sort<T1,MAXN>(nums,tmp,mid+1,r);
        T3 k = 0,i = l,j = mid+1;
        while(i<=mid&&j<=r){
            if(nums[i]<=nums[j]) tmp[k++] = nums[i++];
            else tmp[k++] = nums[j++],ans+=mid-i+1;
        }
        while(i<=mid) tmp[k++] = nums[i++];
        while(j<=r) tmp[k++] = nums[j++];
        for(T3 i = l,j = 0;i<=r;i++,j++) nums[i] = tmp[j];
    }

    template<typename T1,typename T2 = std::vector<T1>,typename T3 = int,typename T4 = i64>
    void get_reverse_order_pairs(T2& nums,T2& tmp,T3 l,T3 r,T4& ans) {
        if(l>=r) return;
        int mid = l+r>>1;
        merge_sort<T1>(nums,tmp,l,mid),merge_sort<T1>(nums,tmp,mid+1,r);
        T3 k = 0,i = l,j = mid+1;
        while(i<=mid&&j<=r){
            if(nums[i]<=nums[j]) tmp[k++] = nums[i++];
            else tmp[k++] = nums[j++],ans+=mid-i+1;
        }
        while(i<=mid) tmp[k++] = nums[i++];
        while(j<=r) tmp[k++] = nums[j++];
        for(T3 i = l,j = 0;i<=r;i++,j++) nums[i] = tmp[j];
    }
}