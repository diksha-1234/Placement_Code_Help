#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int k,temp;
    cin>>k;
    priority_queue<int>pq;//max heap
    //min heap
    // priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(v[i]);
    }
    while(k--){
        temp=pq.top();
        pq.pop();
    }
    // int x=n-k+1;
    // while(x--){
    //     temp=pq.top();
    //     pq.pop();
    // }
    cout<<"kth largest element"<<temp;

}