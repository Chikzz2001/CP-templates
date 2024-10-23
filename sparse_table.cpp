class Sparse_table {
    vector<vector<int>>table;
    public:
    int f(int a,int b) {
      return a+b;
    }
    Sparse_table(vector<int>& v) {
        int N=v.size();
        table=vector<vector<int>>(__lg(N)+1,vector<int>(N));
        for(int i=0;i<N;i++) {
            table[0][i]=v[i];
        }
        for(int i=1;i<=__lg(N);i++) {
            for(int j=0;j+(1<<i)<=N;j++) {
                //change function
                table[i][j]=f(table[i-1][j],table[i-1][j+(1<<(i-1))]);
            }
        }
    }

    int query(int l,int r) {
        int count=r-l+1;
        int k=__lg(count);
        //change function
        return f(table[k][l],table[k][r-(1<<k)+1]);
    }
};