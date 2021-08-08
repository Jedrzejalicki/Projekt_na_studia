#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#define CARDS_MAX (200)
#define LINE_MAX (300)
#define GREEN_MAX (20)
#define CARDS_VALUE (21)
#define COLOR_MAX (6)
#define LINE_SMALL (30)
int activePlayer;
int activeRound;
using namespace std;

class Card {
public:
    int value = 0;
    char color[10] = {
    };
};

class Hand {
public:
    Card cards[CARDS_MAX];
    int numberOfGreens = 0;
    int numberOfCardsInColor[COLOR_MAX] = { 0, 0, 0, 0, 0, 0
    };
    int valueOfGreens[CARDS_VALUE] = {
    }, valueOfBlues[CARDS_VALUE] = {
    }, valueOfReds[CARDS_VALUE] = {
    }, valueOfViolets[CARDS_VALUE] = {
    }, valueOfYellows[CARDS_VALUE] = {
    }, valueOfWhites[CARDS_VALUE] = {
    }, valueOfBlacks[CARDS_VALUE] = {
    };
};

class Deck {
public:
    Card cards[CARDS_MAX];
    int numberOfGreens = 0;
    int  numberOfCardsInColor[COLOR_MAX] = { 0, 0, 0, 0, 0, 0
    }; // tablica przetrzumuj¹ca iloœ kart w danym kolorze 0 -zielony, 1 - niebieskli itd;
    int valueOfGreens[CARDS_VALUE] = {
    }, valueOfBlues[CARDS_VALUE] = {
    }, valueOfReds[CARDS_VALUE] = {
    }, valueOfViolets[CARDS_VALUE] = {
    }, valueOfYellows[CARDS_VALUE] = {
    }, valueOfWhites[CARDS_VALUE] = {
    }, valueOfBlacks[CARDS_VALUE] = {
    };

};


int setStartNumber(char* line) {
    int startNumber = 0;
    for (int x = 0; x < 50; x++) {
        if (line[x] == ':') {
            startNumber = x;

        }

    }
    return startNumber;
}

class Player {
public:
    Hand hand;
    Deck deck;


    int handCardNumber = 0;
    int handColorNumber = 0;
    int deckCardNumber = 0;
    int deckColorNumber = 0;
    int immunnity[COLOR_MAX] = { -1, -1, -1,-1,-1, -1
    };
    int numberOfColors[COLOR_MAX] = { 0, 0, 0, 0, 0, 0
    };



    void addCardToHand(FILE* f) {
        char line[LINE_MAX];
        int cardValue;
        char converter[2];
        fgets(line, LINE_MAX, f);
        int startNumber = setStartNumber(line);


        for (int i = startNumber; line[i] != '\0'; i++) // counting length of line, but starts analyzing it after "1 player hand cards: "
        {
            if (line[i - 1] == ' ' && line[i] != ' ' && line[i + 1] == ' ') {
                cardValue = (int)line[i] - 48;
                hand.cards[handCardNumber].value = cardValue; // changing char to int to add it into value
                handCardNumber++;

            }
            else if (line[i - 1] == ' ' && line[i] != ' ' && line[i + 1] != ' ' && line[i + 2] == ' ') {
                converter[0] = (int)line[i] - 48;
                converter[1] = (int)line[i + 1] - 48;
                cardValue = 10 * converter[0] + converter[1];
                hand.cards[handCardNumber].value = cardValue;
                handCardNumber++;

            }


        }
        checkHandColors(startNumber, line);

    }

    void checkHandColors(int startNumber, char* line) {
        for (int i = startNumber; line[i] != '\0'; i++) {
            if (line[i] == 'g') {
                strcpy_s(hand.cards[handColorNumber].color, "green");
                hand.valueOfGreens[hand.numberOfCardsInColor[0]] = hand.cards[handColorNumber].value;
                handColorNumber++;
                hand.numberOfGreens++;


            }

            else if (line[i] == 'b' && line[i + 2] == 'u') {
                strcpy_s(hand.cards[handColorNumber].color, "blue");
                numberOfColors[0] = 1;
                hand.valueOfBlues[hand.numberOfCardsInColor[0]] = hand.cards[hand.numberOfCardsInColor[0]].value;
                hand.numberOfCardsInColor[0]++;
                handColorNumber++;

            }
            else if (line[i] == 'r' && line[i + 2] == 'd') {
                strcpy_s(hand.cards[handColorNumber].color, "red");
                numberOfColors[2] = 1;
                hand.valueOfReds[hand.numberOfCardsInColor[1]] = hand.cards[handColorNumber].value;
                hand.numberOfCardsInColor[1]++;
                handColorNumber++;

            }
            else if (line[i] == 'v') {
                strcpy_s(hand.cards[handColorNumber].color, "violet");
                numberOfColors[2] = 1;
                hand.valueOfViolets[hand.numberOfCardsInColor[2]] = hand.cards[handColorNumber].value;
                hand.numberOfCardsInColor[2]++;
                handColorNumber++;

            }
            else if (line[i] == 'y') {
                strcpy_s(hand.cards[handColorNumber].color, "yellow");
                numberOfColors[3] = 1;
                hand.valueOfYellows[hand.numberOfCardsInColor[3]] = hand.cards[handColorNumber].value;
                hand.numberOfCardsInColor[3]++;
                handColorNumber++;

            }
            else if (line[i] == 'w' && line[i + 1] == 'h') {
                strcpy_s(hand.cards[handColorNumber].color, "white");
                numberOfColors[4] = 1;
                hand.valueOfWhites[hand.numberOfCardsInColor[4]] = hand.cards[handColorNumber].value;
                hand.numberOfCardsInColor[4]++;
                handColorNumber++;

            }
            else if (line[i] == 'b' && line[i + 2] == 'a') {
                strcpy_s(hand.cards[handColorNumber].color, "black");
                hand.valueOfBlacks[hand.numberOfCardsInColor[5]] = hand.cards[handColorNumber].value;
                numberOfColors[5] = 1;
                hand.numberOfCardsInColor[5]++;
                handColorNumber++;

            }

        }

    }


