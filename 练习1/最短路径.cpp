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
