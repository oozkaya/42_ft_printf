# ft_printf @ 42

Il s'agit de recréer au mieux la fonction printf de la libc.

Partie obligatoire :

* analyser les **flags** (#, 0, -, + et espace), la **taille minimum du champ**, la **precision**, et le **modificateur de taille** (hh, h, l, ll, j, z).
* analyser le **spécificateur de conversion**.
* afficher des **caractères unicode UTF-8**. (%C, %S).
* convertir des **nombres non signés de base 2** (%b), **8** (%o), **10** (%u) et **16** (%x).
* afficher des **nombres signés** (%d, %D, %i). 
* afficher l'**adresse d'un pointeur** (%p).

Bonus :

* **Vitesse de 96%** (comparée au printf de la libc, sans le bonus des couleurs) grâce à un buffer qui sera write à la fin du printf.
* Plusieurs variantes disponibles (ft_dprintf, ft_sprintf, ft_asprintf...).
* **wildcard** (%*): remplace la précision et/ou la taille mininum du champ par le paramètre donné.
* **couleurs** avec les brackets ('{' et '}')
> ex: **{red}test{eoc}** affichera **"test" en rouge**, **{{green}}** affichera le mot **"{green}"** simplement.


# Utilisation

> $> git submodule init

> $> git submodule update

puis :

> $> make

> $> make test     (ou 'make test FLAGS=no' pour les undefined behavior)

> $> ./a.out
