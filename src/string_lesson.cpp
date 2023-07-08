#include<iostream>

int main()
{
    using std::string;

    string normalStr = string("normal");
    
    // error : temporary object
    // string* pNormalStr = &string("normal"); //error
    // error : temporary objectなので、そもそもアドレス取得ができない
    //std::cout << &string("normal") << std::endl; //error

    //これは可能。なぜなら normalStr は左辺値というか、アドレス取得が可能なものなので
    string* pNormalStr = &normalStr;

    // 左辺値なら参照は可能。アドレス取得が可能なので
    string& rNormalStr = normalStr;

    // malocのオブジェクトも参照可能。アドレス取得が可能なので。
    string& raNormalStr = *new string("normal");

    return 0;
}