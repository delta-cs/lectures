<!-- {% raw %} -->

# Práce s daty

## Úvod

Workshop je zaměřen na praktickou práci s daty v jazyce Python.
Na reálném datasetu z katastrofy lodi Titanic si vyzkoušíme
celý pipeline datové analýzy a strojového učení — od průzkumové analýzy dat (EDA),
přes předzpracování, až po trénování klasifikačních modelů.
V závěru se podíváme na efektivní ukládání dat pomocí řídkých matic.

## Příprava playgroundu

Nastartujte si nový `docker` workspace přes Coder.

Vytvořte si nový adresář pro tento workshop a stáhněte si do něj data, obrázky a notebooky přímo z repozitáře

```shell
mkdir -p ~/data-science-workshop/{data,img,notebooks}
cd ~/data-science-workshop

BASE=https://raw.githubusercontent.com/delta-cs/lectures/master/workshopy/data-science

curl -o data/train.csv $BASE/data/train.csv
curl -o data/test.csv  $BASE/data/test.csv

curl -o img/classification-model-types.jpg $BASE/img/classification-model-types.jpg
curl -o img/dense.png                      $BASE/img/dense.png
curl -o img/train-test-split.jpg           $BASE/img/train-test-split.jpg

curl -o notebooks/zaklady_notebooku.ipynb $BASE/notebooks/zaklady_notebooku.ipynb
curl -o notebooks/titanic.ipynb           $BASE/notebooks/titanic.ipynb
curl -o notebooks/ridke_matice.ipynb      $BASE/notebooks/ridke_matice.ipynb
```

Alternativně si můžete jednotlivé soubory stáhnout ručně:

