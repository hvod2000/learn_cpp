#include <bits/stdc++.h>
using namespace std;
typedef vector<set<int>> graph;



vector<set<int>> graph_components(graph G) {
	int n = G.size();
	vector<int> order(n);
	{
		vector<bool> visited(n);
		int offset = 1;
		function<void(int)> dfs = [&](int u) {
			if (visited[u]) return;
			visited[u] = true;
			for (int v : G[u])
				dfs(v);
			order[n - offset++] = u;
		};
		for (int u = 0; u < n; u++)
			dfs(u);
	}
	vector<set<int>> components;
	{
		graph revG(n);
		for (int u = 0; u < n; u++)
			for (int v : G[u])
				revG[v].insert(u);
		vector<bool> visited(n);
		function<void(int)> dfs = [&](int u) {
			if (visited[u]) return;
			visited[u] = true;
			components[components.size() - 1].insert(u);
			for (int v : revG[u])
				dfs(v);
		};
		for (int u : order) {
			if (visited[u]) continue;
			set<int> empty_set;
			components.push_back(empty_set);
			dfs(u);
		}
		for (int u = 0; u < n; u++)
			dfs(u);
	}
	return components;
}



int main() {
	cout << "Number of vertices and edges: ";
	int vertices, edges;
	cin >> vertices >> edges;
	graph G(vertices);
	cout << "Edges: ";
	while (edges--) {
		int u, v;
		cin >> u >> v;
		G[u].insert(v);
	}
	auto components = graph_components(G);
	for (int i = 0; i < components.size(); i++) {
		cout << "Component #" << i << ":";
		for (int u : components[i]) cout << " " << u;
		cout << endl;
	}
}
