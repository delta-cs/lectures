# Objektová úloha: Rezervace v kině

> Vstupní úloha do programu DELTA TopGun.
> Chytrý algoritmus k ní znát nemusíš. Program ale musí být napsaný objektově
> a nejvíc času ti zabere rozmyslet si, jak ho rozvrhnout do tříd.
>
> Odevzdat je potřeba do **28. září 2026, 23:59:59**.

## Příběh

Kino DELTA má dva sály a v každém běží několik projekcí denně. Rezervace si
pokladní zatím zapisuje na papír a nedávno se to vymstilo: dvě rodiny seděly na
stejných místech a promítání kvůli tomu začalo o dvacet minut později.

Napiš program, který to pohlídá za ni.

## Co má program umět

Program je konzolová aplikace, kterou obsluhuje pokladní. Musí umět:

- vypsat, co se dnes hraje, kdy a ve kterém sále,
- ukázat u vybrané projekce, která místa jsou volná a která obsazená,
- zarezervovat konkrétní místo na konkrétní projekci pro zákazníka,
- zrušit rezervaci a uvolnit tím místo.

Sály se liší velikostí. Řady se značí písmeny, místa v řadě čísly, a sál je
obdélník, takže všechny řady jsou stejně dlouhé. Všechny projekce jsou z dnešního
dne, datem se zabývat nemusíš.

Data o filmech, sálech a projekcích si nastav rovnou v kódu, žádné soubory kvůli
tomu vymýšlet nemusíš. Jak se rezervace označuje, když ji pokladní ruší, si
vymysli taky.

## Jak to má být napsané

Tohle je objektová úloha, takže **program musí být napsaný objektově**. Je to
podmínka, ne doporučení. Řešení, kde je všechno v jedné dlouhé funkci nebo
v sadě globálních proměnných a funkcí nad nimi, neuznáme, i kdyby fungovalo
bezchybně.

Znamená to, že věci ze světa kina mají v programu svoje třídy. Každá si drží
svoje data a sama hlídá, co se s nimi smí dělat. Které třídy to budou a jak si
mezi ně rozdělíš práci, je na tobě, a je to zároveň to hlavní, co na odevzdaném
řešení hodnotíme.

Pozor na opačný extrém. Rozsekat program na patnáct tříd, které si jen podávají
data dál a samy o ničem nerozhodují, je stejná chyba jako jedna velká funkce.
Třída, která se jmenuje `SpravceRezervaci` a umí jediné, totiž uložit rezervaci
do seznamu, nic nevyřešila, jen přejmenovala.

Nejpřísněji se díváme na části, které drží data kina. Menu a výpisy do konzole
můžou být jednodušší.

Jestli je pro tebe třída nová věc, nauč se to teď. Budeš ji potřebovat hned na
začátku programu.

### Jak to může vypadat

Podoba výpisů i ovládání je na tobě, tahle ukázka je jenom pro představu.
V plánku sálu je tečka volné místo a `X` obsazené.

```
=== Kino DELTA ===
1) Program kina
2) Rezervovat
3) Zrušit rezervaci
0) Konec
> 1

Dnes hrajeme:
  1   15:30   Sál 2   Vetřelec
  2   18:00   Sál 1   Duna
  3   20:30   Sál 1   Přijede k nám návštěva

> 2
Číslo projekce: 2

Sál 1, 18:00, Duna
      123456789
  A   ..X......
  B   ...XX....
  C   .........

Místo (např. A1): B7
Jméno zákazníka: Nováková
Rezervováno.
```

## Úrovně

Úloha je rozdělená na úrovně. Každá vyšší zahrnuje všechny předchozí.
Odevzdej tu nejvyšší, kterou zvládneš. I samotná úroveň 1 je platné odevzdání.

### Úroveň 1 – Ať to funguje

Program umí všechny čtyři věci ze seznamu výše a je rozdělený do tříd. Jedno
místo přitom nesmí jít rezervovat dvakrát, kvůli tomu celý program vzniká.

Rezervace vydrží po dobu běhu programu, po ukončení se na ně může zapomenout.

### Úroveň 2 – Ať to nejde rozbít

Přibude pátá funkce: vypsat všechny rezervace jednoho zákazníka.

Pokladní je navíc unavená a občas se překlepne. Program musí ustát i tohle:

- místo, které v sále vůbec neexistuje,
- projekce, která není v nabídce,
- rušení rezervace, která nikdy nevznikla,
- prázdný vstup a písmena tam, kde se čeká číslo.

