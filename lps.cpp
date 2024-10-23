vector<int> lps(string text,string pattern) {
    string l = pattern+"#"+text;
    
    vector<int>p(l.size(),0);
    for (int i=1;i<l.size();i++) {
        int j=p[i-1];
        while (j>0&&l[i]!=l[j])
            j=p[j-1];
        p[i]=(j+=l[i]==l[j]);
    }
    
    vector<int>res;
    for(int i=pattern.length()+1;i<l.size();i++) {
        if(p[i]==pattern.length())res.push_back(i-2*pattern.length());
    }
    return res;
}