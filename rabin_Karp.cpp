class Rabin_Karp {
    const int p=31; 
    const int m=1e9+9;
    vector<long long>p_pow,h;
    int size;
    public:
    Rabin_Karp(vector<int>& v) {
        size=sz(v);

        p_pow=vector<long long>(size);
        p_pow[0]=1; 
        for (int i=1;i<size;i++) {
            p_pow[i]=(p_pow[i-1]*p)%m;
        }

        h=vector<long long>(size+1);
        for (int i=0;i<size;i++) {
            h[i+1]=(h[i]+(v[i]+1)*p_pow[i])%m; 
        }
    }
    
    vector<int> find_occurences(vector<int>& t) {
        long long h_s=0; 
        for (int i=0;i<sz(t);i++) {
            h_s=(h_s+(t[i]+1)*p_pow[i])%m; 
        }
        vector<int>occurrences;
        for (int i=0;i+sz(t)-1<size;i++) {
            long long cur_h=(h[i+sz(t)]+m-h[i])%m;
            if (cur_h==h_s*p_pow[i]%m)
                occurrences.push_back(i);
        }
        return occurrences;
    }

    //l and r are 0-based indexing
    long long get_hash(int l,int r) {
        long long hash=(h[r+1]+m-h[l])%m;
        hash=moddiv(hash,p_pow[l],m);
        return hash;
    }
};