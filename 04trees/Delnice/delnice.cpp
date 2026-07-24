#include <bits/stdc++.h>
using namespace std;

class AVLNode {
    public:
        long long value;
        AVLNode *left, *right;
        long long height;
        AVLNode(long long v) {
            value = v;
            left = NULL;
            right = NULL;
            height = 1;
        }
};

class AVLTree {
    public:
        AVLNode *root = NULL;
        void update(AVLNode *node) {
            node->height = 1 + max(height(node->left), height(node->right));
        }
        long long height() {
            return height(root);
        }
        long long height(AVLNode *node) {
            if(node == NULL) return 0;
            else return node->height;
        }
        long long balance(AVLNode *node) {
            return height(node->right) - height(node->left);   
        }
        AVLNode* rotateLeft(AVLNode* node) {
            AVLNode *R = node->right;
            node->right = R->left;
            R->left = node;  
            update(node);
            update(R);
            return R;
        }
        AVLNode* rotateRight(AVLNode* node) {
            AVLNode *L = node->left;
            node->left = L->right;
            L->right = node;
            update(node);
            update(L);
            return L;
        }
        bool contains(long long x) {
            return contains(x, root);
        }
        bool contains(long long x, AVLNode *node) {
            if(node == NULL) return false;
            if(x == node->value) {
                return true;
            }
            if(x < node->value) {
                return contains(x, node->left);
            }
            else return contains(x, node->right);
        }

        void insert(long long x) {
            root = insert(x, root);
        }

        AVLNode* insert(long long x, AVLNode* node) {
            if(node == NULL) {
                return new AVLNode(x);
            }
            if(x <= node->value) node->left = insert(x, node->left);
            else node->right = insert(x, node->right);
            update(node);
            long long b = balance(node);
            if(b == 2) {
                long long bR = balance(node->right);
                if(bR == 0 || bR == 1) {
                    return rotateLeft(node);
                }
                else {
                    node->right = rotateRight(node->right);
                    return rotateLeft(node);
                }
            }
            else if (b == -2) {
                long long bL = balance(node->left);
                if(bL == -1 || bL == 0) return rotateRight(node);
                else {
                    node->left = rotateLeft(node->left);
                    return rotateRight(node);
                }
            }
            return node;
        }

        AVLNode *lowerBound(long long x) {
            return lowerBound(x, root);
        }

        AVLNode *lowerBound(long long x, AVLNode *node) {
            if(node == NULL) return node;
            if(x <= node->value) {
                AVLNode *candidate = lowerBound(x, node->left);
                if(candidate == NULL) return node;
                else return candidate;
            } else return lowerBound(x, node->right);
        }

        AVLNode *upperBound(long long x) {
            return upperBound(x, root);
        }

        AVLNode *upperBound(long long x, AVLNode *node) {
            if(node == NULL) return NULL;
            if(node->value <= x) {
                AVLNode *candidate = upperBound(x, node->right);
                if(candidate == NULL) return node;
                else return candidate;
            } else return upperBound(x, node->left);
        }
};

int main() {
    long long n, z;
    cin >> n >> z;
    long long S = 0;
    AVLTree *tree = new AVLTree();
    tree->insert(0);
    long long minDiff = LLONG_MAX;
    for(long long i = 0; i < n; i++) {
        long long d;
        cin >> d;
        S+=d;
        long long target = S - z;
        AVLNode *candidate1 = tree->lowerBound(target);
        AVLNode *candidate2 = tree->upperBound(target);
        if(candidate1 != NULL) {
            long long profit = S - candidate1->value;
            long long minimumDiff = abs(profit - z);
            if(minimumDiff < minDiff) minDiff = minimumDiff;
        }
        if(candidate2 != NULL) {
            long long profit = S - candidate2->value;
            long long minimumDiff = abs(profit - z);
            if(minimumDiff < minDiff) minDiff = minimumDiff;
        }
        tree->insert(S);
    }
    cout << minDiff;
    return 0;
}