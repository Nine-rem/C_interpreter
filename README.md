<h1>Création d’un Interpréteur de Langage de Programmation</h1>

<h3>Description :</h3>

<p>Ce projet consiste à développer un interpréteur simple de langage de programmation en C. L'interpréteur est capable de traiter des expressions arithmétiques, des affectations de variables, des chaînes de caractères, et d'exécuter des instructions depuis des fichiers ou directement via un mode interactif (REPL)</p>

<h3>Fonctionnalités</h3>

<p><strong>Expressions arithmétiques:</strong> Calcul de sommes, produits, divisions, et soustractions <br></p>
<p><strong>Variables : </strong>Déclaration et utilisation de variables avec gestion des portées globales et locales<br></p>
<p><strong>Affichage avec print :</strong><br></p>
<p>- Des Valeurs de variables : print(x)<br></p>
<p>- Des chaînes de caractères : print(" ")<br></p>
<p><strong>Mode interactif (REPL) : </strong>Permet l'entrée directe de commandes dans le terminal<br></p>
<p><strong>Lecture depuis un fichier :</strong> Lecture et exécution des instructions depuis un fichier texte<br></p>
<p><strong>Portée des variables :</strong><br></p>
<p>- use_local : Active la portée locale<br></p>
<p>- use_global : Revient à la portée globale<br></p>

Lexer
Rôle : Convertir l'entrée utilisateur en une séquence de tokens.
Fonctions clés :
addToken : Ajoute un token à la liste des tokens générés.
lexer : Parcourt l'entrée caractère par caractère pour identifier les unités lexicales (par exemple, variables, opérateurs, mots-clés comme while).

<h3>Structure des Fichiers</h3>

<img width="402" alt="image" src="https://github.com/user-attachments/assets/b2b64434-2cb1-4e20-83f4-c16c122bc8d4">


<h3>Installation </h3>

<p>- Compilez le projet avec : mingw32-make</p>
<p>- Exécutez le grogramme: .\interpreter.exe </p>
