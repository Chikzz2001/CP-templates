//check the out of range return value in query
vector<int>seg_tree;
int f(int a,int b) {
    return a+b;
}
void build(vector<int>& nums,int node,int start,int end)
{
    if(start==end)
    {seg_tree[node]=nums[start];return;}

    int mid=(start+end)/2;

    build(nums,node*2,start,mid);
    build(nums,node*2+1,mid+1,end);
    seg_tree[node]=f(seg_tree[node*2],seg_tree[node*2+1]);
}
void update(int node,int start,int end,int idx,int val)
{
    if(start>end||end<idx||start>idx)return;

    if(start==end)
    //change for max/min
    {seg_tree[node]=val;return;}

    int mid=(start+end)/2;

    update(node*2,start,mid,idx,val);
    update(node*2+1,mid+1,end,idx,val);
    seg_tree[node]=f(seg_tree[node*2],seg_tree[node*2+1]);
}
int query(int node,int start,int end,int l,int r)
{
    if(end<l||start>r)return 0;

    if(start>=l&&end<=r)return seg_tree[node];

    if(start==end)return seg_tree[node];

    int mid=(start+end)/2;
    int left=query(node*2,start,mid,l,r);
    int right=query(node*2+1,mid+1,end,l,r);
    return f(left,right);
}
 