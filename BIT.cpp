ll N = 200005;

ll BIT[200005];
void update(int x,int val) { ++x;  while(x<=N)  {  BIT[x]+=val;  x+=(x&-x);  } } /// update increases the value of xth index by val

int query(int x) {  ++x;  int res=0;  while(x>0)  {  res+=BIT[x];  x-=(x&-x);  } return res; } /// query returns the sum of range [1 , x]

void BITclear(){for(ll i = 0 ; i < N ; i++)BIT[i] = 0;} ///To clear the tree
