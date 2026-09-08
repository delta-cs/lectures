# Algoritmická úloha: Kolik vody zůstane v horách

> Vstupní úloha do programu DELTA TopGun.
> Žádné chytré algoritmy k ní znát nemusíš, vystačíš si s polem, cyklem
> a podmínkou. Přemýšlet ale budeš muset.
>
> Odevzdat je potřeba do **28. září 2026, 23:59:59**.

## Příběh

Za školou se táhne pohoří. Zjednodušeně se dá popsat jako řada různě vysokých
sloupců, něco jako sloupcový graf.

V noci začne pršet. Prší dlouho a vydatně, takže se voda zachytí ve všech
prohlubních. Přebytečná voda přeteče přes okraje pohoří a odteče pryč.

Ráno tě zajímá, kolik vody v horách zůstalo.

## Co přesně počítáme

Terén je popsaný posloupností nezáporných celých čísel, což jsou výšky sloupců
zleva doprava. Žádná hora není vyšší než tisíc jednotek. Každý sloupec je široký
1, takže množství vody nad jedním sloupcem se rovná výšce vody, která nad ním
stojí.

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

Rozpis po sloupcích je jen vysvětlení, program ho vypisovat nemusí.

- Nad prvním sloupcem (výška 3) voda nezůstane.
- Nad druhým (výška 0) sahá voda do výšky 3, tedy 3 jednotky.
- Nad třetím (výška 2) sahá voda do výšky 3, tedy 1 jednotka.
- Nad čtvrtým (výška 0) sahá voda do výšky 3, tedy 3 jednotky.
- Nad pátým (výška 4) voda nezůstane.

Celkem tedy 7 jednotek vody.

Na ověření si vezmi ještě druhý terén, u kterého prozradíme jenom výsledek:
`5 1 0 2 0 4 0 3` zadrží **16 jednotek**. Když ti u něj vyjde něco jiného,
máš v úvaze chybu, přestože ti první ukázka vyšla správně.

## Úrovně

Úloha je rozdělená na úrovně. Úroveň 1 je základ, na kterém stojí všechno
ostatní. Úrovně 2 a 3 jsou na sobě nezávislé, takže se do nich můžeš pustit
v libovolném pořadí, klidně i každou zvlášť.

Odevzdej, co máš. I samotná úroveň 1 je platné odevzdání a úroveň 3 bez
kreslení taky.

### Úroveň 1 – Spočítej to

Program si od uživatele vyžádá terén (klidně jen pár čísel oddělených mezerou)
a vypíše, kolik vody v něm zůstane. Jestli ti to usnadní práci, můžeš jako první
číslo chtít počet sloupců.

Musí správně počítat i pro terény, které vypadají nezvykle. Rozmysli si, které
to jsou.

A nesmí spadnout, ani když mu někdo zadá něco, co terén vůbec není.

### Úroveň 2 – Nakresli to

Program terén i vodu vykreslí podobně jako v ukázce výše:

- `#` = skála
- `~` = voda
- mezera = vzduch

Kreslí se odshora dolů a výška obrázku odpovídá nejvyššímu sloupci. Kreslení
stačí do zhruba třiceti sloupců a výšky třicet, větší obrázek se do konzole
stejně nevejde.

Není to algoritmicky těžké, je to práce s výstupem. Za obrázek si ale sám
zkontroluješ, jestli ti výpočet sedí.

### Úroveň 3 – Zvládni velké pohoří

Program musí zvládnout **1 000 000 sloupců do jedné sekundy** na běžném
notebooku. Měří se samotný výpočet, ne vyrobení ani načtení vstupu.

Do `README` k tomu napiš, **kolikrát tvůj program projde terénem a proč to
stačí**. Tahle věta nás zajímá víc než naměřený čas, protože nezávisí na tom,
jak rychlý počítač zrovna máš.

Kreslit v téhle úrovni nemusí, milion sloupců stejně není vidět. Vstup si
vygeneruj náhodně a změř si čas; generátor přilož k odevzdání, je to taky
zdroják. Jestli kvůli tomu odevzdáš dva programy místo jednoho, nevadí, jen to
napiš do `README`.

### Bonus (nepovinný)

Smíš nejvýš jeden libovolný sloupec zvýšit o 1. Který si vybereš, aby v horách
zůstalo co nejvíc vody, a o kolik si polepšíš? Když je stejně dobrých sloupců
víc, stačí vypsat jeden. Zvýšení, po kterém by vody ubylo, nemá cenu dělat,
takže když žádné nepomůže, ať to program řekne.

U bonusu stačí, když řešení funguje do 1 000 sloupců.

## Co odevzdat

Pošli na <lubos.zapotocny@delta-skola.cz> ZIP archiv, ve kterém bude:

1. Zdrojové kódy tvého programu.
2. Soubor `README` (stačí textový) a v něm:
   - jak se program přeloží a spustí,
   - kterou nejvyšší úroveň máš hotovou a jestli máš hotový bonus,
   - pár vět vlastními slovy o tom, jak řešení funguje a jak tě napadlo
     (a jestli jsi tuhle úlohu už někde viděl, napiš to, nevadí to),
   - u úrovně 3 kolikrát program projde terénem a proč to stačí,
   - k čemu jsi případně použil umělou inteligenci.

Do archivu patří jenom zdrojové kódy a `README`, celý má mít nejvýš pár
megabajtů. Podrobnosti k odevzdávání najdeš na [stránce registrace](readme.md).

## Jak to hodnotíme

| Kritérium | Co sledujeme |
|---|---|
| Funguje to | Program doběhne a spočítá správný výsledek. |
| Nezvyklé terény | Program počítá správně i pro terény, které vypadají nezvykle. Přišel jsi na to, které to jsou? |
| Dosažená úroveň | Kam až se ti povedlo dojít. Úroveň 3 ukazuje algoritmické myšlení. |
| Srozumitelnost kódu | Rozumné názvy, rozdělení na funkce, žádný pětkrát zkopírovaný kus kódu. |
| Vysvětlení v README | Umíš popsat svůj postup a víš, proč funguje. |
| Vadný vstup | Co program udělá, když mu někdo zadá něco, co terén vůbec není. |

## Poznámky

- Programovací jazyk je na tobě. C, C++, C#, Java, Python, JavaScript,
  cokoliv, co umíme spustit. Napiš do `README`, jak na to.
- Formát vstupu a výstupu je taky na tobě, žádný přesný tvar dodržovat nemusíš.
  Program se může ptát, vypisovat menu nebo načítat ze souboru, jak chceš.
  Počítáme jen s tím, že uživatel něco zadá a na výstupu uvidí výsledek.
- Posílej hotovou a funkční verzi, ne rozpracované kusy. Když s odevzdaným
  řešením něco nebude v pořádku, ozveme se ti e-mailem a doladíme to spolu.
  Počet pokusů omezený není.
- Když si nebudeš vědět rady se zadáním (se zadáním, ne s řešením), napiš na
  <lubos.zapotocny@delta-skola.cz>.
- Pravidla registrace a odpovědi na časté dotazy najdeš na
  [stránce registrace](readme.md).
