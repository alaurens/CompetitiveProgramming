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
class SegmentTree12532{
private:
    std::vector<int> A;
    std::vector<int> st;
    int n;
    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L,int R){
        if(L==R){
            st[p] = findSign(A[L]);
        }else{
            int mid = (L+R)/2;

            build( left(p) , L , mid );
            build( right(p) , mid + 1 , R );

            st[p] = findSign(st[left(p)]*st[right(p)]);
        }
    }

    int findSign(int a){
        if(a == 0)
            return 0;
        if(a>0)
            return 1;

        return -1;
    }

    char getSign(int a){
        if(a == 0)
            return '0';
        if(a>0)
            return '+';

        return '-';
    }

    char getSign(char a,char b){
        if(a == '.')
            return b;
        if(b == '.')
            return a;
        if(a == '0' || b == '0')
            return '0';
        if(a == b)
            return '+';

        return '-';
    }

    int rmq(int p,int L ,int R ,int i ,int j){

        if(L > j || R < i) return '.';
        if(L >= i && R <= j) return getSign(st[p]);

        int mid = (L+R)/2;
        char p1 = rmq(left(p), L , mid , i, j);
        char p2 = rmq(right(p), mid + 1 , R , i, j);

        return getSign(p1,p2);
    }

    void change(int p,int L,int R,int idx, int val){
        if(L==R){
            st[p] = findSign(A[L]);
        }else{
            int mid = (L+R)/2;
            if (idx <= mid)
                change( left(p) , L , mid , idx , val );
            else
                change( right(p) , mid + 1 , R , idx , val);

            st[p] = findSign(st[left(p)]*st[right(p)]);
        }
    }

public:
    SegmentTree12532(const std::vector<T>& _A){
        A = _A;
        n = (int)_A.size();
        st.assign(4*n,0);
        build(1,0,n-1);
    }

    char rmq(int i,int j){
        return rmq(1,0,n-1,i,j);
    }

    void change(int idx, int val){
        A[idx] = val;
        change(1,0,n-1,idx,val);
    }

};

int main() {
#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    vector<int> X;
    int n,k;
    string command;
    int a,b;
    while(scii(n,k) != EOF){
        X.clear();
        rep(ii,n){
            int t;
            sci(t);
            X.push_back(t);
        }
        SegmentTree12532<int> st(X);
        rep(ii,k){
            cin >> command;
            scii(a,b);
            if(command == "C"){
                a--;
                st.change(a,b);
            }else{
                a--;
                b--;
                printf("%c",st.rmq(a,b));
            }
        }
        printf("\n");
    }
}
