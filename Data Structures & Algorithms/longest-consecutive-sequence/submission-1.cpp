class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto &val : nums) mp[val] = 0;

        for(int i=0;i<nums.size(); i++){
            if(mp.count(nums[i])==0 || mp[nums[i]]>0) continue;

            int val = nums[i]+1;
            int count = 1;

            while(mp.count(val)){
                if(mp[val]>0){
                    count+=mp[val];
                    mp.erase(val);
                    break;
                }
                count++;
                mp.erase(val);
                val++;
            }

            mp[nums[i]] = count;
            ans = max(ans,count);
        }

        return ans;
    }
};
