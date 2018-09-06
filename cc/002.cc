#include <iostream>
#include <cstring>
using namespace std;

void replaceSpace(char *str, int length) 
{
    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(str[i] == ' ')
            count++;
    }
    str[length + count * 2] = '\0';
    for(int i = length - 1; i >= 0; i--)
    {
        if(str[i] != ' '){
            str[i + 2 * count] = str[i];
        }
        else{
            count--;
            str[i + 2 * count]='%';
            str[i + 2 * count + 1] = '2';
            str[i + 2 * count + 2] = '0';
        }
    }
}

int main(int argc, char const *argv[])
{
    const char * s = " Hello World. ";
    int len = strlen(s);
    char * str = new char[len + 1];
    memcpy(str, s, len);
    str[len] = '\0';
    cout << str << endl;
    replaceSpace(str, len);
    cout << str << endl;
    return 0;
}