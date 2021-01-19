#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

enum Rank {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    BRO, QUEEN, KING
};

enum Suit {
    CLUB, DIAMOND, HEART, SPADE
};

const Suit LastSuit = SPADE;
const Rank LastRank = KING;

class Card {

private:
    Rank m_rank;
    Suit m_suit;

public:
    Card() = delete;
    Card(Suit pSuit, Rank pRank);

    Rank getRank() const;

    Suit getSuit() const;

    int getCardValue();
};

void printCard(const Card &card);
#endif //BLACKJACK_CARD_H
