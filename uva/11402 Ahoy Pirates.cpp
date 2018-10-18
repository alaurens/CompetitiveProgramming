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
class SegmentTree11402{
private:
    std::vector<int> lazy; // 3 inverse 1 everything is (1) 0 everything is (0)
    std::vector<int> st;
    int n;
    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L,int R,const std::vector<T>& A){
        if(L==R){
            st[p] = A[L];
        }else{
            build( left(p) , L , (L+R)/2 ,A);
            build( right(p) , (L+R)/2 + 1 , R ,A);
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] =  p1 + p2;
        }
    }

    int rms(int p,int L ,int R ,int i ,int j){
        propagateLazy(p,L,R);

        if(L > j || R < i) return 0;
        if(L >= i && R <= j) return st[p];

        int p1 = rms(left(p), L , (L+R)/2 , i, j);
        int p2 = rms(right(p), (L+R)/2 + 1 , R , i, j);

        return p1 + p2;
    }

    void inverseUtil(int p,int L, int R, int beg, int fin){
        propagateLazy(p,L,R);
        if(L > fin || R < beg)
            return ;
        if(L >= beg && R <= fin){
            st[p] = (R-L+1) - st[p];
            if(L!=R){
                lazy[left(p)] = flipLazy(lazy[left(p)]);
                lazy[right(p)] = flipLazy(lazy[right(p)]);
            }
            return;
        }
        inverseUtil(left(p),L,(L+R)/2,beg,fin);
        inverseUtil(right(p),(L+R)/2+1,R,beg,fin);

        int p1 = st[left(p)];
        int p2 = st[right(p)];
        st[p] =  p1 + p2;
    }

    void updateRangeUtil(int p,int L, int R, int beg, int fin, T val){
        propagateLazy(p,L,R);
        if(L > fin || R < beg)
            return ;
        if(L >= beg && R <= fin){
            st[p] = (R-L+1)*val;
            if(L!=R){
                lazy[left(p)] = val;
                lazy[right(p)] = val;
            }
            return;
        }
        updateRangeUtil(left(p),L,(L+R)/2,beg,fin,val);
        updateRangeUtil(right(p),(L+R)/2+1,R,beg,fin,val);

        int p1 = st[left(p)];
        int p2 = st[right(p)];
        st[p] =  p1 + p2;
    }

    void propagateLazy(int p,int L,int R){
        if(lazy[p] != -1){
            if(lazy[p] == 0){
                st[p] = 0;
                if(L!=R){
                    lazy[left(p)] = lazy[p];
                    lazy[right(p)] = lazy[p];
                }
            }
            if(lazy[p] == 1){
                st[p] = (R-L+1);
                if(L!=R){
                    lazy[left(p)] = lazy[p];
                    lazy[right(p)] = lazy[p];
                }
            }
            if(lazy[p] == 3){
                st[p] = (R-L+1) - st[p];
                if(L!=R){
                    lazy[left(p)] = flipLazy(lazy[left(p)]);
                    lazy[right(p)] = flipLazy(lazy[right(p)]);
                }
            }
            lazy[p] = -1;
        }
    }

    int flipLazy(int x){
        if(x == 3)
            return -1;
        if(x == 1)
            return 0;
        if(x == 0)
            return 1;
        return 3;
    }

public:
    SegmentTree11402(const std::vector<T>& _A){
        n = (int)_A.size();
        st.assign(4 * n,0);
        lazy.assign(4*n,-1);
        build(1,0,n-1,_A);
    }

    int rms(int i,int j){
        return rms(1,0,n-1,i,j);
    }

    void updateRange(int beg, int fin,T val){
        updateRangeUtil(1,0,n-1,beg,fin,val);
    }

    void inverse(int beg, int fin){
        inverseUtil(1,0,n-1,beg,fin);
    }
};


int main() {
#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    vector<int> X;
    int t;
    string pirates;
    sci(t);
    int caseCounter(1);
    while(t--){
        printf("Case %d:\n",caseCounter++);
        X.clear();
        int m;
        sci(m);
        rep(ii,m){
            int tt;
            sci(tt);
            cin >> pirates;
            rep(jj,tt){
                rep(kk,(int)pirates.length()){
                    X.push_back(pirates[kk]-'0');
                }
            }
        }
        SegmentTree11402<int> st(X);
        int numQ;
        char q;
        int idx1,idx2;
        int counter(1);
        sci(numQ);
        rep(ii,numQ){
            scanf("\n");
            scc(q);
            scii(idx1,idx2);
            if(q == 'I')
                st.inverse(idx1,idx2);
            if(q == 'F')
                st.updateRange(idx1,idx2,1);
            if(q == 'E')
                st.updateRange(idx1,idx2,0);
            if(q == 'S')
                printf("Q%d: %d\n",counter++,st.rms(idx1,idx2));
        }
    }
}
