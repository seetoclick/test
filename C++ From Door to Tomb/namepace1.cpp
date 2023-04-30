#include <iostream>
//命名空间A
namespace A {
    int f() {
        std::cout << "A function in Namespace A\n";
        return 5;
    }

    int r = 5;
}
//命名空间B
namespace B {
    int f() {
        std::cout << "A function in Namespace B\n";
        return 6;
    }

    int r = 6;    
}

int main() {
    int r = 10;

    std::cout << "r in main:" << r << '\n';
    std::cout << "r in A:" << A::r << '\n';
    std::cout << "r in B:" << B::r << '\n';

    //使用using关键字
    using namespace A;
    //比较不加作用域和分别加了A，B作用域后，f()的效果
    f();    //不适用上面的using会报误
    A::f();
    B::f();

    return 0;
}