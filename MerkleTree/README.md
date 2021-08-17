# Description
Implement Merkle Tree in C



# Usage
## Terminal
```bash
cd ./MerkleTree/src/

make

./merkletree InputArgument0 InputArgument1 InputArgument2 ...
```
## C
``` C
#include "merkletree.h"

char *InputWord[] = {"Example1", "Example2", "Example3"};
Init_MerkleTree(InputWord);
Print_MerkleHash_Postorder(root);
```



# Links
[Reference-Document](https://ko.wikipedia.org/wiki/%ED%95%B4%EC%8B%9C_%ED%8A%B8%EB%A6%AC)



# Merkle Tree Structure
## Example Merkle Tree Structure Diagram for Depth 3
```mermaid
graph TD
  A["Merkle Root<br>Hash(H12 + H13) = Final Hash Value"]
  A --> B["Hash(H8 + H9) = H12"]
  A --> C["Hash(H10 + H11) = H13"]
  B --> D["Hash(H0 + H1) = H8"]
  B --> E["Hash(H2 + H3) = H9"]
  C --> F["Hash(H4 + H5) = H10"]
  C --> G["Hash(H6 + H7) = H11"]
  D --> H["Hash(TX0) = H0<br>-----------------------<br>Transaction 0"]  
  D --> I["Hash(TX1) = H1<br>-----------------------<br>Transaction 1"]
  E --> J["Hash(TX2) = H2<br>-----------------------<br>Transaction 2"]
  E --> K["Hash(TX3) = H3<br>-----------------------<br>Transaction 3"]
  F --> L["Hash(TX4) = H4<br>-----------------------<br>Transaction 4"]
  F --> M["Hash(TX5) = H5<br>-----------------------<br>Transaction 5"]
  G --> N["Hash(TX6) = H6<br>-----------------------<br>Transaction 6"]
  G --> O["Hash(TX7) = H7<br>-----------------------<br>Transaction 7"]
```
- Example Merkle Tree Structure Diagram when Input is {TX0, TX1, TX2, TX3}
```mermaid
graph TD
  A["Merkle Root<br>Hash(H4 + H5) = Final Hash Value"]
  A --> B["Hash(H0 + H1) = H4"]
  A --> C["Hash(H2 + H2) = H5"]
  B --> D["Hash(TX0) = H0"]
  B --> E["Hash(TX1) = H1"]
  C --> F["Hash(TX2) = H2"]
  C --> G["Hash(TX3) = H3"]
```
- Example Merkle Tree Structure Diagram when Input is {TX0, TX1, TX2}
```mermaid
graph TD
  A["Merkle Root<br>Hash(H3 + H4) = Final Hash Value"]
  A --> B["Hash(H0 + H1) = H3"]
  A --> C["Hash(H2 + H2) = H4"]
  B --> D["Hash(TX0) = H0"]
  B --> E["Hash(TX1) = H1"] 
  C --> F["Hash(TX2) = H2"]
  C --> G["Hash(TX2) = H2"]
```
