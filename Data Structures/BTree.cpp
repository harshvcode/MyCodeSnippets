#include <bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    node *left;
    node *right;
    node(int key)
    {
        this->key = key;
        left = right = nullptr;
    }
};
node *insert(node *root, int key)
{
    if (root == nullptr)
    {
        root = new node(key);
        return root;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *tmp = q.front();
        q.pop();
        if (tmp->left)
        {
            q.push(tmp->left);
        }
        else
        {
            tmp->left = new node(key);
            return root;
        }
        if (tmp->right)
        {
            q.push(tmp->right);
        }
        else
        {
            tmp->right = new node(key);
            return root;
        }
    }
    return root;
}
void utildelDeepest(node *root, node *deletit)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *tmp = q.front();
        q.pop();
        if (tmp == deletit)
        {
            tmp = nullptr;
            delete (tmp);
            return;
        }
        if (tmp->left)
        {
            if (tmp->left == deletit)
            {
                tmp->left = nullptr;
                delete (tmp->left);
                return;
            }
            else
            {
                q.push(tmp->left);
            }
        }
        if (tmp->right)
        {
            if (tmp->right == deletit)
            {
                tmp->right = nullptr;
                delete (tmp->right);
                return;
            }
            else
            {
                q.push(tmp->right);
            }
        }
    }
}
node *deleete(node *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (root->key == key)
            return nullptr;
        return root;
    }
    queue<node *> q;
    q.push(root);
    node *lastDeep, *keyNode = nullptr; //lastDeep will be deleted and it's key will be the key of keyNode
    while (!q.empty())
    {
        lastDeep = q.front();
        q.pop();
        if (lastDeep->key == key)
        {
            keyNode = lastDeep;
        }
        if (lastDeep->left)
            q.push(lastDeep->left);
        if (lastDeep->right)
            q.push(lastDeep->right);
    }
    if (keyNode != nullptr)
    {
        int lastNodeKey = lastDeep->key;
        utildelDeepest(root, lastDeep);
        keyNode->key = lastNodeKey;
    }
    return root;
}
void inorder(node *temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->key << ' ';
    inorder(temp->right);
}
void preorder(node *temp)
{
    if (!temp)
        return;
    cout << temp->key << " ";
    inorder(temp->left);
    inorder(temp->right);
}
void postorder(node *temp)
{
    if (!temp)
        return;
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->key << " ";
}
vector<int> preOrder(node *root) //Iterative PreOrder, returns preOrder into a Vector
{
    if (root == nullptr)
        return {};
    vector<int> ans;
    stack<node *> st; //Stack
    st.push(root);
    while (!st.empty())
    {
        node *tmp = st.top();
        st.pop();
        ans.push_back(tmp->key);
        if (tmp->right)
            st.push(tmp->right); //Put right node in stack first
        if (tmp->left)
            st.push(tmp->left); //so that left be on top, and traverse left first
    }
    return ans;
}
int height(node *root)
{ //height calculate recursively
    return (root) ? max(height(root->left), height(root->right)) + 1 : 0;
}
int height(node *root)
{ //height calculate iteratively
    int ans = 0;
    if (root == nullptr)
        return ans;
    stack<pair<node *, int>> st; //node with height
    st.push({root, 1});          //root has height 1
    while (!st.empty())
    {
        pair<node *, int> paiir = st.top();
        st.pop();
        ans = max(ans, paiir.second);
        if (paiir.first->left)
        {
            st.push({paiir.first->left, paiir.second + 1});
        }
        if (paiir.first->right)
        {
            st.push({paiir.first->right, paiir.second + 1});
        }
    }
    return ans;
}
int32_t main()
{
    node *root = nullptr;
    for (int i = 1; i <= 5; ++i)
        root = insert(root, i);
    cout << height(root);
    return 0;
}