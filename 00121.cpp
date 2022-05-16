// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro=0;
        int m=INT_MAX;
        for(int i=0; i<prices.size(); i++){
            m=min(m,prices[i]);
            pro=max(pro,prices[i]-m);
        }
        return pro;
    }
};