// question link :- https://leetcode.com/problems/flood-fill/

// Graph Matrix Problem

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>> &image)
{
    int n = image.size();
    int m = image[0].size();

    if (i < 0 || j < 0)
        return;
    if (i >= n || j >= m)
        return;
    if (image[i][j] != initialColor)
        return;

    image[i][j] = newColor;

    dfs(i - 1, j, initialColor, newColor, image);
    dfs(i + 1, j, initialColor, newColor, image);
    dfs(i, j - 1, initialColor, newColor, image);
    dfs(i, j + 1, initialColor, newColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initialCol = image[sr][sc];
    if (initialCol != color)
    {
        dfs(sr, sc, initialCol, color, image);
    }

    return image;
}

int main()
{

    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    int color = 2;

    vector<vector<int>> ans = floodFill(image, sr, sc, color);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}