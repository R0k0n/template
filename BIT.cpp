ll N = 300005;

ll BIT[300005];
void update(ll x,ll val) { ++x;  while(x<=N)  {  BIT[x]+=val;  x+=(x&-x);  } } /// update increases the value of xth index by val

ll query(int x) {  ++x;  ll res=0;  while(x>0)  {  res+=BIT[x];  x-=(x&-x);  } return res; } /// query returns the sum of range [1 , x]

void BITclear(){for(ll i = 0 ; i < N ; i++)BIT[i] = 0;} ///To clear the tree
