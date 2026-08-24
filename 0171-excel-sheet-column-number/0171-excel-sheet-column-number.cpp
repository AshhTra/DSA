class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size();
        int i = 0;
        int ans = 0;
        while(i < n){
            int d = s[i] - 'A';
            d++;
            ans = ans * 26 + d;
            i++;
        }
        return ans;
    }
};