#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--) {
        int n;
        cin>>n;
        
        vector<vector<int>> graph(n+1);
        vector<int> parents(n+1);
        
        for(int i=2; i <= n; i++){
            int elem;
            cin>>elem;

            graph[elem].push_back(i);
        }
        
        queue<int> q;
        q.push(1);
        int prev = -1;
        parents[1] = -1;
        int ans = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if (prev != parents[node] && prev != -1){
                ans+=1;
                prev = -1;
            }
            else {
                prev = node;
            }

            for (auto child: graph[node]){
                parents[child] = node;
                q.push(child);
            }
        }

        cout<<ans<<"\n";

    }
    return 0;
}
