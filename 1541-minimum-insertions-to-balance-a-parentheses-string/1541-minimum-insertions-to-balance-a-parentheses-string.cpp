class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int cnt = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cnt++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') i++;
                else ans++;
                
                if (cnt > 0) cnt--;
                else ans++;
            }
        }
        return ans + 2 * cnt;
    }
};
