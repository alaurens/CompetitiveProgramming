/* Dynamic Programming implementation of MCP problem */
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <set>
#include <assert.h>
#include<limits.h>

#define DEBUG 0

using namespace std;

unsigned long long int binomial(unsigned long long int n,unsigned long long int k,unsigned long long int);

unsigned long long int power(unsigned long long x, unsigned long long int y, unsigned long long p );


int main() {
    unsigned long long int c;
    unsigned long long int b;
    unsigned long long int a;
    unsigned long long int t;
    cin >> t ;
    for(unsigned long long int i=0;i<t;i++){
        cin >> a >> b >> c;
        if(a == 1){
            cout << 1 << endl;
            continue;
        }
        binomial(b,c,a);
    }
}

unsigned long long int power(unsigned long long int x, unsigned long long int y, unsigned long long int p ){
    unsigned long long int res(1);

    while(y != 0){
        if(y & 0x01){
            res = res * x % p;
        }
        y = y >> 1;
        x = x*x%p;
    }
    return res;
}

unsigned long long int binomial(unsigned long long int n,unsigned long long int k,unsigned long long int a){
    if (k > n - k) {
        k = n - k;
    }
    unsigned long long ret = a;

    for (unsigned long long int kk = 0; kk < k; kk++) {
        ret = power(a,(n-kk)/(kk+1),1000000007);
    }
    cout << ret << endl;
    return ret;
}
