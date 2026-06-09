class Solution {
public:
    int maxProfit(vector<int>& prices) {
//init
        int left = 0;
        int right = 1;
        int maxprofit = 0;
//iterate
        while(right < prices.size()){ //not prices of right
            if(prices[right]>prices[left]){
                int profit = prices[right]-prices[left];
                maxprofit =max(maxprofit,profit);
            }
            else{
                left = right;
            }
            right++;

        }
        return maxprofit;

    }
};
