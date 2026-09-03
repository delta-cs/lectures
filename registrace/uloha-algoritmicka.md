# Algoritmická úloha: Kolik vody zůstane v horách

> Vstupní úloha do programu DELTA TopGun.
> Žádné chytré algoritmy k ní znát nemusíš, vystačíš si s polem, cyklem
> a podmínkou. Přemýšlet ale budeš muset.

## Příběh

Za školou se táhne pohoří. Zjednodušeně se dá popsat jako řada různě vysokých
sloupců, něco jako sloupcový graf.

V noci začne pršet. Prší dlouho a vydatně, takže se voda zachytí ve všech
prohlubních. Přebytečná voda přeteče přes okraje pohoří a odteče pryč.

Ráno tě zajímá, kolik vody v horách zůstalo.

## Co přesně počítáme

Terén je popsaný nezápornými celými čísly, což jsou výšky sloupců zleva
doprava. Žádná hora není vyšší než milion. Každý sloupec je široký 1, takže objem vody nad jedním sloupcem se
rovná výšce vody, která nad ním stojí.

Voda teče dolů a rozlévá se do stran. Když se po povrchu dostane až za levý
nebo pravý okraj pohoří, odteče pryč. Když odtéct nemá kudy, zůstane stát
v prohlubni.

Prší tak dlouho, až se hladiny ustálí a víc už se nikam nevejde.

### Ukázka

Terén: `3 0 2 0 4`

```
    #
#~~~#
#~#~#
#~#~#
```

- Nad prvním sloupcem (výška 3) voda nezůstane.
- Nad druhým (výška 0) sahá voda do výšky 3, tedy 3 jednotky.
- Nad třetím (výška 2) sahá voda do výšky 3, tedy 1 jednotka.
- Nad čtvrtým (výška 0) sahá voda do výšky 3, tedy 3 jednotky.
- Nad pátým (výška 4) voda nezůstane.

Celkem tedy 7 jednotek vody.

## Úrovně

Úloha je rozdělená na úrovně. Každá vyšší zahrnuje všechny předchozí.
Odevzdej tu nejvyšší, kterou zvládneš. I samotná úroveň 1 je platné odevzdání.

### Úroveň 1 – Spočítej to

Program si od uživatele vyžádá terén (klidně jen pár čísel oddělených mezerou)
a vypíše, kolik vody v něm zůstane.

Musí si poradit i s nezvyklými vstupy. Jaké to jsou a co s nimi program udělá,
je na tobě.

### Úroveň 2 – Nakresli to

Program navíc terén i vodu vykreslí podobně jako v ukázce výše:

- `#` = skála
- `~` = voda
- mezera = vzduch

Kreslí se odshora dolů a výška obrázku odpovídá nejvyššímu sloupci.

### Úroveň 3 – Zvládni velké pohoří

Program musí zvládnout **100 000 sloupců do jedné sekundy** na běžném
notebooku. Měří se samotný výpočet, ne to, jak dlouho trvá vstup vyrobit.

Kreslit v téhle úrovni nemusí, sto tisíc sloupců stejně není vidět. Vstup si
klidně vygeneruj náhodně a změř si čas. Jestli kvůli tomu odevzdáš dva
programy místo jednoho, nevadí, jen to napiš do `README`.

### Bonus (nepovinný)

Smíš nejvýš jeden libovolný sloupec zvýšit o 1. Který si vybereš, aby v horách
zůstalo co nejvíc vody, a o kolik si polepšíš? Když nepomůže žádné zvýšení,
ať to program řekne.

U bonusu stačí, když řešení funguje do 1 000 sloupců.

## Co odevzdat

Pošli na <lubos.zapotocny@delta-skola.cz> ZIP archiv, ve kterém bude:

1. Zdrojové kódy tvého programu.
2. Soubor `README` (stačí textový) a v něm:
   - jak se program přeloží a spustí,
   - kterou nejvyšší úroveň máš hotovou,
   - pár vět vlastními slovy o tom, jak řešení funguje a jak tě napadlo,
   - u úrovně 3 taky to, proč je dost rychlé.

Do archivu patří jenom zdrojové kódy a `README`, celý má mít nejvýš pár
megabajtů. Podrobnosti k odevzdávání najdeš na [stránce registrace](readme.md).

## Jak to hodnotíme

| Kritérium | Co sledujeme |
|---|---|
| Funguje to | Program doběhne a spočítá správný výsledek. |
| Mezní případy | Program počítá správně i pro terény, které vypadají nezvykle. Napadlo tě, jaké to jsou? |
| Dosažená úroveň | Kam až ses dostal. Úroveň 3 ukazuje algoritmické myšlení. |
| Srozumitelnost kódu | Rozumné názvy, rozdělení na funkce, žádný pětkrát zkopírovaný kus kódu. |
| Vysvětlení v README | Umíš popsat svůj postup a víš, proč funguje. |
| Ošetření vstupu | Co program udělá, když mu někdo zadá něco, co terén vůbec není. |

## Poznámky

- Programovací jazyk je na tobě. C, C++, C#, Java, Python, JavaScript,
  cokoliv, co umíme spustit. Napiš do `README`, jak na to.
- Formát vstupu a výstupu je taky na tobě, žádný přesný tvar dodržovat nemusíš.
  Program se může ptát, vypisovat menu nebo načítat ze souboru, jak chceš.
  Počítáme jen s tím, že uživatel něco zadá a na výstupu uvidí výsledek.
- Posílej hotovou a funkční verzi, ne rozpracované kusy. Když s odevzdaným
  řešením něco nebude v pořádku, ozveme se ti e-mailem a doladíme to spolu.
  Počet pokusů omezený není.
- Když si nebudeš vědět rady se zadáním (se zadáním, ne s řešením), napiš.
- Pravidla registrace a odpovědi na časté dotazy najdeš na
  [stránce registrace](readme.md).
