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

<!-- {% endraw %} -->
