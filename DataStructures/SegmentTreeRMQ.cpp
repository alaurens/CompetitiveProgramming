//
//  SegmentTree.cpp
//  competitve
//
//  Created by Antoine Laurens on 02.06.18.
//  Copyright © 2018 Antoine Laurens. All rights reserved.
//

#include <stdio.h>
#include <vector>
class SegmentTreeRMQ{
private:
    std::vector<int> st,A;
    int n;
    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L,int R){
        if(L==R){
            st[p] = L;
        }else{
            build( left(p) , L , (L+R)/2 );
            build( right(p) , (L+R)/2 + 1 , R );
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p,int L ,int R ,int i ,int j){
        if(L > j || R < i) return -1;
        if(L >= i && R <= j) return st[p];

        int p1 = rmq(left(p), L , (L+R)/2 , i, j);
        int p2 = rmq(right(p), (L+R)/2 + 1 , R , i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }

    void updateUtil(int p, int L, int R,int idx,int value){
        if(L==R){
            return;
        }
        if(idx <= (L+R)/2){
            updateUtil(left(p), L, (L+R)/2,idx,value);
        }else{
            updateUtil(right(p), (L+R)/2+1 , R , idx , value);
        }
        int p1 = st[left(p)];
        int p2 = st[right(p)];
        st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }

public:
    SegmentTreeRMQ(const std::vector<int>& _A){
        A = _A; n = (int)_A.size();
        st.assign(4 * n,0);
        build(1,0,n-1);
    }

    int rmq(int i,int j){
        return rmq(1,0,n-1,i,j);
    }

    void update(int idx, int value){
        A[idx] = value;
        updateUtil(1,0,n-1,idx,value);
    }
};

