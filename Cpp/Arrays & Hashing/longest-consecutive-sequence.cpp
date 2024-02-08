class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> numsSet(nums.begin(), nums.end());

        for (int num : numsSet) {
            if (!numsSet.count(num - 1)) {
                int length = 1;
                while (numsSet.count(num + length)) {
                    length++;
                }
                longest = max(length, longest);
            }
        }

        return longest;
    }
};
