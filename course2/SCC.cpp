#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define REP(a, b) FOR(i, a, b)

typedef long long ll;
typedef vector<int> vi;

template <typename ...Args>
void write(Args && ...args) {
	(cout << ... << args);
}

template <typename ...Args>
void read(Args && ...args) {
	(cin >> ... >> args);
}

# define VERTICES 875715

struct Graph {
	vector<int> *v;
	int V;
};

void dfs(Graph &g, vector<bool>& visited, vector<int>& f, int v) {
	visited[v] = true;

	for (auto it = g.v[v].begin(); it != g.v[v].end(); ++it) {
		if (!visited[*it]) {
			dfs(g, visited, f, *it);
		}
	}
	f.push_back(v);
}

void dfs_reverse(Graph &g, vector<bool>& visited, int v, int& c) {
	visited[v] = true;
	for (auto x : g.v[v]) {
		if (!visited[x]) {
			dfs_reverse(g, visited, x, ++c);
		} 
	}
}

void algorithm(Graph &g, Graph &g_rev) {
	vector<int> f;
	vector<bool> visited(VERTICES, false);
	vector<int> res;
	REP(1, VERTICES) {
		if (!visited[i]) {
			dfs(g, visited, f, i);
		}
	}
	fill(visited.begin(), visited.end(), false);
	for (int i = f.size() - 1; i >= 0; i--) {
		if (!visited[f[i]]) {
			int c = 1;
			dfs_reverse(g_rev, visited, f[i], c);
			res.push_back(c);
		}
	}
	sort(res.begin(), res.end());
	for (int i = res.size() - 1; i >= max((int)res.size() - 5, 0); i--) {
		write(res[i]);
		if (i != res.size() - 5) {
			write(",");
		} else {
			write(endl);
		}
	}
}

void test_case() {

	Graph g;
	Graph g_rev;

	ifstream s;
	string line;

	vector<bool> visited(VERTICES, false);
	g.v = new vector<int>[VERTICES];
	g.V = 0;
	g_rev.v = new vector<int>[VERTICES];
	s.open("input.txt");
	while (getline(s, line)) {
		int u, v;
		stringstream ss(line);
		ss >> u >> v;
			// count the number of vertices
			if (visited[u] == false) {
				++g.V;
				visited[u] = true;
			}
			if (visited[v] == false) {
				++g.V;
				visited[v] = true;
			}
		g.v[u].push_back(v);
		g_rev.v[v].push_back(u);
	}
	g_rev.V = g.V;
	algorithm(g, g_rev);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	test_case();
	return 0;
}
