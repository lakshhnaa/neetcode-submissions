class Solution {
public:
    bool isPalindrome(string s) {
        //prereq
        string cleaned = "";
        //remove spaces spl char
        for(char c : s){
            if(isalnum(c)){
                cleaned +=tolower(c);
            }
        }

        //two pointer technique
        int left =0;
        int right =cleaned.size()-1;
        while(left<=right){
            if(cleaned[left]!=cleaned[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;

    }
};
