// https://leetcode.com/problems/intersection-of-two-arrays/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> stt;
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            stt.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size(); i++){
            if(stt.count(nums2[i])){
                ans.push_back(nums2[i]);
                stt.erase(nums2[i]);
            }
        }
        return ans;
    }
};