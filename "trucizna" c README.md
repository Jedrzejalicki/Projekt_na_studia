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
