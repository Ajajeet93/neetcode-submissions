class Solution {
    unordered_map<int,unordered_map<int,unordered_map<bool,int>>> dp;
    int solve(int i, int prev, bool isBuy, vector<int> &prices){
        if(i>=prices.size()) return 0;
        if(dp.count(i) && dp[i].count(prev) && dp[i][prev].count(isBuy)) return dp[i][prev][isBuy];
        int buy = INT_MIN;
        if(!isBuy){
            buy = solve(i+1,prices[i],true,prices);
        }
        int sell = INT_MIN;
        if(isBuy){
            sell = prices[i] - prev + solve(i+2,0,false,prices);
        }

        int leave = solve(i+1,prev,isBuy,prices);

        return dp[i][prev][isBuy] = max({buy,sell,leave});
    }
public:
    int maxProfit(vector<int>& prices) {
        
        return solve(0,0,false,prices);
    }
};
