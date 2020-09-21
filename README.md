# SZE-MOSZE-2020-Kumisztan

Projekt feladat Modern szoftverfejlesztési eszközök (GKNB_INTM006) tárgyra.

## Működése

A program működéséhez 6 (karakterenként 3-3) paraméter megadása szükséges, melyek a következők:

- ID: karakter azonosítója - neve (string)
- hp: karakter életereje (int)
- dmg: karakter sebzése (int)

Az értékek megadása után, a két karakter addig üti egymást, míg egyikük HP-ja 0-ra csökken, elvesztve így a meccset.

Futtatáshoz a kódot először le kell fordítani:

g++ -std=c++17 *.cpp

Majd ezután futtathatjuk.

Például:

./a.out Peter 150 10 Dan 45 30

## Készítették

- Győrvári Péter Sándor (ZC67Y8)
- Unger Márton (BG4HZ2)
- Varga Dániel (J5HZI6)
