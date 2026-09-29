#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#方法一
int main(){
  vector<int> v{1,1,1,2,2,2,3,3,4,4,5};
  sort(v.begin(),v.end());//先排序
  int sz=v.size();
  int low=0;
  for(size_t i=1;i<sz;i++){
  if(v[i]!=v[low])
  v[++low]=v[i];
  }
  v.resize(low+1);

方法二；unique()，需要头文件<algorithm>
  auto it =unique(v.begin(),v.end());//找到最后一个不重复的元素下标
  v.erase(it,v.end());//清除从it到最后的数据
  }
