#include "merkletree.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Wrong Input Argument\nUsage: ./merkletree InputArgument0 InputArgument1 InputArgument2...\n\tExample:\t./merkletree TX0 TX1 TX2\n\tWrong Example:\t./merkletree\n");
        return -1;
    }

    printf("Initialize..\n");
    Init_MerkleTree(argv + 1);

    printf("\nPrint Edge Hash Value by Post Order\n");
    Print_MerkleHash_Postorder(root);
    printf("\n");
    Get_MerkleHash(root);
    
    printf("\nPrint Merkle Tree Hash Value by Post Order\n");
    Print_MerkleHash_Postorder(root);

    return 0;
}