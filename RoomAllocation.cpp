#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    vector<pair<int,int>> dep(n);
    
    for(int i=0; i<n; i++){
        arr[i].second=dep[i].second=i;
        cin>>arr[i].first>>dep[i].first;
    }
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    
    int total=0;
    
    int idx1=0, idx2=0;
    set<int> empty_rooms;
    map<int,int> alloted_rooms;
    while(idx1<n){
        if(arr[idx1].first<=dep[idx2].first){
            if(empty_rooms.size()){
                alloted_rooms[arr[idx1].second]=*empty_rooms.begin();
                empty_rooms.erase(empty_rooms.begin());
            }
            else{
                total++;
                alloted_rooms[arr[idx1].second]=total;
            }
            idx1++;
        }
        else{
            int x=alloted_rooms[dep[idx2].second];
            empty_rooms.insert(x);
            idx2++;
        }
    }
    
    cout<<total<<endl;
    for(auto x:alloted_rooms) cout<<x.second<<" ";
    return 0;
}