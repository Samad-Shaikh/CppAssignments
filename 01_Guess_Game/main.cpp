#include <iostream>
#include <random>
#include <ctime>

int readNumber();

int getRandomNumber();

bool writeResponse(int guess, int i);

int main() {
    int tries = 7;
    int guess = 0;
    int randomNUmber;
    bool correct = false;


    std::cout<< "Let's play a game. I'm thinking of a number." << std::endl;
    randomNUmber = getRandomNumber();

    while (tries > 0 ) {

        std::cout << "you have " << tries << " tries left" << std::endl;
        guess = readNumber();

        correct = writeResponse(guess, randomNUmber);

        if(correct) break;
        tries--;
        std::cout << guess << std::endl;
        std::cout << randomNUmber << std::endl;

    }
    return 0;
}

bool writeResponse(int guess, int correctAnswer) {
    if(guess > correctAnswer) {
        std::cout << "you guess is too high " << std::endl;
        return false;
    } else if (guess < correctAnswer) {
        std::cout << "you guess is too low " << std::endl;
        return false;
    } else {
        return guess == correctAnswer;
    }
}


// Initialize our mersenne twister with a random seed based on the clock
std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
// Create a reusable random number generator
std::uniform_int_distribution<> generator(1, 100);
int getRandomNumber()
{
    return generator(mersenne);
}

int readNumber()
{
    int num = 0;
    std::cin >> num;
    if(num < 0 || num > 100) return 0;
    return num;
}