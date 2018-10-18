//
//  competitive.hpp
//  competitve
//
//  Created by Antoine Laurens on 16.03.18.
//  Copyright © 2018 Antoine Laurens. All rights reserved.
//

#ifndef competitive_h
#define competitive_h

#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include "stdc++.hpp"
#else
#include <bits/stdc++.h>
#endif

template<typename T1,typename T2>
inline std::ostream& operator << (std::ostream& os,const std::pair<T1,T2>& p) {
    return os << "(" << p.first << ", " << p.second << ")" ;
}

template<typename T>
inline std::ostream& operator << (std::ostream& os,const std::vector<T>& v) {
    bool first = true;
    os << "[";
    for(unsigned int i = 0; i< v.size(); i++){
        if(!first)
            os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}

template<typename T>
inline std::ostream& operator << (std::ostream& os,const std::deque<T>& v) {
    bool first = true;
    os << "[";
    for(unsigned int i = 0; i< v.size(); i++){
        if(!first)
            os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}


template<typename T>
inline std::ostream& operator << (std::ostream& os,const std::set<T>& v) {
    bool first = true;
    os << "[";
    for(typename std::set<T>::const_iterator it = v.begin(); it != v.end(); ++it){
        if(!first)
            os << ", ";
        os << *it;
        first = false;
    }
    return os << "]";
}

template<typename T1,typename T2>
inline std::ostream& operator << (std::ostream& os,const std::map<T1,T2>& m) {
    bool first = true;
    os << "[";
    for(typename std::map<T1,T2>::const_iterator it = m.begin(); it != m.end(); ++it){
        if(!first)
            os << ", ";
        os << it->first << ":" << it->second;
        first = false;
    }
    return os << "]";
}


#ifdef DEBUG
#define debug(args...)            {cerr<< #args <<" => ";dbg,args; cerr<<endl;}
#else
#define debug(args...)              // Just strip off all debug tokens
#endif
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        std::cerr<<v<<" ";
        return *this;
    }
} dbg;

//bit manipulation
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n))
#define LSOne(i) ((i)&(-(i)))
// pairs
#define mp make_pair // useful for working with pairs
#define fi first
#define se second
// logic
#define OR |
#define AND &
#define XOR ^
// math
#define maX(a,b) (a<b?b:a)
#define miN(a,b) (a>b?b:a)
#define abs(x) ((x)<0?(-(x)):x) // big bug here if "-x" is not surrounded by "()"
// comparaison
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
// next three are handy ways to get ints
#define sci(a) scanf("%d", &a)
#define scii(a,b) scanf("%d%d", &a, &b)
#define sciii(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define scd(a) scanf("%lf",&(a))
#define scs(a) scanf("%s",a)
#define scc(a) scanf("%c",&a)
// loops
#define rep(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define dwn(i,n) for(int i=(n); --i>=0; )
#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define dwnr(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)

// working with vectors
#define sz(a) ((int)(a.size()))
#define pb push_back
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
// for filling arrays
#define RESET(a) memset(a,0,sizeof(a))
#define FILL(a,b) memset((a),(b),sizeof(a))



// constants
#define INF 1001001001
#define PI 3.1415926535897932384626
#define MOD 1000000007


#endif /* competitive_h */
