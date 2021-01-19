#include <random>
#include <ctime>
#include <iostream>
#include "Blackjack.h"

std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));

Blackjack::Blackjack(Deck &deck) {
  Deck playerDeck{};
  Deck dealerDeck{};
  mPlayingDeck = deck;
  mPlayerDeck = playerDeck;
  mDealerDeck = dealerDeck;

  mPlayingDeck.createFullDeck();
  mPlayingDeck.printDeck();
  shuffleDeck(mPlayingDeck.getCards());
  mPlayingDeck.printDeck();

  mPlayerDeck.addCard(mPlayingDeck.popLastCard());          // Pick two cards for player
  mPlayerDeck.addCard(mPlayingDeck.popLastCard());
  mDealerDeck.addCard(mPlayingDeck.popLastCard());          // Pick two cards for dealer
  mDealerDeck.addCard(mPlayingDeck.popLastCard());

  playerScore = mPlayerDeck.getTotalCardsValue();
  dealerScore = mDealerDeck.getTotalCardsValue();
}

void Blackjack::pickSingleCard(bool isPlayer) {
  if(isPlayer) {
    mPlayerDeck.addCard(mPlayingDeck.popLastCard());
  } else {
    mDealerDeck.addCard(mPlayingDeck.popLastCard());
  }
}

void Blackjack::printHands() {
  std::cout << "Player Hand:";
  mPlayerDeck.printDeck();
  std::cout << "Score: " << mPlayerDeck.getTotalCardsValue() << std::endl;
  std::cout << "Dealer Hand:" << std::endl;
  printCard(mDealerDeck.getCards()[0]);
  std::cout << u8"\u270B" << std::endl;
}

void Blackjack::revealDealerHand() {
  std::cout << "Dealer Hand:" << std::endl;
  mDealerDeck.printDeck();
}

void Blackjack::shuffleDeck(std::vector<Card> &cards) {
  for(int i = 0; i < 52; ++i) {
    int randomNum = getRandomNumber(0, 51);
    swapCard(cards[i], cards[randomNum]);
  }
}

int Blackjack::getRandomNumber(int min, int max) {
  std::uniform_int_distribution<> generator(min, max);
  return generator(mersenne);
}

void Blackjack::swapCard(Card& from, Card& to){
  Card temp = from;
  from = to;
  to = temp;
}

int Blackjack::getPlayerScore() {
  return mPlayerDeck.getTotalCardsValue();
}

int Blackjack::getDealerScore() {
  return mDealerDeck.getTotalCardsValue();
}

Blackjack::Blackjack() {

}

