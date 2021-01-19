#include <iostream>
#include <Windows.h>
#include "Game.h"

int main() {
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IOFBF, 1000);       // Enable buffering to prevent VS from chopping up UTF-8 byte sequences

    std::cout << u8"\uFFFD" << std::endl;
  //  Card a(Suit::SPADE, Rank::BRO);
//  printCard(a);
//  std::cout << std::endl <<   a.getCardValue() << std::endl;

//  std::cout << u8"\u2652" << std::endl;
//  std::cout << u8"\u26BD" << std::endl;
//  std::cout << u8"\u270B" << std::endl;
  char input('y');

  while(input == 'y' || input == 'Y'){

    Game game{};
    game.playBlackJack();
    std::cout << "play again?" << std::endl;
    std::cin >> input;
  }
  return EXIT_SUCCESS;
}
