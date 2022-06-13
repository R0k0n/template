///~~   v contains the adjacency matrix, it should be build in the main
///~~   1 based index
///~~   call build_lca() in main to build the lca
///~~   lca(a , b) returns the lca of a and b

ll n ;
vector<ll>v[30005];
vector<ll>par(30005);
vector<ll>lvl(30005);
vector<ll>vis(30005);

ll P[30005][30];

void dfs(ll node , ll p){
    vis[node] = 1;
    par[node] = p;
    lvl[node] = 1 + lvl[p];
    for(auto x : v[node]){
        if(vis[x] == 0)dfs(x , node);
    }
}


ll lca(ll p , ll q)
{
    if(lvl[p] < lvl[q])swap(p , q);
    for(ll i = 20 ; i >= 0 ; i--){
        if(lvl[p] - (1 << i)  >= lvl[q]){
            p = P[p][i];
        }
    }

    for(ll i = 20 ; i >= 0 ; i--){
        if(P[p][i] != -1 && P[p][i] != P[q][i]){
            p = P[p][i];q = P[q][i];
        }
    }
    if(p == q)return p;

    return par[p];

}

void build_lca()
{
    for(ll i = 0 ; i <= n ; i++){
        par[i] = 0;
        lvl[i] = 0;
        vis[i] = 0;
    }

    dfs(1 , 0);

    memset(P , -1 , sizeof(P));

    for(ll i = 1 ; i <= n ; i++)P[i][0] = par[i];

    for(ll j = 1 ; (1 << j)  <= n ; j++){
        for(ll i = 1 ; i <= n ; i++){
            if(P[i][j-1] != -1){
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
    return;
}
