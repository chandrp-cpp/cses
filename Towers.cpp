#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    multiset<int> arr;
    
    while(n--){
        int x;
        cin>>x;
        auto it = arr.upper_bound(x);
        if(it != arr.end()) arr.erase(it);
        arr.insert(x);
    }
    cout<<arr.size();
    return 0;
}