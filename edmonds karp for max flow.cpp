#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define pi acos(-1)
#define pb push_back
#define pf push_front
#define el cout << endl;
#define pr pair<ll , ll>
#define ff first
#define ss second
#define pc(x) cout << "Case " << x << ":" <<  " ";
#define valid(x , y , i , j) (i >= 0 && i < x && j >= 0 && j < y)
#define MOD 1000000007
#define setbit(x, k) (x | ((long long)1 << k))
#define clearbit(x, k) (x & ~((long long)1 << k))
#define checkbit(x, k) (x & ((long long)1 << k))

vector<ll>v[105];
ll cost[105][105];
ll n , c , s , t;

vector<ll>vis(105);
vector<ll>path;

ll dfs(ll node , ll val)
{
    if(vis[node] == 1)return 0;
    vis[node] = 1;
    if(node == t)return val;
    for(ll i = 0 ; i < v[node].size() ; i++){
        if(cost[node][v[node][i]] > 0){
            ll ret = dfs(v[node][i] , min(val , cost[node][v[node][i]]));
            if(ret != 0){
                cost[node][v[node][i]] -= ret;
                cost[v[node][i]][node] += ret;
                return ret;
            }
        }
    }
    return 0;
}

ll max_flow()
{
    for(ll i = 0 ; i <= 100 ; i++)vis[i] = 0;
    ll mx = dfs(s , 1e10);
    ll ret = 0;
    ret += mx;
    while(mx != 0){
        for(ll i = 0 ; i <= 100 ; i++)vis[i] = 0;
        mx = dfs(s , 1e10);
        ret += mx;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///*
#ifndef ONLINE_JUDGE
    freopen("input.cpp", "r", stdin);
    //freopen("output.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
    //*/

    ll test;cin >> test;//cout << t << endl;
    //================================================================================================================
    //precode

    //================================================================================================================

    for(ll te = 1; te <= test ; te++){
        cin >> n ;
        cin >> s >> t >> c;

        for(ll i = 0 ; i <= 100 ; i++){
            v[i].clear();
            for(ll j = 0 ; j <= 100 ; j++){
                cost[i][j] = 0;
            }
        }

        for(ll i = 0 ; i < c ; i++){
            ll a , b , cs;cin >> a >> b >> cs;
            v[a].pb(b);
            v[b].pb(a);
            cost[a][b] += cs;
            cost[b][a] += cs;
        }

        pc(te);
        cout << max_flow() << endl;

    }
    return 0;
}
