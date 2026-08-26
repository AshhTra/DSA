class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        int cnt = 0;
        int len = 1e9, ind = -1;
        while(j < n){
            cnt += s[j] - '0';
            while(cnt > k){
                cnt -= s[i] - '0';
                i++;
            }

            if(cnt == k){
                while(s[i] == '0'){
                    i++;
                }
                if(len > j - i + 1){
                    len = j - i + 1;
                    ind = i;
                }else if (j - i + 1 == len) { // coz we need lexicographically smallest :)
                    string curr = s.substr(i, len);
                    string old = s.substr(ind, len);

                    if (curr < old) {
                        ind = i;
                    }
                }
            }
            j++;
        }
        if(ind == -1) return "";
        return s.substr(ind, len);
    }
};