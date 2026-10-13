#include <bits/stdc++.h>
using namespace std;
int main(){
vector<int> v={1,2,3,4,5};
//————find()————
//时间复杂度：O(n)
//头文件：<algorithm>
//找到就返回指向该元素的迭代器，找不到返回 last（尾后迭代器）
//逐个遍历，不要求有序
auto it=find(v.begin(),v.end(),5);//find(初始位置，结束位置，查找元素)
if(it!=v.end())
  cout<<"找到了"<<endl;
else
  cout<<"没找到"<<endl;

//————lower_bound()与upper_bound() 二分查找————
//时间复杂度：O(log n)
//头文件：<algorithm>
//区间一定要有序
auto it1=lower_bound(v.begin(),v.end(),value)//返回第一个 ≥ value的位置
auto it2=upper_bound(v.begin(),v.end(),value)//返回第一个 > value的位置

//若元素不存在，两者都返回第一个可插入且不破坏有序性的位置
vector<int> v = {1,2,4,4,5};
auto lo = lower_bound(v.begin(), v.end(), 3); // 指向 4（下标2），即"3该插在这"
auto up = upper_bound(v.begin(), v.end(), 3); // 同样指向 4（下标2）

//应用：利用两者的差值，可以直接统计某个值出现的次数
int cnt = upper_bound(v.begin(), v.end(), 4) - lower_bound(v.begin(), v.end(), 4); // 得到 2

