#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>res;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    stack<pair<int,int>>s;
    s.push({v[0],1});
    res.push_back(1);
    for(int i=1;i<n;i++){
        int span=1;
        while(!s.empty()&&s.top().first<=v[i]){
            span+=s.top().second;
            s.pop();
        }
        s.push({v[i],span});
       res.push_back(span);
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}