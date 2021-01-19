#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>
#include "Card.h"

class Deck {
private:
  std::vector<Card> cards;

  void initializeSuit(const Suit &suit);

public:
  Deck();

  void createFullDeck();

  int countCards() const;

  void printDeck();

  void addCard(Card card);

  Card popTopCard();

  Card popLastCard();

  std::vector<Card> &getCards();

  int getTotalCardsValue();
};

#endif //BLACKJACK_DECK_H
