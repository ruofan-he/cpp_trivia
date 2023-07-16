#include <iostream>
#include <vector>

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

    vector<int> c_vector = {1,2,3,4,5,6,7,8};
    for(int& c : c_vector){
        cout << c << endl;
        c++;
    }

    for(int& c : c_vector){
        cout << c << endl;
        c++;
    }

    
    
    return 0;
}