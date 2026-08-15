
#include <bits/stdc++.h>
using namespace std;

int MinimumPlatforms(vector<pair<int, int>> &trains)
{
    sort(trains.begin(), trains.end());
    int platformNeeded = 1;
    priority_queue<int> trainDepartureTime;
    trainDepartureTime.push(-1*trains[0].second);

    for(int i=1; i<trains.size(); i++){
        if(trains[i].first > trainDepartureTime.top()*-1){
            trainDepartureTime.pop();
            trainDepartureTime.push(-trains[i].second);
        }else{
            platformNeeded++;
            trainDepartureTime.push(-trains[i].second);
        }
    }
    return platformNeeded;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> trains;

    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        trains.push_back({s, t});
    }

    cout << MinimumPlatforms(trains) << '\n';
}
