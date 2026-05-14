# **The Spirit Train**

Reproduction de la locomotive des dieux du jeu **_The Legend of Zelda: Spirit Tracks_**.

![Jaquette The Legend of Zelda: Spirit Tracks](./assets/documentation/zelda_spirit_track.jpg)

## **Commandes utilisateurs**

### **[ECHAP]** Quitter la fenêtre

L'appuie de cette touche fermera la fenêtre

---

### **[L]** Mode fillaire

L'appuie de cette touche activera ou désactivera la vision fillaire de la scène.

---

### **[G]** Afficher / Retirer la grille du terrain

L'appuie de cette touche activera ou désactivera l'affichage de la grille du terrain.

---

### **[Z]**, **[Q]**, **[S]**, **[D]** Déplacer la caméra _(Orbital, FPS et Roof)_

L'appuie de ces touches permettra de déplacer la caméra dans la scène.

---

### **[R]**, **[T]** Zoomer / Dézoomer _(Orbital et Roof)_

L'appuie de ces touches permettra de zoomer ou de dézoomer la caméra dans la scène.

---

### **[A]**, **[E]** Descendre / Monter _(FPS)_

L'appuie de ces touches permettra de faire monter ou descendre la caméra dans la scène.

---

### **[C]** Changer de Caméra _(Orbital, FPS et Roof)_

L'appuie de cette touche permettra de changer la caméra.

## **Implémentation**

### Modification du CMakeLists

Transformation de la ligne :

```
file(GLOB EXT_SRC_FILES [^e][^x]*.cpp)
```

en cette ligne :

```
file(GLOB_RECURSE EXT_SRC_FILES *.cpp)
```

Cela permet de compiler tous les fichier **.cpp** qui sont dans des sous-dossiers.

---

Transformation de la ligne :

```
file(GLOB EXE_SRC_FILES ex[^\#]*.cpp)
```

en cette ligne :

```
file(GLOB EXE_SRC_FILES main.cpp)
```

Cela me permet d'avoir un unique fichier **.cpp** reconnue comme executable.

---

Ajout de nohlmann :

```
# ---Add nlohmann---
include_directories(third_party/)
set(CMAKE_COLOR_MAKEFILE ON)
```

Cela permet d'aller chercher le dossier nohlmann dans third_party
