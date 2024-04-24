// finding nearest smaller element to left.

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
    
    s.push(n - 1); // push last element index
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[s.top()] <= v[i])
        {
            s.push(i);
        }
        else
        {
            while (!s.empty() && v[s.top()] > v[i])
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
