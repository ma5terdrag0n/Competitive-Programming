
map<ll, vii > adj;

vii bridges;

vi articulation_point, dfs_parent, dfs_low, dfs_num;

ll counter = 0;

ll dfs_root, rootChildren;

ll n, e; // node, edges

void articulationPointsAndBridges(ll u){
	dfs_low[u] = dfs_num[u] = counter++;
	for(int i = 0 ; i < adj[u].size() ; i++){
		ll v=adj[u][i].first;
		if(dfs_num[v] == -1){
			dfs_parent[v] = u;

			if(u == dfs_root)rootChildren++;

			articulationPointsAndBridges(v);

			if(dfs_low[v] >= dfs_num[u]){
				articulation_point.pb(u);
			}
			if(dfs_low[v] > dfs_num[u]){
				bridges.pb(make_pair(u, v));
			}

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}else if(v!=dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}


void preprocess(){
	articulation_point.clear();
	bridges.clear();
	dfs_low.clear();
	dfs_num.clear();
	dfs_parent.clear();
	adj.clear();

	// resizing vectors
	dfs_low.assign(n, 0);
	dfs_num.assign(n, -1);
	dfs_parent.assign(n, 0);
}

void solve(){
	cin >> n >> e;
	preprocess();
	for(int i = 0 ; i < e ; i++){
		ll u, v, c=0;
		cin >> u >> v;
		cin >> c; // comment this if the graph is unweighted!
		u--, v--;
		adj[u].push_back(make_pair(v, c));
		adj[v].push_back(make_pair(u, c));
	}

	for(int i = 0 ; i < n ; i++){
		if(dfs_num[i] == -1){
			dfs_root = i;
			rootChildren = 0;
			articulationPointsAndBridges(i);
			if(rootChildren <= 1){  
				articulation_point.pop_back(); //because dfs_root will be pushed in the vector at the end of rec.
			}
		}
	}

	cout << "Articulation Points: \n";

	for(int i = 0 ; i < articulation_point.size() ; i ++){
		cout << articulation_point[i] << " " ;
	}

	cout << endl;

	cout << "Bridges: \n";

	for(int i = 0 ; i < bridges.size() ; i ++){
		cout << bridges[i].first <<"  " << bridges[i].second << endl;
	}

}
