#ifndef BLACKJACK_BLACKJACK_H
#define BLACKJACK_BLACKJACK_H

#include "Deck.h"

class Blackjack {
private:
  Deck mPlayingDeck;
  Deck mPlayerDeck;
  Deck mDealerDeck;

  void shuffleDeck(std::vector<Card> &cards);

  int getRandomNumber(int min, int max);

  void swapCard(Card &from, Card &to);

  int playerScore;
  int dealerScore;

public:
  void printHands();

  void revealDealerHand();

  int getPlayerScore();

  int getDealerScore();

  void pickSingleCard(bool isPlayer);

  Blackjack();

  Blackjack(Deck &deck);
};

#endif //BLACKJACK_BLACKJACK_H
