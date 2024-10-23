// initially the parent array is assigned to 0
int dp[MAXN][25];
int lvl[MAXN];

int lift_node(int u, int d)
{
    if (!d)
        return u;
    int c = 0;
    while (d)
    {
        if (d & 1)
            u = dp[u][c];
        c++;
        d >>= 1;
    }
    return u;
}

void dfs(vector<int> g[], int n, int p, int l)
{
    lvl[n] = l;
    dp[n][0] = p;
    for (int c : g[n])
    {
        if (c != p)
        {
            dfs(g, c, n, l + 1);
        }
    }
}

// check the node range 0<=node<n or 1<=node<=n modify i according to that
// we do not need the root node so exclude the root(in i) during the process
for (int j = 1; j < 25; j++)
{
    for (int i = 1; i <= n; i++)
    {
        if (dp[i][j - 1])
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }
}

// see the query format for this
int u, v, lca;
if (lvl[u] > lvl[v])
    u = lift_node(u, lvl[u] - lvl[v]);
else
    v = lift_node(v, lvl[v] - lvl[u]);
if (u == v)
    lca = u;
else if (min(u, v) == root)
    lca = root;
else
{
    for (int i = 24; i >= 0; i--)
    {
        if (dp[u][i] != dp[v][i])
        {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    lca = dp[u][0];
}