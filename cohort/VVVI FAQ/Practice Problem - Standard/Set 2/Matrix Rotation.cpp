
#include <bits/stdc++.h>
using namespace std;


void RotateMatrix(vector<vector<int>> &v)
{
    int n=v.size();
    int m=v[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(v[i][j], v[j][i]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m/2; j++){
            swap(v[i][j], v[i][m-1-j]);
        }
    }
}


int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }

    RotateMatrix(v);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
}
