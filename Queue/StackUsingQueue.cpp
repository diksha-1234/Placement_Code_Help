#include<iostream>
#include<bits/stdc++.h>
using namespace std;
queue<int>q1;
queue<int>q2;
void pushele(){
    int ele;
    cin>>ele;
    q2.push(ele);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    q1.swap(q2);
}
void popele(){
    if(q1.size()){
        int temp=q1.front();
        q1.pop();
        cout<<"popped element is "<<temp<<endl;
    }
    else{
        cout<<"empty stack!!!"<<endl;
    }
    
}
void topele(){
    if(q1.size()){
        cout<<"top element is"<<q1.front()<<endl;
    }else
    {
        cout<<"stack is empty"<<endl;
    }
}
int main(){
    int ch;
    while(1){
    cout<<"1.push 2.pop 3.top"<<endl;
    cout<<"enter your choice";
    cin>>ch;
    switch(ch){
        case 1:
        pushele();
        break;
        case 2:
        popele();
        break;
        case 3:
        topele();
        break;
        default:exit(0);
    }
    }
}