    void addCardToDeck(FILE* f) {
        char line[LINE_MAX];
        fgets(line, LINE_MAX, f);
        int cardValue;
        char converter[2];
        int startNumber = setStartNumber(line);


        for (int i = startNumber; line[i] != '\0'; i++) // counting length of line, but starts analyzing it after "1 player hand cards: "
        {

            if (line[i - 1] == ' ' && line[i] != ' ' && line[i + 1] == ' ') {
                cardValue = (int)line[i] - 48;
                deck.cards[deckCardNumber].value = cardValue; // changing char to int to add it into value
                deckCardNumber++;

            }
            else if (line[i - 1] == ' ' && line[i] != ' ' && line[i + 1] != ' ' && line[i + 2] == ' ') {
                converter[0] = (int)line[i] - 48;
                converter[1] = (int)line[i + 1] - 48;
                cardValue = 10 * converter[0] + converter[1];
                deck.cards[deckCardNumber].value = cardValue;
                deckCardNumber++;

            }

        }
        checkDeckColors(startNumber, line);

    }


    void checkDeckColors(int startNumber, char* line) {
        for (int i = startNumber; line[i] != '\0'; i++) {
            if (line[i] == 'g') {
                strcpy_s(deck.cards[deckColorNumber].color, "green");
                deck.valueOfGreens[deck.numberOfCardsInColor[0]] = deck.cards[handColorNumber].value;
                deckColorNumber++;
                deck.numberOfGreens++;

            }
            else if (line[i] == 'b' && line[i + 2] == 'u') {
                strcpy_s(deck.cards[deckColorNumber].color, "blue");
                numberOfColors[0] = 1;
                deck.valueOfBlues[deck.numberOfCardsInColor[0]] = deck.cards[deck.numberOfCardsInColor[0]].value;
                deck.numberOfCardsInColor[0]++;
                deckColorNumber++;


            }
            else if (line[i] == 'r' && line[i + 2] == 'd') {
                strcpy_s(deck.cards[deckColorNumber].color, "red");
                numberOfColors[1] = 1;
                deck.valueOfReds[deck.numberOfCardsInColor[1]] = deck.cards[deckColorNumber].value;
                deck.numberOfCardsInColor[1]++;
                deckColorNumber++;

            }
            else if (line[i] == 'v') {
                strcpy_s(deck.cards[deckColorNumber].color, "violet");
                numberOfColors[2] = 1;
                deck.valueOfViolets[deck.numberOfCardsInColor[2]] = deck.cards[deckColorNumber].value;
                deck.numberOfCardsInColor[2]++;
                deckColorNumber++;

            }
            else if (line[i] == 'y') {
                strcpy_s(deck.cards[deckColorNumber].color, "yellow");
                numberOfColors[3] = 1;
                deck.valueOfYellows[deck.numberOfCardsInColor[3]] = deck.cards[deckColorNumber].value;
                deck.numberOfCardsInColor[3]++;
                deckColorNumber++;

            }
            else if (line[i] == 'w' && line[i + 1] == 'h') {
                strcpy_s(deck.cards[deckColorNumber].color, "white");
                numberOfColors[4] = 1;
                deck.valueOfWhites[deck.numberOfCardsInColor[4]] = deck.cards[deckColorNumber].value;
                deck.numberOfCardsInColor[4]++;
                deckColorNumber++;

            }
            else if (line[i] == 'b' && line[i + 2] == 'a') {
                strcpy_s(deck.cards[deckColorNumber].color, "black");
                numberOfColors[5] = 1;
                deck.valueOfBlacks[deck.numberOfCardsInColor[5]] = deck.cards[deckColorNumber].value;
                deck.numberOfCardsInColor[5]++;
                deckColorNumber++;

            }

        }

    }
};


class Pile {
public:
    Card cards[200];
    int explosionNumber = 0;
    int pileCardNumber = 0;
    int pileColorNumber = 0;
    int numberOfGreens = 0;

    int numberOfColors[COLOR_MAX] = { 0, 0, 0, 0, 0, 0
    };
    int valueOfBlues[CARDS_VALUE] = {
    }, valueOfReds[CARDS_VALUE] = {
    }, valueOfViolets[CARDS_VALUE] = {
    }, valueOfYellows[CARDS_VALUE] = {
    }, valueOfWhites[CARDS_VALUE] = {
    }, valueOfBlacks[CARDS_VALUE] = {
    };


