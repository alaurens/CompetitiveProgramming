// Accepted
//  main.cpp
//  competitve
//
//  Created by Antoine Laurens on 13.03.18.
//  Copyright © 2018 Antoine Laurens. All rights reserved.
//



#include "competitive.hpp"
using namespace std;

typedef std::pair<int,int> ii;
typedef std::vector<int> vi;
typedef std::vector<ii> vii;
typedef std::vector< std::vector<int> > vvi;
typedef std::pair<int,ii> iii;
typedef long long ll;
typedef long l;

template<typename T>
class SegmentTree11235{
private:

    std::vector<int> A;
    std::vector<int> st;
    std::vector<int> le;
    std::vector<int> ri;
    int n;
    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L,int R){
        if(L==R){
            st[p] = le[p] = ri[p] = 1;
        }else{
            int mid = (L+R)/2;

            build( left(p) , L , mid );
            build( right(p) , mid + 1 , R );

            st[p] = maX(st[left(p)],st[right(p)]);
            if (A[mid] == A[mid+1])
                st[p] = maX(st[p],le[right(p)]+ri[left(p)]);

            le[p] = le[left(p)];
            if (A[L] == A[mid+1])
                le[p] += le[right(p)];

            ri[p] = ri[right(p)];
            if (A[R] == A[mid])
                ri[p] += ri[left(p)];
        }
    }

    int rmq(int p,int L ,int R ,int i ,int j){

        if(L > j || R < i) return 0;
        if(L >= i && R <= j) return st[p];

        int mid = (L+R)/2;
        int p1 = rmq(left(p), L , mid , i, j);
        int p2 = rmq(right(p), mid + 1 , R , i, j);
        if(A[mid] == A[mid+1] ){
            int x = maX(i,mid - ri[left(p)] + 1);
            int y = miN(j,mid+1 + le[right(p)] - 1);
            return maX(maX(y-x+1,p1),p2);
        }
        return p1>p2 ? p1 :p2;
    }

public:
    SegmentTree11235(const std::vector<T>& _A){
        A = _A;
        n = (int)_A.size();
        le.assign(4*n,0);
        ri.assign(4*n,0);
        st.assign(4*n,0);
        build(1,0,n-1);
    }

    int rmq(int i,int j){
        return rmq(1,0,n-1,i,j);
    }

};

//int left[4*100100],right[4*100100],max[4*100100];
//int a[100000];

void build(int p,int L,int R,int){

}
int rmq(int i,int j){
    return 0;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    vector<int> A;
    int n,q;
    while(scii(n,q),n!=0){
        A.clear();
        rep(i,n){
            int t;
            sci(t);
            A.push_back(t);
        }
        SegmentTree11235<int> st(A);
        rep(ii,q){
            int i,j;
            scii(i,j);
            i--;j--;
            printf("%d\n",st.rmq(i,j));
        }
    }
}
