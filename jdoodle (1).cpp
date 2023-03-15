#include <iostream>
#include <cstdlib>
#include <ctime>//ctime е стандардна библиотека која овозможува работа со време и датум. Оваа библиотека содржи функции и структури за претставување на време и датум, како и функции за работа со нив.

using namespace std;

// Енумерација за симболите на карти
enum Suit {
   List,
   Srce,
    Detelina,
    Karo
};
 // Енумерација за вредностите на картите
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

// Структура за картите
    union {
        Value value;
        char letterValue;
    };
    Suit suit;
};

// Алгоритам за мешање на шпилот на карти (Fisher-Yates shuffle)
void shuffleDeck(Card deck[], int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(deck[i], deck[j]);
    }
}

// Функција за прикажување на шпилот на карти

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

int main() {
    // Се дефинира бројот на картите
    const int DECK_SIZE = 54;
    Card deck[DECK_SIZE];

    // Се иницијализира шпилот карти
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

    // Се додаваат два џокери
    const int NUM_JOKERS = 2;
    for (int i = 0; i < NUM_JOKERS; i++) {
        deck[cardIndex].suit = static_cast<Suit>(i + 4); // Assign suit to be above the existing suits (DIAMONDS)
        deck[cardIndex].letterValue = 'J';
        cardIndex++;
    }

    // Се меша шпилот карти
    shuffleDeck(deck, DECK_SIZE);

    // Се прикажува шпилот карти
    displayDeck(deck, DECK_SIZE);

    return 0;
}
