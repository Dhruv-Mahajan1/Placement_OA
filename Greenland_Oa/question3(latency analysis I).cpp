// Removing edges from the graph such that the maximum edge weight is minimized.
// Another constraint is that graph cannot be broken into more than k subgraphs.
vector<set<int>> graph;
vector<int> visited;
void dfs(int cur,int par){
    visited[cur] = 1;
    for(auto v : graph[cur]){
        if(v==par) continue;
        dfs(v,cur);
    }
}
int find_ans(int n,vector<int> from,vector<int> to,vector<int> weight,int k){
    // cout<<"in\n";
    graph.resize(n+1);
    visited.assign(n+1,0);
    int m = from.size();
    vector<pair<int,pair<int,int>>> sorted_wts;
    multiset<int> wts = {0};
    rep(x,0,m){
        int a = from[x],b = to[x],w = weight[x];
        sorted_wts.push_back({w,{a,b}});
        graph[a].insert(b);
        graph[b].insert(a);
        wts.insert(w);
    }
    sort(sorted_wts.begin(),sorted_wts.end(),greater<pair<int,pair<int,int>>>());
    int cur_networks = 0;
    int ans = 0;
    rep(x,0,m){
        int w = sorted_wts[x].first;
        int a,b;tie(a,b) = sorted_wts[x].second;
        if(cur_networks>k){
            break;
        }
        ans = *wts.rbegin();
        graph[a].erase(b);
        graph[b].erase(a);
        // cout<<w<<" "<<a<<" "<<b<<"\n";
        wts.erase(wts.find(w));
        int temp_nets = 0;
        rep(y,1,n+1){
            if(!visited[y]){
                dfs(y,-1);
                temp_nets++;
            }
            visited[y] = 0;
        }
        cur_networks = temp_nets;
        // cout<<cur_networks<<"\n";
    }
    if(cur_networks<=k){
        ans = *wts.rbegin();
    }
    return ans;
}


void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(m),b(m),c(m);
    rep(x,0,m){
        cin>>a[x];
    }
    rep(x,0,m){
        cin>>b[x];
    }
    rep(x,0,m) cin>>c[x];
    cout<<find_ans(n,a,b,c,k)<<"\n";
	
}
 
 
 
 

