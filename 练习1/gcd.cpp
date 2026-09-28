#include <iostream>


using namespace std;
//方法一：超时

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

//方法三：时间限制30ms

#include <iostream>
using namespace std;

int GCD(int m, int n) {
    // 提前边界处理，0开销直接返回
    if (n == 0) return m;
    while (n != 0) {
        int temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}

int main() {
    ios::sync_with_stdio(false); // 关闭C++输入流与C stdio的同步，cin提速5~10倍
    cin.tie(nullptr); // 解绑cin与cout，避免输出刷新拖慢输入速度
    
    int M, N;
    cin >> M >> N;
    cout << GCD(M, N);
    return 0;
}



