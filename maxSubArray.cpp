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


long min(long a, long b){
    return (a<b)? a:b;
}

long max(long a, long b){
    return (a>b)? a:b;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d;
    cin >> d;
    vector<long> SizeDim(5,1);
    for(int i=0;i<d;i++){
        cin >> SizeDim[d-i-1];
    }

    int mat[SizeDim[0]][SizeDim[1]][SizeDim[2]][SizeDim[3]][SizeDim[4]];

    for(int i0=0;i0<SizeDim[0];i0++){
        for(int i1=0;i1<SizeDim[1];i1++){
            for(int i2=0;i2<SizeDim[2];i2++){
                for(int i3=0;i3<SizeDim[3];i3++){
                    for(int i4=0;i4<SizeDim[4];i4++){
                        scanf("%d",mat[i0][i1][i2][i3][i4]);
                        //cout << mat[i0][i1][i2][i3][i4] << endl;
                    }
                }
            }
        }
    }

    int q(0);
    int sum(0);
    cin >> q;
    vector<long> l(5,1);
    vector<long> r(5,1);
    for(int j = 0;j<q;j++){
        sum = 0;
        l = vector<long>(5,1);
        r = vector<long>(5,1);
        for(int i=0;i<d;i++){
            cin >> l[d-i-1];
        }
        for(int i=0;i<d;i++){
            cin >> r[d-i-1];
        }
        for(int i0=min(l[0],r[0])-1;i0<max(l[0],r[0]);i0++){
            for(int i1=min(l[1],r[1])-1;i1<max(l[1],r[1]);i1++){
                for(int i2=min(l[2],r[2])-1;i2<max(l[2],r[2]);i2++){
                    for(int i3=min(l[3],r[3])-1;i3<max(l[3],r[3]);i3++){
                        for(int i4=min(l[4],r[4])-1;i4<max(l[4],r[4]);i4++){
                            sum += mat[i0][i1][i2][i3][i4];
                        }
                    }
                }
            }
        }
        cout << sum << endl;
    }

}
