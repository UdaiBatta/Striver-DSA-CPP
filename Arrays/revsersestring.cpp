#include <iostream>
#include <algorithm> // for std::reverse
#include <string>   // for std::string

using namespace std;

int main() {
    string str = "Hello, World!";
    
    // Use std::reverse to reverse the string
    reverse(str.begin(), str.end());
    
    cout << "Reversed string: " << str << endl;

    return 0;
}

