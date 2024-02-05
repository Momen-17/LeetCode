class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strs_map;

        for (const string& str : strs) {
            string sorted_string = str;
            sort(sorted_string.begin(), sorted_string.end());
            strs_map[sorted_string].push_back(str);
        }

        vector<vector<string>> ret;
        for (const auto& entry : strs_map) {
            ret.push_back(entry.second);
        }
        return ret;
    }
};
