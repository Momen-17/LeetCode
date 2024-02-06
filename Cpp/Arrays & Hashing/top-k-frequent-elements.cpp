class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numsCount;
        vector<pair<int, int>> pairs;

        for (int num : nums) {
            numsCount[num]++;
        }

        vector<int> ret;
        for (auto item = numsCount.begin(); item != numsCount.end(); item++) {
            pairs.push_back({item->second, item->first});
        }

        sort(pairs.rbegin(), pairs.rend());

        for (int i = 0; i < k; i++) {
            ret.push_back(pairs[i].second);
        }

        return ret;
    }
};
