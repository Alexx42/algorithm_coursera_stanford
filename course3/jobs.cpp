#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define REP(a, b) FOR(i, a, b)

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

template <typename ...Args>
void write(Args && ...args) {
		(cout << ... << args);
}

template <typename ...Args>
void read(Args && ...args) {
		(cin >> ... >> args);
}

bool cmp(pi p1, pi p2) {
		float dp1 = p1.first / (float)p1.second;
		float dp2 = p2.first / (float)p2.second;
		return dp1 > dp2;
}

bool cmp_diff(pi p1, pi p2) {
		int dp1 = p1.first - p1.second;
		int dp2 = p2.first - p2.second;

		return dp1 == dp2 ? p1.first > p2.first : dp1 > dp2;
}

void test_case() {
		int n;
		string line;
		vector<pi> desc;
		ifstream f("jobs.txt");
  
		getline(f, line);
		n = stoi(line);
		while (getline(f, line)) {
				stringstream ss(line);
				pi p;
				ss >> p.first >> p.second;
				desc.push_back(p);
		}
		sort(desc.begin(), desc.end(), cmp);
		ll r = 0, ci = 0;
		for (auto p : desc) {
				ci += p.second;
				r += p.first * ci;
		}
		write(r, endl);
}

int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);

		test_case();
		return 0;
}
