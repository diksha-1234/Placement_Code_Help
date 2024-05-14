//sort the kth sorted array
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int k;
    cin>>k;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        if(pq.size()>k){
            cout<<pq.top();
            pq.pop();
        }
        pq.push(v[i]);
    }
    while(!pq.empty()){
        cout<<pq.top();
        pq.pop();
    }
}