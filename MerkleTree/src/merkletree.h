#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../SHA256/src/sha256.h"

typedef struct _merkletree {
    uint32_t* hash;
    struct _merkletree* left;
    struct _merkletree* right;
} node;

node* root;

uint32_t* Get_Edge_MerkleHash(uint8_t* buf);
uint32_t* Get_MerkleHash(uint32_t* h1, uint32_t* h2);

void Init_MerkleTree(char* data[]);
void Create_Node(node* t, int level, int depth);
void Insert_Edge_MerkleHash(node* t, char* buf);
void Print_MerkleHash_Postorder(node* t);