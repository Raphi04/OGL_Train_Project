# **The Spirit Train**

Reproduction de la locomotive des dieux du jeu **_The Legend of Zelda: Spirit Tracks_**.

![Jaquette The Legend of Zelda: Spirit Tracks](./assets/documentation/zelda_spirit_track.jpg)

## **Commandes utilisateurs**

### **[ECHAP]** Quitter la fenêtre

L'appuie de cette touche fermera la fenêtre

---

### **[L]** Mode fillaire

L'appuie de cette touche activera ou désactivera la vision fillaire de la scène.

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