    void addCardsToPile(FILE* f) {
        char line[LINE_MAX];
        int cardValue;
        char converter[2];
        fgets(line, LINE_MAX, f);
        int startNumber = setStartNumber(line);



        for (int i = startNumber; line[i] != '\0'; i++)
        {
            if (line[i - 1] == ' ' && line[i] != ' ' && line[i + 1] == ' ') {
                cardValue = (int)line[i] - 48;
                cards[pileCardNumber].value = cardValue;
                pileCardNumber++;

            }
            else if (line[i - 1] == ' ' && line[i] != ' ' && line[i + 1] != ' ' && line[i + 2] == ' ') {
                converter[0] = (int)line[i] - 48;
                converter[1] = (int)line[i + 1] - 48;
                cardValue = 10 * converter[0] + converter[1];
                cards[pileCardNumber].value = cardValue;
                pileCardNumber++;

            }

        }
        checkColors(startNumber, line);

    }

    void checkColors(int startNumber, char* line) {
        for (int i = startNumber; line[i] != '\0'; i++)
        {
            if (line[i] == 'g') {
                strcpy_s(cards[pileColorNumber].color, "green");
                numberOfGreens++;
                pileColorNumber++;

            }
            else if (line[i] == 'b' && line[i + 2] == 'u') {
                strcpy_s(cards[pileColorNumber].color, "blue");
                valueOfBlues[numberOfColors[0]] = cards[pileColorNumber].value;
                numberOfColors[0]++;
                pileColorNumber++;


            }
            else if (line[i] == 'r' && line[i + 2] == 'd') {
                strcpy_s(cards[pileColorNumber].color, "red");
                valueOfReds[numberOfColors[1]] = cards[pileColorNumber].value;
                numberOfColors[1]++;
                pileColorNumber++;

            }
            else if (line[i] == 'v') {
                strcpy_s(cards[pileColorNumber].color, "violet");
                valueOfViolets[numberOfColors[2]] = cards[pileColorNumber].value;
                numberOfColors[2]++;
                pileColorNumber++;

            }
            else if (line[i] == 'y') {
                strcpy_s(cards[pileColorNumber].color, "yellow");
                valueOfYellows[numberOfColors[3]] = cards[pileColorNumber].value;
                numberOfColors[3]++;
                pileColorNumber++;

            }
            else if (line[i] == 'w' && line[i + 1] == 'h') {
                strcpy_s(cards[pileColorNumber].color, "white");
                valueOfWhites[numberOfColors[4]] = cards[pileColorNumber].value;
                numberOfColors[4]++;
                pileColorNumber++;

            }
            else if (line[i] == 'b' && line[i + 2] == 'a') {
                strcpy_s(cards[pileColorNumber].color, "black");
                valueOfBlacks[numberOfColors[5]] = cards[pileColorNumber].value;
                numberOfColors[5]++;
                pileColorNumber++;

            }

        }

    }
};



void giveCardsToPlayers(Player* players, int numberofPlayers, FILE* f) {
    for (int i = 0; i < numberofPlayers; i++) { // rozdaje karty graczom, na rêke i na stosik przed nich
        players[i].addCardToHand(f);
        players[i].addCardToDeck(f);

    }

}




void giveCardsToPiles(Pile* piles, int numberOfPiles, FILE* f) {
    for (int i = 0; i < numberOfPiles; i++) { // rozdajê karty do kocio³ków
        piles[i].addCardsToPile(f);

    }
}



int compare(const void* a, const void* b)// funkcja porównawcza do quick sort
{
    return (*(int*)a - *(int*)b);
}

int** sort(int** array, int* sizes) {
    for (int i = 0; i < COLOR_MAX; i++)
        qsort(array[i], sizes[i], sizeof(int), compare);



    return array;

}

int countGreens(Player* players, Pile* pile, int numberofPlayers, int numberOfPiles) {
    int numberOfGreens = 0;
    int* tmp = new int[numberofPlayers];// tablice tymczsowe,, które pos³ó¿¹ do dodania wartoœci
    int* tmp1 = new int[numberofPlayers];
    for (int i = 0; i < numberofPlayers; i++) {
        tmp[i] = 0;
        tmp1[i] = 0;

    }
    int tmp2 = 0;
    int tmp3 = 0;
    for (int i = 0; i < numberofPlayers; i++) {
        tmp1[i] += players[i].deck.numberOfGreens;// dodaje osobno ze stosiku i z rêki gracza, liczba zielnoych kart  w póŸniejszej fazie gry musi byæ niezale¿na
        tmp[i] += players[i].hand.numberOfGreens;

    }

    for (int i = 0; i < numberofPlayers; i++) {
        tmp2 += tmp[i];
        tmp3 += tmp1[i];

    }
    numberOfGreens = tmp2 + tmp3;


    for (int i = 0; i < numberOfPiles; i++)
        numberOfGreens += pile[i].numberOfGreens;// do zielonych kart graczy dodaje karty z kocio³ków

    return numberOfGreens;
}

