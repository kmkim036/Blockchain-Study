#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define ROTLEFT(A, B) ((A << B) | (A >> (32 - B)))
#define ROTRIGHT(A, B) ((A >> B) | (A << (32 - B)))

#define UPPERSIGMA0(A) ((ROTRIGHT(A, 2)) ^ (ROTRIGHT(A, 13)) ^ (ROTRIGHT(A, 22)))
#define UPPERSIGMA1(A) ((ROTRIGHT(A, 6)) ^ (ROTRIGHT(A, 11)) ^ (ROTRIGHT(A, 25)))

#define LOWERSIGMA0(A) ((ROTRIGHT(A, 7)) ^ (ROTRIGHT(A, 18)) ^ (A >> 3))
#define LOWERSIGMA1(A) ((ROTRIGHT(A, 17)) ^ (ROTRIGHT(A, 19)) ^ (A >> 10))

#define CH(A, B, C) ((A & B) | ((~A) & C))
#define MAJ(A, B, C) ((A & B) ^ (A & C) ^ (B & C))

uint32_t* Make_W(char* buf);
void Round_Func(uint32_t* H, uint32_t W, int i);
uint32_t* Get_Hash(char* buf);