#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sorter()
    {
        stack<int> min_stack;  // going to store the minimum element of the updated stack.
        stack<int> hold_stack; // will display the final stack as answer.
        stack<int> exc_previous_minimum;
        // contains the elements from decreasing to increasing sequeuce.

        min_stack.push(s.top());
        s.pop();

        while (!s.empty())
        {

            while (!s.empty())
            {
                if (s.top() < min_stack.top())
                {

                    // now i want to extract all the elments of the original stack into another stack except the minimum.
                    exc_previous_minimum.push(min_stack.top());

                    min_stack.pop();
                    min_stack.push(s.top());
                }
                else
                {
                    exc_previous_minimum.push(s.top());
                }
                s.pop();
            }

            // now we have the minimum element of our stack in min_stack.
            hold_stack.push(min_stack.top());
            min_stack.pop();

            // min_stack becomes empty here.

            s.swap(exc_previous_minimum);


            // this part can be removed as epm has already been swaped with an empty stack.
            while (!exc_previous_minimum.empty())
            {
                exc_previous_minimum.pop();
            }
            

            min_stack.push(s.top());
            s.pop();

        }

        // when s becomes empty min_stack would still be left with a element which has to be put in the hold stack to complete the arrangement.

        hold_stack.push(min_stack.top());
        min_stack.pop();

        // to get the final answer in  original stack only.
        s.swap(hold_stack);
    }

};

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

    return 0;
}