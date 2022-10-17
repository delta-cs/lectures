# DELTA SŠIE - TopGun
Talentový program [DELTA TopGun](https://www.delta-skola.cz/talentovy-program-delta-topgun) jsme založili, abychom dokázali v programátorských dovednostech efektivně posouvat i zkušené programátory.

![DELTA TopGun poster](/assets/logo.jpg)
## Sylabus kurzu *Teoretická* *informatika*

### Osnova přednášek

| #   | Téma                                                                                                                                                                               |
| --- |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 0   | [Úvod do programu Delta TopGun, úvod do kurzu Teoretická informatika, úvod do kurzu Praktický seminář](00_uvod)                                                                    |
| 1   | [První kód v C, kompilace, datové typy, zpracování vstupu a výstupu (scanf, printf), kontrola validity vstupu, formátování výstupu, debugging](01_uvod_do_programovaciho_jazyka_c) |
| 2   | [Reprezentace čísel v počítači (celočíselné, s plovoucí čárkou), problematika čísel se znaménkem (doplňkový/aditivní/přímý kód), bitwise](02_reprezentace_cisel_v_pocitaci)        |
| 3   | [Pole a paměť, segmentace paměti, základní alokace paměti, průchody polem, segmentation fault, řetězce znaků (null character), kopírování řetězců](03_pole_a_pamet)                |
| 4   | [Reprezentace datových struktur v paměti. Asymptotická složitost, rozdíly mezi omikron, omega, theta, ukázky algoritmů a jejich složitostí](04_slozitost_a_tridici_algoritmy)      |
| 5   | [Sorting algoritmy - insertion, selection, bubble, quick sort](04_slozitost_a_tridici_algoritmy)                                                                                   |
| 6   | Paměť - Stack vs Heap, referenční a hodnotové předávání parametrů (pointery), garbage collector, manuální správa paměti, efektivita programu z pohledu cache pamětí                |
| 7   | Dynamické pole, asymptotická vs amortizovaná složitost                                                                                                                             |
| 8   | [Spojový seznam - základní operace (vkládání, mazání, průchod seznamem), obousměrně zřetězené a kruhově zřetězené seznamy a jejich aplikace](05_spojovy_seznam)                    |
| 9   | [Rekurze - koncová vs nekoncová rekurze, rozděl a panuj](06_rekurze)                                                                                                               |
| 10  | [Stromové struktury](07_stromove_struktury)                                                                                                                                        |
| 11  | [Vyhledávaci stromy - BVS (binární vyhledávací strom)](08_binarni_vyhledavaci_strom)                                                                                               |
| 12  | [AVL stromy - definice, algoritmus na vyvažování](09_vyvazene_stromy)                                                                                                              |
| 13  | [Grafy - zobecnění předchozích témat](10_uvod_do_teorie_grafu)                                                                                                                                                
| 14  | [Zásobník, Fronta - využití, fifo, lifo](11_pruchody_grafem)                                                                                                                                             
| 15  | [Průchody grafem - in/out/pre order průchod stromem, BFS, DFS](11_pruchody_grafem)                                                                                                                     
| 16  | Datová struktura binární minimová halda, heapsort algoritmus                                                                                                                       |
| 17  | Hledání nejkratší cesty v grafu - BFS, Dijkstrův algoritmus, Bellman-Ford algoritmus                                                                                               |

## Sylabus kurzu *Praktický projekt*
### Zaměření kurzu
Kurz *Praktický projekt* nabízí studentovi příležitost věnovat se realizaci softwarového projektu v konkrétní oblasti vlastního zájmu. Každý student má k dispozici lektora, pod jehož vedením svůj projekt zpracovává. Od každého studenta je očekáván návrh zadání individuálního projektu a jeho následné zpracování. Praktický kurz je rovněž jednou za 3 týdny proložen workshopem (prezenčně ve škole), který je věnován konkrétní problematice z oboru (viz [Harmonogram praktických workshopů](#harmonogram-praktických-workshopů)).

### Párování student × lektor – Pitch Day
Párování studenta s lektorem je vyhodnoceno na základě průniku zaměření studentova projektu a oblasti zájmu lektora. Párování proběhne v reakci na tzv. Pitch Day – nultou hodinu kurzu, kdy studenti prezentují své projektové záměry a lektoři poskytují zpětnou vazbu. Datum konání Pitch Day je v každém ročníku individuální a bude komunikováno s dostatečným předstihem.

### Povinnosti zapsaných studentů
1. Odprezentovat svůj projektový záměr (viz [Náležitosti projektového záměru](#náležitosti-projektového-záměru))
2. Absolvovat úvodní schůzku s přiděleným lektorem
3. Každý pracovní den zapisovat svou aktivitu do on-line journalu (viz [Náležitosti každodenního zápisu do on-line journalu](#náležitosti-každodenního-zápisu-do-on-line-journalu))
4. Vypracovat rámcovou analýzu softwarového projektu (viz [Náležitosti rámcové analýzy](#náležitosti-rámcové-analýzy))
5. Vypracovat projektovou roadmapu
6. Průběžně (minimálně však jednou za týden) s lektorem konzultovat aktuální stav projektu, řešené problémy a plán dalšího postupu (periodicita konzultací a jejich forma je v kompetenci lektora)
7. Před každým praktických workshopem veřejně odprezentovat svůj postup – tzv. *status update* (viz [Náležitosti "status update"](#náležitosti-status-update))
8. Pravidelně (minimálně však jednou za týden) lektorovi odeslat *pull-request* ke code-review (periodicita code-review a jejich forma je v kompetenci lektora)
9. Pravidelně (minimálně však jednou za týden) poskytnout code-review projektu spolužáka (bude přihlédnuto k přidruženosti technologického stacku)
10. Pravidelně kód praktického projektu verzovat dle lektorem doporučené verzovací strategie

### Neplnění povinností kurzu
Při opakovaném neplnění [Povinnosti zapsaných studentů](#povinnosti-zapsaných-studentů) bude přistoupeno k vyřazení studenta z programu. A to zejména v následujích případech:
- Student, bez předchozí omluvy, během školního pololetí 5x nezapsal aktivitu do on-line journalu (viz [Náležitosti každodenního zápisu do on-line journalu](#náležitosti-každodenního-zápisu-do-on-line-journalu))
- Student, bez předchozí omluvy, během školního pololetí 2x neodprezentoval *status update* dle náležitostí (viz [Náležitosti "status update"](#náležitosti-status-update))
- Student, bez předchozí omluvy, 3x neodeslal lektorovi pull-request ke code-review
- Student, bez předchozí omluvy, 3x neposkytnul code-review přidruženému projektu
- Student, bez předchozí omluvy, 2x nereaguje na výzvu lektora ohledně nenaplnění cíle, který si student sám stanovil během *status update*


#### Náležitosti projektového záměru
Jedno z "Realizace vlastního projektu", "Realizace projektu pro rozvoj školního ekosystému", "Realizace modelového projektu".
-- tba
#### Náležitosti rámcové analýzy
-- tba
#### Náležitosti každodenního zápisu do on-line journalu
Student každý pracovní den do on-line journalu zapíše, čemu se daný den v rámci svého praktického projektu věnoval. Je naprosto v pořádku, když se student v daném dnu praktickému projektu nevěnoval vůbec, tuto skutečnsot však rovněž musí do on-line journalu zapsat. Zápisy do on-line journalu poskytují lektorům nástroj, jakým dodatečně vyhodnotit aktivitu studentů. Zápisy do on-line journalu probíhají na platformě Discord, kam je na dedikovaného server každý student při začátku programu přizván.
#### Náležitosti "status update"
Během *status update* student nejprve **živě** odprezentuje dosavadní výsledek svého softwarového projektu a ukáže jeho historii verzování. Následně stručně odpoví a vyhodnotí následující otázky:

- *Splnil jsem cíl, který jsem si na uplynulé 3 týdny stanovil?*
- *Cíl jsem nesplnil. Jaké chyby jsem udělal? Jak se z nich příště poučím?*
- *Cíl jsem splnil. Co se mi povedlo a budu v tom nadále pokračovat?*
- *Jaký cíl plánuji splnit v následujících 3 týdnech? Jaká je jeho hlavní náplň a jak budu postupovat k jeho dosažení?*
  
### Realizace vlastního projektu
-- tba
### Realizace projektu pro rozvoj školního ekosystému
-- tba
### Realizace modelového projektu
#### Osnovy pro modelová zadání projektů
#### Fullstack webová aplikace

| #   | Fullstack webová aplikace                                                                                                           |
| --- | ----------------------------------------------------------------------------------------------------------------------------------- |
| 1   | Rámcový návrh a analýza aplikace                                                                                                    |
| 2   | Databázový model a nastavení databáze                                                                                               |
| 3   | Realizace REST/GraphQL API (Java/PHP/Node.js)                                                                                       |
| 4   | Realizace webového frontend rozhraní (JavaScript (vanilla)/React.js/Vue.js) (případně možnost realizovat hybridní mobilní aplikaci) |
| 5   | Automatizované otestování aplikace (unit, e2e)                                                                                      |
| 6   | Optimalizace výkonnosti webové aplikace                                                                                             |
| 7   | Deployment aplikace                                                                   |


#### Praktické programování v jazyce Java

| #   | Praktické programování v jazyce Java                                          |
| --- | ----------------------------------------------------------------------------- |
| 1   | Základní syntaxe                                                              |
| 2   | Build a správa závislostí - Maven                                             |
| 3   | Objektově orientované programování (polymorfismus, rozhraní)                  |
| 4   | Datové struktury                                                              |
| 5   | Automatizované unit testy, ladění aplikací (debugging)                        |
| 6   | Práce s relační databází, mapování objektů do relačních databází              |
| 7   | Návrhové vzory a principy                                                     |
| 8   | Objektově orientovaná analýza a návrh - charakteristika UML, přehled diagramů |
| 9   | Praktický projekt - REST API/CLI aplikace                                     |

#### Praktické programování v PHP

| #   | Praktické programování v PHP                     |
| --- | ------------------------------------------------ |
| 1   | Základní syntaxe a Xdebug                        |
| 2   | Objektově orientované programování v PHP         |
| 3   | Správa externích závislostí – composer           |
| 4   | Persistence dat                                  |
| 5   | Automatické testování aplikace – unit testy      |
| 6   | Tvorba jednoduchého webu – PHP+HTML+CSS          |
| 7   | Tvorba REST API                                  |
| 8   | Tvorba modulů a pluginů do existujících projektů |


### Harmonogram praktických workshopů
| # | Datum        | Téma                            | Lektor         |
|---|--------------|---------------------------------|----------------|
| 1 | 18. 10. 2022 | Úvod do verzovacího systému git | Michal Havelka |