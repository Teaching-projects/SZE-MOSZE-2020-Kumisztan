# SZE-MOSZE-2020-Kumisztan

Projekt feladat Modern szoftverfejlesztési eszközök (GKNB_INTM006) tárgyra.

## Működése

A program működéséhez 2 json fájl megadása szükséges, melyek a karakterek tulajdonságait tartalmazzák.

Például a Petyero.json fájl tartalma:

{
    "name" : "PETYERO",
    "hp" : 20000,
    "dmg" : 2500
}

A fájlok megadása után, a két karakter addig üti egymást, míg egyikük HP-ja 0-ra csökken, elvesztve így a meccset.

Futtatáshoz a kódot először le kell fordítani:

g++ -std=c++17 *.cpp

Majd ezután futtathatjuk.

Például:

./a.out Units/Petyero.json Units/Vargussen.json

## Készítették

- Győrvári Péter (ZC67Y8)
- Unger Márton (BG4HZ2)
- Varga Dániel (J5HZI6)