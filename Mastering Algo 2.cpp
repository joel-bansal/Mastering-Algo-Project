#include<iostream>
#include<vector>
#include <algorithm>
#include <climits>

using namespace std;

void maximum(vector<int>& nums,int n,int k){
    int pos_max,start=0,end=0,c=0;
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        pos_max += nums[i];

        if(max<pos_max){
            max = pos_max;
            start = c;
            end = i;
        }
        if(pos_max<0){
            pos_max=0;
            c = i+1;
        }
    }
    // cout<<start<<end;
    if(max>=k)
        cout<<end-start+1;
    else
        cout<<-1;
}

int main(){
    vector<int> nums;
    int n,k,x;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    maximum(nums,n,k);
    // cout<<ans;
}