<!-- {% raw %} -->

# Docker workshop

## Úvod

[Docker](https://www.docker.com/) je platforma pro kontejnerizaci aplikací,
která umožňuje balení, distribuci a spouštění aplikací v izolovaných prostředích nazývaných kontejnery.

Docker kontejnery jsou lehké a rychlé, protože sdílejí jádro hostitelského operačního systému
a nevyžadují plnou virtualizaci hardwaru jako tradiční virtuální stroje.

Hlavními koncepty Dockeru jsou:

- **Image** - šablona pro vytvoření kontejneru, obsahuje vše potřebné pro běh aplikace
- **Container** - běžící instance image, izolované prostředí pro aplikaci
- **Dockerfile** - textový soubor s instrukcemi pro sestavení image
- **Registry** - úložiště pro Docker images (např. Docker Hub)
- **Volume** - persistentní úložiště dat mimo životní cyklus kontejneru
- **Network** - virtuální síť pro komunikaci mezi kontejnery

> Jaký je rozdíl mezi kontejnerem a virtuálním strojem?

<details>
<summary>Odpověď</summary>

Virtuální stroj (VM) emuluje celý hardware a běží vlastní operační systém,
což vyžaduje více zdrojů a je pomalejší.

Kontejner sdílí jádro hostitelského systému a izoluje pouze aplikaci a její závislosti,
což je rychlejší a efektivnější z hlediska využití zdrojů.

| Vlastnost | Kontejner | Virtuální stroj |
|-----------|-----------|-----------------|
| Izolace | Procesová | Hardwarová |
| Velikost | MB | GB |
| Start | Sekundy | Minuty |
| Výkon | Nativní | Overhead |
| OS | Sdílené jádro | Vlastní OS |

</details>

## Příprava playgroundu

Nastartujte si nový `docker` workspace přes Coder, nebo použijte jakýkoliv systém s nainstalovaným Dockerem.

Ověřte, že Docker je nainstalovaný a běží:

```shell
docker --version
```

Výstup by měl vypadat podobně jako:

```text
Docker version 28.x.x, build xxxxxxx
```

Také ověřte, že Docker daemon běží:

```shell
docker info
```

Pokud vidíte informace o Dockeru, je vše v pořádku.

## Základní příkazy

### Spuštění prvního kontejneru

Spusťte si jednoduchý kontejner s `hello-world` obrazem:

```shell
docker run hello-world
```

Docker stáhne obraz z Docker Hub, vytvoří kontejner a spustí ho.
Po vypsání uvítací zprávy se kontejner automaticky ukončí.

### `docker run`

Příkaz `docker run` je základní příkaz pro spuštění kontejneru.

Syntaxe:

```shell
docker run [OPTIONS] IMAGE [COMMAND] [ARG...]
```

Nejčastější přepínače:

- `-d, --detach` - spustí kontejner na pozadí
- `-p, --publish` - mapování portů (host:kontejner)
- `-v, --volume` - připojení volume nebo adresáře
- `-e, --env` - nastavení proměnných prostředí
- `--name` - pojmenování kontejneru
- `--rm` - automatické odstranění kontejneru po ukončení
- `-it` - interaktivní režim s terminálem

Spusťte nginx webový server na pozadí:

```shell
docker run -d -p 8080:80 --name my-nginx nginx
```

Přes Coder si otevřete port `8080` a zkontrolujte, že nginx běží.

### `docker ps`

Příkaz `docker ps` zobrazuje běžící kontejnery.

```shell
docker ps
```

Jak zobrazíte všechny kontejnery, včetně ukončených?

<details>
<summary>Řešení</summary>

```shell
docker ps -a
```

</details>

Jak zobrazíte pouze ID kontejnerů?

<details>
<summary>Řešení</summary>

```shell
docker ps -q
```

</details>

### `docker stop` a `docker start`

Zastavte běžící nginx kontejner:

```shell
docker stop my-nginx
```

Ověřte, že kontejner již neběží:

```shell
docker ps
```

Spusťte kontejner znovu:

```shell
docker start my-nginx
```

### `docker logs`

Příkaz `docker logs` zobrazuje logy kontejneru.

```shell
docker logs my-nginx
```

Jak budete sledovat logy v reálném čase (podobně jako `tail -f`)?

<details>
<summary>Řešení</summary>

```shell
docker logs -f my-nginx
```

</details>

### `docker exec`

Příkaz `docker exec` umožňuje spustit příkaz uvnitř běžícího kontejneru.

Spusťte interaktivní shell uvnitř nginx kontejneru:

```shell
docker exec -it my-nginx /bin/bash
```

Uvnitř kontejneru můžete prohlížet soubory:

```shell
cat /etc/nginx/nginx.conf
exit
```

### `docker rm`

Příkaz `docker rm` odstraní kontejner.

Nejdříve zastavte kontejner:

```shell
docker stop my-nginx
```

Poté ho odstraňte:

```shell
docker rm my-nginx
```

Jak zastavíte a odstraníte kontejner jedním příkazem?

<details>
<summary>Řešení</summary>

```shell
docker rm -f my-nginx
```

Přepínač `-f` (force) zastaví běžící kontejner před odstraněním.

</details>

### `docker images`

Příkaz `docker images` zobrazuje stažené obrazy.

```shell
docker images
```

### `docker pull`

Příkaz `docker pull` stáhne obraz z registru.

```shell
docker pull alpine:latest
```

### `docker rmi`

Příkaz `docker rmi` odstraní obraz.

```shell
docker rmi hello-world
```

> **Poznámka**: Obraz nelze odstranit, pokud existuje kontejner, který ho používá.

## Dockerfile

Dockerfile je textový soubor obsahující instrukce pro sestavení Docker obrazu.

### Základní instrukce

- `FROM` - základní obraz, ze kterého se staví
- `RUN` - spuštění příkazu během sestavení
- `COPY` - zkopírování souborů z hostitele do obrazu
- `ADD` - podobné jako COPY, ale podporuje URL a rozbalování archivů
- `WORKDIR` - nastavení pracovního adresáře
- `ENV` - nastavení proměnné prostředí
- `EXPOSE` - dokumentace portu, který kontejner používá
- `CMD` - výchozí příkaz při spuštění kontejneru
- `ENTRYPOINT` - hlavní příkaz kontejneru

### Vytvoření vlastního obrazu

Vytvořte si pracovní adresář:

```shell
mkdir ~/docker-workshop
cd ~/docker-workshop
```

Vytvořte jednoduchý HTML soubor:

```shell
cat > index.html << 'EOF'
<!DOCTYPE html>
<html>
<head>
    <title>Docker Workshop</title>
</head>
<body>
    <h1>Hello from Docker!</h1>
    <p>Tato stránka běží v Docker kontejneru.</p>
</body>
</html>
EOF
```

Vytvořte Dockerfile:

```shell
cat > Dockerfile << 'EOF'
FROM nginx:alpine

COPY index.html /usr/share/nginx/html/index.html
EOF
```

Sestavte obraz:

```shell
docker build -t my-web:v1 .
```

Spusťte kontejner:

```shell
docker run -d -p 8080:80 --name my-web my-web:v1
```

Přes Coder otevřete port `8080` a zkontrolujte, že vidíte vaši stránku.

### Samostatná úloha 1

Vytvořte Dockerfile pro jednoduchou Python aplikaci, která vypíše "Hello from Python in Docker!".

<details>
<summary>Řešení</summary>

Vytvořte adresář pro Python aplikaci:

```shell
mkdir -p ~/docker-workshop/01_python_app
cd ~/docker-workshop/01_python_app
```

Vytvořte soubor `app.py`:

```shell
cat > app.py << 'EOF'
print("Hello from Python in Docker!")
EOF
```

Vytvořte `Dockerfile`:

```shell
cat > Dockerfile << 'EOF'
FROM python:3.12-alpine

WORKDIR /app

COPY app.py .

CMD ["python", "app.py"]
EOF
```

Sestavte a spusťte:

```shell
docker build -t my-python-app:v1 .
docker run --rm my-python-app:v1
```

</details>

### Samostatná úloha 2

Vytvořte Dockerfile pro Node.js HTTP server, který bude odpovídat na portu 3000.

<details>
<summary>Řešení</summary>

Vytvořte adresář pro Node.js aplikaci:

```shell
mkdir -p ~/docker-workshop/02_node_app
cd ~/docker-workshop/02_node_app
```

Vytvořte soubor `server.js`:

```shell
cat > server.js << 'EOF'
const http = require('http');

const server = http.createServer((req, res) => {
    res.writeHead(200, { 'Content-Type': 'text/plain' });
    res.end('Hello from Node.js in Docker!\n');
});

server.listen(3000, '0.0.0.0', () => {
    console.log('Server running at http://0.0.0.0:3000/');
});
EOF
```

Vytvořte `Dockerfile`:

```shell
cat > Dockerfile << 'EOF'
FROM node:24-alpine

WORKDIR /app

COPY server.js .

EXPOSE 3000

CMD ["node", "server.js"]
EOF
```

Sestavte a spusťte:

```shell
docker build -t my-node-app:v1 .
docker run -d -p 3000:3000 --name my-node-app my-node-app:v1
```

</details>

## Volumes

Volumes jsou mechanismus pro persistentní ukládání dat mimo životní cyklus kontejneru.

### Typy volumes

1. **Named volumes** - spravované Dockerem, pojmenované
2. **Bind mounts** - mapování adresáře z hostitele
3. **tmpfs mounts** - dočasné úložiště v paměti

### Named volumes

Vytvořte named volume:

```shell
docker volume create my-data
```

Zobrazte seznam volumes:

```shell
docker volume ls
```

Spusťte kontejner s připojeným volume:

```shell
docker run -d --name db-container -v my-data:/var/lib/data alpine tail -f /dev/null
```

Vytvořte soubor uvnitř kontejneru:

```shell
docker exec db-container sh -c "echo 'persistent data' > /var/lib/data/test.txt"
```

Zastavte a odstraňte kontejner:

```shell
docker rm -f db-container
```

Spusťte nový kontejner se stejným volume:

```shell
docker run -d --name db-container-2 -v my-data:/var/lib/data alpine tail -f /dev/null
```

Ověřte, že data přetrvala:

```shell
docker exec db-container-2 cat /var/lib/data/test.txt
```

### Bind mounts

Bind mount mapuje adresář z hostitelského systému přímo do kontejneru.

Vytvořte lokální adresář:

```shell
mkdir ~/docker-workshop/shared-data
echo "data from host" > ~/docker-workshop/shared-data/host-file.txt
```

Spusťte kontejner s bind mount:

```shell
docker run -d --name bind-test -v ~/docker-workshop/shared-data:/data alpine tail -f /dev/null
```

Ověřte, že soubor je viditelný v kontejneru:

```shell
docker exec bind-test cat /data/host-file.txt
```

Vytvořte soubor z kontejneru:

```shell
docker exec bind-test sh -c "echo 'data from container' > /data/container-file.txt"
```

Ověřte, že soubor je viditelný na hostiteli:

```shell
cat ~/docker-workshop/shared-data/container-file.txt
```

### Samostatná úloha 3

Vytvořte MySQL kontejner s persistentním úložištěm pro databázová data.

<details>
<summary>Řešení</summary>

Vytvořte adresář pro MySQL úlohu:

```shell
mkdir -p ~/docker-workshop/03_mysql
cd ~/docker-workshop/03_mysql
```

Spusťte MySQL kontejner s volume:

```shell
docker volume create mysql-data

docker run -d \
    --name mysql-db \
    -e MYSQL_ROOT_PASSWORD=secret \
    -e MYSQL_DATABASE=workshop \
    -v mysql-data:/var/lib/mysql \
    -p 3306:3306 \
    mysql:8.0
```

Ověřte, že databáze běží:

```shell
docker exec mysql-db mysql -uroot -psecret -e "SHOW DATABASES;"
```

</details>

## Networks

Docker networks umožňují komunikaci mezi kontejnery.

### Typy sítí

- **bridge** - výchozí síť, izolovaná síť pro kontejnery
- **host** - kontejner sdílí síťový stack s hostitelem
- **none** - kontejner nemá síťové připojení
- **overlay** - síť pro Docker Swarm

### Vytvoření vlastní sítě

Vytvořte bridge síť:

```shell
docker network create my-network
```

Zobrazte seznam sítí:

```shell
docker network ls
```

### Komunikace mezi kontejnery

Spusťte dva kontejnery ve stejné síti:

```shell
docker run -d --name server1 --network my-network alpine tail -f /dev/null
docker run -d --name server2 --network my-network alpine tail -f /dev/null
```

Z kontejneru `server2` pingněte `server1` pomocí jména:

```shell
docker exec server2 ping -c 3 server1
```

> **Poznámka**: Docker automaticky poskytuje DNS rozlišení pro kontejnery ve stejné síti.

### Samostatná úloha 4

Vytvořte síť a spusťte v ní webový server (nginx) a aplikaci, která se na něj připojí.

<details>
<summary>Řešení</summary>

Vytvořte adresář pro síťovou úlohu:

```shell
mkdir -p ~/docker-workshop/04_network
cd ~/docker-workshop/04_network
```

Vytvořte síť a spusťte kontejnery:

```shell
docker network create web-network

docker run -d --name web-server --network web-network nginx

docker run --rm --network web-network alpine wget -qO- http://web-server
```

</details>

## Docker Compose

Docker Compose je nástroj pro definování a spouštění multi-kontejnerových aplikací.

### Instalace

Docker Compose je součástí Docker Desktop. Na Linuxu ověřte instalaci:

```shell
docker compose version
```

### Základní compose.yml

Vytvořte soubor `compose.yml`:

```shell
cat > compose.yml << 'EOF'
services:
  web:
    image: nginx:alpine
    ports:
      - "8080:80"
    volumes:
      - ./html:/usr/share/nginx/html:ro
    networks:
      - webnet

  api:
    build: ./api
    ports:
      - "3000:3000"
    environment:
      - NODE_ENV=development
    networks:
      - webnet
    depends_on:
      - db

  db:
    image: mysql:8.0
    environment:
      MYSQL_ROOT_PASSWORD: secret
      MYSQL_DATABASE: app
    volumes:
      - db-data:/var/lib/mysql
    networks:
      - webnet

networks:
  webnet:

volumes:
  db-data:
EOF
```

### Struktura projektu

Vytvořte potřebnou strukturu:

```shell
mkdir -p html api
```

Vytvořte `html/index.html`:

```shell
cat > html/index.html << 'EOF'
<!DOCTYPE html>
<html>
<head>
    <title>Docker Compose Demo</title>
</head>
<body>
    <h1>Hello from Docker Compose!</h1>
</body>
</html>
EOF
```

Vytvořte `api/Dockerfile`:

```shell
cat > api/Dockerfile << 'EOF'
FROM node:24-alpine

WORKDIR /app

COPY package.json .
RUN npm install

COPY . .

EXPOSE 3000

CMD ["node", "index.js"]
EOF
```

Vytvořte `api/package.json`:

```shell
cat > api/package.json << 'EOF'
{
  "name": "api",
  "version": "1.0.0",
  "main": "index.js",
  "dependencies": {
    "express": "^5.2.1"
  }
}
EOF
```

Vytvořte `api/index.js`:

```shell
cat > api/index.js << 'EOF'
const express = require('express');
const app = express();

app.get('/', (req, res) => {
    res.json({ message: 'Hello from API!' });
});

app.get('/health', (req, res) => {
    res.json({ status: 'ok' });
});

app.listen(3000, '0.0.0.0', () => {
    console.log('API server running on port 3000');
});
EOF
```

### Spuštění aplikace

Spusťte všechny služby:

```shell
docker compose up -d
```

Zobrazte běžící služby:

```shell
docker compose ps
```

Zobrazte logy:

```shell
docker compose logs
```

Sledujte logy v reálném čase:

```shell
docker compose logs -f
```

### Základní příkazy Docker Compose

| Příkaz | Popis |
|--------|-------|
| `docker compose up` | Spustí služby |
| `docker compose up -d` | Spustí služby na pozadí |
| `docker compose down` | Zastaví a odstraní služby |
| `docker compose ps` | Zobrazí běžící služby |
| `docker compose logs` | Zobrazí logy |
| `docker compose build` | Sestaví obrazy |
| `docker compose pull` | Stáhne obrazy |
| `docker compose exec` | Spustí příkaz ve službě |

### Zastavení aplikace

Zastavte a odstraňte všechny kontejnery:

```shell
docker compose down
```

Jak odstraníte i volumes?

<details>
<summary>Řešení</summary>

```shell
docker compose down -v
```

</details>

### Samostatná úloha 5

Vytvořte Docker Compose konfiguraci pro WordPress s MySQL databází.

<details>
<summary>Řešení</summary>

Vytvořte adresář pro WordPress:

```shell
mkdir -p ~/docker-workshop/05_wordpress
cd ~/docker-workshop/05_wordpress
```

Vytvořte `compose.yml`:

```shell
cat > compose.yml << 'EOF'
services:
  wordpress:
    image: wordpress:latest
    ports:
      - "8080:80"
    environment:
      WORDPRESS_DB_HOST: db
      WORDPRESS_DB_USER: wordpress
      WORDPRESS_DB_PASSWORD: wordpress
      WORDPRESS_DB_NAME: wordpress
    volumes:
      - wordpress-data:/var/www/html
    depends_on:
      - db
    networks:
      - wp-network

  db:
    image: mysql:8.0
    environment:
      MYSQL_DATABASE: wordpress
      MYSQL_USER: wordpress
      MYSQL_PASSWORD: wordpress
      MYSQL_ROOT_PASSWORD: secret
    volumes:
      - db-data:/var/lib/mysql
    networks:
      - wp-network

networks:
  wp-network:

volumes:
  wordpress-data:
  db-data:
EOF
```

Spusťte:

```shell
docker compose up -d
```

Přes Coder otevřete port `8080` a dokončete instalaci WordPressu.

</details>

## Multi-stage builds

Multi-stage builds umožňují vytvářet menší a bezpečnější obrazy.

### Příklad s Go aplikací

Vytvořte Go aplikaci:

```shell
mkdir ~/go-app
cd ~/go-app

cat > main.go << 'EOF'
package main

import (
    "fmt"
    "net/http"
)

func main() {
    http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
        fmt.Fprintf(w, "Hello from Go in Docker!")
    })
    
    fmt.Println("Server starting on port 8080...")
    http.ListenAndServe(":8080", nil)
}
EOF
```

Vytvořte multi-stage Dockerfile:

```shell
cat > Dockerfile << 'EOF'
# Build stage
FROM golang:1.25-alpine AS builder

WORKDIR /app

COPY main.go .

RUN go build -o server main.go

# Production stage
FROM alpine:latest

WORKDIR /app

COPY --from=builder /app/server .

EXPOSE 8080

CMD ["./server"]
EOF
```

Sestavte a spusťte:

```shell
docker build -t go-app:v1 .
docker run -d -p 8080:8080 --name go-app go-app:v1
```

Porovnejte velikost obrazů:

```shell
docker images | grep -E "golang|go-app|alpine"
```

> **Poznámka**: Multi-stage build výrazně zmenšuje velikost výsledného obrazu,
> protože finální obraz neobsahuje build nástroje a zdrojový kód.

## Best practices

### Optimalizace Dockerfile

1. **Používejte specifické tagy** - nikdy `latest` v produkci
2. **Minimalizujte počet vrstev** - kombinujte RUN příkazy
3. **Využívejte cache** - kopírujte závislosti před zdrojovým kódem
4. **Používejte .dockerignore** - vylučte nepotřebné soubory
5. **Nepoužívejte root** - vytvořte neprivilegovaného uživatele
6. **Multi-stage builds** - pro menší produkční obrazy

### Příklad optimalizovaného Dockerfile

```dockerfile
FROM node:24-alpine

# Vytvoření neprivilegovaného uživatele
RUN addgroup -g 1001 -S nodejs && \
    adduser -S nodejs -u 1001

WORKDIR /app

# Kopírování závislostí (využití cache)
COPY package*.json ./
RUN npm ci --only=production

# Kopírování zdrojového kódu
COPY --chown=nodejs:nodejs . .

# Přepnutí na neprivilegovaného uživatele
USER nodejs

EXPOSE 3000

CMD ["node", "index.js"]
```

### .dockerignore

Vytvořte `.dockerignore` pro vyloučení nepotřebných souborů:

```shell
cat > .dockerignore << 'EOF'
node_modules
npm-debug.log
Dockerfile*
docker-compose*
.git
.gitignore
.env
*.md
EOF
```

## Health checks

Health checks umožňují Dockeru monitorovat stav kontejneru.

### V Dockerfile

```dockerfile
FROM nginx:alpine

HEALTHCHECK --interval=30s --timeout=3s --start-period=5s --retries=3 \
    CMD wget --no-verbose --tries=1 --spider http://localhost/ || exit 1
```

### V Docker Compose

```yaml
services:
  web:
    image: nginx:alpine
    healthcheck:
      test: ["CMD", "wget", "--no-verbose", "--tries=1", "--spider", "http://localhost/"]
      interval: 30s
      timeout: 3s
      retries: 3
      start_period: 5s
```

Zobrazte stav health checku:

```shell
docker ps --format "table {{.Names}}\t{{.Status}}"
```

## Úklid

### Odstranění nepoužívaných zdrojů

Odstraňte zastavené kontejnery:

```shell
docker container prune
```

Odstraňte nepoužívané obrazy:

```shell
docker image prune
```

Odstraňte nepoužívané volumes:

```shell
docker volume prune
```

Odstraňte vše nepoužívané (kontejnery, obrazy, volumes, sítě):

```shell
docker system prune -a --volumes
```

> **Varování**: Tento příkaz odstraní všechna nepoužívaná data. Používejte opatrně!

## Závěrečná samostatná úloha

Vytvořte kompletní třívrstvou aplikaci pomocí Docker Compose:

1. **Frontend** - nginx servírující statický HTML/CSS
2. **Backend** - Node.js nebo Python API
3. **Databáze** - PostgreSQL nebo MySQL

Požadavky:
- Všechny služby běží ve vlastní síti
- Databáze má persistentní úložiště
- Backend se připojuje k databázi
- Frontend proxy požadavky na backend

<details>
<summary>Řešení</summary>

Vytvořte adresář pro fullstack aplikaci:

```shell
mkdir -p ~/docker-workshop/06_fullstack/frontend
mkdir -p ~/docker-workshop/06_fullstack/backend
cd ~/docker-workshop/06_fullstack
```

Vytvořte `compose.yml`:

```shell
cat > compose.yml << 'EOF'
services:
  frontend:
    image: nginx:alpine
    ports:
      - "80:80"
    volumes:
      - ./frontend:/usr/share/nginx/html:ro
      - ./nginx.conf:/etc/nginx/conf.d/default.conf:ro
    depends_on:
      - backend
    networks:
      - app-network

  backend:
    build: ./backend
    environment:
      - DATABASE_URL=postgresql://postgres:secret@db:5432/app
    depends_on:
      - db
    networks:
      - app-network

  db:
    image: postgres:16-alpine
    environment:
      POSTGRES_USER: postgres
      POSTGRES_PASSWORD: secret
      POSTGRES_DB: app
    volumes:
      - postgres-data:/var/lib/postgresql/data
    networks:
      - app-network

networks:
  app-network:

volumes:
  postgres-data:
EOF
```

Vytvořte `nginx.conf`:

```shell
cat > nginx.conf << 'EOF'
server {
    listen 80;
    
    location / {
        root /usr/share/nginx/html;
        index index.html;
    }
    
    location /api/ {
        proxy_pass http://backend:3000/;
        proxy_http_version 1.1;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
    }
}
EOF
```

Vytvořte `frontend/index.html`:

```shell
cat > frontend/index.html << 'EOF'
<!DOCTYPE html>
<html>
<head>
    <title>Fullstack App</title>
    <style>
        body { font-family: sans-serif; max-width: 800px; margin: 50px auto; }
        #result { padding: 20px; background: #f0f0f0; margin-top: 20px; }
    </style>
</head>
<body>
    <h1>Fullstack Docker App</h1>
    <button onclick="fetchApi()">Fetch from API</button>
    <div id="result"></div>
    
    <script>
        async function fetchApi() {
            const res = await fetch('/api/');
            const data = await res.json();
            document.getElementById('result').textContent = JSON.stringify(data, null, 2);
        }
    </script>
</body>
</html>
EOF
```

Vytvořte `backend/Dockerfile`:

```shell
cat > backend/Dockerfile << 'EOF'
FROM node:24-alpine

WORKDIR /app

COPY package.json .
RUN npm install

COPY . .

EXPOSE 3000

CMD ["node", "index.js"]
EOF
```

Vytvořte `backend/package.json`:

```shell
cat > backend/package.json << 'EOF'
{
  "name": "backend",
  "version": "1.0.0",
  "dependencies": {
    "express": "^4.18.2"
  }
}
EOF
```

Vytvořte `backend/index.js`:

```shell
cat > backend/index.js << 'EOF'
const express = require('express');
const app = express();

app.get('/', (req, res) => {
    res.json({
        message: 'Hello from Backend API!',
        timestamp: new Date().toISOString(),
        database: process.env.DATABASE_URL ? 'configured' : 'not configured'
    });
});

app.listen(3000, '0.0.0.0', () => {
    console.log('Backend API running on port 3000');
});
EOF
```

Spusťte aplikaci:

```shell
docker compose up -d --build
```

Přes Coder otevřete port `80` a otestujte aplikaci.

</details>

## Další zdroje

- [Docker Documentation](https://docs.docker.com/)
- [Docker Hub](https://hub.docker.com/)
- [Dockerfile Best Practices](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/)
- [Docker Compose Documentation](https://docs.docker.com/compose/)
- [Play with Docker](https://labs.play-with-docker.com/) - online Docker playground

<!-- {% endraw %} -->

