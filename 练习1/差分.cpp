#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_ID = 100000;
    //数组存储情侣映射
    vector<int> couple(MAX_ID, -1);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        couple[a] = b;
        couple[b] = a;
    }

    int M;
    cin >> M;
    vector<int> arr2(M);
    vector<int> pos(MAX_ID, -1);
    for (int i = 0; i < M; ++i) {
        cin >> arr2[i];
        pos[arr2[i]] = i;//记录下标
    }

    vector<int> diff(M + 2, 0);
    vector<bool> is_single(M, false);

    for (int i = 0; i < M; ++i) {
        int id = arr2[i];
        if (pos[id] == -1) continue;

        int partner = couple[id];
        //没有情侣或情侣不在聚会现场，标记为单身
        if (partner == -1 || pos[partner] == -1) {
            is_single[i] = true;
            continue;
        }

        int j = pos[partner];
        int l = i, r = j;
        if (l > r) swap(l, r);
        //相邻情侣场景
        if (r == l + 1) {

            if (l - 1 >= 0) { 
                ++diff[l - 1];
                 --diff[l];
                }
            if (r + 1 <  M) {
                 ++diff[r + 1];
                  --diff[r + 2];
                 }
        } else {
            //不相邻情侣场景
            diff[l + 1]++;
            diff[r]--;
        }

        //标记已处理，避免重复计算
        pos[arr2[i]] = -1;
        pos[arr2[j]] = -1;
    }

    //差分还原count数组
    vector<int> count(M);
    count[0] = diff[0];
    for (int i = 1; i < M; ++i) {
        count[i] = count[i - 1] + diff[i];
    }

    //找最大撒狗粮次数
    int max_cnt = -1;
    for (int i = 0; i < M; ++i) {
        if (is_single[i] && count[i] > max_cnt) {
            max_cnt = count[i];
        }
    }

    //收集结果并排序
    vector<int> res;
    for (int i = 0; i < M; ++i) {
        if (is_single[i] && count[i] == max_cnt) {
            res.push_back(arr2[i]);
        }
    }
    sort(res.begin(), res.end());

    for (size_t i = 0; i < res.size(); ++i) {
        if (i) cout << " ";//用空格间隔开
        //补前导0
        cout.fill('0');
        cout.width(5);
        cout << res[i];
    }

    return 0;
}
