#include <iostream>
#include "Deck.h"

Deck::Deck() {
}

void Deck::createFullDeck() {
  for(int i = 0; i <= LastSuit; ++i) {
    initializeSuit(static_cast<Suit>(i));
  }
}

void Deck::initializeSuit(const Suit &suit) {
  for(int i = 0; i <= LastRank; ++i) {
    cards.emplace_back(suit, static_cast<Rank>(i));
  }
}

void Deck::addCard(Card card) {
  cards.emplace_back(card);
}

// WARNING: This method has high complexity for removing top element from vector
Card Deck::popTopCard() {
  auto card = std::move(cards.front());
  cards.erase(cards.begin());
  return card;
}

Card Deck::popLastCard() {
  Card card = cards.back();
  cards.pop_back();                 // pop_back is O(1)
  return card;
}

std::vector<Card> &Deck::getCards(){
  return cards;
}

int Deck::getTotalCardsValue() {
  int total = 0;
  bool isAce = false;
  for(Card card: getCards()){
    int value = card.getCardValue();
    if (value > 10) {
      value = 10;
    } else if ( value == 1) {
      isAce = true;
    }
    total += value;
  }
  if (isAce && total + 10 <= 21) {
    total += 10;
  }
  return total;
}

int Deck::countCards() const {
  return cards.size();
}

void Deck::printDeck() {
//  for (int i = 0; i < playingDeck.countCards(); ++i) {
//    if(i % cardsPerDeck == 0){
//      std::cout << std::endl;
//    }
//    Card card (playingDeck.getCards()[i]);
//    card.printCard(card);
//  }
  int cardsPerDeck = 13;
  int count = 0;
  for (Card card: getCards()) {
    if (count % cardsPerDeck == 0) {
      std::cout << std::endl;
    }
    printCard(card);
    ++count;
  }
  std::cout << std::endl;
}
