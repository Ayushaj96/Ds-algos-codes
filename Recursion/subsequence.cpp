#include <iostream>
#include <string>
using namespace std;

void print_subs(string in, string out){
    if(in.length() == 0){
        cout<<out<<"\n";
        return;
    }

    print_subs(in.substr(1),out);
    print_subs(in.substr(1),out + in[0]);

}

int main() {
    string str;
    cin>>str;

    print_subs(str,"");
}
