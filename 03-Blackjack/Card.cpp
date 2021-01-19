#include <iostream>
#include "Card.h"

Card::Card(Suit suit, Rank rank) {
  m_suit = suit;
  m_rank = rank;
}

void printCard(const Card &card) {
  const std::string heart = u8"\u2665";
  const std::string spade = u8"\u2660";
  const std::string club = u8"\u2663";
  const std::string diamond = u8"\u2666";
  const std::string ten = u8"\u277F";

  switch (card.getRank()) {
    case ACE: std::cout << 'A';
      break;
    case TWO: std::cout << '2';
      break;
    case THREE: std::cout << '3';
      break;
    case FOUR: std::cout << '4';
      break;
    case FIVE: std::cout << '5';
      break;
    case SIX: std::cout << '6';
      break;
    case SEVEN: std::cout << '7';
      break;
    case EIGHT: std::cout << '8';
      break;
    case NINE: std::cout << '9';
      break;
    case TEN: std::cout << ten;
      break;
    case BRO: std::cout << 'B';
      break;
    case QUEEN: std::cout << 'Q';
      break;
    case KING: std::cout << 'K';
      break;
  }

  switch (card.getSuit()) {
    case CLUB: std::cout << club << '\t';
      break;
    case DIAMOND: std::cout << diamond << '\t';
      break;
    case HEART: std::cout << heart << '\t';
      break;
    case SPADE: std::cout << spade << '\t';
      break;
  }
}


int Card::getCardValue() {
  switch (m_rank) {
/* An Ace will have a value of 11 unless that would give a player or the dealer a score in excess of 21;
 * in which case, it has a value of 1.*/
    case ACE: return 1;
    case TWO: return 2;
    case THREE: return 3;
    case FOUR: return 4;
    case FIVE: return 5;
    case SIX: return 6;
    case SEVEN: return 7;
    case EIGHT: return 8;
    case NINE: return 9;
    case TEN:
    case BRO:
    case QUEEN:
    case KING: return 10;
    default: return 0;
  }
}

Rank Card::getRank() const {
  return m_rank;
}

Suit Card::getSuit() const {
  return m_suit;
}
