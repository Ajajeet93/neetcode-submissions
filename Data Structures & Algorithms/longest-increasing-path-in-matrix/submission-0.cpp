class Solution {
    int solve(int i, int j,int prev, vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j] <= prev) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int top = solve(i-1,j,matrix[i][j],matrix,dp);
        int dowm = solve(i+1,j,matrix[i][j],matrix,dp);
        int right = solve(i,j+1,matrix[i][j],matrix,dp);
        int left = solve(i,j-1,matrix[i][j],matrix,dp);
        
        return dp[i][j] = max({top,dowm,left,right}) + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        int res = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j] == -1){
                    int val = solve(i,j,INT_MIN,matrix,dp);
                    res = max(res,val);
                }
            }
        }
        return res;
    }
};
