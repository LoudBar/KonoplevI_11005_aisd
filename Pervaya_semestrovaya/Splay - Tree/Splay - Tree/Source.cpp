#include <iostream>;
#include <ctime>;
#include <fstream>;

using namespace std;

struct TreeNode
{
    int key = 0;
    TreeNode* parent = 0;
    TreeNode* left = 0;
    TreeNode* right = 0;
};

struct SplayTree
{
    TreeNode* root = 0;

    void zig(TreeNode* x) //Если родитель x - корень.
    {
        TreeNode* p = x->parent;

        if (p->left == x)
        {
            TreeNode* a = x->left;
            TreeNode* b = x->right;
            TreeNode* c = p->right;

            x->parent = NULL;
            x->right = p;
            p->parent = x;
            p->left = b;

            if (b) b->parent = p;
        }

        else
        {
            TreeNode* a = p->left;
            TreeNode* b = x->left;
            TreeNode* c = x->right;

            x->parent = NULL;
            x->left = p;
            p->parent = x;
            p->right = b;

            if (b) b->parent = p;
        }
    }

    void zig_zag(TreeNode * x) //Если x >= р <= g или x <= р >= g.
    {
        TreeNode* p = x->parent;
        TreeNode* g = p->parent;
        if (p->right == x)
        {
            TreeNode* a = p->left;
            TreeNode* b = x->left;
            TreeNode* c = x->right;
            TreeNode* d = g->right;

            x->parent = g->parent;
            x->left = p;
            x->right = g;

            p->parent = x;
            p->right = b;

            g->parent = x;
            g->left = c;

            if (x->parent)
            {
                if (x->parent->left == g) x->parent->left = x;
                else x->parent->right = x;
            }

            if (b) b->parent = p;

            if (c) c->parent = g;
        }
        else
        {
            TreeNode* a = g->left;
            TreeNode* b = x->left;
            TreeNode* c = x->right;
            TreeNode* d = p->right;

            x->parent = g->parent;
            x->left = g;
            x->right = p;

            p->parent = x;
            p->left = c;

            g->parent = x;
            g->right = b;

            if (x->parent)
            {
                if (x->parent->left == g) x->parent->left = x;
                else x->parent->right = x;
            }

            if (b) b->parent = g;

            if (c) c->parent = p;
        }
        
    }

    void zig_zig(TreeNode* x) //Если g >= p >= x или x <= p <= g.
    {
        TreeNode* p = x->parent;
        TreeNode* g = p->parent;
        if (p->left == x)
        {
            TreeNode* a = x->left;
            TreeNode* b = x->right;
            TreeNode* c = p->right;
            TreeNode* d = g->right;

            x->parent = g->parent;
            x->right = p;

            p->parent = x;
            p->left = b;
            p->right = g;

            g->parent = p;
            g->left = c;


            if (x->parent)
            {
                if (x->parent->left == g) x->parent->left = x;
                else x->parent->right = x;
            }

            if (b) b->parent = p;

            if (c) c->parent = g;
        }
        else
        {
            TreeNode* a = g->left;
            TreeNode* b = p->left;
            TreeNode* c = x->left;
            TreeNode* d = x->right;

            x->parent = g->parent;
            x->left = p;

            p->parent = x;
            p->left = g;
            p->right = c;

            g->parent = p;
            g->right = b;

            if (x->parent)
            {
                if (x->parent->left == g) x->parent->left = x;
                else x->parent->right = x;
            }

            if (b != NULL) b->parent = g;

            if (c != NULL) c->parent = p;
        }
    }

    void splay(TreeNode* x)
    {
        while (x->parent)
        {
            TreeNode* p = x->parent;
            TreeNode* g = p->parent;

            if (!g) zig(x);
            else if ((g->left == p && p->left == x) || (g->right == p && p->right == x)) zig_zig(x);
            else zig_zag(x);
        }
        root = x;
    }

