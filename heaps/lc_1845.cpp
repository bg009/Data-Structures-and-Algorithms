#include <bits/stdc++.h>
using namespace std;

class SeatManager
{
public:
    int n;
    priority_queue<int, vector<int>, greater<int>> q;

    SeatManager(int a)
    {

        n = a;

        for (int i = 1; i <= n; i++)
            q.push(i);
    }

    int reserve()
    {

        int a = q.top();
        q.pop();

        return a;
    }

    void unreserve(int n)
    {
        q.push(n);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */