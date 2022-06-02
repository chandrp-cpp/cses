#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    
    set<int> nums;
    for(int i=1; i<=n; i++) nums.insert(i);
    
    auto itr = nums.begin();
    
    while(nums.size()){
        int k1=k%(nums.size());
        for(int i=0; i<k1; i++){
            itr++;
            if(itr==nums.end()) itr=nums.begin();
        }
        int x = *itr;
        cout<<x<<" ";
        itr++;
        if(itr==nums.end()) itr=nums.begin();
        nums.erase(x);
    }
    // if(nums.size()) cout<<*nums.begin();
    return 0;
}