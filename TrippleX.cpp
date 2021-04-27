#include <iostream>
#include <ctime>

void PrintIntroduction(int LevelDifficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << LevelDifficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int LevelDifficulty)
{
    PrintIntroduction(LevelDifficulty);

    // Generate Code
    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;


    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;
    std::cout << "For the sake of this demo and my pride, the codes are: " << CodeA << " " << CodeB << " " << CodeC << " " << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // create new random sequence based on time of day
    
    int LevelDifficulty = 1;
    int const MaxDifficulty = 100;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}