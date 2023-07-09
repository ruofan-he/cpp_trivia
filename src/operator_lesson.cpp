#include <iostream>

using namespace std;

class TestClass
{
    int num;

public:
    //+記号をオーバーロード
    TestClass operator +(TestClass r)
    {
        TestClass tc;
        cout << this->num << endl;
        cout << r.num << endl;
        tc.num = this->num + r.num;
        return tc;
    }
    //-記号をオーバーロード
    TestClass operator -(TestClass r)
    {
        TestClass tc;
        tc.num = this->num - r.num;
        return tc;
    }

    //代入演算子のオーバーロード
    TestClass &operator =(const TestClass &r)
    {
        cout << "代入演算子" << endl;
        return *this;
    }


    TestClass(int x = 0) { num = x; }

    //コピーコンストラクタ
    TestClass(const TestClass &c): num(c.num)
    {
        cout << "コピーコンストラクタ" << endl;
    }


    int get() { return num; }
    void set(int x) { num = x; }
    TestClass& reference(){
        return *this;
    }
};

int main()
{
    TestClass tc1(10), tc2(20), tc4(40);

    //エラー
    TestClass tc3 = tc1 + tc2 + tc4;

    auto tc5 = tc3.reference();


    tc5 = tc1 = tc2;
    cout << tc1.get() << endl;
    cout << tc5.get() << endl;
    cout << tc2.get() << endl;
}