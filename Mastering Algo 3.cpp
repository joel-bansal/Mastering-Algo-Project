#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void find(vector<int>nums,vector<int> query,vector<int>& ans,int n,int q){

    for(int k:query){
        vector<int> copiedVec(nums);

        for(int i=0;i<k;i++){
            sort(nums.begin(),nums.end());
            int x=nums[nums.size()-1]-nums[0];
            nums.erase(nums.begin());
            nums.pop_back();
            nums.push_back(x);
        }
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        ans.push_back(s);

        nums.clear();
        for(int i:copiedVec){
            nums.push_back(i);
        }
    }
}

int main() {
    int n,q;
    cin>>n>>q;

    vector<int> query;
    vector<int> nums;
    vector<int> ans;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        query.push_back(x);
    }
    // for(int i:query)
    // cout<<i<<" ";
    find(nums,query,ans,n,q);
    for(int i:ans)
        cout<<i<<" ";
}