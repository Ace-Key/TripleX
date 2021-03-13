#include<iostream>
#include<ctime>
const int MaxLevel = 5;
void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\n You're the meanest secret agent in the motu bro...\n You have to break into a level " << Difficulty;
    std::cout << " secure vault... \n You gotta enter these numbers in right, otherwise you're stuffed!\n\n";
}
bool PlayGame(int Difficulty)
{ 
    PrintIntroduction(Difficulty);
//code sequence randomisation
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

//output for the variables
    std::cout << "| There are toru nama (3 numbers) in the code...";
    std::cout << "\n| They all add up to:" << CodeSum;
    std::cout << "\n| The codes whakarea (multiplies) to give: " << CodeProduct << std::endl;
    
//stores player guess
    int GuessA, GuessB, GuessC;
    
    std::cin >> GuessA >> GuessB >> GuessC;
        
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

//check if the player guesses are correct or not
             
    if (GuessSum == CodeSum && GuessProduct == CodeProduct && Difficulty < MaxLevel)
    {
        std::cout << "\nKapai, that's correct!";
        std::cout << "\nOn to the next vault level...";
        return true;
    }
    if (GuessSum == CodeSum && GuessProduct == CodeProduct && Difficulty == MaxLevel)
    {
        std::cout << "\nKapai, that's correct!";
        return true;
    }
    else
    {
        std::cout << "\nKaore, you're wrong as! Try Again...";
        return false;
    }
}

int main() 
{ 
    srand(time(NULL));//seeds random based on time of day (PC time)

    int LevelDifficulty = 1;
    while (LevelDifficulty <= MaxLevel)
    {
    bool bLevelComplete = PlayGame(LevelDifficulty);    
    std::cin.clear();
    std::cin.ignore();

    if (bLevelComplete)
    {
        ++LevelDifficulty; 
    }
 }
    std::cout << "\n\n\nKapai te Rawa! You cracked into all levels of the vault!";
    return 0;

}