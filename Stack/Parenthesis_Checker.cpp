#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {

        stack<char> stack1;

        char hold;
        for (int i = 0; i < x.length(); ++i)
        {
            hold = x.at(i);
            if (hold == '(' || hold == '[' || hold == '{')
            {
                printf("%c ", hold);
                stack1.push(hold);
            }
            else if (hold == ')' || hold == ']' || hold == '}')
            {
                if (hold == ')' && stack1.top() != '(')
                    return false;
                else
                    stack1.pop();

                if (hold == ']' && stack1.top() != '[')
                    return false;
                else
                    stack1.pop();

                if (hold == '}' && stack1.top() != '{')
                    return false;
                else
                    stack1.pop();
            }
        }
        if (stack1.empty())
        {
            return true;
        }

        return false;
    }

    void display(stack<char> stack1)
    {
        stack<char> copy = stack1;
        for (int i = 0; i < copy.size(); i++)
        {
            cout << copy.top() << " ";
            copy.pop();
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solution object1;

    bool answer = object1.ispar("{[(a+b)*c]+e}");

    cout << "Answer = " << answer << endl;

    if (answer)
    {
        printf("Balanced ");
    }
    else
    {
        printf("Not Balanced");
    }
    return 0;
}