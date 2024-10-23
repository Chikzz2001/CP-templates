int in[MAXN],out[MAXN],C[MAXN];
vector<int>g[MAXN];
vector<int>tour;

int dfs(int n,int p,int &timer) {
    in[n]=timer;
    tour.push_back(n);
    timer++;
    for(int c:g[n]) {
        if(c!=p) {
            dfs(c,n,timer);
        }
    }
    tour.push_back(n);
    out[n]=timer;
    timer++;
}

vector<int>seg_tree,nums,lazy;
int n;
void build(vector<int>& nums,int node,int start,int end)
{
    if(start==end) {
        seg_tree[node]=nums[start];return;
    }

    int mid=(start+end)/2;
    build(nums,node*2,start,mid);
    build(nums,node*2+1,mid+1,end);
    seg_tree[node]=seg_tree[node*2]+seg_tree[node*2+1];
}
//point update
void update(int node,int start,int end,int idx,int diff)
{
    if(start>end||end<idx||start>idx)return;

    seg_tree[node]+=diff;
    if(start==end)return;

    int mid=(start+end)/2;

    update(node*2,start,mid,idx,diff);
    update(node*2+1,mid+1,end,idx,diff);
}
//range update
void propagate(int node,int start,int end){
    if(lazy[node]==0)return;
    seg_tree[node]+=(end-start+1)*lazy[node];

    if(start!=end){
        lazy[node*2]=lazy[node*2+1]=lazy[node];
    }
    lazy[node]=0;
}

void update(int node,int start,int end,int l,int r,int c){
    propagate(node,start,end);
    if(end<l||r<start)return;
    
    if(start==end||(l<=start&&end<=r)) {
        lazy[node]=c;
        propagate(node,start,end);
    }
    else {
        int mid=(start+end)/2;
        update(node*2,start,mid,l,r,c);
        update(node*2+1,mid+1,end,l,r,c);
        seg_tree[node]=seg_tree[node*2]|seg_tree[node*2+1];
    }
}

int query(int node,int start,int end,int l,int r)
{
    if(end<l||start>r)return 0;
    propagate(node,start,end);
    if(start>=l&&end<=r)return seg_tree[node];

    if(start==end)return seg_tree[node];

    int mid=(start+end)/2;
    int left=query(node*2,start,mid,l,r);
    int right=query(node*2+1,mid+1,end,l,r);
    return left|right;
}