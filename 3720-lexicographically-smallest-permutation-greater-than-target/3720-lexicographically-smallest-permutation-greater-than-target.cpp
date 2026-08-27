class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        string ans = "";

        // Try to match target from left to right
        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // Try to keep same character
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
                continue;
            }

            // Same character unavailable.
            // Try smallest character greater than target[i].
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {
                    ans += char('a' + c);
                    freq[c]--;

                    // Remaining characters in smallest order
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }

            // Can't make current position greater.
            // Backtrack.
            while (!ans.empty()) {

                int pos = ans.size() - 1;

                freq[ans.back() - 'a']++;
                ans.pop_back();

                int cur = target[pos] - 'a';

                for (int c = cur + 1; c < 26; c++) {

                    if (freq[c] > 0) {
                        ans += char('a' + c);
                        freq[c]--;

                        // Remaining characters smallest first
                        for (int j = 0; j < 26; j++) {
                            while (freq[j] > 0) {
                                ans += char('a' + j);
                                freq[j]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // We formed target exactly.
        // Need STRICTLY greater, so backtrack.
        while (!ans.empty()) {

            int pos = ans.size() - 1;

            freq[ans.back() - 'a']++;
            ans.pop_back();

            int cur = target[pos] - 'a';

            for (int c = cur + 1; c < 26; c++) {

                if (freq[c] > 0) {
                    ans += char('a' + c);
                    freq[c]--;

                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};