# ergodox_bepolite
My ergodox bepo/french/config

****
Configuration de mon clavier ergodox
****
Il s'agit d'un mix entre une configuration classique et des adaptions pour rendre plus accessibles :
* les flèches (avec les pouces, ou alternativement à avec des touches type hjkl)
* les touches fonctions et les raccourcis FreeDesktop notamment Alt+F2 Alt+F4
* les nombres (pour un personne qui n'utise jamais de clavier numérique / numpad)
* les touches modificatrices : shift,  ctrl , ainsi que AltGr (très utilisé dans bépo), alt et alt

# Hardware
Require an ergodox 80keys. Warning on the 2 space thumbs keys: you'll probably need to modify the shape of the buttons.

Cette disposition necessite un clavier ergodox à 80 touches.
Les deux touches "Espace" doivent être rendu plus accessibles, soit en les déplacant, soit en y mettant des embouts plus large.




# get all tools
If you didn't have clone the repository yet :

```git clone --recursive -j8 git://github.com/luffah/ergodox_bepolite```

Else, in the clone of the repository, you will need to do :

```git submodule update --init --recursive```

# install
You need a keyboard with teensy chip atmega u80 (ergodox like).
You will need sudo password to transfer.

```make```
