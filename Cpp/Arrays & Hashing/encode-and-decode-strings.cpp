class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (string str : strs) {
            result += to_string(str.length()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        
        while (i < s.length()) {
            int mark = s.find('#', i);
            int length = stoi(s.substr(i, mark - i));
            result.push_back(s.substr(mark + 1, length));
            i = mark + length + 1;
        }

        return result;
    }
};
