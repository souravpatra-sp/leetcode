#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algorithm
        int count=1;
        int major=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(count==0){
                major=nums[i];
            }
            count += (major==nums[i])?+1:-1;
        }
        return major;
    }
};