#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void upercasepermutation(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    string nextinput = input.substr(1, input.length());
    upercasepermutation(nextinput, output + input[0]);
    upercasepermutation(nextinput, output + (char)toupper(input[0]));
}

int main()
{
    string s1 = "abc";
    upercasepermutation(s1, "");

    return 0;
}