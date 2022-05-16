// https://leetcode.com/problems/reshape-the-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rr=mat.size();
        int cc=mat[0].size();
        if(rr*cc != c*r)
            return mat;
        vector<vector<int>> ans(r,vector<int>(c));
        for(int i=0; i<r*c; i++){
            ans[i/c][i%c] = mat[i/cc][i%cc];
        }
        return ans;
    }
};