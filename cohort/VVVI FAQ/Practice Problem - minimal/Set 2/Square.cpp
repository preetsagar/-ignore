
#include <bits/stdc++.h>
using namespace std;

vector<long long> ds;

// Optimization:
// Instead of checking all 4! = 24 permutations, only 3 distinct vertex arrangements are enough (others are just rotations/reversals).
// The cleanest solution is to compute the 6 pairwise distances once, sort them, and verify: first 4 distances are equal and non-zero (sides), last 2 are equal (diagonals). This removes permutations entirely.

long long dist(vector<long long> &a, vector<long long> &b){
    long long dx = a[0] - b[0];
    long long dy = a[1] - b[1];
    return dx*dx + dy*dy;
}

bool isValid(vector<vector<long long>> &v){

    int A = ds[0];
    int B = ds[1];
    int C = ds[2];
    int D = ds[3];

    long long AB = dist(v[A], v[B]);
    long long BC = dist(v[B], v[C]);
    long long CD = dist(v[C], v[D]);
    long long DA = dist(v[D], v[A]);

    long long AC = dist(v[A], v[C]);
    long long BD = dist(v[B], v[D]);

    return (AB > 0 &&
            AB == BC &&
            BC == CD &&
            CD == DA &&
            AC == BD);
}

bool solve(vector<vector<long long>> &v, int mask){
    if(ds.size() == 4){
        return isValid(v);
    }

    for(int j=0; j<4; j++){
        if((mask & (1<<j)) == 0){
            ds.push_back(j);
            if(solve(v, mask | (1<<j)))
                return true;
            ds.pop_back();
        }
    }
    return false;
}

bool isValidSquare(vector<vector<long long>> &v)
{
    if(solve(v, 0)) return true;
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<long long>> v(4, vector<long long>(2));
    for (int i = 0; i < 4; i++)
        cin >> v[i][0] >> v[i][1];
    cout << isValidSquare(v) << '\n';
    return 0;
}
