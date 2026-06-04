class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int> need(n, -1);

        for (auto &r : requirements) {
            need[r[0]] = r[1];
        }

        if (need[0] > 0) return 0;

        const int MAX_INV = 400;

        vector<int> dp(MAX_INV + 1, 0);
        dp[0] = 1;

        for (int len = 1; len <= n; len++) {
            vector<int> pref(MAX_INV + 1, 0);
            pref[0] = dp[0];

            for (int i = 1; i <= MAX_INV; i++) {
                pref[i] = (pref[i - 1] + dp[i]) % MOD;
            }

            vector<int> ndp(MAX_INV + 1, 0);

            for (int inv = 0; inv <= MAX_INV; inv++) {
                int L = max(0, inv - (len - 1));

                ndp[inv] = pref[inv];
                if (L > 0) {
                    ndp[inv] =
                        (ndp[inv] - pref[L - 1] + MOD) % MOD;
                }
            }

            int req = need[len - 1];

            if (req != -1) {
                vector<int> filtered(MAX_INV + 1, 0);

                if (req <= MAX_INV) {
                    filtered[req] = ndp[req];
                }

                dp.swap(filtered);
            } else {
                dp.swap(ndp);
            }
        }

        int finalReq = need[n - 1];

        if (finalReq != -1) {
            return dp[finalReq];
        }

        long long ans = 0;
        for (int x : dp) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};