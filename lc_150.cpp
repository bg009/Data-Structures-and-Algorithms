#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &str)
    {

        stack<int> s;

        for (auto &x : str)
        {
            if (x == "+")
            {
                int b = s.top();
                s.pop();

                int a = s.top();
                s.pop();

                s.push(a + b);
            }

            else if (x == "-")
            {
                int b = s.top();
                s.pop();

                int a = s.top();
                s.pop();

                s.push(a - b);
            }

            else if (x == "*")
            {
                int b = s.top();
                s.pop();

                int a = s.top();
                s.pop();

                s.push(a * b);
            }

            else if (x == "/")
            {
                int b = s.top();
                s.pop();

                int a = s.top();
                s.pop();

                s.push(a / b);
            }

            else
            {
                int a = stoi(x);
                s.push(a);
            }
        }

        return s.top();
    }
};