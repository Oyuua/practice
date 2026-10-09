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
//最大余数
#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            ans=max(ans,a[i] % a[j]);
        }
    }

    cout<<ans<<endl;
    return 0;
}
