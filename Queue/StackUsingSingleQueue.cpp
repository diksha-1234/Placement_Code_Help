// reversing a queue or implement stack using single queue
#include <bits/stdc++.h>
using namespace std;
queue<int> qs;
void pushele()
{
    int x;
    cin >> x;
    if (qs.size() > 1)
    {
        qs.push(x);
        int si = qs.size() - 1;
        while (si--)
        {
            qs.push(qs.front());
            qs.pop();
        }
    }
    else
    {
        qs.push(x);
    }
}
void popele()
{
    if (qs.size() == 0)
    {
        cout << "stack empty" << endl;
    }
    else
    {
        int t = qs.front();
        qs.pop();
        cout << "popped element is" << t << endl;
    }
}

void topele()
{
    if (qs.size() == 0)
    {
        cout << "stack empty" << endl;
    }
    else
    {
        cout << "top element is" << qs.front() << endl;
    }
}
int main()
{
    int ch;
    while (1)
    {
        cout << "1.push 2.pop 3.top" << endl;
        cout << "enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            pushele();
            break;
        case 2:
            popele();
            break;
        case 3:
            topele();
            break;
        default:
            cout << "exit!!";
            exit(0);
        }
    }
}