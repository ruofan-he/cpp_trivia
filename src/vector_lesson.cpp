#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main(){


    vector<string> a;
    string b[] = {"a", "b", "c"};


    for(string& str :b){
        cout << str << endl;
        a.push_back(str);
    }

    for(string& str :a){
        cout << str << endl;
    }



    return 0;
}