class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) //return type : vector<vector<string>> 
    //(vector<string>& strs) → Parameter list // strs → variable name
    {
      unordered_map<string, vector<string>> res;//key value
        for (const auto& s : strs) { // auto guesses the data type ,const avoiding copying or modifying
            vector<int> count(26, 0); // declare in alpha order
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++) { 
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};