#include <iostream>

using namespace std;

int main()
{
    // [capture list](parameter list){function body}
    // or
    // [capture list](parameter list)->return_value_type{function body}

    // Call lambda function directly after definition
    [](){
            cout << "This is Lambda! Wao!" << endl;
        }();


    auto func = [](){
        cout << "Hello World!" << endl;
    };

    func();

    // Lambda function that takes parameters
    [](int a, int b){
            cout << "a+b = " << a+b <<endl;
        }(7,3);

    // Lambda that returns something
    int sum = [](int a, int b)->int{
            return a+b;
        }(7,3);

    cout << "sum = " << sum << endl;

    // Capture Lists
    int a = 10;
    int b = 9;

    [a,b](){
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }();


    // capture everything outside by value
    [=](){
        cout << "a2 = " << a << endl;
        cout << "b2 = " << b << endl;
    }();

    // capture everything outside by reference
    [&](){
        //Warning you may alter the variable values of main()
        cout << "a2 = " << a << endl;
        cout << "b2 = " << b << endl;
    }();


    return 0;
}
