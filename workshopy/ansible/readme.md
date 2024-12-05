<!-- {% raw %} -->

# Ansible workshop


## Úvod

[Ansible](https://docs.ansible.com/ansible/latest/) je nástroj pro automatizaci konfigurace a správy serverů.
Jeho hlavní výhodou je jednoduchost správy a rychlost provádění akcí na více serverech najednou.

Ansible je **agentless**, což znamená, že na cílových serverech není potřeba žádný agent, stačí **SSH přístup**.

Hlavními koncepty Ansible jsou:

- **Playbook** - soubor s instrukcemi, co a jak má být provedeno
- **Role** - znovupoužitelný soubor playbooků
- **Inventory** - seznam serverů, na kterých se mají playbooky spustit
- **Module** - "knihovna" funkcí, které Ansible používá k provádění akcí na serverech
- **Task** - jednotlivé kroky v playbooku, které se mají provést

## Příprava playgroundu

Nastartuje si nový `ubuntu` server přes Coder, nazvěte ho
- `<username>-ansible-control`

Dále si nastartujte 2 další `ubuntu` servery a nazvěte je 
- `<username>-ansible-server-1`
- `<username>-ansible-server-2`

Jďete na `control` server a vygenerujte si SSH klíč, kterým se budete přihlašovat na ostatní servery

```shell
ssh-keygen -f ~/.ssh/ansible-workshop
```

Následně si tento klíč přidejte na ostatní servery

```shell
control $ cat ~/.ssh/ansible-workshop.pub
```

A na ostatních serverech tento veřejný klíč přidejte do `~/.ssh/authorized_keys` (**na konec souboru**, nemažte nic co tam již je)

```shell
server-1 $ vim ~/.ssh/authorized_keys
server-2 $ vim ~/.ssh/authorized_keys
```

Zjistěte si IP adresy serverů

```shell
server-1 $ ip a
server-2 $ ip a
```

Vyzkoušejte, že se můžete přihlásit na ostatní servery pomocí SSH klíče

```shell
control  $ ssh -i ~/.ssh/ansible-workshop <username>@<ip-of-server-1>
server-1 $ hostname
server-1 $ exit

control  $ ssh -i ~/.ssh/ansible-workshop <username>@<ip-of-server-2>
server-2 $ hostname
server-2 $ exit
```

## Instalace Ansible

Na `control` serveru nainstalujte Ansible

```shell
control $ sudo apt update
control $ sudo apt install ansible
```

Ověřte, že Ansible je nainstalovaný

```shell
control $ ansible --version
```

Verze by měla být alespoň `2.7`

Vyzkoušeje nejjednodušší příkaz, který zjistí, zdali jsou servery dostupné

```shell
control $ ansible all -m ping -i "<ip-of-server-1>," -u <username> --private-key ~/.ssh/ansible-workshop
```

> **Poznámka**: Všimněte si, že za IP adresou serveru je čárka, to je důležité.
> Normálně se přepínač `-i` používá pro `inventory` soubor, ale v tomto případě předáváme IP adresu serveru přímo.
> V tomto případě je potřeba za IP adresou přidat čárku, aby Ansible nehledal inventory soubor, ale použil IP adresu přímo.
> 
> Více serverů můžete přidat takto: `-i "<ip-of-server-1>,<ip-of-server-2>,"`

Výsledek tohoto příkaazu by měl vypadat nějak takto

```shell
<ip> | SUCCESS => {
    "ansible_facts": {
        "discovered_interpreter_python": "/usr/bin/python3"
    },
    "changed": false,
    "ping": "pong"
}
```

Zkuste si, že připojení funguje i pro druhý server

## Inventory

Založte si pracovní adresář pro tento workshop

```shell
control $ mkdir ansible-workshop
control $ cd ansible-workshop
```

Než začneme s celým Ansiblem, pojďme si vytvořit `inventory` soubor, který bude obsahovat IP adresy našich serverů.

Tento soubor slouží také pro definici skupin serverů, což nám umožní provádět akce na více serverech najednou.

Vytvořte si soubor `inventory` s následujícím obsahem

```shell
control $ vim inventory
```

```ini
[all]
<ip-of-server-1>
<ip-of-server-2>
```

Nyní můžeme použít tento inventory soubor pro naše příkazy

```shell
control $ ansible all -m ping -i inventory -u <username> --private-key ~/.ssh/ansible-workshop
```

Výstup by měl být podobný jako předtím, ale tentokrát jsme použili inventory soubor a nemuseli jsme zadávat IP adresy ručně.
Uvidíte také, že ansible provedl příkaz na obou serverech.

## Config

Jelikož jsme líní, nechceme pokaždé zadávat parametry pro připojení k serverům (`-i inventory -u <username> --private-key ~/.ssh/ansible-workshop`),
takže si vytvoříme konfigurační soubor.

Vytvořte si soubor `ansible.cfg` s následujícím obsahem

```shell
control $ vim ansible.cfg
```

```ini
[defaults]
inventory = inventory
private_key_file = ~/.ssh/ansible-workshop
remote_user = <username>
```

Tyto parametry se budou používat pro všechny příkazy, které spustíme pomocí Ansible (v tomto adresáři).

Můžeme otestovat, zdali se nám konfigurace načte správně

```shell
control $ ansible all -m ping
```

## Playbook

Nyní si vytvoříme první playbook, který nám nainstaluje `nginx` na obou serverech.

Vytvořte si soubor `nginx-playbook.yml` s následujícím obsahem

```shell
control $ vim nginx-playbook.yml
```

```yaml
---
- name: Install Nginx
  hosts: all
  become: true
  tasks:
    - name: Install Nginx
      apt:
        name: nginx
        state: present
```

Playbook je YAML soubor, který obsahuje seznam `plays`, kde každý `play` obsahuje několik `tasks`.

Play je logické seskupení tasků, které se mají provést na daném serveru.
Pro každý `play` se specifikuje seznam serverů či skupin serverů, na kterých se mají tasky provést.

Také zde často uvidíte `become: true`, což znamená, že při spouštění tasků se má použít `sudo`.
(nepřihlašujeme se jako root, proto je potřeba `sudo`)

Každý `task` má několik atributů, nejdůležitější jsou:

- `name` - název tasku, který se zobrazí v logu
- modul, který se má použít (v tomto případě `apt`)
- parametry modulu (v tomto případě `name` a `state`)

Spusťte svůj první playbook

```shell
control $ ansible-playbook nginx-playbook.yml
```

Výsledek by měl zobzazit tento výstup

```text
PLAY [Install Nginx] *************************************************************************************************

TASK [Gathering Facts] ***********************************************************************************************
ok: [<ip-of-server-1>]
ok: [<ip-of-server-2>]

TASK [Install Nginx] *************************************************************************************************
changed: [<ip-of-server-1>]
changed: [<ip-of-server-2>]

PLAY RECAP ***********************************************************************************************************
<ip-of-server-1>               : ok=2    changed=1    unreachable=0    failed=0    skipped=0    rescued=0    ignored=0   
<ip-of-server-2>               : ok=2    changed=1    unreachable=0    failed=0    skipped=0    rescued=0    ignored=0
```

Vidíte, že Ansible provedl task na obou serverech a nainstaloval `nginx`.

Zkuste si příkaz spustit ještě jednou, uvidíte, že se nic nestane (neuvidíte `changed`), protože `nginx` je již nainstalovaný.

Přes Coder si protunelujte port `80` z `server-1` a `server-2` a zkontrolujte, že `nginx` běží (zobrazí se defaultní stránka).

### Další moduly

Ansible má [mnoho modulů](https://docs.ansible.com/ansible/latest/collections/index_module.html), které můžete použít pro různé úkoly.

Například modul `service` můžete použít pro start/stop/restart služeb.
Nebo modul `copy` pro kopírování souborů z `control` serveru na cílové servery.

Pojďme si vyzkoušet několik dalších modulů.

#### Modul `copy`

Kompetní dokumentace `copy` modulu je [zde](https://docs.ansible.com/ansible/latest/collections/ansible/builtin/copy_module.html)

Vytvoříme si vlastní HTML stránku a zkopírujeme ji pomocí modulu `copy` na oba servery.

Ansible modul `copy` hledá soubory v adresáři `files` ve stejném adresáři jako playbook.

Vytvořte si soubor `files/index.html` s následujícím obsahem

```shell
control $ mkdir files
control $ vim files/index.html
```

```html
<!DOCTYPE html>
<html>
<head>
    <title>Ansible Workshop</title>
</head>
<body>
    <h1>Hello from Ansible!</h1>
</body>
</html>
```

Upravte playbook tak, aby zkopíroval tento soubor na oba servery

```shell
control $ vim nginx-playbook.yml
```

```yaml
    - name: Copy index.html
      copy:
        src: index.html
        dest: /var/www/html/index.html
```

> **Poznámka**: `src` je cesta k souboru na `control` serveru, `dest` je cesta, kam se má soubor zkopírovat na cílový server.
> `src` je lokace souboru pro zkopírování relativní k adresáři `files`.
> 
> V případě, že soubor v dané lokaci neexistuje, Ansible vyzkouší ještě [několik dalších lokací](https://docs.ansible.com/ansible/latest/playbook_guide/playbook_pathing.html#resolving-local-relative-paths) a pokud soubor nenajde, skončí s chybou.

Spusťte znovu playbook

```shell
control $ ansible-playbook nginx-playbook.yml
```

Ve výpisu příkaazu uvidíte, že Ansible zkopíroval soubor na oba servery.

```text
...
TASK [Copy index.html]
changed: [<ip-of-server-1>]
changed: [<ip-of-server-2>]
...
```

Zkontrolujte (přes Coder), že se soubor zkopíroval a že nginx zobrazuje novou stránku.

#### modul `template`

Kompletní dokumentace `template` modulu je [zde](https://docs.ansible.com/ansible/latest/collections/ansible/builtin/template_module.html)

Dalším užitečným modulem je `template`, který umožňuje použít Jinja2 šablonu pro generování souborů.

Jedná se v postatě o stejný modul jako `copy`,
ale Ansible místo jednoduchého kopírování souboru nejdříve zdrojový soubor zpracuje pomocí Jinja2 šablonovacího systému
a teprve poté ho zkopíruje na cílový server.

Rozdíl je, že modul `template` hledá šablony v adresáři `templates` ve stejném adresáři jako playbook.

Vytvořte si soubor `templates/id.html.j2` s následujícím obsahem

```shell
control $ mkdir templates
control $ vim templates/id.html.j2
```

```html
<!DOCTYPE html>
<html>
<head>
    <title>Ansible Workshop</title>
</head>
<body>
    <h1>Hello from Ansible!</h1>
    <p>Server: {{ ansible_hostname }}</p>
</body>
</html>
```

Upravte playbook tak, aby zkopíroval tuto šablonu na oba servery

```shell
control $ vim nginx-playbook.yml
```

```yaml
    - name: Copy templated id.html
      template:
        src: id.html.j2
        dest: /var/www/html/id.html
```

Spusťte znovu playbook, zkontroluje, že nginx zobrazuje správnou stránku s hostname serveru.

> **Poznámka**: `ansible_hostname` je proměnná, kterou Ansible automaticky nastaví na hostname serveru, na kterém se task provádí.
> Více o proměnných, které Ansible nastavuje, najdete [zde](https://docs.ansible.com/ansible/latest/reference_appendices/special_variables.html)
> Vlastní proměnné můžete nastavit například v inventory souboru.
> 
> Syntaxe pro nastavení přoměnných je `<ip> moje_promenna=123` a následně v šabloně či playbooku můžete použít `{{ moje_promenna }}`

#### modul `service` a závislosti tasků

Kompletní dokumentace `service` modulu je [zde](https://docs.ansible.com/ansible/latest/collections/ansible/builtin/service_module.html)

Posledním modulem, který si v této sekci ukážeme je `service`, který umožňuje start/stop/restart služeb.

Vytvoříme si konfigurační soubor pro nginx, který bude řídit, na jakém portu bude nginx poslouchat.

V případě, že se tento soubor změní, bude potřeba restartovat nginx, aby se změny projevily.

Vytvořte si soubor `files/nginx.conf` s následujícím obsahem

```shell
control $ vim files/nginx.conf
```

```nginx
server {
    listen 8080;

    location / {
        root /var/www/html;
    }
}
```

Upravte playbook tak, aby zkopíroval tento soubor na oba servery a restartoval nginx, pouze pokud se soubor změnil

```shell
control $ vim nginx-playbook.yml
```

```yaml
    - name: Copy nginx.conf
      copy:
        src: nginx.conf
        dest: /etc/nginx/sites-available/default
      register: nginx_conf

    - name: Restart Nginx
      service:
        name: nginx
        state: restarted
      when: nginx_conf.changed
```

> **Poznámka**: `/etc/nginx/sites-available/default` je cesta k defaultní konfiguraci nginx na Ubuntu.

> **Poznámka**: `register` je atribut, který uloží výstup tasku do proměnné, kterou můžete použít v dalším tasku.
> V tomto případě uložíme výstup kopírování souboru do proměnné `nginx_conf` a poté v dalším tasku pomocí `when` podmínky zkontrolujeme, zdali se soubor změnil.

Spusťte znovu playbook, zkontrolujte, že nginx nově poslouchá na portu `8080` (a né na původním portu `80`).

> **Poznámka**: Ansible na tyto "restartovací" procesy doporučuje používat tzv. `handlers`, které se spustí až na konci playbooku a pouze pokud byl task, který je volá, proveden.
> Jedná se o takový druh "callbacku", který se spustí až na konci playbooku, pokud ho nějaký task "aktivuje".
> 
> Více o handlerech najdete [v dokumentaci](https://docs.ansible.com/ansible/latest/playbook_guide/playbooks_handlers.html)

### Samostatná úloha 1

Vytvořte si playbook, který na serveru nastaví cron job, který každou minutu zaloguje (připíše nový řádek) do souboru `/var/log/cron.log` s aktuálním datumem a časem.

> **Nápověda**: Existuje k tomu užitečný modul.

Vytvořte také playbook, který tento cron job odstraní.

> **Bonus**: Umožněte nastavit interval, ve kterém se má cron job spouštět, pomocí proměnné v inventory souboru.

<details>
    <summary>
        Řešení
    </summary>

Vytvořte si soubor `cron-playbook.yml` s následujícím obsahem

```shell
control $ vim cron-playbook.yml
```

```yaml
---
- name: Setup cron job
  hosts: all
  become: true
  tasks:
    - name: Setup cron job
      cron:
        name: "log_time"
        minute: "*"
        hour: "*"
        job: "date >> /var/log/cron.log"
```

Playbook na odstranění cron jobu

```shell
control $ vim cron-remove-playbook.yml
```

```yaml
---
- name: Remove cron job
  hosts: all
  become: true
  tasks:
    - name: Remove cron job
      cron:
        name: "log_time"
        state: absent
```

</details>

### Samostatná úloha 2

Vytvořte si velmi jednoduchý `nodejs` HTTP server, který bude poslouchat na portu `3000` a zobrazovat `Hello from Node.js!`.

Po prvním úspěšném spuštění serveru, upravte zdrojový soubor (např. upravte hlášku, kterou server vypisuje) a zajistěte, že nové spuštění playbooku aktualizuje server.

> **Poznámka**: Server bude muset být spuštěn pomocí nějakého hlavního procesu, který se bude starat o jeho spuštění a běh.
> 
>Můžete zvolit spouštění přes vlastní `systemd` službu, nebo použít proces manager (např. `pm2`).

> **Bonus**: Umožněte nastavit port, na kterém server běží, pomocí proměnné v inventory souboru.

<details>
    <summary>
        Řešení
    </summary>

Vytvořte si soubor `files/server.js` s následujícím obsahem

```shell
control $ vim files/server.js
```

```javascript
const http = require('http');

const server = http.createServer((req, res) => {
    res.writeHead(200, { 'Content-Type': 'text/plain' });
    res.end('Hello from Node.js!\n');
});

server.listen(3000, '0.0.0.0', () => {
    console.log('Server running at http://0.0.0.0:3000/');
});
```

Playbook pro instalaci `nodejs`, `pm2` a spuštění serveru

```shell
control $ vim nodejs-playbook.yml
```

```yaml
---
- name: Install Node.js
  hosts: all
  become: true
  tasks:
    - name: Install Node.js
      apt:
        name: nodejs
        state: present
        
    - name: Install npm
      apt:
        name: npm
        state: present

    # pm2 is installed globally using npm
    - name: Install pm2
      npm:
        name: pm2
        global: yes

    - name: Copy server.js
      copy:
        src: server.js
        dest: /srv/server.js
      register: server_file
      
    - name: Determine, if server is running
      command: pm2 pid my-nodejs-server
      register: pm2_server_pid
      ignore_errors: yes
      changed_when: false
    
    - name: Stop server
      command: pm2 stop my-nodejs-server
      when: server_file.changed and pm2_server_pid.stdout is defined and pm2_server_pid.stdout | int > 0
      register: pm2_stop
      
    - name: Start server
      command: pm2 start /srv/server.js --name my-nodejs-server
      when: pm2_stop.changed or server_file.changed or pm2_server_pid.stdout is not defined or pm2_server_pid.stdout | int == 0
```

Spusťte playbook a zkontrolujte, že server běží na portu `3000`.

Po úspěšném spuštění serveru, upravte zdrojový soubor `server.js` a spusťte playbook znovu.

Pro odstranění serveru můžete použít playbook

```shell
control $ vim nodejs-remove-playbook.yml
```

```yaml
---
- name: Stop server
  hosts: all
  become: true
  tasks:
    - name: Stop server
      command: pm2 stop my-nodejs-server
      ignore_errors: yes
```

</details>

### Samostatná úloha 3

Pomocí Ansible playbooku nainstaluje a nakonfigurujte XFCE desktop environment na serveru `server-1`.

Poté nainstaluje noVNC server a nakonfigurujte ho tak, aby se připojil k virtuálnímu monitoru, který bude zobrazovat XFCE desktop.

Webový interface noVNC serveru by měl být dostupný na portu `9000` a dostupný přes Coder.

> **Poznámka**: noVNC server je webový VNC klient, který umožňuje připojit se k VNC serveru přes webový prohlížeč.
> 
> Podle zvoleného VNC serveru a jeho nastavní, může být potřeba nastavit heslo pro připojení (heslo pro VNC server).

> **Bonus**: Umožněte nastavit port, na kterém bude noVNC server běžet, pomocí proměnné v inventory souboru.

> **Bonus**: Umožněte nastavit heslo pro připojení k noVNC serveru, pomocí proměnné v inventory souboru.

<details>
    <summary>
        Řešení
    </summary>

Nejdříve upravíme `inventory` soubor, aby obsahoval skupinu pro servery, na kterých chceme nainstalovat XFCE a noVNC

```shell
control $ vim inventory
```

```ini
[all]
<ip-of-server-1>
<ip-of-server-2>

[xfce_novnc]
<ip-of-server-1> novnc_port=9000 novnc_password=123456
```

Budeme spouštět VNC server, který očekává inicializační skript `~/.vnc/xstartup`, který spustí XFCE desktop.

Vytvoříme si tedy tento skript

```shell
control $ vim files/xstartup
```

```shell
#!/bin/sh
unset SESSION_MANAGER
unset DBUS_SESSION_BUS_ADDRESS

xrdb $HOME/.Xresources
startxfce4 &
```

Jako další krok si vytvoříme šablonu pro systemd service pro TightVNC server

```shell
control $ vim templates/tightvnc.service.j2
```

```ini
[Unit]
Description=TightVNC server
After=syslog.target network.target

[Service]
Type=forking
ExecStart=/usr/bin/vncserver :1
ExecStop=/usr/bin/vncserver -kill :1
User={{ ansible_user }}
Restart=on-failure

[Install]
WantedBy=multi-user.target
```

Dále si vytvoříme šablonu pro systemd service pro noVNC server

```shell
control $ vim templates/novnc.service.j2
```

```ini
[Unit]
Description=noVNC server
After=syslog.target network.target

[Service]
Type=simple
ExecStart=/usr/bin/websockify --web /usr/share/novnc/ {{ novnc_port }} localhost:5901
User={{ ansible_user }}
Restart=on-failure

[Install]
WantedBy=multi-user.target
```

A konečně si vytvoříme playbook `xfce-playbook.yml` s následujícím obsahem

```shell
control $ vim xfce-novnc-playbook.yml
```

```yaml
---
- name: Install XFCE accessible via noVNC
  hosts: xfce_novnc
  become: true
  tasks:
    - name: Install XFCE desktop
      apt:
        name: xfce4 dbus-x11
        state: present
    
    - name: Install TightVNC server
      apt:
        name: tightvncserver
        state: present
     
    - name: Install noVNC
      apt:
        name: novnc
        state: present
    
    - name: Create .vnc directory in home directory
      file:
        path: /home/{{ ansible_user }}/.vnc
        state: directory
        owner: "{{ ansible_user }}"
        group: "{{ ansible_user }}"
        mode: 0700

    - name: Generate VNC password
      command:
        cmd: vncpasswd /home/{{ ansible_user }}/.vnc/passwd
        stdin: "{{ novnc_password }}\n{{ novnc_password }}\nn"
    
    - name: Set correct permissions for VNC password
      file:
        path: /home/{{ ansible_user }}/.vnc/passwd
        owner: "{{ ansible_user }}"
        group: "{{ ansible_user }}"
        mode: 0600
    
    - name: Copy xstartup file
      copy:
        src: xstartup
        dest: /home/{{ ansible_user }}/.vnc/xstartup
        owner: "{{ ansible_user }}"
        group: "{{ ansible_user }}"
        mode: 0700
      register: xstartup_file
    
    - name: Copy TightVNC service file
      template:
        src: tightvnc.service.j2
        dest: /etc/systemd/system/tightvnc.service
        owner: root
        group: root
        mode: 0644
      register: tightvnc_service
    
    - name: Copy noVNC service file
      template:
        src: novnc.service.j2
        dest: /etc/systemd/system/novnc.service
        owner: root
        group: root
        mode: 0644
      register: novnc_service

    - name: Start TightVNC service
      service:
        name: tightvnc
        state: started
        enabled: yes
    
    - name: Start noVNC server
      service:
        name: novnc
        state: started
        enabled: yes
    
    - name: Reload systemd daemon
      systemd:
        daemon_reload: yes
      when: xstartup_file.changed or tightvnc_service.changed or novnc_service.changed
    
    - name: Restart TightVNC service
      service:
        name: tightvnc.service
        state: restarted
      when: xstartup_file.changed or tightvnc_service.changed
    
    - name: Restart noVNC service
      service:
        name: novnc.service
        state: restarted
      when: novnc_service.changed
```

</details>

<!-- {% endraw %} -->
