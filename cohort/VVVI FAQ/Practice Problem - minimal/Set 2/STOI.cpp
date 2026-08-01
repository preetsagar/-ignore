
#include <bits/stdc++.h>
using namespace std;

struct Response
{
    bool isValid;
    long long int integer;

    Response() : isValid(true), integer(0) {}
    Response(bool isValid, long long int integer) : isValid(isValid), integer(integer){};
};


Response STOI(string s)
{
    Response result;
    int neg=0;
    
    result.integer = 0;
    result.isValid = true;
    for(int i=0; i<s.size(); i++){
        if(i==0 && (s[0]=='+' || s[0]=='-')){
            if(s[0]=='-') {neg=1;}
            if(s.size()==1) result.isValid = false;
            continue;
        }
        if((s[i]>='0') && (s[i]<='9')){
            result.integer = (result.integer * 10) + (s[i]-'0');
        }else{
            result.isValid = false;
            break;
        }
    }
    if (neg) result.integer *= -1ll;
    return result;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        string s;
        cin >> s;

        Response response = STOI(s);

        if (!response.isValid)
            cout << "Invalid\n";
        else
            cout << response.integer << "\n";
    }
}
