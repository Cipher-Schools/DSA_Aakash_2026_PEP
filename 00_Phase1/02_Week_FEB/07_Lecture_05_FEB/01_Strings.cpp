#include <iostream>
#include <cstring>
using namespace std;

int main() {
    
    char str1[] = "aakash";

    char str2[] = {'a','a','k','a','s','h', '\0'};
    
    char str3[] = {'a','a','k','a','s','h'};

    // printing
    cout << "Printing strings:" << endl;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl; // undefined behaviour
    
    cout << endl;

    // sizeof
    cout << "Sizeof:" << endl;
    cout << "str1 size" <<  sizeof(str1) << endl;
    cout << "str2 size" <<  sizeof(str2) << endl;
    cout << "str3 size" <<  sizeof(str3) << endl;
    
    //access last elemet
    cout << "Last element:" << endl;
    cout << "last str1" << str1[6] << endl;
    cout << "last str2" << str2[6] << endl;
    cout << "last str3" << str3[5] << endl;
    
    // inbuild functions : cstring header file
    
    // strlen
    cout << "Length using strlen:" << endl;
    cout << "str1 len : " << strlen(str1) << endl;
    cout << "str2 len : " << strlen(str2) << endl;
    cout << "str3 len : " << strlen(str3) << endl; // undefined behaviour
    
    cout << endl;

    // strcmp
    cout << "strcmp:" << endl;
    cout << strcmp(str1, str2) << endl;
    cout << strcmp(str1, str3) << endl;  // undefined behaviour
    
    cout << endl;

    // strcpy
    char dest1[20];
    char dest2[20];
    char dest3[20];

    strcpy(dest1, str1);
    strcpy(dest2, str2);
    strcpy(dest3, str3); // undefined behaviour

    cout << "strcpy:" << endl;
    cout << dest1 << endl;
    cout << dest2 << endl;
    cout << dest3 << endl;

    cout << endl;
    
    // strcat
    char cat1[4] = "aa1";
    char cat2[20] = "aa2";
    // char cat3[20] = "aa3";
    char cat3[3] = {'a','a','3'};

    strcat(cat1, str1);
    strcat(cat2, str2);
    strcat(cat3, str3);

    cout << "strcat:" << endl;
    cout << cat1 << endl;
    cout << cat2 << endl;
    cout << cat3 << endl;

    return 0;
}