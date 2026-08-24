class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";

        while(n > 0) {
            n--;  // Excel is 1-based :)
            int d = n % 26;
            ans += ('A' + d);
            n /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// A - Z = 26
// AA - ZZ = 27, 26 + (26 * 26)
// AAA - ZZZ =  703, 26 + (26 * 26) + (26 * 26 * 26)