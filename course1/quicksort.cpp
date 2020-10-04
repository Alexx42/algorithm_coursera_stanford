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

# define N 10000

int a[N];

int choose_pivot(int start, int end) {
	int mid = (start + end) / 2;

	if (a[end] > a[start] != a[end] > a[mid]) {
		return end;
	}
	if (a[mid] > a[start] != a[mid] > a[end]) {
		return mid;
	}
	if (a[start] > a[mid] != a[start] > a[end]) {
		return start;
	}
	return mid;
}

int partition(int start, int end, int piv_pos) {
	int pivot = a[piv_pos], i = start + 1;

	swap(a[piv_pos], a[start]);
	FOR(j, start + 1, end + 1) {
		if (a[j] < pivot) {
			swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[start], a[i - 1]);
	return i - 1;
}

ll quicksort(int start, int end) {
	ll ans = 0;
	if (start < end) {
		int pivot_pos = choose_pivot(start, end);
		int pos = partition(start, end, pivot_pos);

		ans += (pos - 1 - start);
		ans += quicksort(start, pos - 1);
		ans += (end - pos + 1);
		ans += quicksort(pos + 1, end);
	}
	return ans;
}


void test_case() {	
	int n;

	read(n);
	REP(0, n) {
		read(a[i]);
	}

	ll ans = quicksort(0, n - 1);	

	REP(0, 40) {
		write(a[i], endl);
	}
	write(ans, endl);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	srand(time(NULL));
	test_case();
	return 0;
}
