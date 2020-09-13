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

# define N 100000

ll a[N];

ll inversions(int start, int mid, int end) {
	int p = start, q = mid + 1, k = 0;
	ll A[end - start + 1];
	ll ans = 0;
	REP(start, end + 1) {
		if (p > mid) {
			A[k++] = a[q++];
		} else if (q > end) {
			A[k++] = a[p++];
		} else if (a[p] > a[q]) {
			ans += mid + 1 - p;
			A[k++] = a[q++];
		} else {
			A[k++] = a[p++];
		}
	}
	REP(0, k) {
		a[start++] = A[i];
	}
	return ans;
}

ll count_inversions(int start, int end) {
	ll ans = 0;
	if (start < end) {
		int mid = (end + start) / 2;
		ans += count_inversions(start, mid);
		ans += count_inversions(mid + 1, end);

		ans += inversions(start, mid, end);
	}
	return ans;
}

void test_case() {
	int n;

	read(n);
	REP(0, n) {
		read(a[i]);
	}
	ll ans = count_inversions(0, n - 1);
	write(ans, endl);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	test_case();
	return 0;
}
