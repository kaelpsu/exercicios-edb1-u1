/**
 * @author Kael Paraguassu
 * @brief Implementation of the Hot-Cold Guess Game
 * @version 0.1
 * @date 2023-08-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <array>

/**
 * @brief Prints the help message in terminal.
 * 
 */
void printHelpMessage()
{
    std::cout << "Use: ./hot_cold [<range_limit>]\n";
}

/**
 * @brief Prints the start message with the game instructions in terminal.
 * 
 * @param limit Limit of the range in which the secret number will be.
 */
void printStartMessage(short limit)
{
    std::cout << "===================================================\n";
    std::cout << "Welcome to the Hot-Cold Guess game, copyright 2020.\n";
    std::cout << "===================================================\n";
    std::cout << "---------------------------------------------------\n";
    std::cout << "These are the game rules:\n";
    std::cout << "* I’ll choose a random number in [1," << limit << "]. Your job is to guess that number.\n";
    std::cout << "* From the second guess onward, I’ll tell you if your guess\n";
    std::cout << "is hot (closer than the previous guess) or cold (farther from\n";
    std::cout << "the previous guess).\n";
    std::cout << "* If you wish to quit the game, just type\n ;in a negative number.\n";
    std::cout << "Good luck!\n";
    std::cout << "----------------------------------------------------\n";
}

/**
 * @brief Generates a random number in the range [1, limit].
 * 
 * @param secret Variable which will receive a random generated number.
 * @param limit Limit of the range in which the secret number will be.
 */
void generateSecret(short &secret, short limit) {
    std::srand(time(NULL));

    secret = std::rand() % limit + 1;

}


int main(int argc, char *argv[])
{
    short new_limit;

    if (argc == 2)
    {
        new_limit = std::stoi(argv[1]); ///< Converts the user string input to the short type
        printStartMessage(new_limit);
        
    }
    else
    {
        printHelpMessage();
        exit(0);
        
    }

    short secret_number;

    generateSecret(secret_number, new_limit);

    short previous_guess = secret_number;

    std::cout << ">>> Guess the number: \n";

    int min_guess = 1;
    int max_guess = new_limit;
    int guess;
    int attempts = 0;

    while (true)
    {
        short guess;
        // Calculate the next guess as the midpoint of the current range
        guess = (min_guess + max_guess) / 2;
        attempts++;

        std::cout << "Attempt " << attempts << ": My guess is " << guess << std::endl;
        
        short distance_guess = (guess > secret_number) ? guess - secret_number : secret_number - guess;
        short distance_prev = (previous_guess > secret_number) ? previous_guess - secret_number : secret_number - previous_guess;

        if (guess == secret_number)
        {
            std::cout << ">>> Yeah, correct guess!\n";
            std::cout << "Thanks for playing!\n";

            exit(0);
        }
        else if (distance_guess <= distance_prev)
        {
            std::cout << ">>> Nop, it’s hot though, try again: \n";
        }
        else
        {
            std::cout << ">>> Nop, it’s getting cold, try again: \n";
        }

        if (guess < secret_number) {
            min_guess = guess + 1;
        } else {
            max_guess = guess - 1; // Adjust the upper bound of the range
        }

        previous_guess = guess;
    }

    return 0;
}