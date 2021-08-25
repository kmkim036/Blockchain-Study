#include "sha256.h"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Wrong Input Argument\nUsage: ./sha256 InputWord\n\tExample:\t./sha256 블록체인\n\tWrong Example:\t./sha256\n\t\t\t./sha256 비트코인 블록체인\n");
        return -1;
    }

    uint32_t* SHA256HashOutput = Get_SHA256Hash(argv[1]);

    printf("0x");
    for (int i = 0; i < 8; i++)
        printf("%x", SHA256HashOutput[i]);
    printf("\n");

    return 0;
}