#include <iostream>
#include "libstd/MemoryBlock.hpp"
#include "libstd/Assert.hpp"
using namespace std;
int main() {
    uint32 len = 10;
    char str[len] = {'0','1','2','3','4'};

    cout << str << endl;

    cout << sizeof(str) << endl;
    char *dst = (char *)malloc(sizeof(char)*len);

    MemoryBlock m_block = MemoryBlock();

    m_block.copy(dst, str, len);

    cout << dst << endl;

    return 0;
}
