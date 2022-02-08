
#define nsz 100010
#define tsz 6000010

ll arr[nsz];
ll nxt_free = 2;
ll version[nsz];
ll tre[tsz] , lft[tsz] , rgt[tsz];

void build(ll node , ll lw , ll hi)
{
    //cout << node << " " << lw << " " << hi << endl;
    if(lw == hi){
        tre[node] = 0;
        return;
    }
    lft[node] = nxt_free++;
    rgt[node] = nxt_free++;
    ll mid = (hi + lw) >> 1;
    build(lft[node] , lw , mid);
    build(rgt[node] , mid + 1 , hi);
    tre[node] = tre[lft[node]] + tre[rgt[node]];
}

ll update(ll node , ll lw , ll hi , ll idx , ll v)
{
    if(lw > idx || hi < idx)
        return node;
    ll nnode = nxt_free++;
    if(lw == hi){
        tre[nnode] = tre[node];
        tre[nnode] += v;
        //cout << lw << " " << tre[nnode] << " " << v << endl;
        return nnode;
    }
    ll mid = (lw + hi) >> 1;
    lft[nnode] = update(lft[node] , lw , mid , idx , v);
    rgt[nnode] = update(rgt[node] , mid + 1 , hi , idx , v);
    tre[nnode] = tre[lft[nnode]] + tre[rgt[nnode]];
    return nnode;
}

ll query(ll lnode , ll rnode , ll lw , ll hi , ll l , ll r)
{//cout << lw << " " << hi << " " << l << " " << r << endl;

    if(lw > r || hi < l)
        return 0;

    if(lw >= l && hi <= r){
        //cout << tre[rnode] << endl;
        return tre[rnode] - tre[lnode];
    }

    ll mid = (lw + hi) >> 1;
    return query(lft[lnode] , lft[rnode] , lw , mid , l , r)
            + query(rgt[lnode] , rgt[rnode] , mid + 1 , hi , l , r);
}

