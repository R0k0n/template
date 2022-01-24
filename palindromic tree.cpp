
const int N = 3e5 + 10;

int tre[N][26 + 1] , idx;
int link[N] , len[N] , t;
char s[N];

void extend(int p) {
  while(s[p - len[t] - 1] != s[p]) t = link[t];
  int x = link[t], c = s[p] - 'a';
  while(s[p - len[x] - 1] != s[p]) x = link[x];
  if(!tre[t][c]) {
    tre[t][c] = ++idx;
    len[idx] = len[t] + 2;
    link[idx] = len[idx] == 1 ? 2 : tre[x][c];
  } t = tre[t][c];
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

    len[1] = -1 , link[1] = 1;
    len[2] = 0 , link[2] = 1;
    idx = t = 2;
    string str;cin >> str;
    ll ln = str.size();
    for(ll i = 0 ; i < ln ; i++){
        s[i + 1] = str[i];
        extend(i + 1);
    }
    return 0;
}
