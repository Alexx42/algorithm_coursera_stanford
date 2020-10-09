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

int a[10000];

template<typename T>
class Heap {
	public:
		Heap<T>() {}
		~Heap<T>() {}
	
		T& parent(int i) {return heap_[(i - 1) / 2];}
		T& left(int i) {return heap_[(i * 2) + 1];}
		T& right(int i) {return heap_[(i * 2) + 2];}

		bool is_left(int i) {return ((2 * i) + 1 < heap_.size());}
		bool is_right(int i) {return ((2 * i) + 2 < heap_.size());}


		T get_min(){ return heap_[0]; }


		bool empty() {return heap_.size() == 0;}
	
		void init_heap(T a[], int n) {
			// Initializes the private attribute
			heap_.clear();

			// heapify up on each add
			REP(0, n) {
				heap_.push_back(a[i]);
				heapify_up(i);
			}
		}

		void heapify_up(int i) {
			while (i > 0 && parent(i) > heap_[i]) {
				swap(parent(i), heap_[i]);
				heapify_up((i - 1) / 2);
			}
		}

		void heapify_down(int i) {
			while (i < heap_.size()) {
				if (is_left(i) && is_right(i)) {
					if (left(i) < right(i) && left(i) < heap_[i]) {
						swap(left(i), heap_[i]);
						i = 2 * i + 1;
					} else if (right(i) < left(i) && right(i) < heap_[i]) {
						swap(right(i), heap_[i]);
						i = 2 * i + 2;
					} else {
						break ;
					}
				} else if (is_left(i) && left(i) < heap_[i]) {
					swap(left(i), heap_[i]);
					i = 2 * i + 1;
				} else if (is_right(i) && right(i) < heap_[i]) {
					swap(right(i), heap_[i]);
					i = 2 * i + 2;
				} else {
					break ;
				}
			}	
		}

		int find(T x) {
			int i = 0;

			while (i < heap_.size()) {
				if (heap_[i] == x) {
					return i;
				}
				if (is_left(i) && left(i) > x) {
					i = 2 * i + 2;
				} else {
					i = 2 * i + 1;
				}
			}
			return -1;
		}

		bool remove(T x) {
			int pos = find(x);
			if (pos == -1) {
				return false;
			}
			swap(heap_[heap_.size() - 1], heap_[pos]);
			heap_.pop_back();
			heapify_down(pos);
			return true;
		}

		bool insert(T x) {
			if (find(x) != -1) {
				return false;
			}
			heap_.push_back(x);
			heapify_up(heap_.size() - 1);
			return true;
		}

		const void print_heap() const{
			REP(0, heap_.size()) {
				write(heap_[i], " \n"[i == heap_.size() - 1]);
			}
		}
		
	private:
		vector<T> heap_;
};

void test_case() {
	int n;
	Heap<int> heap;

	read(n);
	REP(0, n) {
		read(a[i]);
	}
	heap.init_heap(a, n);
	heap.print_heap();
	heap.remove(1);
	heap.print_heap();
	heap.insert(42);
	heap.print_heap();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	test_case();
	return 0;
}
