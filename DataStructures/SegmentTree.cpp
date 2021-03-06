//
//  SegmentTree.cpp
//  
//
//  Created by Antoine Laurens on 03.06.18.
//

#include <stdio.h>
#include <vector>
// please note that less has a strict inequality and therefor when
// the segment tree is built if there exist multiple min element in range
// the index that will be returned will be the LAST one in the range
template<typename T,class Comp = std::less<T>>
class SegmentTree{
private:
    Comp comparator;
    std::vector<T> A;
    std::vector<int> st;
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
            st[p] = comparator(A[p1],A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p,int L ,int R ,int i ,int j,bool value = false){
        if(L > j || R < i) return -1;
        if(L >= i && R <= j) return st[p];

        int p1 = rmq(left(p), L , (L+R)/2 , i, j);
        int p2 = rmq(right(p), (L+R)/2 + 1 , R , i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return comparator(A[p1],A[p2]) ? p1 : p2;
    }

    void updateUtil(int p, int L, int R,int idx,T value){
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
        st[p] = comparator(A[p1],A[p2]) ? p1 : p2;
    }

public:
    SegmentTree(const std::vector<T>& _A){
        A = _A; n = (int)_A.size();
        st.assign(4 * n,0);
        build(1,0,n-1);
    }

    int rmq(int i,int j){
        return rmq(1,0,n-1,i,j);
    }

    int rmqValue(int i,int j){
        return A[rmq(1,0,n-1,i,j)];
    }

    void update(int idx, T value){
        A[idx] = value;
        updateUtil(1,0,n-1,idx,value);
    }

};
