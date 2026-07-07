class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_set<int> st;

       for(auto &val: nums){
            if(st.count(val)) return true;
            st.insert(val);
       }

       return false;
    }
};