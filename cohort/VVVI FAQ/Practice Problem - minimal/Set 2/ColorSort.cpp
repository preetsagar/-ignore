
#include <bits/stdc++.h>
using namespace std;

void sort(int a[], int n)

{
    int l=0, r=n-1, i=0;

    while(i<=r){
        if(a[i]==0){
            swap(a[i], a[l]);
            l++; i++;
        }
        else if(a[i]==2){
            swap(a[i], a[r]);
            r--;
        }else i++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, n);
    for (int i : a)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