int saveAndCheckGreensValue(Player* players, Pile* piles, int numberOfPlayers, int NumberOfPiles, int numberofGreens) {
    int greensValue[GREEN_MAX] = {
    };
    int x = 0;
    int check = 0;

    for (int i = 0; i < numberOfPlayers; i++) {
        for (int j = 0; j < players[i].handCardNumber; j++) {
            if (strcmp(players[i].hand.cards[j].color, "green") == 0) {// sprawdzam ktory kolor to green i wartoœci tych kart wpisuje do tablicy 
                greensValue[x] = players[i].hand.cards[j].value;
                x++;


            }


        }
        for (int j = 0; j < players[i].deckCardNumber; j++) {
            if (strcmp(players[i].deck.cards[j].color, "green") == 0) {
                greensValue[x] = players[i].deck.cards[j].value;
                x++;


            }


        }


    }
    for (int i = 0; i < NumberOfPiles; i++) {
        for (int j = 0; j < piles[i].pileCardNumber; j++) {
            if (strcmp(piles[i].cards[j].color, "green") == 0) {
                greensValue[x] = piles[i].cards[j].value;
                x++;

            }


        }


    }
    int i = 0;
    int first = greensValue[i];// porównuje tablice i sprawdzam czy wszystkie jej elementy s¹ równe pierwszemu 

    for (; i < numberofGreens; ++i)
        if (greensValue[i] != first) break;

    if (i == numberofGreens)
        check = 1;
    else if (i < numberofGreens)
        check = -1;



    return check;
}
int* countNumberOfColors(Player* players, Pile* piles, int numberOfPlayers, int numberOfPiles) {
    int bluePlayerHand = 0, redPlayerHand = 0, violetPlayerHand = 0, yellowPlayerHand = 0, whitePlayerHand = 0, blackPlayerHand = 0;
    int bluePlayerDeck = 0, redPlayerDeck = 0, violetPlayerDeck = 0, yellowPlayerDeck = 0, whitePlayerDeck = 0, blackPlayerDeck = 0;
    int bluePile = 0, redPile = 0, violetPile = 0, yellowPile = 0, whitePile = 0, blackPile = 0;
    int* color = new int[6];
    for (int i = 0; i < numberOfPlayers; i++) {// zliczam poszczególne kolory z r¹k i stosów wszystkich graczy
        bluePlayerHand += players[i].hand.numberOfCardsInColor[0];
        bluePlayerDeck += players[i].deck.numberOfCardsInColor[0];
        redPlayerHand += players[i].hand.numberOfCardsInColor[1];
        redPlayerDeck += players[i].deck.numberOfCardsInColor[1];
        violetPlayerHand += players[i].hand.numberOfCardsInColor[2];
        violetPlayerDeck += players[i].deck.numberOfCardsInColor[2];
        yellowPlayerHand += players[i].hand.numberOfCardsInColor[3];
        yellowPlayerDeck += players[i].deck.numberOfCardsInColor[3];
        whitePlayerHand += players[i].hand.numberOfCardsInColor[4];
        whitePlayerDeck += players[i].deck.numberOfCardsInColor[4];
        blackPlayerHand += players[i].hand.numberOfCardsInColor[5];
        blackPlayerDeck += players[i].deck.numberOfCardsInColor[5];

    }

    for (int i = 0; i < numberOfPiles; i++) {//zliczam kolory z kocio³ków
        bluePile += piles[i].numberOfColors[0];
        redPile += piles[i].numberOfColors[1];
        violetPile += piles[i].numberOfColors[2];
        yellowPile += piles[i].numberOfColors[3];
        whitePile += piles[i].numberOfColors[4];
        blackPile += piles[i].numberOfColors[5];


    }


    color[0] = bluePlayerHand + bluePlayerDeck + bluePile;//dodaje je i wpisuje do tablicy celem sprawdzania póŸniej tej tablicy wzd³u¿ i w szerz
    color[1] = redPlayerHand + redPlayerDeck + redPile;
    color[2] = violetPlayerHand + violetPlayerDeck + violetPile;
    color[3] = yellowPlayerHand + yellowPlayerDeck + yellowPile;
    color[4] = whitePlayerHand + whitePlayerDeck + whitePile;
    color[5] = blackPlayerHand + blackPlayerDeck + blackPile;


    return color;
}


int checkColor(Player* players, Pile* piles, int numberOfPlayers, int numberOfPiles) {
    int* color = countNumberOfColors(players, piles, numberOfPlayers, numberOfPiles);

    for (int i = 0; i < COLOR_MAX; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (color[i] == 0 && color[j] != 0) {
                color[i] = color[j];


            }


        }


    }

    int i = 0;
    for (; i < COLOR_MAX; ++i) // sprawdzamy czy wszystkie wartoœci s¹ takie same
        if (color[i] != color[0]) break;

    if (i == 6) {
        return 1;


    }
    else {
        return -1;

    }

}




