///* #######LCA          ?? Longest Common Ancestor
//LCA using sparse table
//Complexity: O(NlgN,lgN)
#define mx 5005
ll L[mx]; ///LEVEL
ll P[mx][22];///SPARCE TABLE
ll T[mx]; ///PARENT
vector<ll>g[mx];
void dfs(ll from,ll u,ll dep)
{
    T[u]=from;
    L[u]=dep;
    for(ll i=0;i<(ll)g[u].size();i++)
    {
        ll v=g[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

ll lca_query(ll N, ll p, ll q)
  {
      ll tmp, log, i;

      if (L[p] < L[q])
          tmp = p;p = q;q = tmp;

        log=1;
      while(1) {
        ll next=log+1;
        if((1<<next)>L[p])break;
        log++;

      }

        for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];

      if (p == q)
          return p;

        for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];

      return T[p];
  }

void lca_init(ll N)
  {
      memset (P,-1,sizeof(P));
      ll i, j;
       for (i = 0; i < N; i++)
          P[i][0] = T[i];

      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }
 //*/
