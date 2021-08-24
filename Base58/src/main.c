#include "base58.h"

void print_usage()
{
    printf("Wrong Input Argument\n");
    printf("Usage:\t./base58 e InputWord\n\t./base58 d InputWord\n");
    printf("\tExample:\t./base58 e kmkim\n\t\t\t./base58 d D7y6YY4\n");
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        print_usage();
        return -1;
    }

    char* Base58Output;

    if (argv[1][0] == 'e')
        Base58Output = Encode_Base58(argv[2]);
    else if (argv[1][0] == 'd')
        Base58Output = Decode_Base58(argv[2]);
    else {
        print_usage();
        return -2;
    }

    if (Base58Output != -1)
        printf("%s\n", Base58Output);
    else {
        print_usage();
        return -3;
    }

    return 0;
}