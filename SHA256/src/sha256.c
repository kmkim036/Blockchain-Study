#include "sha256.h"

// sequence of sixty-four constant words
const uint32_t SHA256_K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

const uint32_t SHA256_H[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// pre-process of input message
uint32_t* Make_W(uint8_t* buf)
{
    int i;

    uint8_t msg[64] = { 0 };
    for (i = 0; i < strlen(buf); i++)
        msg[i] = buf[i];
    msg[i] = 0x80;
    msg[63] = i * 8;

    uint32_t* SHA256_W = malloc(sizeof(uint32_t) * 64);
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

uint32_t* Get_SHA256Hash(uint8_t* buf)
{
    int i;

    uint32_t* SHA256_W = Make_W(buf);

    uint32_t SHA256_H_TEMP[8];
    for (i = 0; i < 8; i++)
        SHA256_H_TEMP[i] = SHA256_H[i];

    for (i = 0; i < 64; i++)
        Round_Func(SHA256_H_TEMP, SHA256_W[i], i);

    uint32_t* HASH_VALUE = malloc(sizeof(uint32_t) * 8);
    for (i = 0; i < 8; i++)
        HASH_VALUE[i] = SHA256_H_TEMP[i] + SHA256_H[i];

    return HASH_VALUE;
}