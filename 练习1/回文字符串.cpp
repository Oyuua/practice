#include <bits/stdc++.h>//万能头
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.size();
        int cnt[2][26] = {};

        for (int i = 0; i < n; i++) {
            cnt[i % 2][s[i] - 'a']++;
        }

        bool ok = true;

        if (n % 2 == 0) {
            //偶数长度：对称位置分属不同组，两组字符频数必须相同
            for (int c = 0; c < 26; c++) {
                if (cnt[0][c] != cnt[1][c]) {
                    ok = false;
                    break;
                }
            }
        } else {
            //奇数长度：中心位置所属的组允许恰好一种字符出现奇数次
            int centerGroup = ((n - 1) / 2) % 2;

            for (int g = 0; g < 2; g++) {
                int odd = 0;

                for (int c = 0; c < 26; c++) {
                    if (cnt[g][c] % 2 != 0) {
                        odd++;
                    }
                }

                if (g == centerGroup) {
                    if (odd != 1) ok = false;
                } else {
                    if (odd != 0) ok = false;
                }
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
