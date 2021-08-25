#include "base58.h"

#define SizeofRet 80

char Get_Char(int input)
{
    if (input < 9)
        return input + 49;
    else if (input < 17)
        return input + 56;
    else if (input < 22)
        return input + 57;
    else if (input < 33)
        return input + 58;
    else if (input < 44)
        return input + 64;
    else
        return input + 65;
}

int Get_Value(char input)
{
    if (input > 48 && input < 58)
        return input - 49;
    else if (input > 64 && input < 73)
        return input - 56;
    else if (input > 73 && input < 79)
        return input - 57;
    else if (input > 79 && input < 91)
        return input - 58;
    else if (input > 96 && input < 108)
        return input - 64;
    else if (input > 108 && input < 123)
        return input - 65;
    else
        return -1;
}

void Reverse_String(char* str)
{
    size_t size = strlen(str);
    char temp;

    for (size_t i = 0; i < size / 2; i++) {
        temp = str[i];
        str[i] = str[(size - 1) - i];
        str[(size - 1) - i] = temp;
    }
}

char* Encode_Base58(char* input)
{
    unsigned long long int sum = 0;
    while (*input != 0) {
        sum = sum << 8;
        sum += *input;
        input++;
    }

    char* ret = malloc(sizeof(char) * SizeofRet);
    int i = 0;

    for (i; sum > 58; i++) {
        unsigned long long int divisor = 1;
        while (divisor < sum)
            divisor *= 58;
        divisor /= 58;

        int quotient = sum / divisor;
        sum %= divisor;
        *(ret + i) = Get_Char(quotient);
    }
    *(ret + i) = Get_Char(sum);
    *(ret + i + 1) = 0;

    return ret;
}

char* Decode_Base58(char* input)
{
    unsigned long long int sum = 0;
    unsigned long long int j = 1;
    int i;
    for (i = strlen(input) - 1; i > -1; i--, j *= 58) {
        int value = Get_Value(*(input + i));
        if (value == -1)
            return -1;
        else
            sum += (unsigned long long int)(value * j);
    }

    char* ret = malloc(sizeof(char) * SizeofRet);
    i = 0;

    while (sum != 0) {
        *(ret + i) = sum & 0xFF;
        i++;
        sum = sum >> 8;
    }

    Reverse_String(ret);
    return ret;
}