int countValues(Player* players, int numberOfPlayers, Pile* piles, int numberOfPiles) {
    int bu = 0, r = 0, v = 0, y = 0, w = 0, bc = 0;
    int check = 0;
    int** colors = new int* [6];

    int* sizes = countNumberOfColors(players, piles, numberOfPlayers, numberOfPiles);
    for (int i = 0; i < COLOR_MAX; i++) {
        colors[i] = new int[sizes[i]];


    }
    for (int i = 0; i < numberOfPlayers; i++) {
        for (int j = 0; j < players[i].handCardNumber; j++) {
            if (strcmp(players[i].hand.cards[j].color, "blue") == 0) {// sprawdzam wartoœci poszczególnyuch kolorów i zapisuje je do tablicy dwu wymiarowej
                colors[0][bu] = players[i].hand.cards[j].value;
                bu++;


            }
            else if (strcmp(players[i].hand.cards[j].color, "red") == 0) {
                colors[1][r] = players[i].hand.cards[j].value;
                r++;


            }
            else if (strcmp(players[i].hand.cards[j].color, "violet") == 0) {
                colors[2][v] = players[i].hand.cards[j].value;
                v++;


            }
            else if (strcmp(players[i].hand.cards[j].color, "yellow") == 0) {
                colors[3][y] = players[i].hand.cards[j].value;
                y++;


            }
            else if (strcmp(players[i].hand.cards[j].color, "white") == 0) {
                colors[4][w] = players[i].hand.cards[j].value;
                w++;


            }
            else if (strcmp(players[i].hand.cards[j].color, "black") == 0) {
                colors[5][bc] = players[i].hand.cards[j].value;
                bc++;


            }

        }

    }
    for (int i = 0; i < numberOfPlayers; i++) {                                              //dodaje do istniej¹cej tablicy waroœci i kolorów wartoœci i kolory ze stosików graczy
        for (int j = 0; j < players[i].deckCardNumber; j++) {
            if (strcmp(players[i].deck.cards[j].color, "blue") == 0) {
                colors[0][bu] = players[i].deck.cards[j].value;
                bu++;


            }
            else if (strcmp(players[i].deck.cards[j].color, "red") == 0) {
                colors[1][r] = players[i].deck.cards[j].value;
                r++;


            }
            else if (strcmp(players[i].deck.cards[j].color, "violet") == 0) {
                colors[2][v] = players[i].deck.cards[j].value;
                v++;


            }
            else if (strcmp(players[i].deck.cards[j].color, "yellow") == 0) {
                colors[3][y] = players[i].deck.cards[j].value;
                y++;


            }
            else if (strcmp(players[i].deck.cards[j].color, "white") == 0) {
                colors[4][w] = players[i].deck.cards[j].value;
                w++;


            }
            else if (strcmp(players[i].deck.cards[j].color, "black") == 0) {
                colors[5][bc] = players[i].deck.cards[j].value;
                bc++;


            }


        }

    }
    for (int j = 0; j < numberOfPiles; j++) {        //dodaje do istniej¹cej tablicy waroœci i kolorów wartoœci i kolory ze kocio³ków
        for (int i = 0; i < sizes[0]; i++)
            if (piles[j].valueOfBlues[i] != 0) {
                colors[0][bu] = piles[j].valueOfBlues[i];
                bu++;


            }
        for (int i = 0; i < sizes[1]; i++)
            if (piles[j].valueOfReds[i] != 0) {
                colors[1][r] = piles[j].valueOfReds[i];
                r++;


            }
        for (int i = 0; i < sizes[2]; i++)
            if (piles[j].valueOfViolets[i] != 0) {
                colors[2][v] = piles[j].valueOfViolets[i];
                v++;


            }
        for (int i = 0; i < sizes[3]; i++)
            if (piles[j].valueOfYellows[i] != 0) {
                colors[3][y] = piles[j].valueOfYellows[i];
                y++;


            }
        for (int i = 0; i < sizes[4]; i++)
            if (piles[j].valueOfWhites[i] != 0) {
                colors[4][w] = piles[j].valueOfWhites[i];
                w++;


            }
        for (int i = 0; i < sizes[5]; i++)
            if (piles[j].valueOfBlacks[i] != 0) {
                colors[5][bc] = piles[j].valueOfBlacks[i];
                bc++;


            }


    }

    colors = sort(colors, sizes); // sortuje tablice dwuwymiarow¹
    for (int i = 0; i < COLOR_MAX; i++) {
        for (int j = 0; j < sizes[i]; j++)
            if (colors[0][j] == colors[i][j] || (colors[0][j] == colors[i][j] && colors[i][j] == 0))//porównuje czy eszystkie wartoœci s¹ takie sdame
                check = 1;
            else {
                check = 0;


            }

    }

    delete[] sizes;

    if (check == 1)
        return 1;
    else
        return -1;


}


int checkCardOnHand(Player* players, int numberOfPlayers) {
    int check = 1;
    for (int i = 0; i < numberOfPlayers; i++) {// odejmuje liczbe kart ka¿dego gracza od ka¿dego i je¿eli ró¿nica miêdzy nimi jest mneijsza ni¿ -1 lub wiêsza ni¿ 1
        for (int j = i - 1; j >= 0; j--) {               // to znaczy ¿e któeyœ gracz ma za du¿o lub za ma³o kart
            if (players[i].handCardNumber - players[j].handCardNumber > 1 || players[i].handCardNumber - players[j].handCardNumber < -1)
                check = -1;
            else
                check = 1;

        }

    }

    return check;
}


