#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>


using namespace std;

// Функција која го црта вратилото на основа на бројот на погрешни обиди
void drawHangman(int wrongAttempts) {
    vector<string> hangmanDrawing = {
        "  ____",
        "  |  |",
        "  |  O",
        "  | /|\\",
        "  | / \\",
        "__|______"
    };

    for (int i = 0; i < wrongAttempts; i++) {
        cout << hangmanDrawing[i] << endl;
    }
}

// Функција која ги проверува погодоците и го враќа променетиот збор
string checkGuess(const string& word, string& guessedWord, char guess) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == guess) {
            guessedWord[i] = guess;
        }
    }
    return guessedWord;
}

int main() {
    ifstream file("words.txt");  // Датотека со зборови
    if (!file) {
        cout << "Ne moze da se otvori fajlot so zborovi" << endl;
        return 1;
    }

    vector<string> words;
    string word;
    while (file >> word) {
        words.push_back(word);
    }
    file.close();

    srand(time(0));
    int randomIndex = rand() % words.size();
    string selectedWord = words[randomIndex];
    string guessedWord(selectedWord.length(), '_');

    int maxAttempts = 6;  // Максимален број на обиди
    int wrongAttempts = 0;

    while (wrongAttempts < maxAttempts) {
        cout << "Pogodi go zborot: " << guessedWord << endl;

        char guess;
        cout << "Vnesi bukva: ";
        cin >> guess;

        string updatedWord = checkGuess(selectedWord, guessedWord, guess);
        if (updatedWord == guessedWord) {
            wrongAttempts++;
            cout << "Seuste ne go pogodi zborot,preostanati obidi: " << maxAttempts - wrongAttempts << endl;
        } else {
            guessedWord = updatedWord;
        }

        drawHangman(wrongAttempts);

        if (guessedWord == selectedWord) {
            cout << "Cestitki! Go pogodi zborot: " << selectedWord << endl;
            break;
        }
    }

    if (wrongAttempts >= maxAttempts) {
        cout << "Izgubi! Zborot e : " << selectedWord << endl;
    }

    return 0;
}
