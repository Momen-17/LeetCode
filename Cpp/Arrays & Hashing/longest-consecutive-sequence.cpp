class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> numsSet;
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        for (int num : sortedNums) {
            numsSet.insert(num);
        }

        for (int num : numsSet) {
            if (numsSet.find(num - 1) == numsSet.end()) {
                int length = 1;
                while (numsSet.find(num + length) != numsSet.end()) {
                    length++;
                }
                
                longest = max(length, longest);
            }
        }

        return longest;
    }
};
