bool traverse(Node *root, int &cnt)
{
    if (root == NULL)
        return true;
    if (root->left)
    {
        if (root->val < root->left->val)
            return false;
    }
    if (root->right)
    {
        if (root->val > root->right->val)
            return false;
    }
    bool l = traverse(root->left, cnt + 1);
    bool r = traverse(root->right, cnt + 1);
    return (l && r);
}
void tree(Node *r, int &ans)
{
    if (r == NULL)
        return;
    int cnt = 1;
    if (traverse(r, cnt))
    {
        ans = max(ans, cnt);
    }

    tree(r->left, ans);
    tree(r->right, ans);
}