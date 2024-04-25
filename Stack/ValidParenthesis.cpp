#include<stack>
#include<iostream>
using namespace std;
int main(){
    string s1="(())[[]]";//"((([[[{{}{}])))" "((({{}})[[[]]]))" "()" "()[]{}"
    stack<char>s;
    s.push(s1[0]);
   for(int i=1;i<s1.size();i++){
       if(s.empty()){
           s.push(s1[i]);
       }
       else if(s.top()=='('&&s1[i]==')'||s.top()=='{'&&s1[i]=='}'||s.top()=='['&&s1[i]==']'){
           s.pop();
       }
       else{
       s.push(s1[i]);
       }
   }
   if(s.empty()){
       cout<<"valid parenthesis";
   }
   else
   {
       cout<<"invalid parenthesis";
   }
   return 0;
}