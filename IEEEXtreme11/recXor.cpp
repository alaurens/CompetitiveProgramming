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
void findBornes(long l,long long n,long d1, long d2,vector<long long> &min,vector<long long> &max);

long long f(long long a) {
     long long res[] = {a,1,a+1,0};
     return res[a%4];
}

long long getXor(long long a, long long b) {
     return f(b)^f(a-1);
}

int main() {
    long h,l,t,d1,d2;
    std::cin >> t ;
    long long n;
    long long diff(0);
    vector<long long> borneMin,borneMax;
    long long answer(0);
    for(int i=0;i<t;i++){
        borneMin.clear();
        borneMax.clear();
        answer = 0;
        std::cin >> l >> h >> n >> d1 >> d2 ;
        if(d1==n && d2 == n+l*h-1){
           cout << 0 << endl;
            continue;
        }
        findBornes(l,n,d1,d2,borneMin,borneMax);
        if(d1!=n){
            //cout << n << " "<< borneMin.front()-1 << endl;
            answer  ^= getXor(n,borneMin.front()-1);
        }
        if(d1 !=n && d2 != n+l*h-1){
            for(int j=0;j<borneMin.size()-1;j++){
                diff = borneMax[j]+1-borneMin[j+1]+1;
                if(diff > 0){
                    ;
                }else if(diff == 0){
                    answer ^= borneMax[j];
                }else{
                    //cout << borneMax[j]+1 << " "<< borneMin[j+1]-1 << endl;
                    answer ^= getXor(borneMax[j]+1,borneMin[j+1]-1);
                }
            }
        }

        if(d2 != n+l*h-1)
        {
            //cout << borneMax.back()+1 << " "<< n+l*h-1 << endl;
            answer ^= getXor(borneMax.back()+1,n+l*h-1);
        }
        cout << answer << endl;
        //cout << endl;
    }
}

void findBornes(long l,long long n,long d1, long d2,vector<long long> &min,vector<long long> &max){
    long int i1,i2;

    long d11 = d1 - n + 1;
    long d22 = d2 - n + 1;

    i1 = d11%l;
    i2 = d22%l;
    if(i1==0)
        i1 = l;
    if(i2==0)
        i2 = l;

    if(i1<i2){
        min.push_back(d1);
        max.push_back(d1 + (i2-i1));
        while(max.back() != d2){
            min.push_back(min.back()+l);
            max.push_back(max.back()+l);
        }
    }else{
        min.push_back(d1 - (i1-i2));
        max.push_back(d1);
        while(min.back() != d2){
            min.push_back(min.back()+l);
            max.push_back(max.back()+l);
        }
    }
}
