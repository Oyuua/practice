//多项式求和
#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    double x;
    cin>>n>>x;
    double val=0;
    for(int i=0;i<=n;i++){
        int a[i];
        cin>>a[i];
        double y=1;
        for(int j=0;j<n-i;j++){
            y*=x;
        }
        val+=a[i]*y;
    }
    printf("%.3f\n",val);
}
