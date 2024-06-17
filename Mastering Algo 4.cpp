#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>

using namespace std;

void subset(vector<int>& cost, vector<int>& nums, vector<int>& subsets, vector<int>& subsets1, int k, int& max, int index) {
    int sum = 0, sum1 = 0;
    for (int i = 0; i < subsets.size(); i++) {
        sum += subsets[i];
        sum1 += subsets1[i];
    }
    if (sum <= k) {
        if (max < sum1)
            max = sum1;
    } else {
        return;
    }

    for (int i = index; i < cost.size(); i++) {
        subsets.push_back(cost[i]);
        subsets1.push_back(nums[i]);
        subset(cost, nums, subsets, subsets1, k, max, i + 1);
        subsets.pop_back();
        subsets1.pop_back();
    }
}

int main() {
    int t;
    cin>>t;

    while(t--){
        int n,k;
        vector<int> cost,num;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            cost.push_back(x);
            num.push_back(y);
        }

        int max=INT_MIN;
        vector<int> set1;
        vector<int> set2;
        subset(cost, num, set1, set2,k,max,0);
        cout<<max<<endl;
    }

}