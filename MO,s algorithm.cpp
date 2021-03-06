
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
#define pll pair <ll, ll>
#define pii <pair<ll , ll>
#define mp make_pair
#define sl1(t) scanf("%lld" , &t)
#define si1(t) scanf("%d" , &t)
#define sl3(t , u , v) scanf("%lld %lld %lld" , &t , &u , &v)
#define si3(t , u , v) scanf("%d %d %d" , &t , &u , &v)
#define sl2(t , u) scanf("%lld %lld" , &t , &u)
#define si2(t , u) scanf("%d %d" , &t , &u)
#define el cout << endl;
#define ff first
#define ss second
#define sp printf(" ")
#define pi1(t) printf("%d " ,t)
#define pl1(t) printf("%lld\n" , t)
#define pc(x) cout << "Case " << x << ":" << " "
#define valid(x , y , i , j) (i >= 0 && i < x && j >= 0 && j < y)
#define MOD 1000000007
#define setbit(x, k) (x | ((long long)1 << k))
#define clearbit(x, k) (x & ~((long long)1 << k))
#define checkbit(x, k) (x & ((long long)1 << k))


vector<ll>a(2e5 + 5);
vector<ll>vis(1000006);

int mxn = 2e5 + 5;

struct query{
    int l , r , id;
}q[200005];

const int k = 320;//size of a block

bool cmp(query &a , query &b)
{
    int block_a = a.l/k , block_b = b.l/k;
    if(block_a != block_b) return block_a < block_b;
    if(block_a&1) return a.r < b.r;
    
    return a.r > b.r;
}

int l = 0 , r = -1 ;
ll ans[200005] , sum = 0;

void add(int x){
    if(a[x] == vis[a[x]])sum--;
    vis[a[x]]++;
    if(a[x] == vis[a[x]])sum++;
}
void remov(int x){
    if(a[x] == vis[a[x]])sum--;
    vis[a[x]]--;
    if(a[x] == vis[a[x]])sum++;
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

    ll n;cin >> n;ll qu;cin >> qu;
    for(ll i = 1 ; i <= n ; i++){// 1 based indexing
        ll x;cin >> x;
        if(x > 100001)x = 100001;
        a[i] = x;
    }


    for(ll i = 0 ; i < qu ; i++){
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    sort(q , q + qu , cmp);

    for(ll i = 0 ; i < qu ; i++){
        while(l > q[i].l) add(--l);
        while(r < q[i].r)add(++r);
        while(l < q[i].l)remov(l++);
        while(r > q[i].r)remov(r--);
        ans[q[i].id] = sum;
    }

    for(ll i = 0 ; i < qu ; i++)cout << ans[i] << endl;
    
    
    return 0;
}
