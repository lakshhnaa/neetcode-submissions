class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //two pointer technique
        int left =0;
        int right = numbers.size() -1;
        while(left<right){

            int sum = numbers[left]+ numbers[right];
            if(target==sum){//if sum equals target
            // check if its == otherwise answer is not coming
                return{left+1,right+1};
            }
            if(target<sum){
            //since sum is grater to make it smaller mover right to smaller number
            //since its in increasing order
            right--;

            }
            if(target>sum){
                left++;
            }
        }
        return {};
    }
};
