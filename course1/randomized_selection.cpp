#include <bits/stdc++.h>

using namespace std;

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

# define endl "\n"

# define N 10000
int a[N];

int partition(int start, int end, int piv_pos) {
	int piv = a[piv_pos], i = start + 1;

	swap(a[start], a[piv_pos]);
	FOR(j, start, end) {
		if (a[j] < piv) {
			swap(a[i], a[j]);
			i += 1;
		}
	}
	swap(a[i - 1], a[start]);

	return i - 1;
}

int r_selection(int start, int end, int x) {
	if (start < end) {
		int piv_pos = start + rand() % (end - start);
		int j = partition(start, end, piv_pos);

		if (j == x) {
			return j;
		} else if (j > x) {
			return r_selection(start, j, x);
		} else {
			return r_selection(j + 1, end, x);
		}
	}
	return 0;
}

void test_case() {
	int n, x;

	read(n);
	REP(0, n) {
		read(a[i]);
	}
	read(x);
	x = r_selection(0, n, x);
	write(x," ", a[x], endl);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	test_case();
	return 0;
}
