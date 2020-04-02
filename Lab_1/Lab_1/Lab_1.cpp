#include <iostream>
#include <algorithm>
#include <locale>
#include <cmath>
#include "stdlib.h"
using namespace std;

struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

struct treeNode* newNode(int data) {
    struct treeNode* node = new (struct treeNode);
    node->data = data;
    node->left = node->right = NULL;

    return (node);
};

int minPathUtil(struct treeNode* root, int &result) {

    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) return root->data;


    int ls = minPathUtil(root->left, result);
    int rs = minPathUtil(root->right, result);

    if (root->left && root->right) {
        result = min(result, ls + rs + root->data);
        return min(ls + root->data, rs + root->data);
    }

    return (!root->left) ? (rs + root->data) : (ls + root->data);
}

int minPath(struct treeNode* root)
{
    int result = INT_MAX;
    minPathUtil(root, result);
    return result;
}

int max(int a, int b) { return (a >= b) ? a : b; }

int maxPathUtil(struct treeNode *root, int &result) {

    if (root == NULL) return 0;

    if (!root->left && !root->right) return root->data;

    int ls = maxPathUtil(root->left, result);
    int rs = maxPathUtil(root->right, result);

    if (root->left && root->right) {
        result = max(result, ls + rs + root->data);
        return max(ls, rs) + root->data;
    }
    return (!root->left) ? (rs + root->data) : (ls + root->data);
}

int maxPath(struct treeNode *root) {
    int result = INT_MIN;
    maxPathUtil(root, result);
    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;

    cout << "Введите значение корня дерева: ";
    cin >> n;
    struct treeNode* root = newNode(n);

    cout << "Введите значение левого поддерева: ";
    cin >> n;
    root->left = newNode(n);

    cout << "Введите значение левого листа: ";
    cin >> n;
    root->left->left = newNode(n);

    cout << "Введите значение правого листа: ";
    cin >> n;
    root->left->right = newNode(n);


    cout << "Введите значение правого поддерева: ";
    cin >> n;
    root->right = newNode(n);

    cout << "Введите значение левого листа: ";
    cin >> n;
    root->right->left = newNode(n);

    cout << "Введите значение правого листа: ";
    cin >> n;
    root->right->right = newNode(n);

    n = 1;
    while (n == 1 || n == 2) {
        cout << "\nНайти максимум или минимум?\n1. Найти максимум\n2. Найти минимум\n\n";
        cin >> n;

        switch(n) {
            case 1 : cout << "Максимальное расстояние между листьями: " << maxPath(root) << endl;
                break;
            case 2 : cout << "Минимальное расстояние между листьями: " << minPath(root) << endl;
                break;
            default: break;
        }

    }

    return 0;
}
