vector<long long> spsp(int n,int src,vector<vector<pair<int,long long>>>& g) {
    vector<long long>dist(n,1e18);

    priority_queue<pair<long long,int>>pQ;
    pQ.push({0ll,src});
    dist[src]=0;

    while(!pQ.empty()) {
        int curr=pQ.top().second;pQ.pop();
        for(auto nbr:g[curr]) {
            if(dist[nbr.first]>nbr.second+dist[curr]) {
                dist[nbr.first]=nbr.second+dist[curr];
                pQ.push({-dist[nbr.first],nbr.first});
            }
        }
    }

    return dist;
}
      