#include <iostream>


using namespace std;
//方法一：超时
/*
int GCD(int m,int n){
    if(n == 0) return m;
    if(m == 0) return n;
    if(m<n)
    {
        return GCD(m,n-m);
    }
    if(m==n) return m;
    if(m>n) return GCD(m-n,n);
}
*/
//方法二：辗转相除法

int GCD(int m, int n){
    return n == 0 ? m : GCD(n, m % n);
}

int main(){
    int M,N;
    cin>>M>>N;
    cout<<GCD(M,N);

    return 0;
}


