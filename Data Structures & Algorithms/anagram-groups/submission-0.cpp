class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto st : strs){
            string temp = st;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(st);
        }
        vector<vector<string>> res;
        for(auto &[key,val] : mp) res.push_back(val);
        return res;
        }
};
