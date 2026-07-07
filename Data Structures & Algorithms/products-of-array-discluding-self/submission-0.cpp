class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long res = 1;
        int zero = 0;
        vector<int> ans(nums.size(),0);
        for(auto &val : nums){
            if(val==0) zero++;
            else res*=val;
        }

        if(zero>1) return ans;

        for(int i=0;i<nums.size();i++){
            if(zero>0 && nums[i]==0){
                ans[i]=res;
            }
            else if(zero==0){
                ans[i] = res/nums[i];
            }
        }

        return ans;
    }
};
