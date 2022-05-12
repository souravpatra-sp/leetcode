// https://leetcode.com/problems/majority-element-ii/

#include<bits/stdc++.h>
using namespace std;

// Brute Force

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> anss;
        unordered_set<int> ans;
        int majority = nums.size()/3;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            count=0;
            for(int j=0; j<nums.size(); j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            if(count>majority){
                ans.insert(nums[i]);
            }
        }
        for(auto it:ans)
            anss.push_back(it);
        return anss;
    }
};

//----------------------------------------------------------------

// Using Map
// TC - O(n)
// SC - O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        int majority = nums.size()/3;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second>majority)
                ans.push_back(it.first);
        }
        return ans;
    }
};

//-------------------------------------------------------------

// boyer moore voting algorithm

// TC - o(n) + o(n)
// SC - o(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n1=0, n2=0, c1=0, c2=0;
        int majority = nums.size()/3;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==n1){
                c1++;
            }else if(nums[i]==n2){
                c2++;
            }else if(c1==0){
                n1=nums[i];
                c1=1;
            }else if(c2==0){
                n2=nums[i];
                c2=1;
            }else{
                c1--;
                c2--;
            }
        }
        c1=c2=0;
        for(int i=0; i<nums.size(); i++){
            if(n1==nums[i]){
                c1++;
            }else if(n2==nums[i]){
                c2++;
            }
        }
        if(c1>majority) 
            ans.push_back(n1);
        if(c2>majority) 
            ans.push_back(n2);
        return ans;
    }
};