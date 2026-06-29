class Solution {
public://calculating the profit for eac prices then returning the max.
    int maxProfit(vector<int>& prices) {
        int minsofar = prices[0]; //maintaining the min price to buy
        int mp = 0;//max profit = 0
        for(int i = 0; i<prices.size(); i++){
            minsofar = min(minsofar,prices[i]);
            mp = max(mp, prices[i] - minsofar);
        }
        return mp;
    }
};
