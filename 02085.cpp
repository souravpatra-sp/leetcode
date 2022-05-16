// Using single map --- *Better than 50% *

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> mpp;
        int count=0;
        for(auto it:words1){
            mpp[it]++;
        }
        for(auto it:words2){
            auto i = mpp.find(it);
            if(i==mpp.end())
                continue;
            if(i->second < 2) 
                i->second--;
            if(i->second==0)
                count++;
            else if(i->second==-1)
                count--;
        }
        return count;
    }
};

// Using 2 maps --- Better than 90%

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mp1;
        unordered_map<string,int>mp2;
        int count=0;
        for(auto it:words1){
            mp1[it]++;
        }
        for(auto it:words2){
            mp2[it]++;
        }
        for(auto it:mp1){
            if(it.second==1 && mp2[it.first]==1){
                count++;
            }
        }
        return count;
    }
};

// Using 3 maps --- Better than 75%

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mp1;
        unordered_map<string,int>mp2;
        unordered_map<string,int>mp3;
        int count=0;
        for(int i=0;i<words1.size();i++){
            mp1[words1[i]]++;
        }
        for(int i=0;i<words2.size();i++){
            mp2[words2[i]]++;
        }
        for(auto ch:mp1){
            if(ch.second==1){
                mp3[ch.first]++;
            }
        }
        for(auto ch:mp2){
            if(ch.second==1){
                mp3[ch.first]++;
            }
        }
        for(auto ch: mp3){
            if(ch.second==2){
                count++;
            }
        }
        return count;
    }
};