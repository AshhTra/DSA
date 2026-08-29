class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        long long maxi = 0;
        // long long len = 0;
        int ind = -1;
        for (int mid = 0; mid < n; mid++) {
            long long len = 1;
            // maxi = max(maxi, len);
            if(len > maxi){
                maxi = len;
                ind = mid;
            }
            int l = mid - 1, r = mid + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                len = r - l + 1;
                if(len > maxi){
                    maxi = len;
                    ind = l;
                }
                l--;
                r++;
            }

            l = mid;
            r = mid + 1;
            len = 0;
            while (l >= 0 && r < n && s[l] == s[r]) {
                len = r - l + 1;
                if(len > maxi){
                    maxi = len;
                    ind = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(ind, maxi);
    }
};
