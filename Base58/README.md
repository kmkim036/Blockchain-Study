# Description
Implement Base58 Encoding / Decoding in C



# Usage
## Terminal
```bash
cd ./Base58/src/

make

./base58 e InputWord
# or
./base58 d InputWord
```
## C
``` C
#include "base58.h"

char* Base58DecodedInput = "kmkim";
char* Base58EncodingOutput = Encode_Base58(Base58DecodedInput);
char* Base58EncodedInput = "D7y6YY4";
char* Base58DecodingOutput = Decode_Base58(Base58EncodedInput);
```



# Links
[Reference-Document](https://tools.ietf.org/id/draft-msporny-base58-01.html)  
[Online-Base58-Encoder](https://www.browserling.com/tools/base58-encode)  
[Online-Base58-Decoder](https://www.browserling.com/tools/base58-decode)  