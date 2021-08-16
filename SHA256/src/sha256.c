#include "sha256.h"

// pre-process of input message
uint32_t* Make_W(char* buf)
{
    int i;
    
    uint8_t msg[64] = { 0 };
    for (i = 0; i < strlen(buf); i++)
        msg[i] = buf[i];
    msg[i] = 0x80;
    msg[63] = i * 8;

    static uint32_t SHA256_W[64];
    for (i = 0; i < 16; i++)
        SHA256_W[i] = msg[i * 4] << 24 | msg[i * 4 + 1] << 16 | msg[i * 4 + 2] << 8 | msg[i * 4 + 3];
    for (i = 16; i < 64; i++)
        SHA256_W[i] = LOWERSIGMA1(SHA256_W[i - 2]) + SHA256_W[i - 7] + LOWERSIGMA0(SHA256_W[i - 15]) + SHA256_W[i - 16];

    return SHA256_W;
}

void Round_Func(uint32_t* H, uint32_t W, int i)
{
    uint32_t T1 = SHA256_K[i] + UPPERSIGMA1(H[4]) + CH(H[4], H[5], H[6]) + H[7] + W;
    uint32_t T2 = UPPERSIGMA0(H[0]) + MAJ(H[0], H[1], H[2]);
    H[7] = H[6];
    H[6] = H[5];
    H[5] = H[4];
    H[4] = H[3] + T1;
    H[3] = H[2];
    H[2] = H[1];
    H[1] = H[0];
    H[0] = T1 + T2;
}

uint32_t* Get_Hash(char* buf)
{
    int i;

    uint32_t* SHA256_W = Make_W(buf);

    static uint32_t SHA256_H[8] = { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };
    uint32_t SHA256_H_TEMP[8];
    for (i = 0; i < 8; i++)
        SHA256_H_TEMP[i] = SHA256_H[i];

    for (i = 0; i < 64; i++)
        Round_Func(SHA256_H_TEMP, SHA256_W[i], i);

    for (i = 0; i < 8; i++)
        SHA256_H[i] += SHA256_H_TEMP[i];

    return SHA256_H;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Wrong Input Argument\nUsage: ./sha256 InputWord\n\tExample:\t./sha256 블록체인\n\tWrong Example:\t./sha256\n\t\t\t./sha256 비트코인 블록체인\n");
        return -1;
    }

    uint32_t* SHA256HashOutput = Get_Hash(argv[1]);

    printf("0x");
    for (int i = 0; i < 8; i++)
        printf("%x", SHA256HashOutput[i]);
    printf("\n");

    return 0;
}