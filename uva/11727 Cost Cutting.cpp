// Accepted

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;



int main(){
    int t;
    scanf("%d",&t);
    int a,b,c;
    int count = 1;
    while(t--){
        scanf("%d %d %d",&a,&b,&c);
        if(a > b)  swap(a,b)  ;
        if(b > c)  swap(b,c) ;
        if(a > b)  swap(a,b) ;
        printf("Case %d: %d\n",count,b);
        count++;
    }

}