int checkPilesColor(Pile* piles, int numberOfPiles) {
    int* number = new int[COLOR_MAX];
    int colorCheck[COLOR_MAX][COLOR_MAX];
    int check = 1;
    int index = 0;
    for (int i = 0; i < COLOR_MAX; i++)
        number[i] = 0;

    for (int i = 0; i < numberOfPiles; i++) {
        for (int x = 0; x < COLOR_MAX; x++) {
            if (piles[0].numberOfColors[x] > 0) {
                colorCheck[index][x] = 1;
                index++;

            }
            else
                colorCheck[0][x] = 0;
            if (piles[1].numberOfColors[x] > 0)
                colorCheck[1][x] = 1;
            else
                colorCheck[1][x] = 0;
            if (numberOfPiles > 1) {
                if (piles[2].numberOfColors[x] > 0)
                    colorCheck[2][x] = 1;
                else
                    colorCheck[2][x] = 0;

            }
            if (numberOfPiles > 2) {
                if (piles[3].numberOfColors[x] > 0)
                    colorCheck[3][x] = 1;
                else
                    colorCheck[3][x] = 0;

            }
            if (numberOfPiles > 3) {
                if (piles[4].numberOfColors[x] > 0)
                    colorCheck[4][x] = 1;
                else
                    colorCheck[4][x] = 0;

            }
            if (numberOfPiles > 4) {
                if (piles[5].numberOfColors[x] > 0)
                    colorCheck[5][x] = 1;
                else
                    colorCheck[5][x] = 0;

            }

        }

    }



    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (colorCheck[i][j] == 1)
                number[i]++;

        }

    }

    for (int i = 0; i < COLOR_MAX; i++)
        if (number[i] > 1)
            check = -1;

    return check;
}

int* checkPilesSum(Pile* piles, int numberOfPiles) {
    int* sum = new int[numberOfPiles];
    int check = 1;
    for (int i = 0; i < numberOfPiles; i++)
        sum[i] = 0;

    for (int i = 0; i < numberOfPiles; i++)
        for (int j = 0; j < piles[i].pileCardNumber; j++)
            sum[i] += piles[i].cards[j].value;


    return sum;
}

int checkExplosion(Pile* piles, int numberOfPiles) {
    int check = 1;
    int* sum = checkPilesSum(piles, numberOfPiles);

    for (int i = 0; i < numberOfPiles; i++)
        if (piles[i].explosionNumber < sum[i])
            check = -1;
    return check;
}




void explosion(Player* players, Pile* piles, int pileNumber, int numberOfCardsToMove) {
    int playerIndex = players[activePlayer].deckCardNumber;
    for (int i = 0; i < numberOfCardsToMove; i++) {
        players[activePlayer].deck.cards[playerIndex] = piles[pileNumber].cards[i];
        players[activePlayer].deckCardNumber += piles[pileNumber].pileCardNumber;
        piles[pileNumber].cards[i].value = 0;
        piles[pileNumber].cards[i].color[0] = '\0';
        piles[pileNumber].pileCardNumber = 0;
        playerIndex++;

    }

}

void explode(Player* players, Pile* piles, int numberOfPiles) {
    int pileNumber = 0;
    int numberOfCardsToMove;
    int* sum = checkPilesSum(piles, numberOfPiles);

    for (int i = 0; i < numberOfPiles; i++) {
        if (sum[i] > piles[0].explosionNumber) {
            pileNumber = i;
            numberOfCardsToMove = piles[i].pileCardNumber;
            explosion(players, piles, pileNumber, numberOfCardsToMove);

        }

    }
}







void makeMove(Player* players, Pile* piles, int numberOfPiles) {

    if (strcmp(players[activePlayer].hand.cards[0].color, "green") == 0) {                                                           //sprawdzay czy karta nie jest zielona wtedy dok³adamy na pierwszy stos                                 
        piles[0].cards[piles[0].pileCardNumber] = players[activePlayer].hand.cards[0];  // dodajemy kartê nastêpn¹ po ostatniej
        piles[0].pileCardNumber++;                                                                                                      //zwiêkszamy liczbê kart na stosie 

    }
    else {
        for (int i = 0; i < numberOfPiles; i++) {
            for (int j = 0; j < piles[i].pileCardNumber; j++) {
                if (strcmp(players[activePlayer].hand.cards[0].color, piles[i].cards[j].color) == 0) { //porównojemy pierwsz¹ karte z rêki
                    piles[i].cards[piles[i].pileCardNumber] = players[activePlayer].hand.cards[0];  //z ka¿d¹ kart¹ na stosie i dodajmemy jeœli kolory s¹ takie same 
                    piles[i].pileCardNumber++;
                    break;

                }

            }

        }

    }
}

void moveHandCards(Player* players, int numberOfPlayers) {
    for (int i = 0; i < players[activePlayer].handCardNumber - 1; i++) {
        players[activePlayer].hand.cards[i] = players[activePlayer].hand.cards[i + 1];

    }
    players[activePlayer].handCardNumber--;
}


