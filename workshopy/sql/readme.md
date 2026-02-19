<!-- {% raw %} -->

# SQL workshop

## Úvod

[SQL](https://en.wikipedia.org/wiki/SQL) (Structured Query Language) je jazyk pro práci s relačními databázemi.
Jeho hlavní výhodou je jednoduchost, čitelnost a možnost provádět složité operace nad (strukturovanými) daty.

Nejrozšířenějšími databázovými systémy, které používají SQL, jsou:
- 

- [MySQL](https://www.mysql.com/)
- [PostgreSQL](https://www.postgresql.org/)
- [SQLite](https://www.sqlite.org/)
- [Microsoft SQL Server](https://www.microsoft.com/en-us/sql-server)
- [Oracle Database](https://www.oracle.com/database/)

SQL je **standardizovaný jazyk**, ale každý databázový systém má své specifické rozšíření, vlastnosti a nadstavby.

Hlavními koncepty SQL jsou:

- **Databáze** - logický kontejner pro data
- **Tabulka** - strukturovaná data v řádcích a sloupcích
- **Sloupec** - jedna vlastnost, kterou má každý řádek v tabulce
- **Řádek** - jeden záznam v tabulce
- **Primární klíč** - unikátní identifikátor řádku
- **Cizí klíč** - klíč, který odkazuje na primární klíč v jiné tabulce (relace)
- **Index** - optimalizace pro rychlejší vyhledávání
- **Transakce** - skupina operací, které se provádí jako jedna celistvá
  operace ([ACID](https://en.wikipedia.org/wiki/ACID))
- **Pohled** - virtuální tabulka, která je vytvořena na základě jiných tabulek

## Příprava playgroundu

Nastartuje si nový `docker` workspace přes Coder

Vytvořte si nový adresář pro tento workshop

```shell
mkdir sql-workshop
cd sql-workshop
```

A vytvořte si `compose.yml` soubor

```shell
vim compose.yml
```

```yaml
services:
  database:
    image: mysql:9.2.0
    ports:
      - '3306:3306'
    environment:
      MYSQL_ROOT_PASSWORD: root
      MYSQL_DATABASE: workshop
      MYSQL_USER: user
      MYSQL_PASSWORD: password
    volumes:
      - database:/var/lib/mysql
  
  adminer:
    image: adminer:4.17.1
    ports:
      - 8080:8080
    environment:
      ADMINER_DEFAULT_SERVER: database
    depends_on:
      - database
  
  phpmyadmin:
    image: phpmyadmin:5.2.2
    ports:
      - 8081:80
    environment:
      PMA_HOST: database
    depends_on:
      - database

volumes:
  database:
```

Spusťte si pomocí `docker compose` databázový server a administrační rozhraní

```shell
docker compose up --detach
```

Přes Coder si můžete otevřít port

- `8080` pro `adminer`
- `8081` pro `phpmyadmin`

Obě rozhraní slouží jako grafické nástroje pro správu databází, ale mají trochu jiný vzhled a funkce.
Pro účely tohoto workshopu si můžete vybrat, které chcete použít.

Tento workshop bude používat `adminer`.

Přihlašovací údaje pro databázi jsou:

- **server**: `database`
- **port**: `3306`
- **user**: `user`
- **password**: `password`

> S databázi lze interagovat i přes příkazovou řádku, ale pro začátek je lepší použít grafické rozhraní
>
> Příkaz pro připojení k databázi přes příkazovou řádku
>
>```shell
>docker compose exec database mysql -u user -ppassword workshop
>```

## Vytvoření základní tabulky

Při práci s jakýmkoliv databázovým systémem je nutné pracovat v kontextu databáze.
Databázové servery totiž mohou obsahovat více databází, každou s vlastními tabulkami a daty.

Přepněte se do databáze `workshop` pomocí rolovacího menu vlevo nahoře s názvem `DB:`.

Pomocí záložky `SQL příkaz` v `admineru` si vytvořte hlavní vytvořte tabulku s názvem `movies`.

```sql
CREATE TABLE movies (
    id INT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(255) NOT NULL,
    year INT NOT NULL
);
```

Tento příkaz vytvoří tabulku `movies` s třemi sloupci:

- `id` - primární klíč, který se automaticky inkrementuje, jedná se o `INT`, tedy celé číslo
- `title` - název filmu, povinný, řetězec s maximální délkou `255` znaků
- `year` - rok vydání filmu, povinný, celé číslo

Dále si do databáze vložte několik záznamů

```sql
INSERT INTO movies (title, year) VALUES 
    ('The Shawshank Redemption', 1994),
    ('The Godfather', 1972),
    ('The Dark Knight', 2008),
    ('The Lord of the Rings: The Return of the King', 2003),
    ('Pulp Fiction', 1994),
    ('Forrest Gump', 1994),
    ('Inception', 2010),
    ('The Matrix', 1999),
    ('The Silence of the Lambs', 1991),
    ('The Green Mile', 1999),
    ('The Lord of the Rings: The Fellowship of the Ring', 2001),
    ('The Lord of the Rings: The Two Towers', 2002),
    ('The Lord of the Rings: The Return of the King', 2003),
    ('The Hobbit: An Unexpected Journey', 2012),
    ('The Hobbit: The Desolation of Smaug', 2013),
    ('The Hobbit: The Battle of the Five Armies', 2014),
    ('The Lion King', 1994);
```

Použijte grafické rozhraní pro zjištění počtu záznamů v tabulce `movies`.

<details>
    <summary>
        Řešení
    </summary>

    34

</details>

## SELECT

[SELECT](https://dev.mysql.com/doc/refman/9.2/en/select.html) je základní příkaz pro získání dat z tabulky.

Většinou se používá ve spojení s dalšími příkazy, jako je `WHERE`, `ORDER BY`, `GROUP BY`, `HAVING`, `JOIN`, atd.

Základní syntaxe `SELECT` příkazu je

```sql
SELECT column1, column2, ... FROM table_name;
```

Pokud chcete získat všechny sloupce z tabulky, můžete použít `*`

```sql
SELECT * FROM table_name;
```

#### Samostatné úlohy na SELECT

Pomocí `SELECT` příkazu získejte všechny záznamy z tabulky `movies`.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT * FROM movies;
```

</details>

Pomocí `SELECT` příkazu získejte názvy filmů od nejnovějšího po nejstarší.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT title FROM movies ORDER BY year DESC;
```

</details>

Pomocí `SELECT` příkazu vyhledejte 5 nejstarších filmů.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT * FROM movies ORDER BY year ASC LIMIT 5;
```

</details>

Pomocí `SELECT` příkazu získejte názvy filmů, které neobsahují slovo `The` v názvu.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT title FROM movies WHERE title NOT LIKE '%The%';
```

</details>

Ke každému roku v tabulce vypište počet filmů, které byly vydány v daném roce.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT year, COUNT(*) FROM movies GROUP BY year;
```

</details>

## JOIN

[JOIN](https://dev.mysql.com/doc/refman/9.2/en/join.html) je příkaz, který slouží k spojení dvou tabulek na základě
společného identifikátoru.

Existují různé typy `JOIN`, nejčastější jsou:

- `INNER JOIN` - vrátí pouze záznamy, které mají shodný identifikátor v obou tabulkách
- `LEFT JOIN` - vrátí všechny záznamy z levé tabulky a záznamy z pravé tabulky, které mají shodný identifikátor
- `RIGHT JOIN` - vrátí všechny záznamy z pravé tabulky a záznamy z levé tabulky, které mají shodný identifikátor
- `FULL JOIN` - vrátí všechny záznamy z obou tabulek

Také klasifikujeme následující vazby mezi tabulkami:

- `1:1` - jeden k jednomu
- `1:n` - jeden k mnoha
- `n:m` - mnoho k mnoha

Tyto vazby se modelují pomocí cizích klíčů.

U vazby `1:1` jedna tabulka obsahuje primární klíč a druhá tabulka obsahuje cizí klíč, který je ale zároveň také primárním klíčem.
Příklad je například tabulka `users` a `profiles`, kde každý uživatel má pouze jeden záznam v tabulce `profiles`, kde například ukládáme dodatkové informace o uživateli.

U vazby `1:n` jedna tabulka obsahuje primární klíč a druhá tabulka obsahuje cizí klíč, který odkazuje na primární klíč.
Rozdíl oproti `1:1` je, že druhá tabulka má svůj vlastní primární klíč a sloupeček s cizím klíčem nemusí být unikátní.
Příklad je například tabulka `users` a `posts`, kde každý uživatel může mít více příspěvků, ale příspěvek je napojen pouze jedním uživatelem.

Pro vazbu typu `n:m` se používá spojovací tabulka, která obsahuje dvojice cizích klíčů, které odkazují na primární klíče obou tabulek.
Příklad je například tabulka `users` a `roles`, kde každý uživatel může mít více rolí a každá role může být přiřazena více uživatelům.

Vytvořme si další tabulky `users` a `ratings`.

```sql
CREATE TABLE users (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL
);

CREATE TABLE ratings (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT NOT NULL,
    movie_id INT NOT NULL,
    rating INT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (movie_id) REFERENCES movies(id),
    UNIQUE (user_id, movie_id)
);
```

Najděte v grafickém rozhraní rozložení tabulek a prohlédněte si vytvořené vzájemné relace (pomocí cizích klíčů).

> Přidali jsme také `UNIQUE` omezení, které zaručí, že každý uživatel může hodnotit každý film pouze jednou.

Vložte několik záznamů do tabulek `users` a `ratings`.

```sql
INSERT INTO users (name) VALUES 
    ('Alice'),
    ('Bob'),
    ('Charlie'),
    ('David'),
    ('Eve');

INSERT INTO ratings (user_id, movie_id, rating) VALUES 
    (1, 1, 10), (1, 2, 9), (1, 3, 8), (1, 4, 7), (1, 5, 6),
    (2, 1, 5), (2, 2, 6), (2, 3, 7), (2, 4, 8), (2, 5, 9), (2, 6, 10), (2, 7, 1), (2, 8, 2),
    (3, 1, 9),
    (5, 1, 10), (5, 2, 9), (5, 3, 8), (5, 4, 7), (5, 5, 6);
```

#### Samostatné úlohy na JOIN

Pomocí `JOIN` příkazu získejte průměrné hodnocení filmů.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT title, AVG(rating) FROM movies
JOIN ratings ON movies.id = ratings.movie_id
GROUP BY title;
```

</details>

Pomocí `JOIN` příkazu získejte průměrné hodnocení filmů, které byly hodnoceny uživatelem `Alice`.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT title, AVG(rating) FROM movies
JOIN ratings ON movies.id = ratings.movie_id
JOIN users ON ratings.user_id = users.id
WHERE users.name = 'Alice'
GROUP BY title;
```

</details>

Vypište filmy bez hodnocení.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT title FROM movies
LEFT JOIN ratings ON movies.id = ratings.movie_id
WHERE ratings.movie_id IS NULL;
```

</details>


Vypište uživatele a počet jejich hodnocení.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT users.name, COUNT(ratings.id) FROM users
LEFT JOIN ratings ON users.id = ratings.user_id
GROUP BY users.name;
```

</details>

Vypište uživatele, kteří hodnotili alespoň 5 filmů.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT users.name, COUNT(ratings.id) FROM users
LEFT JOIN ratings ON users.id = ratings.user_id
GROUP BY users.name
HAVING COUNT(ratings.id) >= 5;
```

</details>

Vypište filmy, které byly hodnocemy méně než 2 uživateli.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT title, COUNT(ratings.id) FROM movies
LEFT JOIN ratings ON movies.id = ratings.movie_id
GROUP BY title
HAVING COUNT(ratings.id) < 2;
```

</details>

Vypište seznam nejlépe hodnocených filmů, společně s počtem hodnocení.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT title, AVG(rating), COUNT(ratings.id) FROM movies
JOIN ratings ON movies.id = ratings.movie_id
GROUP BY title
ORDER BY AVG(rating) DESC;
```

</details>

## Datové modelování

Přidejte do databáze novou tabulku `genres`, která bude obsahovat žánry filmů.

```sql
CREATE TABLE genres (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL
);
```

A vložte několik záznamů

```sql
INSERT INTO genres (name) VALUES 
    ('Action'),
    ('Adventure'),
    ('Comedy'),
    ('Crime'),
    ('Drama'),
    ('Fantasy'),
    ('Horror'),
    ('Mystery'),
    ('Romance'),
    ('Sci-Fi'),
    ('Thriller');
```

### Samostatná úloha na datové modelování

Vytvořte spojovací tabulku `movie_genres`, která bude obsahovat vztah mezi filmy a žánry.

<details>
    <summary>
        Řešení
    </summary>

```sql
CREATE TABLE movie_genres (
    id INT PRIMARY KEY AUTO_INCREMENT,
    movie_id INT NOT NULL,
    genre_id INT NOT NULL,
    FOREIGN KEY (movie_id) REFERENCES movies(id),
    FOREIGN KEY (genre_id) REFERENCES genres(id),
    UNIQUE (movie_id, genre_id)
);
```

</details>

Vytvořte tabulku `users_favorite_genres`, která bude obsahovat oblíbené žánry uživatelů.

<details>
    <summary>
        Řešení
    </summary>

```sql
CREATE TABLE users_favorite_genres (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT NOT NULL,
    genre_id INT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (genre_id) REFERENCES genres(id),
    UNIQUE (user_id, genre_id)
);
```

</details>

Pomocí grafického rozhraní si zobrazte vztahy mezi tabulkami a zkontrolujte, že všechny vztahy jsou správně nastaveny.

> Referenční řešení zvolilo přístup jednoho primárního klíče a následně aplikaci unikátního omezení na dvojici sloupců.
> 
> Existuje i jiný přístup, kdy se jako primární klíč použije dvojice sloupců, ale tento přístup není vždy vhodný z praktických důvodů.
> 
> Představte si, že chcete odkazovat na spojovací tabulku z jiné tabulky, pak je lepší mít jeden jednoznačný identifikátor.
> Pokud byste měli jako primární klíč dvojici sloupců, museli byste vytvořit
> 1. složený klíč, který by se skládal z obou sloupců
> 2. cizí klíče by se museli odkazovat na oba sloupce, což je složitější a méně efektivní

Vložte několik záznamů do právě vytvořených tabulek.

```sql
INSERT INTO movie_genres (movie_id, genre_id) VALUES 
    (1, 5), (1, 8), (1, 9), (1, 10),
    (2, 5), (2, 8), (2, 9), (2, 10),
    (3, 1), (3, 5), (3, 8), (3, 9), (3, 10),
    (4, 1), (4, 5), (4, 8), (4, 9), (4, 10),
    (5, 1), (5, 5), (5, 8), (5, 9), (5, 10),
    (6, 1), (6, 5), (6, 8), (6, 9), (6, 10),
    (7, 1), (7, 5), (7, 8), (7, 9), (7, 10),
    (8, 1), (8, 5), (8, 8), (8, 9), (8, 10),
    (9, 1), (9, 5), (9, 8), (9, 9), (9, 10),
    (10, 1), (10, 5), (10, 8), (10, 9), (10, 10);

INSERT INTO users_favorite_genres (user_id, genre_id) VALUES 
    (1, 5), (1, 8), (1, 9), (1, 10),
    (2, 5), (2, 8), (2, 9), (2, 10),
    (3, 1), (3, 5), (3, 8), (3, 9), (3, 10),
    (4, 1), (4, 5), (4, 8), (4, 9), (4, 10),
    (5, 1), (5, 5), (5, 8), (5, 9), (5, 10);
```

Vypište všechny žánry, které má `Alice` ráda.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT genres.name FROM genres
JOIN users_favorite_genres ON genres.id = users_favorite_genres.genre_id
JOIN users ON users_favorite_genres.user_id = users.id
WHERE users.name = 'Alice';
```

</details>

## Pohledy

[Pohledy](https://en.wikipedia.org/wiki/View_(SQL)) jsou virtuální tabulky, které jsou vytvořeny na základě uloženého `SELECT` příkazu.

Pohledy se používají pro zjednodušení složitých dotazů, které se často opakují.

Vytvořte pohled, který bude obsahovat všechny filmy a jejich průměrné hodnocení, nazvěte ho `movies_ratings`.

<details>
    <summary>
        Řešení
    </summary>

```sql
CREATE VIEW movies_ratings AS
SELECT title, AVG(rating) AS avg_rating FROM movies
JOIN ratings ON movies.id = ratings.movie_id
GROUP BY title;
```

</details>

Nad takto vytvořeným pohledem můžete provádět stejné operace jako nad tabulkou.

Například vypsat všechny filmy, které mají průměrné hodnocení vyšší než `8`, seřazené sestupně.

<details>
    <summary>
        Řešení
    </summary>

```sql
SELECT * FROM movies_ratings
WHERE avg_rating > 8
ORDER BY avg_rating DESC;
```

</details>

## Transakce

[Transakce](https://en.wikipedia.org/wiki/Database_transaction) je skupina operací, které se provádí jako jeden celek.

Pokud by při zpracování tohoto celku nastala chyba, databázový server se vrátí do původního stavu (provede `rollback`).

Typickým příkladem transakce je převod peněz mezi dvěma účty. Pokud by se při převodu stala chyba,
nemůže dojít k situaci, že na jednom účtu budou peníze odečteny a na druhém nepřijdou!

V naší databázi si transakce předvedeme na tvorbě struktury pro odemykání filmů.
Uživatelé budou mít možnost shlédnout film pouze tehdy, pokud za něj zaplatí.

Mohli bychom do tabulky `users` přidat sloupec `balance`, ale častokrát se v praktických aplikacích oddělulují
data od různých bussinessových entit. Zlepšuje to čitelnost a udržitelnost kódu.

Vytvoříme si tedy novou tabulku `balances`, která bude obsahovat zůstatky uživatelů.

> Jedná se o relaci `1:1` mezi tabulkami `users` a `balances`.
> 
> Tento typ relace lze modelovat několika způsoby:
> 1. vlastník (kde je uložen) cizí klíč je tabulka `users`
> 2. vlastník (kde je uložen) cizí klíč je tabulka `balances`
> 
> Ve většině případů se setkáte s postupem 2, jelikož to umožňuje snadnější
> - přidání dalších vlastností k uživatelům,
> - odebrání této funkcionliaty, pokud již není potřeba
> - snadnější rozšíření o další funkcionality v budoucnu

Syntaxe pro transakci v MySQL je následující

```sql
START TRANSACTION;

-- operace

COMMIT;
```

Pokud chce provést `rollback`, můžete použít

```sql
ROLLBACK;
```

Často se v programovaích jazycích používá `try-catch` blok, který zachytí chybu a provede `rollback` transakce.

Kód může vypadat následovně

```php
try {
    $db->beginTransaction();
    
    // operace
    
    $db->commit();
} catch (Exception $e) {
    $db->rollback();
}
```

### Samostatná úloha na transakce

Vytvořte tabulku `balances`, kde cizí klíč bude vlastnit tabulka `balances`.

<details>
    <summary>
        Řešení
    </summary>

```sql
CREATE TABLE balances (
    user_id INT PRIMARY KEY,
    balance DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id)
);
```

</details>

> V referenčním řešení jsme použili `DECIMAL` pro uložení zůstatku, jelikož se jedná o peníze, které mají pevně daný formát.
> 
> `DECIMAL(p, s)` kde `p` je celkový počet číslic a `s` je počet číslic za desetinnou čárkou.
> 
> Také jsme **NEpoužili** `AUTO_INCREMENT`, jelikož primární klíč je také cizí klíč a jedná se o `1:1` relaci

Vytvořte tabulku `subscriptions`, která bude obsahovat informace o zakoupených filmech.

<details>
    <summary>
        Řešení
    </summary>

```sql
CREATE TABLE subscriptions (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT NOT NULL,
    movie_id INT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (movie_id) REFERENCES movies(id)
);
```

</details>

A nakonec vytvoře speciální relační tabulku `1:1` `movie_prices`, která bude obsahovat ceny filmů.

<details>
    <summary>
        Řešení
    </summary>

```sql
CREATE TABLE movie_prices (
    movie_id INT PRIMARY KEY,
    price DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (movie_id) REFERENCES movies(id)
);
```

</details>

Vytvořte jednoduchou aplikaci, která se připojí na databázi a bude umožňovat uživatelům zakoupit film.

Aplikace by měla provést následující operace

1. Zkontrolovat, zdali uživatel má dostatečný zůstatek na účtu
2. Odečíst zůstatek uživatele
3. Přidat záznam do tabulky `subscriptions`
4. Vytisknout informaci o úspěšném nákupu
5. V případě chyby vytisknout chybovou hlášku
6. Všechny operace by měly být součástí jedné transakce

## Bonus: Filmová databáze pro pokročilé

> Tato úloha je určena pro pokročilé účastníky, kteří chtějí vyzkoušet návrh databáze a složitější dotazy na vlastní kůži.
>
> Cílem je navrhnout strukturu tabulek **samostatně** a následně nad nimi napsat požadované dotazy.

### Zadání

Vaše filmová databáze se rozrůstá. Zákazníci chtějí sledovat nejen filmy, ale i **seriály**.
Každý seriál má několik **sérií** (seasons) a každá série obsahuje **epizody**.

Zároveň se platforma rozšiřuje do zahraničí a potřebuje podporovat **více jazyků**.
Názvy a popisy filmů, seriálů i epizod musí existovat ve více jazykových mutacích.
Pokud překlad v preferovaném jazyce uživatele neexistuje, systém musí umět zobrazit anglický název jako fallback.

Databáze také potřebuje evidovat **tvůrce** — herce, režiséry, scenáristy a další role.
Tvůrci mohou pracovat jak na filmech, tak na jednotlivých epizodách seriálů.
U herců chceme navíc evidovat jméno postavy, kterou v daném díle hrají.

V neposlední řadě chceme uchovávat informace o **datech premiér** v různých zemích,
protože filmy i seriály mají v různých zemích různá data uvedení.

Uživatelé mohou hodnotit nejen filmy (to už máme), ale nově i **jednotlivé epizody** seriálů.

### Co je potřeba

1. Navrhněte strukturu nových tabulek, které pokryjí výše popsané požadavky
2. Vytvořte tabulky v databázi a naplňte je testovacími daty
3. Napište následující dotazy:

### Dotazy

1. Vypište všechny seriály a počet jejich epizod.

2. Pro každý film vypište jeho český název. Pokud český překlad neexistuje, zobrazte anglický název.

3. Najděte herce, kteří hráli zároveň ve filmu i v nějakém seriálu.

4. Který herec hrál v nejvíce různých seriálech?

5. Vypište seriály, jejichž průměrné hodnocení epizod je vyšší než celkové průměrné hodnocení všech filmů.

6. Pro každý seriál vypište jeho nejlépe hodnocenou epizodu společně s jejím českým názvem (s fallbackem na angličtinu).

7. Najděte lidi, kteří režírovali film i epizodu seriálu. Pro každého z nich porovnejte průměrné hodnocení jejich filmů a průměrné hodnocení epizod, které režírovali.

### Nadstavba: Vztahy mezi díly

Filmy a seriály na sebe často navazují.
Temný rytíř je sequel Batmana začíná, Better Call Saul je spin-off Breaking Bad (seriál ze seriálu),
Fargo existuje jako film i jako seriál (remake/adaptace).

Systém potřebuje modelovat **vztahy mezi libovolnými dvěma díly**, přičemž dílo může být film nebo seriál.
Typ vztahu (sequel, prequel, remake, spin-off) musí být součástí modelu.

Zásadní designový problém: jak odkázat na entitu, která může být buď film, nebo seriál?

### Dotazy na vztahy

1. Vypište všechny sequely a k nim jejich původní dílo (s českým názvem, fallback na angličtinu).

2. Najděte díla, která mají více než jeden typ vztahu k jiným dílům (např. film má sequel i remake).

3. Najděte herce, kteří hráli v původním díle i v jeho remaku nebo spin-offu.

<!-- {% endraw %} -->
