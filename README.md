# Talentový program DELTA TopGun

> **Registrce pro ročník 2025 je otevřena!**
>
> Více informací o registraci naleznete na [této stránce](registrace).

Talentový program [DELTA TopGun](https://www.delta-skola.cz/talentovy-program-delta-topgun)
jsme založili pro žáky, kteří se chtějí věnovat programování a informatice do (velké) hloubky.

Je nutné míti základní znalosti programování a být ochoten se učit novým věcem.

![DELTA TopGun poster](/misc/poster.jpg)

- [Forma výuky](#forma-vyuky)
- [Rozvrh výuky](#rozvrh-vyuky)
- [Teoretická informatika](#teoreticka-informatika)
    - [Zaměření](#teoreticka-informatika-zamereni)
    - [Přednášky](#teoreticka-informatika-prednasky)
- [Praktický seminář](#prakticky-seminar)
    - [Zaměření](#prakticky-seminar-zamereni)
- [Individuální projekt](#individualni-projekt)
    - [Párování žák × lektor](#parovani-zak-lektor)
    - [Náležitosti projektu](#nalezitosti-projektu)
    - [Status update](#status-update)
    - [Vlastní projekt](#vlastni-projekt)
    - [Projekt pro rozvoj školního ekosystému](#projekt-pro-rozvoj-skolniho-ekosystemu)
    - [Modelový projekt](#modelovy-projekt)
- [Povinnosti zapsaných žáků](#povinnosti-zapsanych-zaku)
- [Neplnění povinností](#neplneni-povinnosti)

## <a name="forma-vyuky"></a> Forma výuky

V rámci programu jsou vyučovány dva kurzy, které jsou pro žáky povinné

- [Teoretická informatika](#teoreticka-informatika)
- [Praktický seminář](#prakticky-seminar)

a žáci také musí pracovat na [individuálním projektu](#individualni-projekt).

Výuka se koná **prezenčně** v režimu **2:1**.
Dva po sobě jdoucí týdny jsou přednášky či cvičení z teoretické informatiky
následované jednou hodinou praktického semináře.

## <a name="rozvrh-vyuky"></a> Rozvrh výuky

Rozvrh **prezenční výuky** a **přednášek** je dostupný
[v kalendáři](https://calendar.google.com/calendar/embed?src=c_779afeb876628db383ca6a9e89a3ffaf3891f7b8b2f59ce4eab9709a37e9df03%40group.calendar.google.com&ctz=Europe%2FPrague).

## <a name="teoreticka-informatika"></a> Teoretická informatika

### <a name="teoreticka-informatika-zamereni"></a> Zaměření

Kurz teoretické informatiky obsahuje některé vybrané oblasti teoretické informatiky a snaží se žákům přiblížit
základní principy a algoritmy, které jsou v informatice důležité a využívané.

Kurz je zaměřen na základní znalosti nízkoúrovňového programování
a na principy řešení algoritmicky zajímavých problémů a úloh.
Důraz je kladen na budování intuice při řešení algoritmických problémů a uchopení základních principú počítačové vědy.

Po dokončení jednotlivých témat teoretické informatiky dostávají žáci programovací úkol
na platformě [DOMJudge](https://domjudge.delta-topgun.cz), do které dostanou přístup na začátku programu.

[Dockerfile](misc/Dockerfile) můžete použít pro lokální vývoj v jazyce C s potřebnými nástroji a knihovnami.

Tyto úlohy jsou zaměřeny na procvičení daného tématu a na získání praktických dovedností s programováním v jazyce C.

Systém automaticky kontroluje správnost řešení
a v případě neúspěšného řešení může žák kontaktovat přednášejícího a konzultovat své řešení.

### <a name="teoreticka-informatika-prednasky"></a> Přednášky

| #  | Téma                                                                                                                                                            |
|----|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 0  | [Představení programu Delta TopGun, kurzu teoretické informatiky a kurzu praktického semináře](teoreticka/00_uvod)                                              |
| 1  | [Překlad programu v C, datové typy, zpracování vstupu a výstupu, kontrola validity vstupu a formátování výstupu](teoreticka/01_uvod_do_programovaciho_jazyka_c) |
| 2  | [Reprezentace čísel v počítači, kódování čísel se znaménkem a bitové operace](teoreticka/02_reprezentace_cisel_v_pocitaci)                                      |
| 3  | [Pole a jeho reprezentace v paměti, řetězce a segmentace paměti](teoreticka/03_pole_a_pamet)                                                                    |
| 4  | [Reprezentace datových struktur v paměti, asymptotická složitost, ukázky algoritmů a jejich složitostí](teoreticka/04_slozitost_a_tridici_algoritmy)            |
| 5  | [Spojový seznam, operace se spojovým seznamem, obousměrně a kruhově zřetězený seznam](teoreticka/05_spojovy_seznam)                                             |
| 6  | [Rekurze, rodíl mezi koncovou a nekoncovou rekurzí a algoritmy rozděl a panuj](teoreticka/06_rekurze)                                                           |
| 7  | [Stromové struktury](teoreticka/07_stromove_struktury)                                                                                                          |
| 8  | [Vyhledávací strom a binární vyhledávací strom](teoreticka/08_binarni_vyhledavaci_strom)                                                                        |
| 9  | [Vyvážený vyhledávací strom a automatické vyvažování](teoreticka/09_vyvazene_stromy)                                                                            |
| 10 | [Teorie grafů](teoreticka/10_uvod_do_teorie_grafu)                                                                                                              |
| 11 | [Základní datové struktury pro průchod grafu](teoreticka/11_pruchody_grafem)                                                                                    |
| 12 | [Binární minimová halda a heapsort algoritmus](teoreticka/12_binarni_halda)                                                                                     |
| 13 | [Hledání nejkratší cesty v grafu, BFS, Dijkstrův a Bellman-Fordův algoritmus](teoreticka/13_nejkratsi_cesta)                                                    |
| 14 | [NP-těžké úlohy a jejich exponenciální algoritmy](teoreticka/14_slozite_ulohy)                                                                                  |
| 15 | [Dynamické programování](teoreticka/15_dynamicke_programovani)                                                                                                  |
| 16 | [Objektově orientované programování a další programovací paradigmata](teoreticka/16_uvod_do_oop)                                                                |
| 17 | [Paralelní programování, deadlocky a řešení maticového násobení](teoreticka/17_paralelni)                                                                       |
| 18 | [Distibuované paralelní programování](teoreticka/18_paralelni_2)                                                                                                |
| 19 | [Formální gramatiky a souvislost s návrhem programovacích jazyků](teoreticka/19_gramatiky)                                                                      |
| 20 | [Deterministické konečné automaty a návaznost na návrhové vzory](teoreticka/20_automaty)                                                                        |
| 21 | [Regulární výrazy a vzájemná převoditelnost regulárních jazyků](teoreticka/21_regularni_vyrazy)                                                                 |
| 22 | [Práce s velkými daty, Jupyter notebooky a základy strojového účení](teoreticka/22_prace_s_daty)                                                                |
| 23 | [Automatické testování softwaru](teoreticka/23_testovani)                                                                                                       |

## <a name="prakticky-seminar"></a> Praktický seminář

### <a name="prakticky-seminar-zamereni"></a> Zaměření

Kurz praktického semináře je zaměřen na praktické využití znalostí programování a informatiky,
které si žáci osvojují v rámci vedených hodin ve škole a následně také na [vlastním projektu](#individualni-projekt).

Hodiny ve škole jsou věnovány workshopům k aktuálním tématům a technologiím z oblasti vývoje softwaru
a praktickému využití těchto znalostí v rámci připravených úkolů a nebo vlastního projektu.

Každý žák pracuje na [vlastním projektu](#individualni-projekt), který si může sám zvolit,
nebo může využít nabízená témata pro [rozvoj školního ekosystému](#projekt-pro-rozvoj-skolniho-ekosystemu)
a nebo [modelové projekty](#modelovy-projekt).

| Téma                                         |
|----------------------------------------------|
| Práce s verzovacím systémem Git              |
| [Linux](workshopy/linux)                     |
| Networking                                   |
| Docker a kontejnerizace                      |
| Objektově orientované programování           |
| [Ansible](workshopy/ansible)                 |
| Testování softwaru                           |
| Autorizace a autentizace                     |
| Microservices a další architektury           |
| [Relační databáze/SQL](workshopy/sql)        |
| NoSQL databáze                               |
| AWS a cloud                                  |
| CI/CD                                        |
| ["Serverování" a hosting](workshopy/server)  |
| Monitoring a logování                        |
| [Paralelní programování](workshopy/parallel) |
| ...                                          |


## <a name="individualni-projekt"></a> Individuální projekt

### <a name="parovani-zak-lektor"></a> Párování žák × lektor

Párování žáka s lektorem je vyhodnoceno na základě průniku zaměření žákova projektu a oblasti odbornosti lektora.
Párování proběhne na tzv. _Pitch Day_, kdy žáci prezentují své projektové záměry a lektoři poskytují zpětnou vazbu.

Datum konání Pitch Day je v každém ročníku různé a bude komunikováno s dostatečným předstihem.

### <a name="nalezitosti-projektu"></a> Náležitosti projektu

Žák si **volí** jednu z těchto kategorií pro svůj individuální projekt:

- [Vlastní projekt](#vlastni-projekt)
- [Projekt pro rozvoj školního ekosystému](#projekt-pro-rozvoj-skolniho-ekosystemu)
- [Modelový projekt](#modelovy-projekt)

Dale je nutné vytvořit **projektový záměr**, který bude obashovat:

1. Představení projektu, jeho myšlenky, využití a cíle
2. Zmapování konkurenčních projektů: Existují již podobné projekty? V jaké fázi jsou? V čem bude můj jiný?
3. Plánovaný rozsah projektu: Co žák plánuje v rámci programu TopGun dokončit?
4. Technologický stack

Jednu z prvních věcí, které přidělený lektor po žákovi bude chtít zpracovat, je **rámcová analýza**:

1. Stručná verze projektového záměru
2. Rozsah projektu
3. Technologický stack a zdůvodnění výběru daných technologí
4. Hrubá časová osa zpracování projektu (_milestones_)
5. Component diagram systému dle notace UML (případně alespoň obdobný diagaram, který zachytí klíčové komponenty
   analyzovaného systému)

Z rámcové analýzy **musí** být **jinému vývojáří** zřejmé:

- _Co má vyrábět_
- _Jak to má vyrábět_
- _Do kdy to má stihnout_

Korektnost rámcové analýzy je vyhodnocena lektorem a bez validní ramcové analýzy nelze začít projekt realizovat.

### Status update

Během **status update** žák odprezentuje aktuální stav svého softwarového projektu.
Následně stručně odpoví na otázky lektora a ostatních žáků.

Prezentace by měla obsahovat následující body:

- _Splnil jsem cíl, který jsem si na uplynulé období stanovil?_
- _Cíl jsem nesplnil. Jaké chyby jsem udělal? Jak se z nich příště poučím?_
- _Cíl jsem splnil. Co se mi povedlo a budu v tom nadále pokračovat?_
- _Jaký cíl plánuji splnit v následujícím období? Jaká je jeho hlavní náplň a jak budu postupovat k jeho dosažení?_

### <a name="vlastni-projekt"></a> Vlastní projekt

Každý žák by měl zvážit realizaci vlastního projektu.
Je to ideální způsob, jak v rámci kurzu pracovat na něčem, co žáka opravdu zajímá a baví.
Za předpokladu splnění veškerých [náležitostí projektu](#nalezitosti-projektu) je žákovi realizace vlastního tématu
umožněna a je podpořena přidělením vhodného lektora.

Podpořena je rovněž realizace vlastního projektu v týmu.
Projekt pohléhá stejným podmínkám jako individuální projekt,
ale je nutné zajistit a udržet rozumné rozdělení zodpovědností a práce v týmu.

### <a name="projekt-pro-rozvoj-skolniho-ekosystemu"></a> Projekt pro rozvoj školního ekosystému

Žáci mohou pracovat na projektech, které podpoří rozvoj školního ekosystému.
Tyto projekty mají předem definované zadání a cíl, který je nutné splnit.

Pro žáky realizující tento typ projektu platí stejné podmínky a povinnosti jako pro vlastní projekt,
a to včetně zpracování a přednesení projektového záměru při [Pitch Day](#parovani-zak-lektor) dle náležitostí.

Podpořena je rovněž realizace projektu v týmu.
Projekt pohléhá stejným podmínkám jako individuální projekt,
ale je nutné zajistit a udržet rozumné rozdělení zodpovědností a práce v týmu.

Škola si vymezuje právo na výběr žáka, či týmu žáků, kterým bude projekt přidělen.

- Soutěž v programování pro žáky ZŠ [Pardubický hacker](https://pardubicky-hacker.delta-skola.cz)
- Motivační informační systém DELTA
- Informační systém „Pardubický IT Draft“
- Systém pro pořádání multioborových soutěží

### <a name="modelovy-projekt"></a> Modelový projekt

Žákům je také umožněno pracovat na projektu v rámci jedné z modelových osnov.

Pro žáky realizující tento typ projektu platí stejné podmínky a povinnosti jako pro vlastní projekt,
a to včetně zpracování a přednesení projektového záměru při [Pitch Day](#parovani-zak-lektor) dle náležitostí.

<details>
  <summary>
    Fullstack webová aplikace
  </summary>

| # | Fullstack webová aplikace                                                                                                           |
|---|-------------------------------------------------------------------------------------------------------------------------------------|
| 1 | Rámcový návrh a analýza aplikace                                                                                                    |
| 2 | Databázový model a nastavení databáze                                                                                               |
| 3 | Realizace REST/GraphQL API (Java/PHP/Node.js)                                                                                       |
| 4 | Realizace webového frontend rozhraní (JavaScript (vanilla)/React.js/Vue.js) (případně možnost realizovat hybridní mobilní aplikaci) |
| 5 | Automatizované otestování aplikace (unit, e2e)                                                                                      |
| 6 | Optimalizace výkonnosti webové aplikace                                                                                             |
| 7 | Deployment aplikace                                                                                                                 |

</details>

<details>
  <summary>
    Praktické programování v PHP
  </summary>

| # | Praktické programování v PHP                     |
|---|--------------------------------------------------|
| 1 | Základní syntaxe a Xdebug                        |
| 2 | Objektově orientované programování v PHP         |
| 3 | Správa externích závislostí – composer           |
| 4 | Persistence dat                                  |
| 5 | Automatické testování aplikace – unit testy      |
| 6 | Tvorba jednoduchého webu – PHP+HTML+CSS          |
| 7 | Tvorba REST API                                  |
| 8 | Tvorba modulů a pluginů do existujících projektů |

</details>

<details>
  <summary>
    DevOps
  </summary>

| # | Devops                                         |
|---|------------------------------------------------|
| 1 | Containerizace, co to je a k čemu se dá využít |
| 2 | Docker, docker-compose                         |
| 3 | CI                                             |
| 4 | Clusters, Docker swarm (monitoring, logging)   |
| 5 | Cloud - AWS (alerts, budgets)                  |
| 6 | Deployment webové aplikace                     |

</details>

<details>
  <summary>
    Hands-on metody kryptografie
  </summary>

| # | Hands-on metody kryptografie                              |
|---|-----------------------------------------------------------|
| 1 | Historické kryprografické systémy                         |
| 2 | Zřízení společného klíče                                  |
| 3 | Hašovací funkce                                           |
| 4 | Blokové šifrování a operační módy blokových šifer         |
| 5 | Asymetrická kryptografie - kryptografie s veřejným klíčem |

</details>

<details>
  <summary>
    Hands-on metody strojového učení
  </summary>

| # | Hands-on metody strojového učení                                                                                                                                               |
|---|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1 | Systémy strojového učení                                                                                                                                                       |
| 2 | Úvod do jazyka Python - práce s realnými daty (předzpracování, vizualizace)                                                                                                    |
| 3 | Vybrané metody strojového učení: Rozhodovací stromy, náhodné lesy                                                                                                              |
| 4 | Evaluace modelů                                                                                                                                                                |
| 5 | Vybrané metody strojového učení: Shlukování                                                                                                                                    |
| 6 | Vybrané metody strojového učení: Lineární regrese, logistická regrese, metoda největšího spádu                                                                                 |
| 7 | Vybrané metody strojového učení: Umělé neuronové sítě a jejich architektury                                                                                                    |
| 8 | Recenze vědeckého článku                                                                                                                                                       |
| 9 | End-to-end machine-learning projekt (analýza a předpoklady problému, získání dat, předzpracování dat a vizualizace, selekce modelu, trénování modelu, fine-tuning, deployment) |

</details>

## <a name="povinnosti-zapsanych-zaku"></a> Povinnosti zapsaných žáků

1. Odevzdávat domácí úlohy v řádném termínu na platformě [DOMJudge](https://domjudge.delta-topgun.cz)
2. Odprezentovat svůj [projektový záměr](#nalezitosti-projektu) na Pitch Day
3. Absolvovat úvodní schůzku s přiděleným lektorem
4. Vypracovat [rámcovou analýzu](#nalezitosti-projektu) softwarového projektu
5. Vypracovat projektovou roadmapu
6. Průběžně, minimálně však jednou za dva týdny, s lektorem konzultovat:
    - Aktuální stav projektu
    - Řešené problémy
    - Plán dalšího postupu
7. [Prezentovat svůj status update](#status-update) ve škole na hodině praktického
   semináře (přibližně **3x** za pololetí)
8. Pravidelně lektorovi odesílat **pull request**y ke code-review
9. Pravidelně kód projektu verzovat dle lektorem doporučené verzovací strategie

## <a name="neplneni-povinnosti"></a> Neplnění povinností

Při opakovaném neplnění [povinností zapsaných žáků](#povinnosti-zapsanych-zaku)
může být přistoupeno k vyřazení žáka z programu DELTA TopGun.

A to zejména v následujích případech:

- Žák, **bez předchozí omluvy**, během školního roku neodevzdal **2** domácí úlohy na
  platformě [DOMJudge](https://domjudge.delta-topgun.cz)
- Žák, **bez předchozí omluvy**, během školního roku **2x** neodprezentoval [status update](#status-update)
- Žák, **bez předchozí omluvy**, během školního roku **2x** nereaguje na výzvu lektora ohledně nenaplnění cíle,
  který si žák sám stanovil během [status update](#status-update)
- Žák, **bez předchozí omluvy**, chyběl na **2** hodinách teoretické informatiky nebo praktického semináře

---


> Computers are good at following instructions,
> but not at reading your mind.
>
> -- <cite>Donald Knuth</cite>

> Any fool can write code that a computer can understand.
> Good programmers write code that humans can understand.
>
> -- <cite>Martin Fowler</cite>

> Code is like humor.
> When you have to explain it, it’s bad.
>
> -- <cite>Cory House</cite>
