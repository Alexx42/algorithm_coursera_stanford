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


void test_case() {
	ifstream f("input.txt");
	priority_queue<int> q_high, q_low;
	string line;
	int r = 0, c_h = 0, c_l = 0, m = 0;
	while (getline(f, line)) {
		int x = stoi(line);
		if (c_l > c_h) {
			if (x < m) {
				q_high.push(-q_low.top());
				q_low.pop();
				q_low.push(x);
				c_h++;
			} else {
				q_high.push(-x);
				c_h++;
			}
			m = (q_low.top());
			r += m % 10000;
		} else if (c_l < c_h) {
			if (x < m) {
				q_low.push(x);
				c_l++;
			} else {
				q_low.push(-q_high.top());
				q_high.pop();
				q_high.push(-x);
				c_l++;
			}
			m = (q_low.top());
			r = (r + m) % 10000;
		} else {
			if (x < m) {
				q_low.push(x);
				c_l++;
				m = q_low.top();
				r = (r + m) % 10000;
			} else {
				q_high.push(-x);
				c_h++;
				m = -q_high.top();
				r = (r + m) % 10000;
			}
		}
	}
	write(r % 10000, endl);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	test_case();
	return 0;
}
