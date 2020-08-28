#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Streams
    cout << "Hello World!" << endl;
    cerr << "Error" << endl;
    clog << "Logging.." << endl;
    string name;
    cin >> name;
    cout <<"You entered : " << name << endl;

    // Data Types
    string hello = "Hello World";
    int count = 7;

    cout << endl << "DATA TYPES" << endl;
    cout << "string: " << hello << endl;
    cout << "integer: " << count << endl;

    // Operators
    int a = 20;
    int b = 7;
    cout << endl << "OPERATORS" << endl;
    cout << "a = " << a << " and b = " << b << endl;
    cout << "a+b =" << a+b << endl;
    cout << "a-b =" << a-b << endl;
    cout << "a*b =" << a*b << endl;
    cout << "float(a/b) ="<< float(a/b) << endl;
    cout << "a%b =" << a%b << endl;

    //
    return 0;
}
