#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int k, int ll, int rr){
    int l=ll, r=rr, i=ll;
    int pivot = A[r];
    while(i<=r){
        if(A[i] < pivot){
            swap(A[i], A[l]);
            l++;i++;
        }else if(A[i]>pivot){
            swap(A[i], A[r]);
            r--;
        }else{
            i++;
        }
    }
    return l;
}

int quickselect(vector<int> A, int k) 
{
    k--;
    int l=0,r=A.size()-1;
    while(l<=r){
        int x = solve(A, k, l, r);
        if(x < k){
            l = x+1;
        }else if(x>k){
            r = x-1;
        }else break;
    }
    return A[k];
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << quickselect(A, K) << '\n';

    return 0;
}