#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string counterGame(long n) {
    long count = 0;
    n-=1;
    while (n) {
        if ((n&1) != 0) {
            count++;
        }
        n>>=1;
    }
    return (count&1)? "Louise": "Richard";
}

int main()
{
    int t;
  cin>>t;
  while(t--){
    long long n;
    cin>>n;
    string winner = counterGame(n);
  }
    return 0;
}
