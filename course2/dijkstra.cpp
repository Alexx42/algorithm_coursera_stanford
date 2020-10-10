#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define REP(a, b) FOR(i, a, b)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

template <typename ...Args>
void write(Args && ...args) {
	(cout << ... << args);
}

template <typename ...Args>
void read(Args && ...args) {
	(cin >> ... >> args);
}

# define N 200

void dijkstra(vector<pair<int, int> > adj[]) {
	int c = 1;
	vector<int> dist(N, INT_MAX);
	
	priority_queue<pi, vector<pi>, greater<pi> > q;
	q.push({0, 0});
	dist[0] = 0;
	while (!q.empty()) {
		int u = q.top().second;
		vector<pair<int, int> > neighbor = adj[u];
		q.pop();
		
		FOR(i, 0, neighbor.size()) {
			int v = neighbor[i].first;
			int weight = neighbor[i].second;

			
			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				q.push({dist[v], v});
			}
			
		}
		
	}
	for (int i = 1; i < N; i++) {
		if (i == 6 || i == 36 || i == 58 || i == 81 \
			|| i == 98 || i == 114 || i == 132 || i == 164 \
			|| i == 187 || i == 196)
			write(dist[i], ",\n"[i == N - 1]);
	}
}

void test_case() {
	vector<pair<int, int> > adj[N];
	// vertices are labelled from 1 to N
	string line;
	ifstream f("input.txt");

	while (getline(f, line)) {
		stringstream ss(line);

		int u;
		ss >> u;
		string edge;
		while (ss >> edge) {
			size_t pos = edge.find(",");
			int v = stoi(edge.substr(0, pos)), weight = stoi(edge.substr(pos + 1, edge.size()));
			adj[u - 1].push_back({v - 1, weight});
			adj[v - 1].push_back({u - 1, weight});
		}
	}
	dijkstra(adj);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	test_case();
	return 0;
}
