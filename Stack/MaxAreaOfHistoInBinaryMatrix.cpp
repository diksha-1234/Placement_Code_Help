#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;
//nearest smaller to right
vector<int>NSR(vector<int>v,int m){
     stack<int> s;
    vector<int> ans(m);
    s.push(0); // push 1st element index
    for (int i = 1; i < m; i++)
    {
        if (v[s.top()] <= v[i])
        {
            s.push(i);
        }
        else
        {
            while (!s.empty() && v[s.top()] > v[i])
            {
                ans[s.top()] = i;
                s.pop();
            }
             s.push(i);
        }
    }
    cout<<"nearest to right array:";
    while (!s.empty())
    {
        ans[s.top()] =m;
        s.pop();
    }
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return ans;
}
//nearest smaller to left
vector<int>NSL(vector<int>v,int m){
     stack<int> s;
    vector<int> ans(m);
    
    s.push(m - 1); // push last element index
    for (int i = m - 2; i >= 0; i--)
    {
        if (v[s.top()] <= v[i])
        {
            s.push(i);
        }
        else
        {
            while (!s.empty() && v[s.top()] > v[i])
            {
                ans[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    while (!s.empty())
    {
        ans[s.top()] =-1;
        s.pop();
    }
    cout<<"nearest to left array:";
    for(int x:ans){
        cout<<x<<" ";
    }
    return ans;
}
//max area of histogram of each row
int MAH(vector<int>histo,int m){
    vector<int>nsr=NSR(histo,m);
    vector<int>nsl=NSL(histo,m);
    int max=INT_MIN;
    for(int i=0;i<m;i++){
        int width;
        width=nsr[i]-nsl[i]-1;
        int area=width*histo[i];
        if(area>max){
            max=area;
        }
    }
    return max;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<int>histo(m,0);
    int max=INT_MIN;
    //for each row histogram is----->
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            if(v[i][j]==0){
                histo[j]=0;
            }
            else
            {
                histo[j]+=v[i][j];
            }
        }
        cout<<"histo"<<endl;
        for(int k=0;k<m;k++){
            cout<<histo[k]<<" ";
        }
        cout<<endl;
        int area=MAH(histo,m);
        if(area>max){
            max=area;
        }
        cout<<endl<<"row"<<i<<":-"<<area<<endl;
    }
    cout<<"result"<<max;
}

