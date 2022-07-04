#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left, *right;
    int data;

    // constructer
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void BuildTree(Node *&root)
{
    int data;
    cout << "Enter the data of root " << endl;
    cin >> data;

    root = new Node(data);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        // create left node
        int ld;
        cout << "Enter root ka left data " << frontNode->data << endl;
        cin >> ld;

        if (ld != -1)
        {
            frontNode->left = new Node(ld);
            q.push(frontNode->left);
        }

        // create right node
        int rd;
        cout << "Enter root ka right data " << frontNode->data;
        cin >> rd;

        if (rd != -1)
        {
            frontNode->right = new Node(rd);
            q.push(frontNode->right);
        }
    }
}

void printTree(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        int sz = q.size();
        q.pop();

        for (int i = 0; i < sz; i++)
        {
            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);
        }
        cout << front->data << " ";
    }
}

Node *createMappingNodeToParent(Node *root, int target, map<Node *, Node *> &nTop)
{
    queue<Node *> q; // we'll going through levelOrder traversal
    q.push(root);

    nTop[root] = NULL; // root ka parent NULL kar diya
    Node *res = NULL;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        // if target find
        if (front->data == target)
            res = front;

        if (front->left)
        {
            nTop[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nTop[front->right] = front;
            q.push(front->right);
        }
    }

    return res;
}

void burntree(Node *root, map<Node *, Node *> &mp)
{
    map<Node *, bool> visited;
    queue<Node *> q; // bcoz we have to do LevelOrder Traverssal
    bool flag = 0;
    int time = 0;

    q.push(root);
    visited[root] = true;

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            Node *front = q.front();
            q.pop();

            // now process for neighbouring Node
            if (front->left && !visited[front->left])
            {
                q.push(front->left);
                visited[front->left] = true;
                flag = 1;
            }

            if (front->right && !visited[front->right])
            {
                q.push(front->right);
                visited[front->right] = true;
                flag = 1;
            }

            if (mp[front] && !visited[mp[front]])
            {
                q.push(mp[front]);
                visited[mp[front]] = true;
                flag = 1;
            }
        }
        if (flag)
            time++;
    }
    cout << time << endl;
}

void funcBurningTree(Node *root, int target)
{
    /*
        steps:
        1. create Mapping with Node and Parent  [Bcoz we don't have pointer from node->parent]
        2. find target
        3. start from target node and check every node is visited or not and increment time
    */

    map<Node *, Node *> nodeToParent;
    Node *targetNode = createMappingNodeToParent(root, target, nodeToParent);

    burntree(targetNode, nodeToParent);
}

int main()
{
    Node *root = NULL;
    BuildTree(root);

    funcBurningTree(root, 2);

    // printTree(root);
    return 0;
}