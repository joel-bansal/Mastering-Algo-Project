#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

long long maximum(vector<long long>& nums,long long n,long long k){
    long long ans,sum=0;
    // cout<<
    sort(nums.begin(), nums.end());
    long long common=0;
    for(long long i:nums){
        if(i==nums[n-1])
            common++;
    }

    long long c = n-common;
    while(sum<=k){
        if(nums[c-1]==nums[n-1]){
            if(sum+(n-c+1)*nums[n-1]<=k)
                sum = sum + (n-c+1)*nums[n-1];
            else
                break;
            for(long long i=c;i<=n-1;i++)
                nums[i]--;
            c--;
        }
        else{
            if(sum+(n-c)*nums[n-1]<=k)
                sum = sum + (n-c)*nums[n-1];
            else
                break;
            for(long long i=c;i<=n-1;i++)
                nums[i]--;

            // c--;
        }
        // cout<<c<<endl;
    }

    return nums[n-1];
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        // cout<<n<<" "<<k<<" ";
        long long x,ans;
        vector<long long> v;
        for(long long i=0;i<n;i++){
            cin>>x;
            v.push_back(x);
        }
        if(n==1){
            while(k>=v[0]){
                k-=v[0];
                v[0]--;
            }
            ans=v[0];
            // cout<<"hello world";
        }
        else
            ans = maximum(v,n,k);
        cout<<ans<<endl;
        // cout<<"Hello"<<endl;
    }


}