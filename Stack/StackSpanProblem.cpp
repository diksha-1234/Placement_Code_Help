#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>left(n);
    vector<int>right(n);
    
    left[0]=v[0];
    right[n-1]=v[n-1];
    //maximum element to its left
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],v[i]);
    }
    //maximum element to its right
    for(int i=n-2;i>=0;i--){
        right[i]=max(right[i+1],v[i]);
    }
    cout<<"left array"<<endl;
    for(int i=0;i<n;i++){
        cout<<left[i]<<" ";
    }
    cout<<endl;
    cout<<"right array"<<endl;
    for(int i=0;i<n;i++){
        cout<<right[i]<<" ";
    }
    cout<<endl;
    int watertrap=0;
    for(int i=0;i<n;i++){
    //take minimum of it ,because between two buildings only the smaller one is responsible for water holding.
        int temp=min(right[i],left[i]);
        int unit=temp-v[i];
        //if unit is negative or zero it implies that it is unable to hold water,make it 0.
        if(unit<0){
            unit=0;
        }
       watertrap+=unit;
    }
    cout<<watertrap;
}
