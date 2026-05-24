class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(const string s: strs){
            res+=to_string(s.size()) + '#' + s;

        }
        return res;
    }

    vector<string> decode(string res) {
        vector<string>result;
        int i=0;
        while(i<res.size()){
            int length =0;
            while(res[i] !='#'){
                   length = length * 10 +(res[i]-'0');
                   i++;
            }
            i++;
            string word = res.substr(i,length);
            result.push_back(word);
            i= i+length;

        }
        return result;
    }
};