void endRound(Player* players, int numberOfPlayers, FILE* file) {
    int immunity[COLOR_MAX] = { -1, -1, -1, -1, -1, -1
    };//w rzêdach odpowiadaj¹cych kolorm, bêdzie numer gracza odpornego na dany kolor(immunity[0] = niebieski, immunity[1] - czerwony itp)
    int playersColor[6][COLOR_MAX] = { 0, 0, 0, 0, 0, 0
    };  //tworze tablice 2D która bêdzie zestawia³a kolory ka¿dego gracza i sprawdza³a gdzie wartoœæ maksymalna
    int max[6] = { 0, 0, 0, 0, 0, 0
    };
    int check[6] = { 0, 0, 0, 0, 0, 0
    };             //u¿ywam tablicy aby unikn¹æ 12 ró¿nych zmiennych
    int* result = new int[numberOfPlayers];
    for (int i = 0; i < numberOfPlayers; i++)
        result[i] = 0;
    int     forbiddenNumbers[COLOR_MAX];
    for (int i = 0; i < COLOR_MAX; i++)
        forbiddenNumbers[i] = -1;
    int     forbiddenNumbers1[COLOR_MAX];
    for (int i = 0; i < COLOR_MAX; i++)
        forbiddenNumbers1[i] = -1;
    int x = 0;
    int y = 0;


    activeRound += 1;
    for (int i = 0; i < numberOfPlayers; i++) {
        for (int j = 0; j < COLOR_MAX; j++) {  // max liczymy od jedynki bo 0 to kolor zielony
            playersColor[i][j] = players[i].deck.numberOfCardsInColor[j];

        }

    }

    for (int i = 0; i < numberOfPlayers; i++) {
        for (int j = 0; j < COLOR_MAX; j++) {
            if (max[j] < playersColor[i][j]) {// tavbela max numer indexu = color, wartoœæ = maxymalna wartoœæ w kolorze
                max[j] = playersColor[i][j];

            }

        }

    }

    for (int i = 0; i < numberOfPlayers; i++) {
        for (int j = 0; j < COLOR_MAX; j++) {
            if (max[j] == players[i].deck.numberOfCardsInColor[j])
                check[j]++;

        }

    }

    for (int i = 0; i < numberOfPlayers; i++) {
        for (int j = 0; j < COLOR_MAX; j++) {
            if (check[j] == 1) {
                immunity[j] = j;

            }


        }
        break;

    }






    for (int j = 0; j < COLOR_MAX; j++) {
        for (int i = 0; i < numberOfPlayers; i++) {
            if (immunity[j] > -1) {
                if (max[j] == playersColor[i][j]) {
                    players[i].immunnity[x] = j;
                    x++;
                    if (j == 0)
                        fprintf(file, "%s", "Na kolor blue odporny jest gracz "), fprintf(file, "%d\n", i + 1);
                    else if (j == 1)
                        fprintf(file, "%s", "Na kolor red odporny jest gracz "), fprintf(file, "%d\n", i + 1);
                    else if (j == 2)
                        fprintf(file, "%s", "Na kolor violet odporny jest gracz "), fprintf(file, "%d\n", i + 1);
                    else if (j == 3)
                        fprintf(file, "%s", "Na kolor yellow odporny jest gracz "), fprintf(file, "%d\n", i + 1);
                    else if (j == 4)
                        fprintf(file, "%s", "Na kolor white odporny jest gracz "), fprintf(file, "%d\n", i + 1);
                    else if (j == 5)
                        fprintf(file, "%s", "Na kolor black odporny jest gracz "), fprintf(file, "%d\n", i + 1);


                }

            }



        }

    }



    for (int i = 0; i < numberOfPlayers; i++) {
        for (int j = 0; j < COLOR_MAX; j++) {
            if (players[i].immunnity[j] >= 0) {
                players[i].deck.numberOfCardsInColor[players[i].immunnity[j]] = 0;


            }

            result[i] += players[i].deck.numberOfCardsInColor[j];

        }

    }

    for (int i = 0; i < numberOfPlayers; i++) {
        result[i] += 2 * (players[i].deck.numberOfGreens);

    }

    for (int i = 0; i < numberOfPlayers; i++) {
        fprintf(file, "%s", "Wynik gracza "), fprintf(file, "%d", i + 1), fprintf(file, "%s", " = "), fprintf(file, "%d\n", result[i]);

    }



}




void print(Player* players, int numberOfPlayers, Pile* piles, int numberOfPiles, FILE* file) {
    if (activePlayer == numberOfPlayers - 1) // pomniejszy³em wczeœniej activePlayer o 1;
        activePlayer = 1;
    else
        activePlayer += 2; //+2, bo pomniejszy³em wczeœniej o jedenz aby pasowa³o do tablicy


    fprintf(file, "%s", "active player = "), fprintf(file, "%d\n", activePlayer);
    fprintf(file, "%s", "players number = "), fprintf(file, "%d\n", numberOfPlayers);
    fprintf(file, "%s", "explosion threshold = "), fprintf(file, "%d\n", piles[0].explosionNumber);

    for (int i = 0; i < numberOfPlayers; i++) {
        fprintf(file, "%d", i + 1), fprintf(file, "%s", " player hand cards: ");
        for (int j = 0; j < players[i].handCardNumber; j++) {
            fprintf(file, "%d", players[i].hand.cards[j].value), fprintf(file, "%s", " "), fprintf(file, "%s", players[i].hand.cards[j].color), fprintf(file, "%s", " ");



        }
        fprintf(file, "%s", "\n");
        fprintf(file, "%d", i + 1), fprintf(file, "%s", " player deck cards: ");
        for (int x = 0; x < players[i].deckCardNumber; x++) {

            fprintf(file, "%d", players[i].deck.cards[x].value), fprintf(file, "%s", " "), fprintf(file, "%s", players[i].deck.cards[x].color), fprintf(file, "%s", " ");

        }
        fprintf(file, "%s", "\n");


    }
    for (int i = 0; i < numberOfPiles; i++) {
        fprintf(file, "%d", i + 1), fprintf(file, "%s", " pile cards: ");
        for (int j = 0; j < piles[i].pileCardNumber; j++) {
            fprintf(file, "%d", piles[i].cards[j].value), fprintf(file, "%s", " "), fprintf(file, "%s", piles[i].cards[j].color), fprintf(file, "%s", " ");



        }

        fprintf(file, "%s", "\n");

    }



}


