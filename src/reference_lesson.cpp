#include <iostream>

using namespace std;

void auto_reference(string& a){
    cout << "&" << a << endl;
}



void auto_reference(string && a){
    cout << "&&" << a << endl;
}

int main()
{
    string a = string("asdf");
    string&& b = string("asdf");
    auto_reference(std::move(a));
    auto_reference(string("asdf"));
    auto_reference(a);
    
    
    return 0;
}