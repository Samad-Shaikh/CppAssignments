#include <iostream>
#include "Game.h"

Game::Game() {
  Deck deck{};
  Blackjack blackjack{deck};
  mBlackjack = blackjack;
  turn++;
}

void Game::playBlackJack() {
  char input('h');
  bool roundFinish = false;

  while(true) {
    mBlackjack.printHands();

    if(mBlackjack.getPlayerScore() > 21) {
      std::cout << "Busted!" << std::endl;
      roundFinish = true;
      break;
    } else if(mBlackjack.getDealerScore() > 21) {
      std::cout << "Dealer Lost, You have Won!" << std::endl;
      roundFinish = true;
      break;
    }

    if(roundFinish != true) {
      if(turn % 2 == 0) {
        if(mBlackjack.getDealerScore() < 17) {
          std::cout << "\u261E" << " Dealer Hit " << std::endl;
          mBlackjack.pickSingleCard(false);
        } else {
          std::cout << "\u261E" << " Dealer Stand " << std::endl;
        }
      } else {
        std::cout << u8"\uFFFD" << "Stand / Hit" << u8"\uFFFD" << std::endl;
        std::cin >> input;
        if(input == 'h' || input == 'H') {
          std::cout << "\u261E" << " Picking a card... " << std::endl;
          mBlackjack.pickSingleCard(true);
        } else if(input == 's' || input == 'S') {
          std::cout << "\u261E" << " You chose Stand " << std::endl;
          break;
        }
      }
    }
    turn++;
  }

  if(!roundFinish) {
    mBlackjack.revealDealerHand();
    if(mBlackjack.getDealerScore() > mBlackjack.getPlayerScore()) {
      std::cout << "You Lost! Dealer beats you in score." << std::endl;
    } else if(mBlackjack.getPlayerScore() > mBlackjack.getDealerScore()) {
      std::cout << "You Won!" << std::endl;
    } else if(mBlackjack.getDealerScore() == mBlackjack.getPlayerScore()) {
      std::cout << "Its a Draw" << std::endl;
    }
  }
}
