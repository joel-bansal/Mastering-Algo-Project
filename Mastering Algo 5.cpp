#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int main() {

    int n;
    cin>>n;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin>>s;
        int sum=0;
        for(int j=0;j<s.length();j++){
            if (isdigit(s[j])) {
                sum += s[j] - '0';
            }
        }
        vec[i].first = s.length();
        vec[i].second = sum;
    }
    sort(vec.begin(), vec.end(), compare);

    // for (const auto& p : vec) {
    //     cout << "(" << p.first << ", " << p.second << ")" << endl;
    // }    

    int i=0,j=n-1;
    int counter=0;
    while(i<j){
        if(vec[i].first+vec[j].first==12){
            if(vec[i].second+vec[j].second==50){
                counter++;
                i++;
                --j;
            }
            else if(vec[i].second+vec[j].second>50)
                j--;
            else
                ++i;
        }
        else if(vec[i].first+vec[j].first>12){
            j--;
        }
        else{
            ++i;
        }
    }
    cout<<counter;
}