#include <iostream>
#include <ctime>
void PrintIntroduction(int Difficulty)
{
  std::cout << "\n\nFind the mess, before you get the test. Level " << Difficulty;
  std::cout << "\nIs it festering or trite?\n";
}

bool PlayGame(int Difficulty)

{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print code
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ the codes adds up to: " << CodeSum;
    std::cout << "\n+ When multiplied; it is: " << CodeProduct <<std::endl;

    //guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
   
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct) 
    {
      std::cout << "\n*** You did it. Let's go once more!";
      return true;
    }
    else
    {
      std::cout << "\n***  Everyone. Be free, be reverent!";
      return false;
    }
}

int main()

{ 
  srand(time(NULL));

  int LevelDifficulty = 1;
  int const MaxDifficulty = 5;
  while (LevelDifficulty <= MaxDifficulty)//loop til done 
  {
    
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear(); //errors gone
    std::cin.ignore(); //ignore

    if (bLevelComplete)
    {
      ++LevelDifficulty;
    }
    
  }
  std::cout << "\n*** It's saved! Great job. ***\n";
  return 0;
}
