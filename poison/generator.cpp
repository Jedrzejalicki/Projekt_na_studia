#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#define CARD_NUMBER 20
#define GREEN_NUMBER 10

using namespace std;


class Card {
public:
    int value = 0;
    char color[10] = {
    };
};

class Deck {
public:
    Card cards[500];
    int cardsNumber = 0;
};

class Player {
public:
    Card cards[500];
    int numberOfCards = 0;
};



void dealingCards(Player* players, Deck& deck, int numberOfPlayers, int numberOfPiles, int numberOfGreens, int numberOfCards) {


    for (int i = 0; i < numberOfPlayers; i++) {
        for (int j = 0; j <= numberOfGreens + numberOfPiles * numberOfCards; j++) {
            players[i].cards[j].value = deck.cards[numberOfPlayers * j + i].value;
            strcpy(players[i].cards[j].color, deck.cards[numberOfPlayers * j + i].color);

        }

    }
}



void making_deck(int numberOfPiles, int numberOfGreens, int greensValue, int numberOfCards, Deck& deck) {
    int value[500];
    int index = numberOfGreens;


    for (int i = 0; i < numberOfGreens; i++) {
        deck.cards[i].value = greensValue;
        strcpy_s(deck.cards[i].color, "green");

    }
    for (int i = numberOfGreens; i < numberOfCards + numberOfGreens; i++) {
        cin >> value[i];

    }
    while (index < deck.cardsNumber) {
        for (int j = numberOfGreens; j < numberOfCards + numberOfGreens; j++) {
            deck.cards[index].value = value[j];
            index++;


        }


    }

    if (numberOfPiles == 1) {
        for (int i = numberOfGreens; i < numberOfGreens + numberOfPiles * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "blue");

    }
    else if (numberOfPiles == 2) {
        for (int i = numberOfGreens; i < numberOfGreens + numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "blue");
        for (int i = numberOfGreens + numberOfCards; i < numberOfGreens + 2 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "red");

    }
    else if (numberOfPiles == 3) {
        for (int i = numberOfGreens; i < numberOfGreens + numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "blue");
        for (int i = numberOfGreens + numberOfCards; i < numberOfGreens + 2 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "red");
        for (int i = numberOfGreens + 2 * numberOfCards; i < numberOfGreens + 3 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "violet");


    }
    else if (numberOfPiles == 4) {
        for (int i = numberOfGreens; i < numberOfGreens + numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "blue");
        for (int i = numberOfGreens + numberOfCards; i < numberOfGreens + 2 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "red");
        for (int i = numberOfGreens + 2 * numberOfCards; i < numberOfGreens + 3 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "violet");
        for (int i = numberOfGreens + 3 * numberOfCards; i < numberOfGreens + 4 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "yellow");



    }
    else if (numberOfPiles == 5) {
        for (int i = numberOfGreens; i < numberOfGreens + numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "blue");
        for (int i = numberOfGreens + numberOfCards; i < numberOfGreens + 2 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "red");
        for (int i = numberOfGreens + 2 * numberOfCards; i < numberOfGreens + 3 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "violet");
        for (int i = numberOfGreens + 3 * numberOfCards; i < numberOfGreens + 4 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "yellow");
        for (int i = numberOfGreens + 4 * numberOfCards; i < numberOfGreens + 5 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "white");


    }
    else if (numberOfPiles == 6) {
        for (int i = numberOfGreens; i < numberOfGreens + numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "blue");
        for (int i = numberOfGreens + numberOfCards; i < numberOfGreens + 2 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "red");
        for (int i = numberOfGreens + 2 * numberOfCards; i < numberOfGreens + 3 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "violet");
        for (int i = numberOfGreens + 3 * numberOfCards; i < numberOfGreens + 4 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "yellow");
        for (int i = numberOfGreens + 4 * numberOfCards; i < numberOfGreens + 5 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "white");
        for (int i = numberOfGreens + 5 * numberOfCards; i < numberOfGreens + 6 * numberOfCards; i++)
            strcpy_s(deck.cards[i].color, "black");


    }
}


void shuffle_deck(Deck& deck)
{

    class Deck tmp;
    int index, i;
    int high, low, random;

    for (i = 0; i < deck.cardsNumber; i++) {

        high = deck.cardsNumber - 1;
        low = i;
        random = rand();

        index = rand() % (high - low + 1) + low;


        tmp.cards[0] = deck.cards[i]; // zamieñ cards[i] z cards[j]
        deck.cards[i] = deck.cards[index];
        deck.cards[index] = tmp.cards[0];


    }
}




void print_deck(int numberOfPlayers, int numberOfPiles, int numberOfGreens, int numberOfCards, Player* players, Deck& deck, FILE* file, int explosionNumber, int maxRounds) {
    fprintf(file, "%s\n", "active player = 1");
    fprintf(file, "%s\n", "active round = 1");
    fprintf(file, "%s", "players number = "), fprintf(file, "%d\n", numberOfPlayers);
    fprintf(file, "%s", "explosion threshold = "), fprintf(file, "%d\n", explosionNumber);
    fprintf(file, "%s", "Rounds = "), fprintf(file, "%d\n", maxRounds);
    for (int i = 0; i < numberOfPlayers; i++) {
        fprintf(file, "%d", i + 1);
        fprintf(file, "%s", " player hand cards: ");
        for (int j = 0; players[i].cards[j].value != 0; j++) {
            fprintf(file, "%d", players[i].cards[j].value), fprintf(file, "%s", " "), fprintf(file, "%s", players[i].cards[j].color), fprintf(file, "%s", " ");


        }
        fprintf(file, "%s", "\n");
        fprintf(file, "%d", i + 1), fprintf(file, "%s\n", " player deck cards: ");

    }
    for (int i = 0; i < numberOfPiles; i++) {
        fprintf(file, "%d", i + 1), fprintf(file, "%s\n", " pile cards:");

    }

}




int main() {
    int numberOfPlayers = 0, numberOfPiles = 0, numberOfGreens = 0, greensValue = 0, numberOfCards = 0, explosionNumber = 0, maxRounds = 0;
    srand(time(NULL));
    FILE* file;

    file = fopen("game.txt", "w");
    if (file == NULL) {
        printf("Error\n");
        return 1;

    }

    cin >> numberOfPlayers;
    cin >> numberOfPiles;
    cin >> numberOfGreens;
    cin >> greensValue;
    cin >> numberOfCards;
    cin >> explosionNumber;
    cin >> maxRounds;

    Player* players = new Player[numberOfPlayers];

    Deck deck;
    deck.cardsNumber = numberOfGreens + numberOfCards * numberOfPiles;

    making_deck(numberOfPiles, numberOfGreens, greensValue, numberOfCards, deck);
    shuffle_deck(deck);
    dealingCards(players, deck, numberOfPlayers, numberOfPiles, numberOfGreens, numberOfCards);
    print_deck(numberOfPlayers, numberOfPiles, numberOfGreens, numberOfCards, players, deck, file, explosionNumber, maxRounds);
    fclose(file);