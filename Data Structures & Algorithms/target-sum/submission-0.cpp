class Solution {
    unordered_map<int,unordered_map<int,int>> dp;
    int solve(int i, vector<int>& nums, int target){
        if(i>=nums.size() && target == 0) return 1;
        if(i>=nums.size()) return 0;
        if(dp.count(i) && dp[i].count(target)) return dp[i][target];
        return dp[i][target] = solve(i+1,nums,target+nums[i]) + solve(i+1,nums,target-nums[i]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,nums,target);
    }
};
