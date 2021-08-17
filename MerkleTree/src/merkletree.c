#include "merkletree.h"

void Init_MerkleTree(char* data[])
{
    root = (node*)malloc(sizeof(node));
    root->left = NULL;
    root->right = NULL;
    root->hash = NULL;

    int CountsofTx = 0;
    while (data[CountsofTx] != 0)
        CountsofTx++;
    int DepthofTree = (int)(ceil)((log(CountsofTx) / log(2)));
    if (!DepthofTree) // if CountsofTx == 1
        DepthofTree++;

    Create_Node(root, 0, DepthofTree);
    for (int i = 0; i < (int)pow(2, DepthofTree); i++) {
        if (i >= CountsofTx)
            Insert_Edge_MerkleHash(root, data[CountsofTx - 1]);
        else
            Insert_Edge_MerkleHash(root, data[i]);
    }
}

void Create_Node(node* t, int level, int depth)
{
    if (level == depth)
        return;

    if (t->left == NULL) {
        printf("at level: %d, left create\n", level);
        node* s = (node*)malloc(sizeof(node));
        s->left = NULL;
        s->right = NULL;
        s->hash = NULL;
        t->left = s;
        Create_Node(s, level + 1, depth);
    }
    if (t->right == NULL) {
        printf("at level: %d, right create\n", level);
        node* s = (node*)malloc(sizeof(node));
        s->left = NULL;
        s->right = NULL;
        s->hash = NULL;
        t->right = s;
        Create_Node(s, level + 1, depth);
    }
}

void Insert_Edge_MerkleHash(node* t, char* buf)
{
    if (t->left == NULL && t->right == NULL)
        t->hash = Get_Hash(buf);
    else {
        if (t->left->hash == NULL && t->right->hash == NULL)
            Insert_Edge_MerkleHash(t->left, buf);
        else if (t->left->hash != NULL && t->right->hash == NULL)
            Insert_Edge_MerkleHash(t->right, buf);
        if (t->left->hash != NULL && t->right->hash != NULL) // Check for un-edge node
            t->hash = 36;
    }
}

void Print_MerkleHash_Postorder(node* t)
{
    if (t != NULL) {
        Print_MerkleHash_Postorder(t->left);
        Print_MerkleHash_Postorder(t->right);

        if (t->hash == 36) {
            printf("null\n");
            return;
        }

        for (int i = 0; i < 8; i++)
            printf("%x", t->hash[i]);
        printf("\n");
    }
}

uint32_t* Get_Edge_MerkleHash(uint8_t* buf)
{
}

uint32_t* Get_MerkleHash(uint32_t* h1, uint32_t* h2)
{
}
