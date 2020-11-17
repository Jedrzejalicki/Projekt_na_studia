# Projekt_na_studia
Instukcja do oryginalnej gry
Napisz program wczytujący informacje o stanie gry w uogólnionej wersji gry Trucizna, Reinera Knizia.
Oryginalnie w grę może grać od 3 do 6 osób. Gracze umieszczają karty w 3 kociołkach (stosach kart) są zatem 4 kolory zielony + pozostałe 3 (niebieski czerwony i fioletowy). 
Zielone karty mają wartość 4. Pozostałe kolory występują w liczbie po 14 kart każdego z nich, a rozkład ich wartości to: 1, 1, 1, 2, 2, 2, 4, 4, 5, 5, 5, 7, 7, 7. W wersji uogólnionej wszystkie te parametry będziemy mogli zmieniać.

Wejście/Input
Pojawi się 2 + 2*n wierszy. Pierwszy zawiera zawsze tą samą informacją, że graczem aktywnym jest pierwszy gracz, czyli napis: "active player = 1".
W drugim wierszu informacja o liczbie graczy w postaci napisu: "players number = n", gdzie n to liczba graczy.
W kolejnych 2*n wierszach informacje o kartach graczy na ręce i zakrytych przed sobą. Kolejno dla każdego gracza 2 wiersze. 
Pierwszy informuje o liczbie i rodzaju kart jakie trzyma na ręce. Jest to napis w postaci: "x player hand cards: [wartość kolor]".
Gdzie x to numer kolejnego gracza a wyrażenie w postaci: [wartość kolor] oznacza, że dowolną liczbę razy, również zero może wystąpić para określająca kartę. 
Każda karta jest określona przez liczbę i kolor ze zbioru: {blue, red, violet, yellow, white, black}.
Drugi wiersz informuje o liczbie i rodzaju kart jakie leżą zakryte przed nim w wyniku eksplozji kociołka, co obrazuje napis: "x player deck cards: [wartość kolor]".

Wyjście/Output
Pojawi się 2*n wierszy. W kolejnych 2*n wierszach informacje o liczbie kart graczy na ręce i zakrytych przed sobą. Kolejno dla każdego gracza 2 wiersze. Pierwszy informuje o liczbie kart = xa, jakie trzyma na ręce gracz nr x. Jest to napis w postaci: "x player has xa cards on hand".
Drugi wiersz informuje o liczbie kart = xb, jakie trzyma zakryte przed sobą gracz nr x. Jest to napis w postaci: "x player has xb cards in front of him".


Przykład 1 / Example 1

Wejście / Input
active player = 1
players number = 3
1 player hand cards: 4 green 4 green 4 green 1 blue 2 blue 4 blue 5 blue 7 blue 1 red 2 red 5 red 7 red 1 violet 2 violet 4 violet 5 violet 7 violet
1 player deck cards:
2 player hand cards: 4 green 4 green 4 green 1 blue 2 blue 5 blue 7 blue 1 red 2 red 4 red 5 red 7 red 1 violet 2 violet 4 violet 5 violet 7 violet
2 player deck cards:
3 player hand cards: 4 green 4 green 1 blue 2 blue 4 blue 5 blue 7 blue 1 red 2 red 4 red 5 red 7 red 1 violet 2 violet 5 violet 7 violet
3 player deck cards:

Wyjście / Output
1 player has 17 cards on hand
1 player has 0 cards in front of him
2 player has 17 cards on hand
2 player has 0 cards in front of him
3 player has 16 cards on hand
3 player has 0 cards in front of him


Wejście / Input
active player = 1
players number = 3
1 player hand cards: 4 green 4 green 4 green 1 blue 2 blue 4 blue 5 blue 7 blue 1 red 2 red
1 player deck cards: 5 red 7 red 1 violet 2 violet 4 violet 5 violet 7 violet
2 player hand cards: 4 green 4 green 4 green 1 blue 2 blue 5 blue 7 blue 1 red 2 red 4 red 5 red 7 red 1 violet 2 violet 4 violet
2 player deck cards: 7 violet
3 player hand cards: 4 green 4 green 1 blue 2 blue 4 blue 5 blue 7 blue 1 red 2 red 4 red 5 red 7 red 1 violet 2 violet 5 violet
3 player deck cards: 5 violet 7 violet

Wyjście / Output
1 player has 10 cards on hand
1 player has 7 cards in front of him
2 player has 15 cards on hand
2 player has 1 cards in front of him
3 player has 15 cards on hand
3 player has 2 cards in front of him
