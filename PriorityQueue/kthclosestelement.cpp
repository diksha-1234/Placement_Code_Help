//kth closest element from a array
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ele,k;
    cin>>ele>>k;
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<n;i++){
        pq.push({abs(v[i]-ele),v[i]});
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        cout<<pq.top().second;
        pq.pop();
    }
}