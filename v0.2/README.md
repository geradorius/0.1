# v0.2 – Didelių rinkinių generavimas ir konteinerių našumo analizė

Šioje versijoje įgyvendinta:

- 5 testinių rinkinių generavimas: 1k, 10k, 100k, 1M, 10M (10M galite pridėti parametru).
- Duomenų nuskaitymas ir padalinimas į dvi kategorijas (galutinis < 5.0 ir >= 5.0).
- Rezultatų įrašymas į du failus per kiekvieną bandymą.
- Konteinerių (std::vector, std::list, std::deque) palyginimas, matuojant tris žingsnius:
  - duomenų nuskaitymą;
  - padalinimą į dvi grupes;
  - naujų failų sukūrimą.

## Failų formatas
Kiekviena eilutė: `VardasX PavardeX p1 p2 p3 p4 p5 egz`, pvz.:
```
Vardas1 Pavarde1 10 9 8 7 6 9
```

## Kompiliavimas
Šiuos failus galite įtraukti į Visual Studio projektą arba kompiliuoti per komandinę eilutę (MSVC ar Clang). Pagrindinis įėjimo taškas: `v0.2/v0.2.cpp`.

## Paleidimas

- Generuoti duomenų failus (numatytai `./v0.2_data`):
```
v0.2.exe --generate --out ./v0.2_data --sizes 1000,10000,100000,1000000,10000000
```

- Vykdyti konteinerių testą vektoriumi:
```
v0.2.exe --run --container vector --in ./v0.2_data --out ./v0.2_data --sizes 1000,10000,100000,1000000
```

Konteinerį galite keisti į `list` ar `deque`.

## Išvesties failai
Kiekvienam bandymui gausite du failus:
- `rez_<container>_<dydis>_vargsiukai.txt`
- `rez_<container>_<dydis>_kietiakiai.txt`

## Pastabos apie atmintį
10M įrašų vienu metu atmintyje gali būti per daug priklausomai nuo kompiuterio. Jei trūksta RAM:
- pradėkite nuo 1k–1M;
- arba pakeiskite realizaciją į „streaming" (vieno praeinimo) režimą, skaidant be pilno įkėlimo į atmintį.
