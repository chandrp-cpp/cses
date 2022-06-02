//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,n;
    cin>>x>>n;
    
    map<int,int> gaps;
    gaps[x]++;
    
    set<int> lights;
    lights.insert(0);
    lights.insert(x);
    
    while(n--){
        int p;
        cin>>p;
        if(p==0 || p==x){
            cout<<gaps.rbegin()->first<<endl;
            continue;
        }
        int l = p-*(--lights.lower_bound(p));
        int r = *(lights.upper_bound(p))-p;
        
        if(gaps.count(l+r)) gaps[l+r]--;
        if(gaps[l+r]==0) gaps.erase(l+r);
        gaps[l]++;
        gaps[r]++;
        lights.insert(p);
        cout<<gaps.rbegin()->first<<" ";
    }
    return 0;
}