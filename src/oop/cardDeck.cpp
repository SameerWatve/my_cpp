#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
enum Suit { Club, Spade, Heart, Diamond };

class ICard {
public:
  virtual Suit GetSuit() const = 0;
  virtual int GetNumber() const = 0;
};

class Card : public ICard {
private:
  Suit _Suit;
  int _Number;

public:
  Card(Suit suit, int number) : _Suit(suit), _Number(number) {}
  virtual Suit GetSuit() const override { return _Suit; }

  virtual int GetNumber() const override { return _Number; }
};

class CardDeck {
private:
  vector<Card> _Cards;

public:
  CardDeck() {
    for (int suit = 0; suit < 4; ++suit) {
      for (int i = 1; i <= 13; i++)
        _Cards.push_back(Card(Suit(suit), i));
    }
  }

  void ShuffleCard() {
    for (int i = 1; i <= 52; i++) {
      int j = rand() % 51;
      Card temp = _Cards[i];
      _Cards[i] = _Cards[j];
      _Cards[j] = temp;
    }
  }

  Card DrawCard() {
    Card lastCard = _Cards.back();
    _Cards.pop_back();
    return lastCard;
  }

  Card DrawCardRandomly() {
    int i = rand() % (_Cards.size()-1);
    Card card = _Cards[i];
    _Cards.erase(_Cards.begin()+i);
    return card;
  }
};

int main() {
  CardDeck cardDeck;
  // shuffle card deck
  cardDeck.ShuffleCard();

  // draw a card randomly
  Card card1 = cardDeck.DrawCardRandomly();

  cout << card1.GetNumber() << " " << card1.GetSuit() << endl;
}