# Projekt_na_studia
W jednym wierszu informacja o liczbie = g i wartości = gv kart trucizny występujących w grze, 
w postaci napisu: "Found g green cards, all with gv value". Jeśli nie wystąpi, żadna karta trucizny wyświetlony zostanie napis: "Green cards does not exist". 
Jeżeli znalezione zostaną przynajmniej dwie karty trucizny o różnych wartościach zostanie wyświetlony napis: "Different green cards values occurred". 


Wejście / Input
active player = 1
players number = 3
1 player hand cards: 4 green 4 green 1 blue 2 blue 4 blue 5 blue 7 blue  5 red 7 red 1 violet 2 violet 4 violet 5 violet 7 violet
1 player deck cards:
2 player hand cards: 4 green 4 green  7 blue 1 red 2 red 4 red 5 red 7 red 1 violet 2 violet 4 violet 5 violet 7 violet
2 player deck cards:
3 player hand cards: 4 green 4 green 1 blue 2 blue 4 blue  7 blue 1 red 2 red 4 red 5 red 7 red  5 violet 7 violet
3 player deck cards:
1 pile cards: 1 red 2 red 4 green
2 pile cards: 4 green 1 blue 2 blue 5 blue 5 blue
3 pile cards: 1 violet 2 violet

Wyjście / Output
Found 8 green cards, all with 4 value

Przykład 2 / Example 2

Wejście / Input
active player = 1
players number = 3
1 player hand cards: 4 violet 4 blue 5 blue 7 blue 
1 player deck cards: 5 red 7 red 1 violet 2 violet 4 violet 5 violet 7 violet
2 player hand cards: 4 violet 4 red 4 blue 1 blue 2 blue 5 blue 7 blue  7 red 1 violet 2 violet 4 violet
2 player deck cards: 7 violet
3 player hand cards: 4 red 4 red 1 blue 2 blue 4 blue 5 blue 7 blue 1 red 2 red 4 red 5 red 7 red 1 violet 2 violet 5 violet
3 player deck cards: 5 violet 7 violet
1 pile cards: 4 violet 1 blue 2 blue 4 blue
2 pile cards: 1 red 2 red 4 red 5 red
3 pile cards:

Wyjście / Output
Green cards does not exist

