#include <iostream>
#include <algorithm>

int main() {
    int a[] = {1, 2, 3443, 114514, 6, 22, 77272, 1, 1, 1, 1};
    int b[] = {1, 2, 3443, 114514, 6, 22, 77272, 1, 1, 1, 1};
    //对a进行排序
    std::sort(a, a + 11);

    int d = std::unique(a, a + 11) - a;

    std::cout << d << std::endl;
    for (int i = 0; i < d; ++i)
        std::cout << a[i] << std::endl;

    for (int i = 0; i < 11; ++i) {
        b[i] = std::lower_bound(a, a + d, b[i]) - a;
        std::cout << b[i] << std::endl; 
    }
    return 0;
}