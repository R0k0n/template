
vector<ll>v[200005];
vector<ll>parent(1000006);
vector<ll>sze(1000006);

void make_set(int v) {
    //for(ll i = 0 ; i <= v ; i++){parent[i] = i;size[i] = 1;}
    parent[v] = v;sze[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sze[a] < sze[b])
            swap(a, b);
        parent[b] = a;
        sze[a] += sze[b];
    }
}
