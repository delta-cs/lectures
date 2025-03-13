<!-- {% raw %} -->

# Linux workshop

## Úvod

[Linux](https://en.wikipedia.org/wiki/Linux) je soubor operačních systémů založených na open-source [jádře](https://en.wikipedia.org/wiki/Linux_kernel),
které v roce 1991 vytvořil [Linus Torvalds](https://en.wikipedia.org/wiki/Linus_Torvalds)

Nejrozšířenějšími Linuxovými distribucemi jsou:

- [Ubuntu](https://ubuntu.com/)
- [Debian](https://www.debian.org/)
- [Fedora](https://fedoraproject.org/)
- [CentOS](https://www.centos.org/)
- [Arch Linux](https://archlinux.org/)
- [openSUSE](https://www.opensuse.org/)
- [Gentoo](https://www.gentoo.org/)

V různých distribucích se často liší:

- balíčkovací systémy (např. `apt`, `yum`, `pacman`, `dnf`)
- desktopové prostředí (např. `GNOME`, `KDE`, `XFCE`, `LXDE`, `i3`)
- umístění konfiguračních souborů
- nástroje pro správu systému
- podporované balíčky a verze
  - některé distribuce mají stabilní verze balíčků - `stable` a získávají pouze bezpečnostní aktualizace (např. `Debian`)
  - jiné distribuce mají nejnovější verze balíčků - `rolling release` / `bleeding edge` a získávají nejnovější funkce a opravy téměř okamžitě (např. `Arch Linux`)
- ...

Instalátory distribucí pomáhají s

- rozdělením disku
- nastavením `bootloaderu`
- výběrem desktopového prostředí
- výběrem softwaru, který se má nainstalovat
- konfigurací sítě
- vytvořením uživatelů
- ...

Na serverových systémech se často používají distribuce bez desktopového prostředí,
protože desktopové prostředí zabírá zbytečně mnoho výpočetních zdrojů a snižuje bezpečnostní úroveň systému

## Příprava playgroundu

> Na Coderových instaních dostáváte přístup do Ubuntu serveru, který je předinstalován a přednastaven pomocí nástroje [cloud-init](https://cloudinit.readthedocs.io/en/latest/)
> 
> Nemusíte se tedy starat o instalaci operačního systému, ale můžete se okamžitě pustit do práce

Nastartuje si nový `ubuntu` workspace přes Coder

Do domovského adresáře si nakopírujeme několik souborů, se kterými budeme pracovat

```shell
cp /etc/hosts .
cp /etc/hostname .
sudo cp /var/log/dmesg .
```

## Představení základních příkazů

### `ls`

[manuálová stránka](https://man7.org/linux/man-pages/man1/ls.1.html)

`ls` je základní příkaz pro výpis obsahu adresáře

Vyzkoušejte si vypsat obsah aktuálního adresáře

```shell
ls
```

Pokud jste se pouze přihlásili do systému, měli byste vidět několik souborů a adresářů ve vašem domovském adresáři

**Všechny úkoly v tomto worshopu vypracujte pouze za pomocí manuálových stránek**

Jak zobrazit skryté soubory?

<details>
    <summary>
        Řešení
    </summary>

```shell
ls -a
```

</details>

Jak zobrazit obsah adresáře s podrobnými informacemi?

<details>
    <summary>
        Řešení
    </summary>

```shell
ls -l
```

</details>

Jak zobrazit obsah adresáře s podrobnými informacemi a skrytými soubory?

<details>
    <summary>
        Řešení
    </summary>

```shell
ls -la
```

</details>

Jak zobrazit obsah adresáře s podrobnými informacemi a skrytými soubory, seřazený podle data vytvoření?

<details>
    <summary>
        Řešení
    </summary>

```shell
ls -lat
```

</details>

Jak zobrazit obsah adresáře s podrobnými informacemi a skrytými soubory, seřazený podle velikosti souborů sesestupně (největší soubory nahoře)?

<details>
    <summary>
        Řešení
    </summary>

```shell
ls -lS
```

</details>

Jak zobrazit obsah adresáře s podrobnými informacemi a skrytými soubory, seřazený podle velikosti souborů vzestupně (nejmenší soubory nahoře)?

<details>
    <summary>
        Řešení
    </summary>

```shell
ls -lSr
```

</details>

Jak zobazit velikost souborů v MB, případně v GB - v lidsky čitelné formě?

<details>
    <summary>
        Řešení
    </summary>

```shell
ls -lh
```

</details>

Jak zobrazit místo uživatele a skupiny, UID a GID vlastníka souboru?

<details>
    <summary>
        Řešení
    </summary>

```shell
ls -ln
```

</details>


### `cd`

[manuálová stránka](https://man7.org/linux/man-pages/man1/cd.1p.html)

`cd` je základní příkaz pro změnu aktuálního adresáře (change directory)

V shellech existují některé speciální adresáře:

- `.` - aktuální adresář
- `..` - nadřazený adresář
- `~` - domovský adresář
- `-` - předchozí adresář
- `/` - kořenový adresář

Vyzkoušejte si změnit aktuální adresář na `/etc`

```shell
cd /etc
```

A vylistujte obsah tohoto adresáře

```shell
ls
```

Jak se dostanete zpět do domovského adresáře?

<details>
    <summary>
        Řešení
    </summary>

```shell
cd
```

nebo

```shell
cd ~
```

</details>

Předpokládejme, že si nepamatujete cestu do adersáře, kde jste před chvílí byli, jak se tam dostanete?

<details>
    <summary>
        Řešení
    </summary>

```shell
cd -
```

</details>

Jak se dostanete do adresáře `.ssh` v domovském adresáři?

<details>
    <summary>
        Řešení
    </summary>

```shell
cd ~/.ssh
```

</details>

Jak se dostanete do nadřazeného adresáře?

<details>
    <summary>
        Řešení
    </summary>

```shell
cd ..
```

</details>

Předpokládejme, že jste v domovském adresáři

V jakém adresáři se budete nacházet po spuštění následujícího příkazu?

```shell
cd .ssh/../.config/../
```

<details>
    <summary>
        Řešení
    </summary>

Stále v domovském adresáři

</details>

### `pwd`

[manuálová stránka](https://man7.org/linux/man-pages/man1/pwd.1.html)

`pwd` je základní příkaz pro vypsání aktuálního adresáře (print working directory)

Jděte do domovského adresáře a vypište aktuální adresář

```shell
cd
pwd
```

Jaký je výstup příkazu `pwd`?

<details>
    <summary>
        Řešení
    </summary>

```shell
/home/<username>
```

</details>

### `mkdir`

[manuálová stránka](https://man7.org/linux/man-pages/man1/mkdir.1.html)

`mkdir` je základní příkaz pro vytvoření adresáře (make directory)

Vytvořte si adresář `workshop` v domovském adresáři

```shell
cd
mkdir workshop
```

Jak zjistíte, že adresář byl vytvořen?

<details>
    <summary>
        Řešení
    </summary>

```shell
ls
```

</details>

Jak vytvoříte adresář `~/workshop/my/very/nested/directory`?

<details>
    <summary>
        Řešení
    </summary>

```shell
mkdir -p ~/workshop/my/very/nested/directory
```

</details>

### `rmdir`

[manuálová stránka](https://man7.org/linux/man-pages/man1/rmdir.1.html)

`rmdir` je bezpečnější verze příkazu `rm`, který slouží k odstranění prázdného adresáře (remove directory)

> Pokud adresář není prázdný, `rmdir` skončí chybou, proto je považován za bezpečnější než klasický `rm` příkaz

Odstraňte adresář `~/workshop/my/very/nested/directory`

```shell
rmdir ~/workshop/my/very/nested/directory
```

Jak zjistíte, že adresář byl odstraněn?

<details>
    <summary>
        Řešení
    </summary>

```shell
ls ~/workshop/my/very/nested/directory
```

Výsledek by měl vypada takto

```text
ls: cannot access '/home/<username>/workshop/my/very/nested/directory': No such file or directory
```

</details>

### `rm`

[manuálová stránka](https://man7.org/linux/man-pages/man1/rm.1.html)

`rm` je základní příkaz pro odstranění souboru nebo adresáře (remove)

Než ale začneme odstraňovat, musíme si něco vytvořit

```shell
mkdir -p ~/workshop/my/very/nested/directory
touch ~/workshop/my/very/nested/directory/file.txt
touch ~/workshop/my/very/file{1..5}.txt
sudo touch ~/workshop/my/very/file6.txt
```

> Prázdné soubory lze vytvořit pomocí příkazu `touch`

> Pomocí `{1..5}` jsme vytvořili soubory `file1.txt`, `file2.txt`, `file3.txt`, `file4.txt`, `file5.txt`
> 
> Více o shellových expanzích bude níže

Pokud nyní zkusíme odstranit adresář `~/workshop/my/very/nested/directory` pomocí `rmdir`, skončíme chybou

```shell
rmdir ~/workshop/my/very/nested/directory
```

```text
rmdir: failed to remove '/home/<username>/workshop/my/very/nested/directory': Directory not empty
```

Pokud použijeme `rm` na odstranění adresáře, dostanema ale jinou chybu

```shell
rm ~/workshop/my/very/nested/directory
```

```text
rm: cannot remove '/home/<username>/workshop/my/very/nested/directory': Is a directory
```

`rm` slouží primárně pouze k odstranění souborů, nikoliv adresářů

Jak odstraníte adresář `~/workshop/my/very/nested/directory`, společně s jeho obsahem?

<details>
    <summary>
        Řešení
    </summary>

```shell
rm -r ~/workshop/my/very/nested/directory
```

</details>

Jak odstraníte všechny soubory v `~/workshop/my/very/` a také samotný adresář?

<details>
    <summary>
        Řešení
    </summary>

```shell
rm -r ~/workshop/my/very
```

</details>

Minulý příkaz se nás zeptal na potvrzení, zdali chceme smazait i soubor `file6.txt`, jelikož je vlastněný uživatelem `root`

```text
rm: remove write-protected regular empty file '/home/<username>/workshop/my/very/file6.txt'?
```

Vytvořme soubor znovu

```shell
mkdir -p ~/workshop/my/very
sudo touch ~/workshop/my/very/file6.txt
```

Jak odstraníte všechny soubory v `~/workshop/my/very/` a také samotný adresář, aniž by se vás systém ptal na potvrzení?

<details>
    <summary>
        Řešení
    </summary>

```shell
rm -rf ~/workshop/my/very
```

</details>

### `cp`

[manuálová stránka](https://man7.org/linux/man-pages/man1/cp.1.html)

`cp` je základní příkaz pro kopírování souborů a adresářů (copy)

Vytvořte si kopii souboru `/etc/passwd` do domovského adresáře

<details>
    <summary>
        Řešení
    </summary>

```shell
cp /etc/passwd ~
```

</details>

Jak zjistíte, že soubor byl úspěšně zkopírován?

<details>
    <summary>
        Řešení
    </summary>

```shell
ls ~
```

Případně můžete porovnat velikost souborů nebo provést kontrolní součet

</details>

Jak zkopírujete obsah adresáře (i podadresářů) `/var/log/` do adresáře `~/logs`?

<details>
    <summary>
        Řešení
    </summary>

```shell
cp -r /var/log ~/logs
```

</details>

Na některé soubory a adresáře nebudete mít dostatečná práva, ale pro naše účely to nevadí

### `mv`

[manuálová stránka](https://man7.org/linux/man-pages/man1/mv.1p.html)

`mv` je základní příkaz pro přesunutí souborů a adresářů (move)

Velmi podobný příkazu `cp`, ale na rozdíl od něj neprovádí kopii, ale pouze přesun a tedy **nezanechává** původní soubor.

Používá se také na přejmenování souborů a adresářů

Jak přejmenujete soubor `~/logs/dpkg.log` na `~/logs/dpkg.log.old`?

<details>
    <summary>
        Řešení
    </summary>

```shell
mv ~/logs/dpkg.log ~/logs/dpkg.log.old
```

</details>

Jak přejmenujete adresář `~/logs` na `~/log`?

<details>
    <summary>
        Řešení
    </summary>

```shell
mv ~/logs ~/log
```

</details>

### `cat`

[manuálová stránka](https://www.man7.org/linux/man-pages/man1/cat.1.html)

`cat` je základní příkaz pro výpis obsahu souborů (concatenate)

Vyzkoušejte si vypsat obsah souboru `/etc/passwd`

```shell
cat /etc/passwd
```

Hlavním účelem `cat` je přečtění několika souborů a jejich spojení do jednoho výstupu

Jak zobrazíte obsah souborů `/etc/passwd` a `/etc/hostname` dohromady?

<details>
    <summary>
        Řešení
    </summary>

```shell
cat /etc/passwd /etc/hostname
```

</details>

> Nicméně v praxi se často setkáte z tím, že se `cat` používá pouze na přečtení obsahu jednoho souboru a následně se s tímto obsahem pracuje pomocí jiných příkazů

### `less` a `more`

[manuálová stránka `less`](https://man7.org/linux/man-pages/man1/less.1.html)

[manuálová stránka `more`](https://man7.org/linux/man-pages/man1/more.1.html)

`less` a `more` jsou základní příkazy pro postupné a interaktivní čtení obsahu souborů v terminálu

`less` je modernější a nabízí více funkcí než `more`, ale oba příkazy jsou velmi podobné

Vyzkoušejte si vypsat obsah souboru `/etc/passwd` pomocí `less`

```shell
less /etc/passwd
```

Jak se pohybujete v `less`?

<details>
    <summary>
        Řešení
    </summary>

šipkami, nebo pomocí kláves

- `j` - dolů
- `k` - nahoru
- `f` - vpřed
- `b` - vzad


- `g` - na začátek
- `G` - na konec
- `/` - vyhledávání (funguje ale pouze dopředu od první zobrazené řádky)
- `q` - ukončení

</details>

### `head` a `tail`

[manuálová stránka `head`](https://man7.org/linux/man-pages/man1/head.1.html)

[manuálová stránka `tail`](https://man7.org/linux/man-pages/man1/tail.1.html)

`head` a `tail` jsou základní příkazy pro výpis prvních nebo posledních řádků souboru

Bez speciálních přepínačů vypisují prvních nebo posledních 10 řádků souboru

Vyzkoušejte si vypsat prvních 10 řádků souboru `/etc/passwd`

```shell
head /etc/passwd
```

Jak zobrazíte posledních 10 řádků souboru `/etc/passwd`?

<details>
    <summary>
        Řešení
    </summary>

```shell
tail /etc/passwd
```

</details>

Jak zobrazíte posledních 20 řádků souboru `/etc/passwd`?

<details>
    <summary>
        Řešení
    </summary>

```shell
tail -n 20 /etc/passwd
```

</details>

Jak pomocí `head` zobrazíte všechny řádky souboru `/etc/passwd` kromě posledních 5?

<details>
    <summary>
        Řešení
    </summary>

```shell
head -n -5 /etc/passwd
```

</details>

Jak pomocí `tail` zobrazíte všechny řádky souboru `/etc/passwd` kromě prvních 5?

<details>
    <summary>
        Řešení
    </summary>

```shell
tail -n +6 /etc/passwd
```

</details>

Tail má i jeden velmi užitečný přepínač `-f`, který sleduje změny v souboru v reálném čase

Otevřete si 2 okna terminálu ve stejné složce, v jednom spusťte následující příkaz

```shell
tail -f my-output.txt
```

V druhém okně terminálu vytvořte soubor `my-output.txt` a zapište do něj nějaký text

```shell
echo "Hello World" > my-output.txt
```

Postupně sledujte první okno a u toho zapisujte další řádky

```shell
echo "Hello World" >> my-output.txt
```

Tento příkaz je velmi užitečný pro sledování nových záznamů v logovacích souborech

### `grep`

[manuálová stránka](https://man7.org/linux/man-pages/man1/grep.1.html)

`grep` je základní příkaz pro vyhledávání řetězců v textu (global regular expression search and print)

Vyzkoušejte si vyhledat řádky v souboru `/etc/passwd`, které obsahují řetězec `root`

```shell
grep root /etc/passwd
```

Jak zobrazíte pouze řádky, které obsahují řetězec `bash`?

<details>
    <summary>
        Řešení
    </summary>

```shell
grep bash /etc/passwd
```

</details>

První argument příkazu `grep` je regulární výraz, což znamená, že můžete použít speciální znaky pro vyhledávání

Jak zobrazíte pouze řádky, které obsahují řetězec `sh` na konci řádku?

Tedy nechceme ve výsledku například uživate `sshd` apod.

<details>
    <summary>
        Řešení
    </summary>

```shell
grep 'sh$' /etc/passwd
```

</details>

Jak zobrazíte pouze řádky, které začínají na písmeno `t`?

<details>
    <summary>
        Řešení
    </summary>

```shell
grep '^t' /etc/passwd
```

</details>

Příkaz `grep` je velmi mocný, příkladem je například vyhledání a nálsedný výpis kontextu

Jak zobrazíte řádky, které obsahují řetězec `sshd` a 2 řádky před a 2 řádky po?

<details>
    <summary>
        Řešení
    </summary>

```shell
grep -B 2 -A 2 sshd /etc/passwd
```

</details>


### `find`

[manuálová stránka](https://man7.org/linux/man-pages/man1/find.1.html)

`find` je základní příkaz pro hledání souborů a adresářů v souborovém systému

Vyzkoušejte si najít všechny soubory ve vašem domovském adresáři

```shell
find ~
```

Všimněte si, že `find` vypisuje i skryté soubory a také v základu vyhledává rekurzivně i v podadresářích

Find také v základu hledá i adresáře

- pokud chcete vzhledávat pouze soubory, použijte přepínač `-type f`
- pokud pouze adresáře, použijte `-type d`

Jak najdete všechny soubory ve vašem domovském adresáři, které začínají na písmeno `d`?

<details>
    <summary>
        Řešení
    </summary>

```shell
find ~ -type f -name 'd*'
```

</details>

Jak najdete všechny soubory ve vašem domovském adresáři, které končí na `.log`?

<details>
    <summary>
        Řešení
    </summary>

```shell
find ~ -type f -name '*.log'
```

</details>


Jak najdete všechny adresáře ve vašem domovském adresáři, které obsahují slovo `server`?

<details>
    <summary>
        Řešení
    </summary>

```shell
find ~ -type d -name '*server*'
```

</details>

Jak najdete všechny soubory ve vašem domovském adresáři, které byly změněny v posledních 7 dnech?

<details>
    <summary>
        Řešení
    </summary>

```shell
find ~ -type f -mtime -7
```

</details>

Jak najdete všechny soubory ve vašem domovském adresáři, které obsahují písmena `rc` **nebo** `conf`?

<details>
    <summary>
        Řešení
    </summary>

```shell
find ~ -type f -name '*rc*' -o -name '*conf*'
```

</details>

### `wc`

[manuálová stránka](https://man7.org/linux/man-pages/man1/wc.1.html)

`wc` je základní příkaz pro počítání znaků, slov a řádků v textu (word count)

Vyzkoušejte si spočítat počet řádků, slov a znaků v souboru `/etc/passwd`

```shell
wc /etc/passwd
```

Jak zobrazíte pouze počet řádků v souboru `/etc/passwd`?

<details>
    <summary>
        Řešení
    </summary>

```shell
wc -l /etc/passwd
```

</details>

Jak zobrazíte pouze počet slov v souboru `/etc/passwd`?

<details>
    <summary>
        Řešení
    </summary>

```shell
wc -w /etc/passwd
```

</details>

Jak zobrazíte pouze počet znaků v souboru `/etc/passwd`?

<details>
    <summary>
        Řešení
    </summary>

```shell
wc -c /etc/passwd
```

</details>

### `cut`

[manuálová stránka](https://man7.org/linux/man-pages/man1/cut.1.html)

`cut` je základní příkaz pro výběr a výřezu částí textu (cut out)

Vyzkoušejte si vypsat první sloupec souboru `/etc/passwd`

```shell
cut -d: -f1 /etc/passwd
```

`-d` určuje oddělovač, ve kterém je soubor zapsán, v tomto případě `:`

`-f` určuje, který sloupec (po rozdělení oddělovačem) chceme vypsat (první sloupec má index `1`)

Jak zobrazíte třetí sloupec souboru `/etc/passwd`?

<details>
    <summary>
        Řešení
    </summary>

```shell
cut -d: -f3 /etc/passwd
```

</details>

Jak zobrazíte jméno uživatele a jeho domovský adresář ze souboru `/etc/passwd`?

<details>
    <summary>
        Řešení
    </summary>

```shell
cut -d: -f1,6 /etc/passwd
```

</details>

### `sed`

[manuálová stránka](https://man7.org/linux/man-pages/man1/sed.1p.html)

`sed` je základní příkaz pro editaci textu (stream editor)

Vyzkoušejte si nahradit všechny dvojtečky ve souboru `/etc/passwd` za mezery

```shell
sed 's/:/ /g' /etc/passwd
```

`'s/:/ /g'` je regulární výraz pro nahrazení všech výskytů `:` za mezeru

Formát je `s/<pattern>/<replacement>/<flags>` kde

- `s` znázorňuje, že se jedná o substituci
- `<pattern>` je regulární výraz, který chceme nahradit
- `<replacement>` je řetězec, kterým chceme ho nahradit
- `<flags>` jsou různé přepínače, například `g` pro globální nahrazení (klasické flagy pro regulární výrazy)

Jak zamaskujete uživatelské jména ve souboru `/etc/passwd` za `<masked>`?

<details>
    <summary>
        Řešení
    </summary>

```shell
sed 's/^[^:]*:/<masked>:/g' /etc/passwd
```

</details>

### `tar`

[manuálová stránka](https://man7.org/linux/man-pages/man1/tar.1.html)

`tar` je základní příkaz pro archivaci souborů a adresářů (tape archive)

Vytvořte si archiv `workshop.tar` ze souborů ve vašem domovském adresáři

```shell
tar -cf workshop.tar ~
```

- `-c` vytvoření archivu
- `-f` určení názvu archivu

Jak zobrazíte obsah archivu `workshop.tar`?

<details>
    <summary>
        Řešení
    </summary>

```shell
tar -tf workshop.tar
```

- `-t` zobrazení obsahu archivu
- `-f` určení názvu archivu

</details>

Jak rozbalíte archiv `workshop.tar` do adresáře `~/workshop`?

<details>
    <summary>
        Řešení
    </summary>

```shell
tar -xf workshop.tar -C ~
```

- `-x` rozbalení archivu
- `-f` určení názvu archivu
- `-C` určení cílového adresáře

</details>

Jak vyextrahujete pouze soubor `.bash_history` z archivu `workshop.tar`?

<details>
    <summary>
        Řešení
    </summary>

```shell
tar -xf workshop.tar -C / home/<username>/.bash_history
```

</details>

Jak jste si možná všimli, `tar` balí i celé cesty k souborům, což může být nežádoucí

Komplikuje nám to například rozbalování archivu, jelikož jsme museli specifikovat

1. root adresář `/` jako cíl rozbalení
2. kompletní cestu k souboru `.bash_history`

Jak vytvoříte archiv `workshop2.tar`, ve kterém soubory nebudou obsahovat prefix `home/<username>`?

<details>
    <summary>
        Řešení
    </summary>

```shell
tar -cf workshop2.tar -C ~ .
```

- `-C` určení kořenového adresáře

</details>

Zobrazte si obsah archivu `workshop2.tar`

<details>
    <summary>
        Řešení
    </summary>

```shell
tar -tf workshop2.tar
```

Nyní můžeme jednoduše extrahovat soubor `.bash_history` do domovského adresáře

```shell
tar -xf workshop2.tar ./.bash_history
```

</details>

> Odstranění prefixu je velmi užitečné, pokud chceme archivovat soubory z jednoho adresáře a následně je rozbalit do jiného adresáře

> Prefix `./` lze dodatečně odstranit pomocí argumentu `--transform='s/^\.\///'`

### `date`

[manuálová stránka](https://man7.org/linux/man-pages/man1/date.1.html)

`date` je základní příkaz pro zobrazení aktuálního data a času

Vyzkoušejte si zobrazit aktuální datum a čas

```shell
date
```

Jak zobrazíte pouze aktuální datum?

<details>
    <summary>
        Řešení
    </summary>

```shell
date '+%Y-%m-%d'
```

</details>

Jak zobrazíte pouze aktuální čas?

<details>
    <summary>
        Řešení
    </summary>

```shell
date '+%H:%M:%S'
```

</details>

Jak zobrazíte aktuální datum a čas ve formátu `YYYY-MM-DD HH:MM:SS`?

<details>
    <summary>
        Řešení
    </summary>

```shell
date '+%Y-%m-%d %H:%M:%S'
```

</details>

Jak zobrazíte aktuální datum a čas ve formátu `YYYY-MM-DD_HH-MM-SS`?

<details>
    <summary>
        Řešení
    </summary>

```shell
date '+%Y-%m-%d_%H-%M-%S'
```

</details>

Jak zobrazíte datum, které bylo před 5 dny?

<details>
    <summary>
        Řešení
    </summary>

```shell
date -d '5 days ago' '+%Y-%m-%d'
```

</details>

Jak zobrazíte datum, které bude za 5 dnů?

<details>
    <summary>
        Řešení
    </summary>

```shell
date -d '5 days' '+%Y-%m-%d'
```

</details>

## Příkazy a expanze

### Expanze

[manuálová stránka](https://www.man7.org/linux/man-pages/man1/bash.1.html#EXPANSION)

Shellové expanze je jeden z kroků při zpracovávní shellových příkazů a zaměřuje se na speciální znaky

- `*` - shoda s libovolným počtem znaků
- `?` - shoda s jedním znakem
- `[]` - shoda s jedním znakem z množiny
- `{}` - expanze složených závorek
- `~` - domovský adresář
- `~<username>` - domovský adresář uživatele
- ...

Vyzkoušejte si vypsat všechny skryté soubory ve vašem domovském adresáři

```shell
ls ~/.*
```

Shell tyto znaky expanduje před spuštěním samotného příkazu nahradí skutečnými soubory

`ls` tedy nemusí umět pracovat s těmito znaky, ale shell mu je předá již expandoané

Podívejte se například na to, jak jednoduchý `echo` příkaz pracuje s expanzí

```shell
echo ~/.*
```

Jak zobrazíte řetězce `hello1`, `hello2`, ... , `hello849`, `hello850`?

<details>
    <summary>
        Řešení
    </summary>

```shell
echo hello{1..850}
```

</details>

Podobný styl expanze provádí i pro proměnné prostředí

```shell
echo $SHELL
```

Nastavte si do proměnné `MY_VAR` hodnotu `hello`

```shell
MY_VAR=hello
```

Jak zobrazíte řetezec `MY_VAR is set to hello`?

<details>
    <summary>
        Řešení
    </summary>

```shell
echo "MY_VAR is set to $MY_VAR"
```

</details>

Shell **neexpanduje** proměnné v jednoduchých uvozovkách

```shell
echo 'This variable will not be expanded: $MY_VAR'
```

## Skripty

Shellové příkazy mohou být skládány do skriptů, které mohou být spouštěny jako celek

Vytvořte si skript `hello.sh`, který vypíše řetězec `Hello, world!`

```shell
#!/bin/bash

echo 'Hello, world!'
```

Skripům je vhodné nastavit práva pro spuštění

```shell
chmod +x hello.sh
```

Následně můžete skript spustit

```shell
./hello.sh
```

Vytvořte si skript `greet.sh`, který vypíše řetězec `Hello, $1!`

> `$1` je první argument, který je předán skriptu

Skript budeme chtít volat s argumentem, například `world`

```shell
./greet.sh world
```

Jak vytvoříte skript `greet.sh`?

<details>
    <summary>
        Řešení
    </summary>

```shell
#!/bin/bash

echo "Hello, $1!"
```

```shell
chmod +x greet.sh
```

</details>

### `for`

`for` je základní příkaz pro iteraci přes seznam prvků

Vytvořte si skript `hello.sh`, který vypíše řetězec `Hello, world!` 5x

```shell
#!/bin/bash

for i in {1..5}
do
    echo "Hello, world!"
done
```

Jak vytvoříte skript `greet.sh`, který vypíše řetězec předaný řetezec X-krát?

Volání bude vypada takto

```shell
./greet.sh 10 "Hello, world!"
```

<details>
    <summary>
        Řešení
    </summary>

```shell
#!/bin/bash

for i in {1..$1}
do
    echo "$2"
done
```

</details>

### `if`

`if` je základní příkaz pro podmíněné vykonání příkazů

Vytvořte si skript `greet.sh`, který vypíše

- `foo` pokud je první argument `bar`
- `baz` pokud je první argument `qux`

Volání bude vypadat takto

```shell
./greet.sh bar

./greet.sh qux
```

<details>
    <summary>
        Řešení
    </summary>

```shell
#!/bin/bash

if [ "$1" == "bar" ]
then
    echo "foo"
elif [ "$1" == "qux" ]
then
    echo "baz"
fi
```

</details>

### `case`

`case` je základní příkaz pro podmíněné vykonání příkazů, který je vhodný pro porovnání s více hodnotami

Jedná se o alternativu k více známému `switch` příkazu v jiných programovacích jazycích

Vytvořte si skript `greet.sh`, který vypíše

- `foo` pokud je první argument `bar`
- `baz` pokud je první argument `qux`

`default` vypíše `unknown`

<details>
    <summary>
        Řešení
    </summary>

```shell
#!/bin/bash

case "$1" in
    bar)
        echo "foo"
        ;;
    qux)
        echo "baz"
        ;;
    *)
        echo "unknown"
        ;;
esac
```

</details>

### subshell

Ve skriptech je někdy potřeba spustit příkazy v novém shellu, který je oddělený od rodičovského shellu

Toho lze docílit pomocí subshellu

Vytvořte si skript `subshell.sh`, který si do proměnné `MY_VAR` uloží výstup příkazu `ls -la` a následně tento výstup vypíše

<details>
    <summary>
        Řešení
    </summary>

```shell
#!/bin/bash

MY_VAR=$(ls -la)

echo "$MY_VAR"
```

</details>

---

## Samostatné úkoly na skripty

### Úkol 1

Vytvořte skript, který podle prvního argumentu vypíše, zdali uživatel s tímto jménem existuje

V případě, že uživatel existuje, vypíše `User exists`, jinak vypíše na standardní chybový výstup `User does not exist` a skončí se stavovým kódem `1`

Použijte pouze příkazy, které jsme si doposud probrali

```shell
./user_exists.sh root
```

<details>
    <summary>
        Řešení
    </summary>

```shell
#!/bin/bash

if grep -q "^$1:" /etc/passwd
then
    echo "User exists"
else
    echo "User does not exist" >&2
    exit 1
fi
```

</details>

Modifikujte skript tak, aby vypsal i uživatelské id, domovský adresář a shell ve formátu

- `uid: <uid>`
- `home: <home>`
- `shell: <shell>`

<details>
    <summary>
        Řešení
    </summary>

```shell
#!/bin/bash

if grep -q "^$1:" /etc/passwd
then
    UID=$(grep "^$1:" /etc/passwd | cut -d: -f3)
    HOME=$(grep "^$1:" /etc/passwd | cut -d: -f6)
    SHELL=$(grep "^$1:" /etc/passwd | cut -d: -f7)
    
    echo "uid: $UID"
    echo "home: $HOME"
    echo "shell: $SHELL"
else
    echo "User does not exist" >&2
    exit 1
fi
```

</details>

### Úkol 2

Vytvořte zálohou skript, který zazálohuje vaši složku `~/.ssh` do adresáře `~/backup`

Zálhování bude provedeno pomocí `tar` archivu a bude provádět rotaci záloh

- při každém spuštění skriptu se vytvoří nový archiv ve formátu `backup-<timestamp>.tar`
- při každém spuštění skriptu se smažou nejstarší zálohy, pokud jich je více než 5

Použijte pouze příkazy, které jsme si doposud probrali

```shell
./backup.sh
```

<details>
    <summary>
        Řešení
    </summary>

```shell
#!/bin/bash

BACKUP_DIR=~/backup
SSH_DIR=~/.ssh

# vytvoření adresáře pro zálohy
mkdir -p $BACKUP_DIR

# vytvoření nové zálohy
tar -cf $BACKUP_DIR/backup-$(date +%s).tar -C $SSH_DIR .

# smazání nejstarších záloh
OLD=$(ls -t $BACKUP_DIR | tail -n +6)
rm -f $BACKUP_DIR/$OLD
```

</details>

---

## Řetězení příkazů

V shellu můžete řetězit příkazy pomocí `;`, `&&` a `||`

- `;` - odděluje příkazy a spustí je postupně
- `&&` - odděluje příkazy a spustí je postupně, pokud předchozí příkaz vrátí stavový kód `0`
- `||` - odděluje příkazy a spustí je postupně, pokud předchozí příkaz vrátí stavový kód `1`

Vyzkoušejte si řetězení příkazů

```shell
echo "Hello, world!" ; echo "Goodbye, world!"
```

```shell
echo "Hello, world!" && echo "Goodbye, world!"
```

```shell
echo "Hello, world!" || echo "Goodbye, world!"
```

Jaký bude výstup následujícího příkazu?

```shell
echo "Hello, world!" && false || echo "Goodbye, world!"
```

<details>
    <summary>
        Řešení
    </summary>

`false` vrací stavový kód `1`, tedy se spustí i poslední příkaz

```text
Hello, world!
Goodbye, world!
```

</details>

Jaký bude výstup následujícího příkazu?

```shell
exit 1 && echo "Hello, world!"
```

A jaký bude výstup následujícího příkazu?

```shell
exit 1 || echo "Hello, world!"
```

### pipelining

Pipelining je základní technika pro přesměrování výstupu jednoho příkazu na vstup druhého

Vyzkoušejte si pipelining

```shell
ls ~ | grep 'log'
```

Jaký bude výstup následujícího příkazu?

```shell
ls ~ | grep 'log' | wc -l
```

Zkuste zkombinovat `find` a `grep` tak, aby vypsaly všechny soubory ve vašem domovském adresáři, které obsahují slovo `log`

<details>
    <summary>
        Řešení
    </summary>

```shell
find ~ | grep 'log'
```

</details>

Modifikujte předchozí příkaz tak, aby místo `/home/<username>` vypisoval pouze `~`

<details>
    <summary>
        Řešení
    </summary>

```shell
find ~ | grep 'log' | sed "s|/home/.*/|~/|"
```

</details>

## Přesměrování

Výstup příkazů lze přesměrovat do souborů, pípes a jiných procesů

- `>` - přesměrování výstupu do souboru (přepíše obsah, overwrite)
- `>>` - přesměrování výstupu do souboru (přidá na konec, append)
- `<` - přesměrování vstupu ze souboru (stdin)

Vyzkoušejte si přesměrování výstupu

```shell
echo "Hello, world!" > hello.txt
```

Jaký bude obsah souboru `hello.txt`?

Uložte si výstup příkazu `ls -la` do souboru `ls.txt`

```shell
ls -la > ls.txt
```

Velká část programů podporuje čtění vstupu ze standardního vstupu, již jsme viděli například `grep`

### `xargs`

[manuálová stránka](https://man7.org/linux/man-pages/man1/xargs.1.html)

Dalším zajímavým a velmi užitečným programem je `xargs`, který umožňuje zpracovávat vstupní řádky a spouštět s nimi příkazy

Vyzkoušejte si například modifikaci výstupu příkazu `ls` pomocí `xargs`

```shell
ls | xargs -I {} echo "File: {}"
```

- `-I` určuje, že se má nahradit `{}` řádkem vstupu

Pokud tedy na vstupu dostáváme seznam souborů, můžeme s nimi spouštět různé příkazy a ukladát je například do specální složky

Jak zkopírujete všechny soubory ve vašem domovském adresáři do složky `~/backup`, ale se jménem ve formátu `<filename>.bak`?

<details>
    <summary>
        Řešení
    </summary>

```shell
ls ~ | xargs -I {} cp {} ~/backup/{}.bak
```

</details>

### `tee`

[manuálová stránka](https://man7.org/linux/man-pages/man1/tee.1.html)

`tee` je základní program, který zapisuje vstup na standardní výstup a zároveň do souboru

Jedná se o tzv. T-příkaz, který zapisuje vstup na dvě místa 

- "dolů", do souboru
- "dopředu", na svůj standardní výstup

Využívá se například při logování

Vyzkoušejte si zápis výstupu příkazu `ls` do souboru `ls.txt` a zároveň na standardní výstup

```shell
ls -la | tee lsla.txt
```

Lze nahlédnout, že `tee` vypisuje výstup na standardní našeho terminálu, ale zároveň zapisal výstup příkazu `ls` do souboru `lsla.txt`

Programy mohou zapisovat do tzn. file-descriptorů, které jsou číslovány

- `0` - standardní vstup (stdin, readonly)
- `1` - standardní výstup (stdout)
- `2` - standardní chybový výstup (stderr)
- ...

Pokud některý program zapisuje to `stderr`, lze tento výstup přesměrovat do `stdout` pomocí `2>&1`

Ale zajímavější je často odfiltrovat klasický `stdout` výstup a ponechat pouze `stderr`

```shell
<program> >/dev/null
```

Tímto jsme shellu řekli, že má filedescriptor `1` (defaultní) (stdout) přesměrovat do `/dev/null`, což je speciální soubor, který všechno co se do něj zapíše, okamžitě zahodí

Stejným postupem můžeme odfiltrovat chybový výstup

```shell
<program> 2>/dev/null
```

Tímto jsme shellu řekli, že má filedescriptor `2` (stderr) přesměrovat do `/dev/null`, což je speciální soubor, který všechno co se do něj zapíše, okamžitě zahodí

Filtrovat stderr je někdy vhodné, pokud například spouštíme `find` na celém systémovém disku a jelikož do některých adresářů nemáme přístup, chybový výstup může být velmi dlouhý

## `sudo`, `su` a uživatelská oprávnění






<!-- {% endraw %} -->
