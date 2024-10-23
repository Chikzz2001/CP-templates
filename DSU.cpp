class DSU
{
    public:
    vector<int>par,size;
    DSU(int n)
    {par=vector<int>(n);size=vector<int>(n);for(int i=0;i<n;i++){par[i]=i;size[i]=1;}}
    int find(int x){if(x==par[x])return x;return par[x]=find(par[x]);}
    bool is_joined(int a,int b){int pa=find(a);int pb=find(b);
    if(pa==pb)return 1;
    if(size[pa]<=size[pb]){par[pa]=pb;size[pb]+=size[pa];}
    else{par[pb]=pa;size[pa]+=size[pb];}
    return 0;}
};