#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

enum Suit {
    List,
    Srce,
    Detelina,
    Karo
};

enum Value {
    Kec,
    Dva,
    Tri,
    Cetiri,
    Pet,
    Sest,
    Sedum,
    Osum,
    Devet,
    Deset,
    Djandar,
    Cupa,
    Pop
};


struct Card {
    union {
        Value value; 
        char letterValue; // K, Q, J или A
    };
    Suit suit; // Znak na kartata
};

void shuffleDeck(Card deck[], int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(deck[i], deck[j]);
    }
}
void displayDeck(Card deck[], int size) {
    for (int i = 0; i < size; i++) {
        if (deck[i].value >= Dva && deck[i].value <= Deset) {
            cout << deck[i].value << " of ";
        }
        else {
            cout << deck[i].letterValue << " of ";
        }
        switch (deck[i].suit) {
            case List:
                cout << "List" << endl;
                break;
            case Srce:
                cout << "Srce" << endl;
                break;
            case Detelina:
                cout << "Detelina" << endl;
                break;
            case Karo:
                cout << "Karo" << endl;
                break;
            default:
                break;
        }
    }
}

bool compareCards(Card a, Card b) {
    return a.value < b.value;
}

int main() {

    const int DECK_SIZE = 54;
    Card deck[DECK_SIZE];

    int cardIndex = 0;
  
    for (int s = List; s <= Karo; s++) {
        for (int v = Kec; v <= Pop; v++) {
            deck[cardIndex].suit = static_cast<Suit>(s);
            if (v >= Dva && v <= Deset) {
                deck[cardIndex].value = static_cast<Value>(v);
            }
            else {
                switch (v) {
                    case Kec:
                       
deck[cardIndex].letterValue = 'A';
                    break;
                case Djandar:
                    deck[cardIndex].letterValue = 'J';
                    break;
                case Cupa:
                    deck[cardIndex].letterValue = 'Q';
                    break;
                case Pop:
                    deck[cardIndex].letterValue = 'K';
                    break;
                default:
                    break;
            }
        }
        cardIndex++;
    }
}

const int NUM_JOKERS = 2;
for (int i = 0; i < NUM_JOKERS; i++) {
    deck[cardIndex].suit = static_cast<Suit>(i + 4); 
    deck[cardIndex].letterValue = 'J';
    cardIndex++;
}

cout << "=== PODREDEN SHPIL KARTI ===" << endl;
sort(deck, deck + DECK_SIZE, [](const Card &a, const Card &b) {
    if (a.suit == b.suit) {
        return a.value < b.value;
    }
    else {
        return a.suit < b.suit;
    }
});
displayDeck(deck, DECK_SIZE);


cout << endl << "=== IZMESAN SHPIL KARTI ===" << endl;
shuffleDeck(deck, DECK_SIZE);
displayDeck(deck, DECK_SIZE);

return 0;
}
