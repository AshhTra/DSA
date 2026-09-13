class Solution {
    void dfs(int node, int &cnt, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        cnt++;

        for(auto neigh : adj[node]){
            if(!vis[neigh]){
                dfs(neigh, cnt, vis, adj);
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        vector<vector<int>>adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;

                long long dx = bombs[i][0] - bombs[j][0];     // x1 - x2
                long long dy = bombs[i][1] - bombs[j][1];     // y1 - y2
                long long r1 = bombs[i][2];

                if(dx*dx + dy*dy <= r1 * r1){
                    adj[i].push_back(j);
                } 
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> vis(n, 0);
            if(!vis[i]){
                int cnt = 0;
                dfs(i, cnt, vis, adj);
                ans = max(cnt, ans);          
            }  
        }
        return ans;
    }
};