vector<ll>vis(30005);

vector<ll>bg(300005);
vector<ll>en(300005);

void dfs(ll node , ll p){
    vis[node] = 1;
    bg[node] = cnt++;
    for(auto x : v[node]){
        if(vis[x] == 0)dfs(x , node);
    }
    en[node] = cnt++;
}
