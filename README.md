# SZE-MOSZE-2020-Kumisztan

Projekt feladat Modern szoftverfejlesztési eszközök (GKNB_INTM006) tárgyra.

## Működése

A program működéséhez 2 json fájl megadása szükséges, melyek a karakterek tulajdonságait tartalmazzák.

Például a Petyero.json fájl tartalma:

```
{
    "name" : "PETYERO",
    "hp" : 200,
    "dmg" : 10
}
```

A fájlok ellenőrzése után (hogy léteznek-e egyáltalán), a két karakter addig üti egymást, míg egyikük HP-ja 0-ra csökken, elvesztve így a meccset. 
Minden egyes bevitt sebzés után az adott karakter a sebzés nagyságával egyenlő értékű XP-t kap. Minden 100. XP után szintet lép, mely a következőkkel jár:

- A maximum HP megnő 10%-kal
- DMG megnő 10%-kal
- Az aktuális HP felmegy a maximumra

Futtatáshoz a kódot először le kell fordítani:

`g++ -std=c++17 *.cpp`

Majd ezután futtathatjuk.

Például:

`./a.out Petyero Vargussen`

## Készítették

- Győrvári Péter (ZC67Y8)
- Unger Márton (BG4HZ2)
- Varga Dániel (J5HZI6)