Rozmysli si, co dalšího může pokladní zadat špatně.

### Úroveň 3 – Ať se to dá změnit

Majitel kina si vzpomněl na dvě věci najednou:

1. Místa nejsou stejná. V posledních dvou řadách jsou pohodlnější křesla
   a v sále 2 je navíc balkon, což je oddělená část s vlastními řadami.
   Každé místo patří právě do jednoho druhu a každý druh stojí jinak.
2. Zákazníci chtějí slevy. Studenti platí míň, děti mladší šesti let mají
   vstup zdarma a na projekce, které začínají před 17:00, je sleva pro všechny.
   U rezervace se proto pokladní musí zeptat i na to, kdo zákazník je.

Doplň obojí a u rezervace rovnou ukaž, kolik to bude stát.

Konkrétní ceny a slevy si vymysli. Rozmysli si taky, co platí, když se na jednu
rezervaci hodí víc slev najednou, a napiš to do `README`.

Zajímá nás přitom hlavně jedna věc: **která místa v programu jsi kvůli tomu
musel otevřít a přepsat.** Napiš to do `README` na rovinu. Právě tady se ukáže,
jak dobře máš program rozvržený.

A ještě jedna otázka na závěr, tuhle změnu už ale **neděláš**. Kino chce zavést
permanentky: zákazník zaplatí měsíční paušál a jednotlivé rezervace má pak
zdarma. Rozmysli si, které části svého programu bys kvůli tomu musel otevřít,
a napiš to do `README`. Nic neprogramuj, stačí odpověď.

### Bonus (nepovinný)

Rodina chce čtyři volná místa vedle sebe v jedné řadě. Ať je program najde sám
a nabídne, rezervovat je nemusí. Podle čeho vybere nejlepší čtveřici, když jich
je víc, je na tobě, jen to napiš do `README`.

Bonus nehodnotíme zvlášť, je to téma na povídání e-mailem.

## Co odevzdat

Pošli na <lubos.zapotocny@delta-skola.cz> ZIP archiv, ve kterém bude:

1. Zdrojové kódy tvého programu.
2. Soubor `README` (stačí textový) a v něm:
   - jak se program přeloží a spustí,
   - kterou nejvyšší úroveň máš hotovou,
   - na jaké části je program rozdělený a proč zrovna takhle,
   - u úrovně 3 taky to, která místa se kvůli ní musela přepsat, a odpověď
     na otázku s permanentkami,
   - k čemu jsi případně použil umělou inteligenci.

Do archivu patří jenom zdrojové kódy a `README`, celý má mít nejvýš pár
megabajtů. Podrobnosti k odevzdávání najdeš na [stránce registrace](readme.md).

## Jak to hodnotíme

| Kritérium | Co sledujeme |
|---|---|
| Objektový návrh | Program je opravdu rozdělený do tříd. Bez toho ho dál nehodnotíme. |
| Funguje to | Program dělá, co má, a dá se ovládat. |
| Rozdělení odpovědností | Každá třída má jednu jasnou úlohu, z názvu jde poznat, co dělá, a je vidět, co z nich rozhoduje o tom, jestli rezervace projde. Ani jedna není prázdná schránka na data. |
| Odolnost | Program nespadne na překlepu ani na nesmyslném vstupu. |
| Snadnost změny | Kolik míst v programu bylo nutné otevřít kvůli úrovni 3 a jestli odpověď o permanentkách sedí s tím, jak je program napsaný. |
| Vysvětlení v README | Umíš zdůvodnit, proč je program rozdělený zrovna takhle. |

Hodnotíme jen to, co odpovídá odevzdané úrovni.

## Poznámky

- Programovací jazyk je na tobě, ale musí umět třídy. C++, C#, Java, Python,
  JavaScript a podobně. Napiš do `README`, jak se program přeloží a spustí.
- Formát vstupu a výstupu je taky na tobě, žádný přesný tvar dodržovat nemusíš.
- Rozvržení programu na části je celé na tobě, s tím ti radit nebudeme.
- Posílej hotovou a funkční verzi, ne rozpracované kusy. Když s odevzdaným
  řešením něco nebude v pořádku, ozveme se ti e-mailem a doladíme to spolu.
  Počet pokusů omezený není.
- Když si nebudeš vědět rady se zadáním (se zadáním, ne s řešením), napiš.
