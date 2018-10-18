//
//  SegmentTreeRSQ.cpp
//  competitve
//
//  Created by Antoine Laurens on 03.06.18.
//  Copyright © 2018 Antoine Laurens. All rights reserved.
//

#include <stdio.h>
#include <vector>

template<typename T>
class SegmentTreeRSQ{
private:
    std::vector<T> lazy;
    std::vector<long long> st;
    int n;
    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L,int R,std::vector<T> A){
        if(L==R){
            st[p] = A[L];
        }else{
            build( left(p) , L , (L+R)/2 ,A);
            build( right(p) , (L+R)/2 + 1 , R ,A);
            long long p1 = st[left(p)];
            long long p2 = st[right(p)];
            st[p] =  p1 + p2;
        }
    }

    long long rms(int p,int L ,int R ,int i ,int j){
        propagateLazy(p,L,R);

        if(L > j || R < i) return 0;
        if(L >= i && R <= j) return st[p];

        long long p1 = rms(left(p), L , (L+R)/2 , i, j);
        long long p2 = rms(right(p), (L+R)/2 + 1 , R , i, j);

        return p1 + p2;
    }

    void updateUtil(int p, int L, int R,int idx,T value){
        propagateLazy(p,L,R);
        if(L==R){
            st[p] = value;
            return;
        }
        if(idx <= (L+R)/2){
            updateUtil(left(p), L, (L+R)/2,idx,value);
        }else{
            updateUtil(right(p), (L+R)/2+1 , R , idx , value);
        }
        long long p1 = st[left(p)];
        long long p2 = st[right(p)];
        st[p] =  p1 + p2;
    }

    void updateRangeUtil(int p,int L, int R, int beg, int fin, T val){
        propagateLazy(p,L,R);
        if(L > fin || R < beg)
            return ;
        if(L >= beg && R <= fin){
            lazy[p] = val;
            return;
        }
        updateRangeUtil(left(p),L,(L+R)/2,beg,fin,val);
        updateRangeUtil(right(p),(L+R)/2+1,R,beg,fin,val);

    }

    void propagateLazy(int p,int L,int R){
        if(lazy[p] != 0){
            st[p] += (R-L+1)*lazy[p];
            lazy[left(p)] += lazy[p];
            lazy[right(p)] += lazy[p];
            lazy[p] = 0;
        }
    }

public:
    SegmentTreeRSQ(const std::vector<T>& _A){
        n = (int)_A.size();
        st.assign(4 * n,0);
        lazy.assign(4*n,0);
        build(1,0,n-1,_A);
    }

    long long rms(int i,int j){
        return rms(1,0,n-1,i,j);
    }

    void update(int idx, T value){
        updateUtil(1,0,n-1,idx,value);
    }

    void updateRange(int beg, int fin,T val){
        updateRangeUtil(1,0,n-1,beg,fin,val);
    }
};

