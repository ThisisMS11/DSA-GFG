#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{

    stack <int> hold_stack;
    for (int i = 0; i < k; i++)
    {
        hold_stack.push(q.front());
        q.pop();
    }

    queue<int> newqueue;
    while(!hold_stack.empty()){
        newqueue.push(hold_stack.top());
        hold_stack.pop();
    }

    // how putting the rest of the elements in the original array into newqueue;

    while(!q.empty()){
        newqueue.push(q.front());
        q.pop();
    }

    return newqueue;
}

void display(queue<int> q){
    queue<int> copy=q;
    while(!copy.empty()){
        cout<<copy.front()<<" ";
        copy.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<int> q;
    q.push(1);
    q.push(4);
    q.push(5);
    q.push(2);
    q.push(3);
    q.push(7);

    display(q);

    queue<int> ans_queue=modifyQueue(q,4);
    cout<<endl;

    display(ans_queue);

    return 0;
}