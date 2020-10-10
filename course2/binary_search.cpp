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


struct BST {
	BST* right;
	BST* left;
	int val;
};

void insert(BST** bst, int x) {
	if (*bst == nullptr) {
		*bst = new BST;
		(*bst)->val = x;
		return ;
	}
	if (x > (*bst)->val) {
		insert(&(*bst)->right, x);
	} else {
		insert(&(*bst)->left, x);
	}
}

void print(BST* bst) {
	if (bst == nullptr) {
		return ;
	}
	print(bst->left);
	write(bst->val, " ");
	print(bst->right);
}

int find_max(BST *bst) {
	if (bst == nullptr) {
		return INT_MAX;
	}
	if (bst->left == nullptr && bst->right == nullptr) {
		return bst->val;
	}
	return find_max(bst->right);
}

BST* find_min(BST *bst) {
	if (bst == nullptr) {
		return nullptr;
	}
	if (bst->left == nullptr && bst->right == nullptr) {
		return bst;
	}
	return find_min(bst->left);
}

BST* find(BST *bst, int key) {
	if (bst == nullptr) {
		return nullptr;
	}
	if (bst->val == key) {
		return bst;
	}
	if (bst->val > key) {
		return find(bst->left, key);
	}
	return find(bst->right, key);
}


void del(BST** bst, int key) {
	if (*bst == nullptr) {
		return ;
	}
	if ((*bst)->val < key) {
		del(&((*bst)->right), key);
	} else if ((*bst)->val > key) {
		del(&((*bst)->left), key);
	} else {
		if ((*bst)->left == nullptr && (*bst)->right == nullptr) {
			delete *bst;
		} else if ((*bst)->left == nullptr || (*bst)->right == nullptr) {
			*bst = (*bst)->left ? (*bst)->left : (*bst)->right;
		}
		else {
			BST* successor = find_min((*bst)->right);

			(*bst)->val = successor->val;

			del(&((*bst)->right), successor->val);
		}
	}
}

void test_case() {
	BST* bst = nullptr;

	int a[] = {1, 4, 3, 2, 8, 5, 7};
	REP(0, 7) {
		insert(&bst, a[i]);
	}
	print(bst);
	write(endl);
	del(&bst, 3);
	print(bst);

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	test_case();
	return 0;
}
