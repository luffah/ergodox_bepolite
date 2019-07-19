# ergodox_bepolite
My ergodox bepo/french/config

****
Configuration de mon clavier ergodox
****
Particularités :
* les touches fonctions et les raccourcis FreeDesktop notamment Alt+F2 Alt+F4 sont faciles d'accès
* les touches modificatrices sont utilisables avec le pouce : Shift,  Ctrl ,  AltGr, et Alt
* les flèches sont utilisables avec les pouces (avec alternative)
* BEPO : meilleur accès à la touche w

# Changelog

20 sept 2017 . =hjkl location causes pinky injury=

Les touches type hjkl sur la rangé la plus basse sont supprimés. La raison ? la présence de ces touches incite à tordre légèrement le poignet, ce qui a pour effet de placer l'auriculaire (flèche droite) dans une position crispée.
Les effets effets négatifs sur l'articulation de l'auriculaire peut se faire ressentir en moins d'1 mois.


Depuis... abandon du projet. Il est bien plus rentable d'utiliser `xkb` pour adapter son clavier.

# Hardware
Require an ergodox 80keys. Warning on the 2 space thumbs keys: you'll probably need to modify the shape of the buttons.

Cette disposition nécessite un clavier ergodox à 80 touches.
Les deux touches "Espace" doivent être rendu plus accessibles, soit en les déplaçant, soit en y mettant des embouts plus large.




# get all tools
If you didn't have clone the repository yet :

```git clone --recursive -j8 git://github.com/luffah/ergodox_bepolite```

Else, in the clone of the repository, you will need to do :

```git submodule update --init --recursive```

# install
You need a keyboard with teensy chip atmega u80 (ergodox like).
You will need sudo password to transfer.

```make```
