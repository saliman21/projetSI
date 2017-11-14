*********************Instruction pour git*******************


 ************************************************
*si git n'est pas installé sur vos perso (il est installer à la fac)
*Installer git avec  la commande :
*sudo apt install git
*il vous demanderas votre mots de passe de votre sessions
* ainsi qu'installer les dépendense
 ****************************************************
 
 dans le dossier du projet faire la commande :
 git init 
 cela va crée un nouveau dépot
 
 ensuite configurer avec git config 
git config --global user.name "votre user name"
git config --global user.email "votre@email.fr"
git config --global core.editor gedit


******************************************************
		Utiliser git

pour recuperer le projet qui est sur git 

git clone https://github.com/saliman21/projetSI

Mettre à jour le dépôt local

git pull

pour envoyer votre nouvelle version sur git

git add fichier ( ou *.cpp pour tout les fichiers cpp ou * pour tout les fichier)
git commit -m "message du commit"
git push (il vas vous demander vos identifiant et mots de passe github)


******************Liste des commandes utiles*********************************

Affiche la différence entre le contenu du dernier commit et celui du répertoire de travail. Cela correspond à ce qui serait commité par git commit -a.

git diff HEAD
Affiche la différence entre le contenu pointé par A et celui pointé par B.

git diff A B
Diff entre un dossier présent sur deux branches

git diff master..MA_BRANCH chemin/vers/mon_dossier


Crée une branche
git branch nom _de_la_branch

supprimer une branche
git branch -d nom_de_la_branch

fusionner une branche
git merge nom_de_la_branch

changer de branche 
git checkout

Affiche X derniers commits

git log -n X
Affiche un ensemble de commits par date (

git log --since=date --until=date
Représentation de l’historique à partir de HEAD (commit / branch)

git log --oneline --graph --decorate
Représentation de l’historique à partir d'un fichier (commit / branch)

git log --oneline --graph --decorate nom_du_fichier



