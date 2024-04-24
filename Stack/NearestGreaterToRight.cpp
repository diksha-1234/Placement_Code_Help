// finding nearest greater element to right.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    stack<int> s;
    vector<int> ans(n);
    
    s.push(0); // push 1st element index
    for (int i = 1; i < n; i++)
    {
        if (v[s.top()] >= v[i])
        {
            s.push(i);
        }
        else
        {
            while (!s.empty() && v[s.top()] < v[i])
            {
                ans[s.top()] = v[i];
                s.pop();
            }
        }
        s.push(i);
    }
    while (!s.empty())
    {
        ans[s.top()] = -1;
        s.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
