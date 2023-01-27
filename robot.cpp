#include<iostream>
#include<cstdlib>
#include<time.h>
#include<fstream>
#include<chrono>
#include<thread>
int randNumGen(int upper, int lower);
void guessNumber();

using namespace std;
using namespace std::chrono_literals;

int main()
{
    int f;
    for (f = 0; f < 100; f++) {
        std::this_thread::sleep_for(1s);
        guessNumber();

    }
}

int randNumGen(int upper, int lower)
{
    return ( rand() % (upper - lower + 1) ) + lower;

}

void guessNumber()
{
    fstream fout;
    fout.open("data_of_guesses_from_several_games.csv", ios::out | ios::app);

    int num;

    int seed;

    int guess;

    int i;

    cout << "Thank you for participating in the Guessing Game" << endl << endl;
    cout << "If you want me to create a real random number enter 0 when prompted for the seed please." << endl << endl;
    cout << "Otherwise enter a number within the specified range please." << endl << endl;

    seed = 0;


    if (seed == 0){
        srand(static_cast<int>(time(nullptr)));
    }

    num = randNumGen(100, 1);

    for (i = 0; i < 5; ++i){

        cout << endl << endl << "Guess the number the computer randomly picked between 1 - 100: ";
        guess = randNumGen(100, 1);
        cout << endl << "The computer guessed: " << guess << endl;
        fout << guess << ",";
        if (guess < num){
            cout << "Sorry, your guess is too low";
        }
        else if (guess > num){
            cout << "Sorry, your guess is too high";
        }
        else{
            cout << "you guessed right, you win!" << endl << endl;
            fout << num << endl;
            break;
        }
        if (i == 4){

            cout << endl << endl << "Sorry, you lost. The number is: " << num << endl << endl;
            fout << num << endl;
        }
    }
}
