class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string s : strs){
            encoded += to_string(s.size()) + "#"+s;// Loop through each string
        }
        return encoded;
    }
    vector<string> decode(string s) {
        vector<string> result;
        int i =0;
        while(i<s.size()){ // total encoded string length
            int length = 0;
            while(s[i] != '#'){ // one individual is a string until it meets #
                length = length * 10 + (s[i] - '0'); // for double digits 
                i++;
            }
            i++; // to skip comma 
            string word  = s.substr(i,length);
            result.push_back(word);
            i = i+length;

        }
        return result ;

    }
};