int checkDeck(Player* players, int numberOfPlayers, Pile* piles, int numberOfPiles) {
    int check1 = 0, check2 = 0, check3 = 0, check4 = 0, check5 = 1, check6 = 0;
    int result = 0;
    int numberOfGreens = countGreens(players, piles, numberOfPlayers, numberOfPiles);


    if (numberOfGreens > 0)
        check1 = saveAndCheckGreensValue(players, piles, numberOfPlayers, numberOfPiles, numberOfGreens);
    else
        check1 = -1;


    check2 = checkColor(players, piles, numberOfPlayers, numberOfPiles);

    check3 = countValues(players, numberOfPlayers, piles, numberOfPiles);


    check4 = checkCardOnHand(players, numberOfPlayers);

    check5 = checkPilesColor(piles, numberOfPiles);

    check6 = checkExplosion(piles, numberOfPiles);

    if (check1 == -1 || check2 == -1 || check3 == -1 || check4 == -1 || check5 == -1 || check6 == -1) {
        result = -1;

    }
    else {
        result = 1;

    }
    return result;

}


int setNumberOfPiles(Player* players, int numberOfPlayers) {
    int numberOfPiles = 0;
    int colors[6] = { 0,0,0,0,0,0
    };

    for (int i = 0; i < numberOfPlayers; i++) {
        if ((players[i].hand.numberOfCardsInColor[0] + players[i].deck.numberOfCardsInColor[0]) > 0)
            colors[0] = 1;
        if ((players[i].hand.numberOfCardsInColor[1] + players[i].deck.numberOfCardsInColor[1]) > 0)
            colors[1] = 1;
        if ((players[i].hand.numberOfCardsInColor[2] + players[i].deck.numberOfCardsInColor[2]) > 0)
            colors[2] = 1;
        if ((players[i].hand.numberOfCardsInColor[3] + players[i].deck.numberOfCardsInColor[3]) > 0)
            colors[3] = 1;
        if ((players[i].hand.numberOfCardsInColor[4] + players[i].deck.numberOfCardsInColor[4]) > 0)
            colors[4] = 1;
        if ((players[i].hand.numberOfCardsInColor[5] + players[i].deck.numberOfCardsInColor[5]) > 0)
            colors[5] = 1;

    }

    for (int i = 0; i < COLOR_MAX; i++)
        numberOfPiles += colors[i];

    return numberOfPiles;
}

int mainFunction() {
    int numberOfPlayers = 0;
    char str_num;
    int expolsionNumber;
    char converter[4];
    char startInput1[LINE_SMALL];
    char startInput2[LINE_SMALL];
    char startInput3[LINE_SMALL];
    int numberOfPiles = 0;
    int correctnes = 0;


    FILE* f = fopen("game.txt", "r");    // otwiera plik do odczytu (musi istniec)
    if (f == NULL)
    {
        cout << "error";
        return 1;

    }

    fgets(startInput1, LINE_SMALL, f);
    fgets(startInput2, LINE_SMALL, f);
    fgets(startInput3, LINE_SMALL, f);

    converter[0] = (int)startInput3[22] - 48;
    converter[1] = (int)startInput3[23] - 48;
    if (startInput3[24] != '\n') {
        converter[2] = (int)startInput3[24] - 48;
        expolsionNumber = 100 * converter[0] + 10 * converter[1] + converter[2];


    }
    else
        expolsionNumber = 10 * converter[0] + converter[1];

    activePlayer = ((int)startInput1[16] - 48) - 1; // liczymy od 0
    str_num = startInput2[17];




    numberOfPlayers = (int)str_num - 48;
    Player* players = new Player[numberOfPlayers];


    giveCardsToPlayers(players, numberOfPlayers, f);

    numberOfPiles = setNumberOfPiles(players, numberOfPlayers);
    Pile* piles = new Pile[numberOfPiles];



    for (int i = 0; i < numberOfPiles; i++)
        piles[i].explosionNumber = expolsionNumber;


    giveCardsToPiles(piles, numberOfPiles, f);

    fclose(f);

    correctnes = checkDeck(players, numberOfPlayers, piles, numberOfPiles);

    FILE* file = fopen("game.txt", "w");    // otwiera plik do odczytu (musi istniec)
    if (file == NULL)
    {
        cout << "error";
        return 1;

    }

    if (correctnes == 1) {
        makeMove(players, piles, numberOfPiles);
        moveHandCards(players, numberOfPlayers);
        explode(players, piles, numberOfPiles);
        print(players, numberOfPlayers, piles, numberOfPiles, file);

    }
    else {
        cout << "there is something wrong with deck" << endl;

    }

    fclose(file);
    FILE* file1 = fopen("result.txt", "w");    // otwiera plik do odczytu (musi istniec)
    if (file == NULL)
    {
        cout << "error";
        return 1;

    }

    endRound(players, numberOfPlayers, file1);

    fclose(file1);
    delete[] players;
    delete[] piles;

}



int main() {


    mainFunction();

}