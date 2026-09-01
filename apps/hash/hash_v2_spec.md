# Hashovaci funkce v2

Vystup je stejny jako v1: retezec 16 malych pismen anglicke abecedy.
Vstup: libovolny retezec ASCII znaku (0-127).

## Popis hashovaci funkce

### 1. Inicializace

Inicializuj `state` jako pole 16 bajtu s hodnotami:

```
state = [72, 111, 100, 110, 111, 116, 97, 65, 108, 103, 111, 82, 105, 116, 104, 109]
```

(ASCII hodnoty retezce "HodnotAlgoRithm")

### 2. S-box

S-box je substitucni tabulka o 256 prvcich, ktera zavadi nelinearitu.
Generuje se deterministicky:

```
sbox[i] = (i * 167 + 53) mod 256, pro i = 0, 1, ..., 255
```

### 3. Absorpce vstupu

Pro kazdy znak `c` vstupniho retezce na pozici `idx` (pocitano od 0) proved:

```
pro kazde i od 0 do 15:
    state[i] = sbox[(state[i] + ascii(c) + i * idx) mod 256] xor state[(i + 1) mod 16]
```

Po absorpci kazdeho znaku proved **michaci kolo** (viz krok 4).

### 4. Michaci kolo

Michaci kolo zajistuje, ze zmena jednoho bajtu ovlivni cely stav:

```
pro kazde i od 0 do 15:
    state[i] = sbox[(state[i] + state[(i + 7) mod 16]) mod 256]
    state[i] = state[i] xor (state[(i + 3) mod 16] rotace-vlevo-o-3-bity)
```

kde `rotace-vlevo-o-3-bity` pro 8-bitovou hodnotu `x` znamena:

```
rotl8(x, 3) = ((x << 3) | (x >> 5)) mod 256
```

### 5. Finalizace

Po zpracovani vsech znaku vstupu proved **4 michaci kola** (krok 4).

### 6. Prevod na vystup

Pro kazdy bajt `state[i]` (i = 0 az 15):

```
result[i] = 'a' + (state[i] mod 26)
```

Vysledkem je retezec 16 malych pismen.

## Priklad

```
hash_v2("Hello World") = ???
```

## Co je jinak oproti v1

| Vlastnost           | v1                              | v2                                |
|---------------------|---------------------------------|-----------------------------------|
| Nelinearita         | zadna (scitani + modulo)        | S-box substituce                  |
| Difuze              | 1 znak ovlivni 1-2 pozice      | 1 znak ovlivni vsech 16 pozic    |
| Michani             | cyklicky posun                  | XOR + rotace + S-box kazdy krok  |
| Finalizace          | zadna                           | 4 michaci kola navic              |
| Zavislost na pozici | slaba (sum dvou sousednich)     | silna (i * idx v absorpci)        |
