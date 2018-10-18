/ // Accepted

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

int main(){
    int t;
    long long a,b;
    int x,y;
    while(scanf("%d",&t),t){
        scanf("%d %d",&x,&y);
        while (t--) {
            scanf("%lld %lld",&a,&b);
            if(x==a || y== b) printf("divisa\n");
            else if(x>a && y > b) printf("SO\n");
            else if(x<a && y < b) printf("NE\n");
            else if(x>a && y < b) printf("NO\n");
            else if(x<a && y > b) printf("SE\n");
        }
    }
}
