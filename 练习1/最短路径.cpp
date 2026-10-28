//邻接矩阵
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int N,M;
    while (cin >> N >> M) {
    vector<vector<int>> A(N,vector<int>(N,-1));
    for(int i=0;i<N;i++){
        A[i][i]=0;
    }
    for(int i=0;i<M;i++){
        int a,b,x;
        cin>>a>>b>>x;
        if(A[a][b]==-1){
            A[a][b]=x;
            A[b][a]=x;
        }
    }
    int S,T;
    cin>>S>>T;
vector<int> dist(N, -1);
        vector<bool> visited(N, false);

        dist[S] = 0;

        for (int i = 0; i < N; i++) {
            int u = -1;

            //找到距离最小的未访问城镇
            for (int j = 0; j < N; j++) {
                if (!visited[j] && dist[j] != -1 &&
                    (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            //没有可继续访问的城镇
            if (u == -1) {
                break;
            }

            visited[u] = true;

            //更新相邻城镇的最短距离
            for (int v = 0; v < N; v++) {
                if (!visited[v] && A[u][v] != -1) {
                    int nd = dist[u] + A[u][v];

                    if (dist[v] == -1 || nd < dist[v]) {
                        dist[v] = nd;
                    }
                }
            }
        }

        cout << dist[T] << '\n';
    }

    return 0;
}


//方法二
#include <iostream>
#include <vector>

using namespace std;
const int INF=0x3f3f3f3f;
//竞赛中常用0x3f3f3f3f代替INT_MAX，防止溢出；
struct Edge{
    int start;
    int end;
    int weight;
};
vector<Edge> edges;

int main(){
    int N,M;
    while(!((N==0)&&(M=0))){
        cin>>N>>M;
    edges.clear();
    for(int i=0;i<M;i++){
        //输入边
        int s,e,w;
        cin>>s>>e>>w;
        edges.push_back({s,e,w});
        edges.push_back({e,s,w});
    }
    int a[105];
    for(int i=0;i<105;i++) a[i]=INT_MAX;
    //或vector<int> a(105,INT_MAX);
    a[1]=0;
    bool update=true;
    for(int i=0;i<N-1 && update;i++){
        update = false;//如果不更新了，则退出迭代
    for(Edge e:edges){//从edges循环取出赋给Edge e
        if(a[e.start]!=INT_MAX && a[e.start]+e.weight<a[e.end]){
            a[e.end]=a[e.start]+e.weight;
            update=true;
        }
    }
}
cout<<a[N]<<endl;
}

return 0;
}
