
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main(){
    
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> indexs(n);
        vector<pair<int, int>> lookup(n);

        for (int i=0; i < n; i++){
            cin>>lookup[i].first;
            indexs[i] = i;
        }
        
        for (int i=0; i < n; i++){
            cin>>lookup[i].second;
        }
        
        sort(indexs.begin(), indexs.end(), [&lookup](int a, int b){
            return lookup[a].first + lookup[a].second < lookup[b].first+lookup[b].second;
        });


        //for(auto i: indexs){
        //    cout<<"("<<lookup[i].first<<" "<<lookup[i].second<<")";
        //}

        int a = n-1, b = n-1;
        long long ans = 0;

        bool turn = true;

        for(; b>=0 && a>=0;){
            if(turn){
                int index = indexs[b];
                
                if (lookup[index].first && lookup[index].second){
                    lookup[index].second = 0;
                    lookup[index].first--;
                    turn = false;
                    ans+=lookup[index].first;
                }

                b--;

            }
            else {
                int index = indexs[a];

                if (lookup[index].first && lookup[index].second){
                    lookup[index].first = 0;
                    lookup[index].second--;
                    turn = true;
                    ans-=lookup[index].second;
                }

                a--;
            }

//            cout<<"("<<a<<" "<<b<<") ";
        }

        cout<<ans;
        cout<<"\n";
        
    }
    return 0;
}
