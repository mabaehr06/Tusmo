# Tusmo

**Tusmo** est un remake en **C / CSFML** du jeu français de mots (style Wordle), avec une interface graphique simple et une interface colorée.

## Requirements

- **GCC** + **make**
- **CSFML** (Graphics / Window / System)
- (Optionnel) **WSL Ubuntu** si vous développez sous Windows


## Installation

### 1) Installer CSFML

Exemple (Debian/Ubuntu) :

- paquet CSFML : `libcsfml-dev`

### 2) Cloner le repo

~~~bash
git clone https://github.com/mabaehr06/Tusmo.git Tusmo
cd Tusmo
~~~

### 3) Compiler

~~~bash
make
~~~

Le Makefile génère un exécutable nommé `tusmo`.

### 4) Lancer

~~~bash
./tusmo
~~~

## Utilisation

### Commandes

- `./tusmo -h` : affiche l’aide (usage).

### Contrôles (en jeu)

- **A–Z** : entrer une lettre
- **Backspace** : effacer
- **Entrée** : valider le mot
- **Molette / clic droit** : scrolling / reset du panneau “RESULT” (barre de droite)

## Dictionnaire / mots

Le jeu tire un mot depuis `assets/dico` (aléatoirement) et le normalise en majuscules.  
Assurez-vous donc de garder le dossier `assets/` au même niveau que l’exécutable (icônes + dico).

## Notes

- Une partie est limitée par un **timeout de 120s** (2 minutes).
- Le projet embarque aussi des libs utilitaires (printf, maths, etc.) compilées via le Makefile.

## Auteur

- Marc-Alexandre BAEHR
