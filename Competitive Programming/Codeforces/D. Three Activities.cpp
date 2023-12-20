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
        vector<vector<pair<int, int>>> grid(3, vector<pair<int,int>>(3));
        pair<int, int> elem;

        for(int c=0; c < 3; c++){
            for (int i=0; i < n; i++){
                cin>>elem.first;
                elem.second = i;

                if (elem.first > grid[c][0].first){
                    grid[c][2] = grid[c][1];
                    grid[c][1] = grid[c][0];
                    grid[c][0] = elem;
                }
                else if (elem.first > grid[c][1].first){
                    grid[c][2] = grid[c][1];
                    grid[c][1] = elem;
                }
                else if (elem.first > grid[c][2].first){
                    grid[c][2] = elem;
                }
            }
        }

        int ans = 0;

        for (auto ski : grid[0]){
            for (auto movie: grid[1]){
                if (movie.second == ski.second) continue;

                for(auto board: grid[2]){
                    if (board.second == movie.second || board.second == ski.second) continue;
                    
                    ans = max(ans, ski.first+ board.first + movie.first);
                }
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}
