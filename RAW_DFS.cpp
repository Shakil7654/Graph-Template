#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}




#define LIM 1003
int n, m, friends[LIM][LIM];

using namespace std;
vector<int> adj_list[LIM];
int vis[LIM];




void Dfs(int u){
	vis[u] = 1;                                // making first node visited.
	for(int i=0; i<adj_list[u].size(); i++){   // checking where to go from node u.
		int v= adj_list[u][i];
		if(vis[v]==1) continue;
		Dfs(v);
	}
}


int DfsNumberOfComp(int u){
	vis[u] = 1;
	int ans = 1;                              // making first node visited.
	for(int i=0; i<adj_list[u].size(); i++){ // checking where to go from node u.
		int v= adj_list[u][i];
		
		if(vis[v]==1) continue;
		ans += DfsNumberOfComp(v);
	}
	return ans;

}

void MatrixInput() {
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        friends[u][v] = friends[v][u] = 1;
    }
}

void ListInput() {
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
}

int main(){
	ListInput();
	memset(vis, 0, sizeof vis);
	int ans = DfsNumberOfComp(1);
	cout<<ans;
}

/*
7 7
1 2
1 7
1 3
1 6
3 4
3 5
6 5
*/