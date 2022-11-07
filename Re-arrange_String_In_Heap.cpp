#include <bits/stdc++.h>
using namespace std;
#include <map>
#include <queue>

string reArrangeString(string &s)
{
    int n = s.size();
    map<char, int> m; // int -> freq

    for (char ch : s)
    {
        m[ch]++; // ch jab jab milega ++ kardenge frquency ko
    }

    priority_queue<pair<int, char>> pq;

    for (auto itr : m)
    {
        pq.push(make_pair(itr.second, itr.first));
    }

    pair<int, char> g = {-1, '$'}; // block

    string ans = "";

    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();

        ans += temp.second;

        temp.first--;

        if (g.first > 0)
        {
            pq.push(g);
        }
        g = temp;
    }

    if (n == ans.size())
    {
        return ans;
    }
    return "not possible";
}
