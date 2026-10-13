#include <bits/stdc++.h>

using namespace std;
bool exist(vector<int> &v,int a){
    for(int i=0;i<v.size();i++){
        if(v[i]==a) return true;
    }

    return false;
}
int main(){
    int M,N;
    cin>>M>>N;
    vector<int> v(N);
    vector<int> v2(1);
    int cnt=1;
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    v2[0]=v[0];
    for(int i=1;i<N;i++){
        if(!exist(v2,v[i])){
            if(v2.size()>=M){
                v2.erase(v2.begin());//erase(迭代器)
            }
            v2.push_back(v[i]);
            cnt++;
        }
    }
    cout<<cnt<<endl;

    return 0;
}
