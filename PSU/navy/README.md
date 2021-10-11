# B-PSU-101-LIL-1-1-navy-thibault2.brumaire

## Navy game

- Compilation : make fclean && make all
- Usage       : ./navy [PID] [FILE]

### TODO

- [x] Détection des arguments et l'option -h
- [x] Communication entre les joueurs (process)
  - [x] Connection entre les deux process
  - [x] Envois d'information sur la partie
  - [x] Freeze unfreeze des programmes ou veille
- [ ] Ouverture de la carte et vérification de celle-ci
  - [ ] Vérification du respect absolut de l'input
  - [ ] Vérification si il y a bien le bon nombre de bâteaux
  - [ ] Vérif taille des bateaux
- [x] Loop de jeux
  - [x] Détection de l'user input
  - [x] Vérification du coup
  - [x] Vérification sur le statut de victoire / défaite
- BUGS
  - Ennemy 1 not exit on first loop `zsh: user-defined signal 1  ./navy pos1`
  <br>possible fix : bigger usleep val ? #TODO ask AER
  - USR1 not detecting lose (only occured 1 time)