- Data: [train.csv](https://raw.githubusercontent.com/delta-cs/lectures/master/workshopy/data-science/data/train.csv), [test.csv](https://raw.githubusercontent.com/delta-cs/lectures/master/workshopy/data-science/data/test.csv)
- Notebooky: [zaklady_notebooku.ipynb](https://raw.githubusercontent.com/delta-cs/lectures/master/workshopy/data-science/notebooks/zaklady_notebooku.ipynb), [titanic.ipynb](https://raw.githubusercontent.com/delta-cs/lectures/master/workshopy/data-science/notebooks/titanic.ipynb), [ridke_matice.ipynb](https://raw.githubusercontent.com/delta-cs/lectures/master/workshopy/data-science/notebooks/ridke_matice.ipynb)
- Obrázky: [classification-model-types.jpg](https://raw.githubusercontent.com/delta-cs/lectures/master/workshopy/data-science/img/classification-model-types.jpg), [dense.png](https://raw.githubusercontent.com/delta-cs/lectures/master/workshopy/data-science/img/dense.png), [train-test-split.jpg](https://raw.githubusercontent.com/delta-cs/lectures/master/workshopy/data-science/img/train-test-split.jpg)

> **Poznámka**: Data pocházejí ze soutěže [Kaggle Titanic](https://www.kaggle.com/c/titanic/data)
> a lze je stáhnout i přímo z Kaggle.

Spusťte JupyterLab pomocí Dockeru

```shell
docker run -it --rm \
  -p 8888:8888 \
  -v $(pwd):/home/jovyan/work \
  quay.io/jupyter/datascience-notebook:2026-04-13
```

Po spuštění kontejneru se v terminálu zobrazí URL s tokenem.
Otevřete toto URL v prohlížeči a v JupyterLab přejděte do složky `work/notebooks/`.

PyTorch není součástí image — nainstalujte ho přímo v notebooku

```python
!pip install torch
```

> **Poznámka**: Instalace PyTorch může trvat několik minut. Knihovnu budeme potřebovat až v sekci neuronových sítí,
> takže instalaci můžete spustit na pozadí a pokračovat ve workshopu.

## Notebooky

| # | Notebook | Obsah |
|---|----------|-------|
| 1 | [Základy notebooku](notebooks/zaklady_notebooku.ipynb) | Úvod do Jupyteru a Pythonu — typy buněk, proměnné, datové typy, cykly, funkce, importy, vizualizace, Markdown, klávesové zkratky |
| 2 | [Titanic](notebooks/titanic.ipynb) | Průzkumová analýza dat (EDA), předzpracování dat, klasifikační modely (Decision Tree, Random Forest, Neural Network, AdaBoost) |
| 3 | [Řídké matice](notebooks/ridke_matice.ipynb) | Husté vs. řídké matice, formáty COO/CSR/CSC, porovnání paměťové náročnosti |

## Samostatné úlohy

Úlohy jsou určeny k samostatné práci studentů. Řešení jsou ve skládacích blocích níže.

### Samostatná úloha 1

Vytvořte korelační matici numerických sloupců (`Survived`, `Pclass`, `Age`, `SibSp`, `Parch`, `Fare`)
a vizualizujte ji pomocí `sns.heatmap`.
Vytvořte seskupený sloupcový graf míry přežití podle kombinace třídy (Pclass) a pohlaví (Sex)
pomocí `sns.barplot` s parametrem `hue`.

<details>
<summary>Řešení</summary>

```python
import seaborn as sns
import matplotlib.pyplot as plt

# Korelační matice
corr = train[['Survived', 'Pclass', 'Age', 'SibSp', 'Parch', 'Fare']].corr()
plt.figure(figsize=(8, 6))
sns.heatmap(corr, annot=True, cmap='coolwarm', center=0)
plt.title('Korelační matice')
plt.show()

# Seskupený barplot
sns.barplot(x='Pclass', y='Survived', hue='Sex', data=train)
plt.title('Míra přežití podle třídy a pohlaví')
plt.show()
```

Nejvíce korelující proměnné s přežitím jsou `Fare` (pozitivní korelace — dražší lístek → vyšší šance)
a `Pclass` (negativní korelace — nižší třída → nižší šance na přežití).

</details>

### Samostatná úloha 2

Místo doplnění chybějícího věku průměrem vyzkoušejte jiné strategie:

1. Doplňte mediánem celého sloupce
2. Doplňte mediánem podle třídy (Pclass) — tj. pro každou třídu zvlášť
3. Která strategie dává větší intuitivní smysl a proč?

<details>
<summary>Řešení</summary>

```python
train_raw = pd.read_csv('data/train.csv')

# 1. Medián celého sloupce
age_median = train_raw['Age'].median()
print(f"Medián věku: {age_median}")

# 2. Medián podle třídy
train_raw['Age_per_class'] = train_raw.groupby('Pclass')['Age'].transform(
    lambda x: x.fillna(x.median())
)

print("\nMedián věku podle třídy:")
print(train_raw.groupby('Pclass')['Age'].median())
```

Doplnění mediánem podle třídy dává větší smysl, protože pasažéři 1. třídy
byli typicky starší než pasažéři 3. třídy. Globální průměr/medián
tento rozdíl ignoruje.

</details>

### Samostatná úloha 3

Experimentujte s parametrem `max_depth` rozhodovacího stromu.

1. Natrénujte rozhodovací stromy s `max_depth` = 1, 2, 3, 5, 10, None (bez omezení)
2. Pro každý strom spočítejte přesnost pomocí 5-fold cross-validace (`sklearn.model_selection.cross_val_score`)
3. Výsledky vykreslete do grafu
4. Jaká hodnota `max_depth` dává nejlepší výsledek na cross-validaci?

<details>
<summary>Řešení</summary>

```python
from sklearn.model_selection import cross_val_score
from sklearn.tree import DecisionTreeClassifier
import matplotlib.pyplot as plt

depths = [1, 2, 3, 5, 10, None]
scores = []

for d in depths:
    dt = DecisionTreeClassifier(max_depth=d, random_state=42)
    cv_score = cross_val_score(dt, X, y, cv=5, scoring='accuracy')
    scores.append(cv_score.mean())
    print(f"max_depth={str(d):>4s}: accuracy={cv_score.mean():.4f} (+/- {cv_score.std():.4f})")

plt.figure(figsize=(8, 5))
plt.plot([str(d) for d in depths], scores, marker='o')
plt.xlabel('max_depth')
plt.ylabel('Cross-validation accuracy')
plt.title('Vliv max_depth na přesnost rozhodovacího stromu')
plt.grid(True)
plt.show()
```

Typicky nejlepší výsledek dává `max_depth` kolem 3–5.
Příliš hluboký strom (None) má tendenci k přetrénování (overfitting).

</details>

### Samostatná úloha 4

Zkuste upravit architekturu neuronové sítě:

1. Přidejte třetí skrytou vrstvu
2. Změňte velikosti skrytých vrstev na 64 a 128
3. Přidejte `Dropout(0.3)` mezi vrstvy (pomáhá proti přetrénování)
4. Porovnejte finální loss s původní architekturou

<details>
<summary>Řešení</summary>

```python
class NeuralNetworkV2(nn.Module):
    def __init__(self, input_size=10):
        super(NeuralNetworkV2, self).__init__()
        self.fc1 = nn.Linear(input_size, 64)
        self.dropout1 = nn.Dropout(0.3)
        self.fc2 = nn.Linear(64, 128)
        self.dropout2 = nn.Dropout(0.3)
        self.fc3 = nn.Linear(128, 64)
        self.dropout3 = nn.Dropout(0.3)
        self.fc4 = nn.Linear(64, 1)

    def forward(self, x):
        x = torch.relu(self.fc1(x))
        x = self.dropout1(x)
        x = torch.relu(self.fc2(x))
        x = self.dropout2(x)
        x = torch.relu(self.fc3(x))
        x = self.dropout3(x)
        x = torch.sigmoid(self.fc4(x))
        return x

model_v2 = NeuralNetworkV2(input_size=X_tensor.shape[1])
criterion_v2 = nn.BCELoss()
optimizer_v2 = optim.Adam(model_v2.parameters(), lr=0.001)

dataset = TensorDataset(X_tensor, y_tensor)
dataloader = DataLoader(dataset, batch_size=32, shuffle=True)

best_model_v2 = None
best_loss_v2 = float('inf')

for epoch in range(1000):
    model_v2.train()
    for X_batch, y_batch in dataloader:
        optimizer_v2.zero_grad()
        y_pred = model_v2(X_batch)
        loss = criterion_v2(y_pred, y_batch)
        loss.backward()
        optimizer_v2.step()

    if loss.item() < best_loss_v2:
        best_loss_v2 = loss.item()
        best_model_v2 = model_v2.state_dict().copy()

    if (epoch + 1) % 100 == 0:
        print(f"Epoch {epoch + 1}/1000, Loss: {loss.item():.4f}")

print(f"\nNejlepší loss V2: {best_loss_v2:.4f}")
print(f"Nejlepší loss V1: {best_loss:.4f}")
```

Dropout pomáhá regularizovat model a může vést k lepší generalizaci,
i když trénovací loss může být vyšší.

</details>

### Samostatná úloha 5 (Bonus)

Porovnejte všechny modely natrénované během workshopu pomocí 5-fold cross-validace.

1. Vyhodnoťte Decision Tree, Random Forest, AdaBoost a AdaBoost + SVC
2. Vytvořte sloupcový graf průměrné přesnosti s error bary (směrodatná odchylka)
3. Který model dosáhl nejlepší přesnosti?

> **Poznámka**: Neuronovou síť (PyTorch) nelze jednoduše vyhodnotit pomocí `cross_val_score`,
> proto ji v tomto porovnání vynecháme.

<details>
<summary>Řešení</summary>

```python
from sklearn.model_selection import cross_val_score
import matplotlib.pyplot as plt

models = {
    'Decision Tree': DecisionTreeClassifier(max_depth=3, random_state=42),
    'Random Forest': RandomForestClassifier(n_estimators=100, max_depth=3, random_state=42),
    'AdaBoost': AdaBoostClassifier(n_estimators=100, random_state=42),
    'AdaBoost + SVC': AdaBoostClassifier(
        estimator=SVC(probability=True),
        n_estimators=100,
        random_state=42,
    )
}

means = []
stds = []
names = []

for name, model in models.items():
    scores = cross_val_score(model, X, y, cv=5, scoring='accuracy')
    means.append(scores.mean())
    stds.append(scores.std())
    names.append(name)
    print(f"{name:20s}: accuracy={scores.mean():.4f} (+/- {scores.std():.4f})")

plt.figure(figsize=(10, 6))
plt.bar(names, means, yerr=stds, capsize=5, color=['#2196F3', '#4CAF50', '#FF9800', '#F44336'])
plt.ylabel('Cross-validation accuracy')
plt.title('Porovnání klasifikačních modelů')
plt.ylim(0.7, 0.9)
plt.grid(axis='y', alpha=0.3)
plt.show()
```

</details>

### Samostatná úloha 6

Vytvořte jednotkovou matici 1 000 × 1 000 (`np.eye(1000)`).

1. Převeďte ji do všech tří řídkých formátů (COO, CSR, CSC)
2. Porovnejte paměťovou náročnost všech čtyř reprezentací
3. Který formát je pro jednotkovou matici nejefektivnější a proč?

<details>
<summary>Řešení</summary>

```python
import numpy as np
from scipy.sparse import coo_matrix, csr_matrix, csc_matrix

identity = np.eye(1000)

identity_coo = coo_matrix(identity)
identity_csr = csr_matrix(identity)
identity_csc = csc_matrix(identity)

print(f"Hustá matice: {identity.nbytes / 1e6:.1f} MB")
print(f"COO formát:   {get_coo_matrix_size(identity_coo) / 1e6:.3f} MB")
print(f"CSR formát:   {get_csrcsc_matrix_size(identity_csr) / 1e6:.3f} MB")
print(f"CSC formát:   {get_csrcsc_matrix_size(identity_csc) / 1e6:.3f} MB")
```

CSR a CSC jsou stejně efektivní, protože jednotková matice má přesně jeden nenulový prvek
na každém řádku i sloupci. COO je méně efektivní, protože ukládá oba indexy pro každý prvek.

</details>

### Samostatná úloha 7

Experimentujte s různými stupni řídkosti matice 5 000 × 5 000.

1. Postupně nastavte různé procento prvků na nulu: 50 %, 80 %, 95 %, 99 %
2. Pro každý stupeň řídkosti změřte paměťovou náročnost husté matice a formátu CSR
3. Výsledky vykreslete do grafu pomocí matplotlib
4. Při jakém stupni řídkosti se CSR stane efektivnějším než hustá matice?

<details>
<summary>Řešení</summary>

```python
import numpy as np
import matplotlib.pyplot as plt
from scipy.sparse import csr_matrix

sparsity_levels = [0.5, 0.8, 0.95, 0.99]
dense_sizes = []
csr_sizes = []

for sparsity in sparsity_levels:
    matrix = np.random.rand(5000, 5000)
    matrix[matrix < sparsity] = 0

    csr = csr_matrix(matrix)

    dense_sizes.append(matrix.nbytes / 1e6)
    csr_sizes.append(
        (csr.data.nbytes + csr.indices.nbytes + csr.indptr.nbytes) / 1e6
    )

labels = [f"{int(s * 100)} %" for s in sparsity_levels]

plt.figure(figsize=(10, 6))
plt.bar([x - 0.2 for x in range(len(labels))], dense_sizes, 0.4, label="Hustá matice")
plt.bar([x + 0.2 for x in range(len(labels))], csr_sizes, 0.4, label="CSR formát")
plt.xticks(range(len(labels)), labels)
plt.xlabel("Podíl nulových prvků")
plt.ylabel("Paměť (MB)")
plt.title("Porovnání paměťové náročnosti podle řídkosti")
plt.legend()
plt.show()
```

CSR je efektivnější než hustá matice přibližně od 75–80 % řídkosti.

</details>

## Další zdroje

- [NumPy dokumentace](https://numpy.org/doc/)
- [SciPy — Sparse Matrices](https://docs.scipy.org/doc/scipy/reference/sparse.html)
- [pandas dokumentace](https://pandas.pydata.org/docs/)
- [scikit-learn dokumentace](https://scikit-learn.org/stable/)
- [PyTorch tutoriály](https://pytorch.org/tutorials/)
- [Kaggle — Titanic soutěž](https://www.kaggle.com/c/titanic)
- [seaborn dokumentace](https://seaborn.pydata.org/)
- [matplotlib dokumentace](https://matplotlib.org/stable/)

<!-- {% endraw %} -->
