class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum = 0;
        int pro = 1;
        while(num){
            int d = num % 10;
            sum += d;
            pro *= d;
            num /= 10;
        }
        sum += pro;
        return !(n % sum);
    }
};