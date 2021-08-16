# Description
Implement SHA256 Hash Algorithm in C



# Usage
## Terminal
```bash
cd ./SHA256/src/

make

./sha256 InputWord
```
## C
``` C
#include "sha256.h"

char *InputWord = "Example";
uint32_t *HashOutput = Get_Hash(InputWord);
```



# Links
[Reference-Document](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf)  
[Online-SHA256-Calculator](https://xorbin.com/tools/sha256-hash-calculator)  

