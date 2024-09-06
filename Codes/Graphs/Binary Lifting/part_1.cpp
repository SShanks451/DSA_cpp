// finding kth ancestor of the node
// Time complexity :- O(log N) per query

// question link :- https://cses.fi/problemset/task/1687

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> gr;
int pre_calc[200009][35];

void dfs(int vr, int par)
{
    pre_calc[vr][0] = par;
    for (int i = 1; i <= 30; i++)
    {
        if (pre_calc[vr][i - 1] == -1)
        {
            pre_calc[vr][i] = -1;
        }
        else
        {
            pre_calc[vr][i] = pre_calc[pre_calc[vr][i - 1]][i - 1];
        }
    }

    for (auto child : gr[vr])
    {
        if (child != par)
        {
            dfs(child, vr);
        }
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> vec(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> vec[i];
    }

    gr.resize(n + 5);
    for (int i = 0; i < vec.size(); i++)
    {
        gr[vec[i]].push_back(i + 2);
    }

    dfs(1, -1);

    while (q--)
    {
        int x, k;
        cin >> x >> k;
        int ans = x;
        for (int j = 30; j >= 0; j--)
        {
            if (k & (1 << j))
            {
                ans = pre_calc[ans][j];
                if (ans == -1)
                    break;
                k -= (1 << j);
            }
        }
        cout << ans << endl;
    }

    return 0;
}