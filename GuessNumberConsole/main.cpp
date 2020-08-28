#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    int guessNumber, secretNumber;
    srand(time(NULL));

    secretNumber = rand()%10 +1;//srand (static_cast<unsigned int>((time(nullptr))));

    cout << "Guess The number between (1-10)"<< endl;
    do{
        cin >> guessNumber;
        if (guessNumber < secretNumber){
            cout << "The number is greater than that" << endl;
        }
        else if (guessNumber > secretNumber){
            cout << "The number is less than that" << endl;
        }
        else cout << "Congrats you found the number" << endl;
    }while(guessNumber != secretNumber);
    cout << "Hello World!" << endl;
    return 0;
}
