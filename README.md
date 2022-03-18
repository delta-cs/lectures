# DELTA SŠIE - Lekce

- [DELTA SŠIE - Lekce](#delta-sšie---lekce)
  - [Teoretická informatika](#teoretická-informatika)
    - [Osnova přednášek](#osnova-přednášek)
  - [Praktický seminář](#praktický-seminář)
    - [Osnovy individuálních projektů](#osnovy-individuálních-projektů)
      - [Fullstack webová aplikace](#fullstack-webová-aplikace)
      - [Devops](#devops)
      - [Praktické programování v jazyce Java](#praktické-programování-v-jazyce-java)
      - [Praktické programování v PHP](#praktické-programování-v-php)
      - [Hands-on metody strojového učení](#hands-on-metody-strojového-učení)
      - [Hands-on metody kryptografie](#hands-on-metody-kryptografie)

## Teoretická informatika

### Osnova přednášek

| #   | Téma                                                                                                                                                                               |
| --- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 0   | [Úvod do programu Delta TopGun, úvod do kurzu Teoretická informatika, úvod do kurzu Praktický seminář](00_uvod)                                                                    |
| 1   | [První kód v C, kompilace, datové typy, zpracování vstupu a výstupu (scanf, printf), kontrola validity vstupu, formátování výstupu, debugging](01_uvod_do_programovaciho_jazyka_c) |
| 2   | [Reprezentace čísel v počítači (celočíselné, s plovoucí čárkou), problematika čísel se znaménkem (doplňkový/aditivní/přímý kód), bitwise](02_reprezentace_cisel_v_pocitaci)        |
| 3   | [Pole a paměť, segmentace paměti, základní alokace paměti, průchody polem, segmentation fault, řetězce znaků (null character), kopírování řetězců](03_pole_a_pamet)                           |
| 4   | Reprezentace datových struktur v paměti. Asymptotická složitost, rozdíly mezi omikron, omega, theta, ukázky algoritmů a jejich složitostí                                          |
| 5   | Sorting algoritmy - insertion, selection, bubble, quick sort                                                                                                                       |
| 6   | Paměť - Stack vs Heap, referenční a hodnotové předávání parametrů (pointery), garbage collector, manuální správa paměti, efektivita programu z pohledu cache pamětí                |
| 7   | Dynamické pole, asymptotická vs amortizovaná složitost                                                                                                                             |
| 8   | Spojový seznam - základní operace (vkládání, mazání, průchod seznamem), obousměrně zřetězené a kruhově zřetězené seznamy a jejich aplikace                                         |
| 9   | Rekurze - koncová vs nekoncová rekurze, rozděl a panuj                                                                                                                             |
| 10  | Stromové struktury, LCA (nejbližší společný předek)                                                                                                                                |
| 11  | Vyhledávaci stromy - BVS (binární vyhledávací strom)                                                                                                                               |
| 12  | AVL stromy - definice, algoritmus na vyvažování                                                                                                                                    |
| 13  | Grafy - zobecnění předchozích témat                                                                                                                                                |
| 14  | Zásobník, Fronta - využití, fifo, lifo                                                                                                                                             |
| 15  | Průchody grafem - in/out/pre order průchod stromem, BFS, DFS                                                                                                                       |
| 16  | Datová struktura binární minimová halda, heapsort algoritmus                                                                                                                       |
| 17  | Hledání nejkratší cesty v grafu - BFS, Dijkstrův algoritmus, Bellman-Ford algoritmus                                                                                               |

## Praktický seminář

### Osnovy individuálních projektů

#### Fullstack webová aplikace

| #   | Fullstack webová aplikace                                                                                                           |
| --- | ----------------------------------------------------------------------------------------------------------------------------------- |
| 1   | Rámcový návrh a analýza aplikace                                                                                                    |
| 2   | Databázový model a nastavení databáze                                                                                               |
| 3   | Realizace REST/GraphQL API (Java/PHP/Node.js)                                                                                       |
| 4   | Realizace webového frontend rozhraní (JavaScript (vanilla)/React.js/Vue.js) (případně možnost realizovat hybridní mobilní aplikaci) |
| 5   | Automatizované otestování aplikace (unit, e2e)                                                                                      |
| 6   | Optimalizace výkonnosti webové aplikace                                                                                             |
| 7   | Deployment aplikace (možnost spojit s osnovou “Docker/devops”)                                                                      |

#### Devops

| #   | Devops                                         |
| --- | ---------------------------------------------- |
| 1   | Containerizace, co to je a k čemu se dá využít |
| 2   | Docker, docker-compose                         |
| 3   | CI                                             |
| 4   | Clusters, Docker swarm (monitoring, logging)   |
| 5   | Cloud - AWS (alerts, budgets)                  |
| 6   | Deployment webové aplikace                     |

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

#### Hands-on metody strojového učení

| #   | Hands-on metody strojového učení                                                                                                                                               |
| --- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| 1   | Systémy strojového učení                                                                                                                                                       |
| 2   | Úvod do jazyka Python - práce s realnými daty (předzpracování, vizualizace)                                                                                                    |
| 3   | Vybrané metody strojového učení: Rozhodovací stromy, náhodné lesy                                                                                                              |
| 4   | Evaluace modelů                                                                                                                                                                |
| 5   | Vybrané metody strojového učení: Shlukování                                                                                                                                    |
| 6   | Vybrané metody strojového učení: Lineární regrese, logistická regrese, metoda největšího spádu                                                                                 |
| 7   | Vybrané metody strojového učení: Umělé neuronové sítě a jejich architektury                                                                                                    |
| 8   | Recenze vědeckého článku                                                                                                                                                       |
| 9   | End-to-end machine-learning projekt (analýza a předpoklady problému, získání dat, předzpracování dat a vizualizace, selekce modelu, trénování modelu, fine-tuning, deployment) |

#### Hands-on metody kryptografie

| #   | Hands-on metody kryptografie                              |
| --- | --------------------------------------------------------- |
| 1   | Historické kryprografické systémy                         |
| 2   | Zřízení společného klíče                                  |
| 3   | Hašovací funkce                                           |
| 4   | Blokové šifrování a operační módy blokových šifer         |
| 5   | Asymetrická kryptografie - kryptografie s veřejným klíčem |
