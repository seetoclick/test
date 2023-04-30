#include <stdio.h>

void fun() {
    printf("%s and 114514\n",  __func__);
}

int main() {
    fun();
    printf("%s and 666",  __func__);
    return 0;
}