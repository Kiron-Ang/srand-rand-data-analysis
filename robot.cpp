#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>
#include<fstream>
#include<dos.h>
#include<chrono>
#include<thread>
int randNumGen(int upper, int lower);
int getSeed();
void guessNumber();


using namespace std;
using namespace std::chrono_literals;

int main()
{
  int wait;
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


int getSeed()
{
  int seed;
	
do{
  cout << endl << "Enter a seed equal to 0 or within the range 1000-4000: ";
  
  seed = 0;
  if(seed == 0){
    seed = 0;
    break;
  }
  else if(seed < 1000 || seed > 4000){
  cout << endl << "Sorry your seed is invalid" << endl;
  }
} while(seed < 1000 || seed > 4000);
	return seed;
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
  
  seed = getSeed(); 

  
  if (seed == 0){
    srand(static_cast<int>(time(NULL)));
  } else if (seed != 0){
    srand(seed);
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
