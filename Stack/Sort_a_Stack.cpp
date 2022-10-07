#include <bits/stdc++.h>
using namespace std;
class SortedStack
{
public:
    stack<int> s;
    void sorter();
};

// push pop top
void SortedStack ::sorter()
{
    vector<int> hold;
    while (!s.empty())
    {
        hold.push_back(s.top());
        s.pop();
    }

    sort(hold.begin(), hold.end());

    vector<int>::iterator iter;
    for (iter = hold.begin(); iter != hold.end(); ++iter)
    {
        s.push(*iter);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int len;
    scanf("%d", &len);

    int hold;

    SortedStack stack1;
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &hold);
        stack1.s.push(hold);
    }

    stack1.sorter();

    while(!stack1.s.empty())
    {
        cout << stack1.s.top() << " ";
        stack1.s.pop();
    }

    return 0;
}