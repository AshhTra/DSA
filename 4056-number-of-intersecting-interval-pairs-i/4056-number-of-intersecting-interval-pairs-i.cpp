class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(intervals[i][1] >= intervals[j][0]) cnt++;
            }
        }
        return cnt;
    }
};

// start = intervals[i][0];
//             if(end >= start){
//                 cnt += 1;
//                 end = max(end, intervals[i][1]);
//             }
//             else {
//                 end = intervals[i][1];
//             }