    void insert(int x)
    {
        if (!root) { root = new TreeNode; root->key = x; return; }

        TreeNode* curr = root;

        while (curr)
        {
            if (x < curr->key)
            {
                if (!curr->left)
                {
                    TreeNode* newNode = new TreeNode;
                    newNode->key = x;
                    curr->left = newNode;
                    newNode->parent = curr;
                    splay(newNode);
                    return;
                }
                else curr = curr->left;
            }
            else if (x > curr->key)
            {
                if (curr->right == NULL)
                {
                    TreeNode* newNode = new TreeNode;
                    newNode->key = x;
                    curr->right = newNode;
                    newNode->parent = curr;
                    splay(newNode);
                    return;
                }
                else curr = curr->right;
            }
            else
            {
                splay(curr);
                return;
            }
        
        }
    }

    TreeNode* find(int x)
    {
        TreeNode* ans = NULL;
        TreeNode* curr = root;
        TreeNode* prev = NULL;

        while (curr)
        {
            if (x < curr->key) curr = curr->left;
            else if (x > curr->key) curr = curr->right;
            else
            {
                ans = curr;
                break;
            }
        }
        if (ans) splay(ans);        

        return ans;
    }

    TreeNode* subtree_max(TreeNode* subRoot)
    {
        TreeNode* curr = subRoot;
        while (curr->right) curr = curr->right;
        return curr;
    }

    TreeNode* subtree_min(TreeNode* subRoot)
    {
        TreeNode* curr = subRoot;
        while (curr->left) curr = curr->left;
        return curr;
    }

    void Delete(int x)
    {
        TreeNode* del = find(x);
        if (!del)
        {
            return;
        }
        TreeNode* L = del->left;
        TreeNode* R = del->right;
        if (!L && !R)
        {
            root = NULL;
        }
        else if (!L)
        {
            TreeNode* M = subtree_min(R);
            splay(M);
        }
        else if (!R)
        {
            TreeNode* M = subtree_max(L);
            splay(M);
        }
        else
        {
            TreeNode* M = subtree_max(L);
            splay(M);
            M->right = R;
            R->parent = M;
        }
        if (del->parent) {
            if (del->parent->right == del)
                del->parent->right = NULL;
            else if (del->parent->left == del)
                del->parent->left = NULL;
        }
        delete del;
    }

    void printTree(TreeNode* root, bool brackets)
    {
        if (!root)
        {
            if (brackets) printf("{}");
            return;
        }
        if (brackets) printf("{");
        if (root->left) printTree(root->left, brackets);
        if (root) printf(" %d ", root->key);
        if (root->right) printTree(root->right, brackets);
        if (brackets) printf("}");
    }

    void print(bool brackets) { printTree(root, brackets); }
};

int main()
{
    SplayTree* tree = new SplayTree;

    tree->insert(2);
    tree->print(true);
    printf("\n---------------------------------------------------------------\n");

    tree->insert(5);
    tree->print(true);
    printf("\n---------------------------------------------------------------\n");

    tree->Delete(2);
    tree->print(true);
    printf("\n---------------------------------------------------------------\n");

    tree->insert(1);
    tree->print(true);
    printf("\n---------------------------------------------------------------\n");

    tree->insert(0);
    tree->print(true);
    printf("\n---------------------------------------------------------------\n");

    tree->insert(5);
    tree->print(true);
    printf("\n---------------------------------------------------------------\n");
   
    cout << endl;
    cout << tree->find(5) << endl;

    ofstream fout;
    fout.open("Insert.txt");

    for (int n = 1000; n <= 100000; n += 1000)
    {
        double totalTime = 0;

        for (int j = 0; j < 10; j++)
        {
            SplayTree* tree = new SplayTree;

            double startTime = clock();

            for (int i = 0; i < n; i++)
                tree->insert(rand());

            double endTime = clock();
            totalTime += endTime - startTime;
        }

        totalTime /= 10;

        fout << (int)totalTime << endl;
    }
    
    fout.close();
    
    return 0;
}