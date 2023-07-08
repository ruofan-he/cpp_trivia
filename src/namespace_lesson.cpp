#include <iostream>

namespace A
{
    void f(){std::cout << "A" << std::endl;};
    void hoge(){
        f(); // 名前空間の中では修飾しなくても呼び出せる
    }
}

namespace B
{
    void f(){std::cout << "B" << std::endl;};
    void hoge(){
        A::f(); // 別の名前空間から呼びたいなら修飾する
    }
}

int main()
{
    A::f(); // A
    B::f(); // B
    A::hoge(); // A
    B::hoge(); // A
}