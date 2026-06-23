class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        // frequency count
        for(int x : nums)
            mp[x]++;

        // min heap : {frequency, number}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        for(auto it : mp) {

            int num = it.first;
            int freq = it.second;

            pq.push({freq, num});

            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};