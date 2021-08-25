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
        t->hash = Get_SHA256Hash(buf); // get sha256 hash result using a function "Get_SHA256Hash" in sha256.c
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

void Get_MerkleHash(node* t)
{
    if (t->left->hash == 36)
        Get_MerkleHash(t->left);
    if (t->right->hash == 36)
        Get_MerkleHash(t->right);
    if (t->left->hash != 36 && t->right->hash != 36) {
        uint32_t* h1 = malloc(sizeof(uint32_t) * 8);
        uint32_t* h2 = malloc(sizeof(uint32_t) * 8);
        h1 = t->left->hash;
        h2 = t->right->hash;

        uint32_t* buf = malloc(sizeof(uint32_t) * 8);
        for (int i = 0; i < 8; i++)
            buf[i] = h1[i] + h2[i];

        t->hash = Get_SHA256Hash(buf);
    }
}
