#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
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

#define N 400


void add_list(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void add_edge(vector<pair<int, int> > edge, int u, int v) {
	edge.push_back(make_pair(u, v));
	edge.push_back(make_pair(v, u));
}

void test_case() {
	vector<int> adj[N];
	vector<pair<int, int> > edges;

	int u, v;
	ifstream file;
	string line;

	file.open("input");
	while (getline(file, line)) {
		stringstream iss(line);
		iss >> u;
		while (iss >> v) {
			add_list(adj, u, v);
			add_edge(edges, u, v);
		}
	}
	file.close();
	int i = 0;
	while (i < 4) {
		write(" : ");
		for (auto x : adj[i]) {
			write(x, " ");
		}
		write(endl);
		i++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	test_case();
	return 0;
}
