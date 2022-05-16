// https://leetcode.com/problems/intersection-of-multiple-arrays/

#include<bits/stdc++.h>
using namespace std;

// Using 1 extra map

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        int row = nums.size();
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                mpp[nums[i][j]]++;
                if(mpp[nums[i][j]]==row){
                    ans.push_back(nums[i][j]);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


// Using 1 extra vector of size 1001


class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans, count(1001);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                count[nums[i][j]]++;
            }
        }
        for(int i=0; i<count.size(); i++){
            if(count[i]==nums.size()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};