class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto &val : nums){
            freq[val]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto [key,v] : freq){
            pq.push({v,key});
            while(!pq.empty() && pq.size()>k) pq.pop();
        }
        vector<int> res;

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;

    }
};
