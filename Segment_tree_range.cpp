//Always check out of bound ranges return values
vector<int>seg_tree,nums,lazy;
auto f(auto a,auto b) {
    return a+b;
}
void build(vector<int>& nums,int node,int start,int end)
{
    if(start==end) {
        seg_tree[node]=nums[start];return;
    }

    int mid=(start+end)/2;
    build(nums,node*2,start,mid);
    build(nums,node*2+1,mid+1,end);
    seg_tree[node]=f(seg_tree[node*2],seg_tree[node*2+1]);
}

void propagate(int node,int start,int end) {
    if(start!=end) {
        lazy[2*node]=f(lazy[2*node],lazy[node]);
        lazy[2*node+1]=f(lazy[2*node+1],lazy[node]);
    }
    seg_tree[node]=f(seg_tree[node],(end-start+1)*lazy[node]);
    //set default
    lazy[node]=0;
}

//range update
void update(int node,int start,int end,int l,int r,int val){
    propagate(node,start,end);
    if(end<l||r<start)return;
    if(l<=start&&end<=r) {
        lazy[node]=f(lazy[node],val);
        propagate(node,start,end);
    }
    else {
        int mid=(start+end)/2;
        update(node*2,start,mid,l,r,val);
        update(node*2+1,mid+1,end,l,r,val);
        seg_tree[node]=f(seg_tree[node*2],seg_tree[node*2+1]);
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
    return f(left,right);
}