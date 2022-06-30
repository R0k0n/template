
/// LIS in nlogn
/// 1 based indexing


ll n;
vector<ll>v(100005);


ll lis[100005];
vector<ll>tre(400005);
void update(ll node , ll l , ll r , ll pnt , ll val)
{
    if(pnt > r || pnt < l)return;
    if(pnt == r && pnt == l){
        tre[node] = max(val , tre[node]);
        //cout << node << " " << l << " " << r << " " << tre[node] << endl;
        return;
    }
    ll mid = (l + r) >> 1;
    update(2 * node , l , mid , pnt , val);
    update(2 * node + 1 , mid + 1 , r , pnt , val);
    tre[node] = max(tre[node * 2] , tre[node * 2 + 1]);
}

ll query(ll node , ll l , ll r , ll pnt){
    if(r < pnt){
        return tre[node];
    }
    if(l > pnt)return 0;
    if(l == pnt && r == pnt){
        return tre[node];
    }
    ll mid = (l + r) >> 1;
    ll ret1 = query(2 * node , l , mid , pnt);
    ll ret2 = query(2 * node + 1 , mid + 1 , r , pnt);
    return max(ret1 , ret2);
}

ll solve(ll n)
{
    for(ll i = 1 ; i <= n ; i++){
        ll mx = query(1 , 1 , 100000 , v[i]-1);
        lis[i] = mx + 1;
        cout << i << " " << mx + 1 << endl;
        //cout << i << " " << lis[i] << endl;
        update(1 , 1 , 100000 , v[i] , lis[i]);
    }
    return lis[n];
}
