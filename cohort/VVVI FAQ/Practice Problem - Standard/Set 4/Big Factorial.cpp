#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int>& digit, int x) {
    int carry = 0;

    for(int &d : digit) {
        int val = d * x + carry;
        d = val % 10;
        carry = val / 10;
    }

    while(carry) {
        digit.push_back(carry % 10);
        carry /= 10;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> digit = {1};

    for(int x = 2; x <= n; x++)
        multiply(digit, x);

    for(auto it = digit.rbegin(); it != digit.rend(); it++)
        cout << *it;

    return 0;
}
