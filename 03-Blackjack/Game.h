#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H

#include "Blackjack.h"

class Game {
private:
  Blackjack mBlackjack;
  int turn;

public:
  Game();

  void playBlackJack();
};

#endif //BLACKJACK_GAME_H
