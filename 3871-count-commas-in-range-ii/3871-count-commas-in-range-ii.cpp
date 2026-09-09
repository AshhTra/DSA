class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long start = 1000;
        int comma = 1;

        while(start <= n){
            long long end = min(n, start * 1000 - 1);
            ans += (end - start + 1) * comma;

            start *= 1000;
            comma += 1;
        }
        return ans;
    }
};