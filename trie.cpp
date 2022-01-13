
const int N = 1e5 + 100;
int to[N][12];
int cnt[N];
int tot_nodes = 1;
ll f = 0;
string s;

void add_string()
{
    int cur = 1;
    for(int i = 0 ; i < s.size() ; i++){
        int ch = s[i] - '0';

        if(!to[cur][ch]){
            to[cur][ch] = ++tot_nodes;
        }
        cur = to[cur][ch];
        cnt[cur]++;
    }
}

string str;

int query()
{
    int cur = 1;
    for(int i = 0 ; i < str.size() ; i++){
        int ch = str[i] - '0';
        if(!to[cur][ch])return 0;
        cur = to[cur][ch];
    }
    return cnt[cur];

}
