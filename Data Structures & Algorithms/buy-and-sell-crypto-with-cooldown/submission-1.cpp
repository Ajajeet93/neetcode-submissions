class Solution {
    unordered_map<int,unordered_map<bool,int>> dp;
    int solve(int i, bool isBuy, vector<int> &prices){
        if(i>=prices.size()) return 0;
        if(dp.count(i) &&  dp[i].count(isBuy)) return dp[i][isBuy];
        int buy = INT_MIN;
        if(!isBuy){
            buy = solve(i+1,true,prices) - prices[i];
        }
        int sell = INT_MIN;
        if(isBuy){
            sell = prices[i] + solve(i+2,false,prices);
        }

        int leave = solve(i+1,isBuy,prices);

        return dp[i][isBuy] = max({buy,sell,leave});
    }
public:
    int maxProfit(vector<int>& prices) {
        
        return solve(0,false,prices);
    }
};
