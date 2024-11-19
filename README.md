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

<h1>Création d’un Interpréteur de Langage de Programmation</h1> 

<h3>Description :</h3> 

<p>Ce projet consiste à développer un interpréteur simple de langage de programmation en C. L'interpréteur est capable de traiter des expressions arithmétiques, des affectations de variables, des chaînes de caractères, et d'exécuter des instructions depuis des fichiers ou directement via un mode interactif (REPL).</p> 

<h3>Fonctionnalités Principales :</h3> 
<ul> 
<li><strong>Analyse Lexicale (Lexer) :</strong> Conversion de l'entrée utilisateur en une séquence de tokens, représentant les unités lexicales telles que les variables, les opérateurs, et les mots-clés (<code>while</code>, <code>print</code>, etc.).</li> <li><strong>Analyse Syntaxique (Parser) :</strong> Construction d'un arbre syntaxique abstrait (AST) pour valider et structurer les instructions.</li> <li><strong>Évaluation des Expressions :</strong> Calcul des expressions mathématiques et logiques imbriquées.</li> <li><strong>Gestion des Boucles :</strong> Exécution des structures de contrôle comme <code>while</code>.</li> <li><strong>Affectation de Variables :</strong> Déclaration et mise à jour des variables avec la prise en charge des portées locales et globales.</li> <li><strong>Exemple : Calcul de la somme de deux nombres :</strong> <ul> <li><code>a = 10;</code> Initialise la variable <code>a</code> avec la valeur <code>10</code>.</li> <li><code>b = 20;</code> Initialise la variable <code>b</code> avec la valeur <code>20</code>.</li> <li><code>result = a + b;</code> Calcule la somme de <code>a</code> et <code>b</code> et stocke le résultat dans <code>result</code>.</li> <li><code>print(result);</code> Affiche la valeur de <code>result</code>.</li> </ul> <strong>Résultat attendu dans la console :</strong> <pre> 30 </pre> </li> <li><strong>Exemple : Multiplication et affichage intermédiaire :</strong> <ul> <li><code>x = 5;</code> Initialise <code>x</code> avec la valeur <code>5</code>.</li> <li><code>y = 3;</code> Initialise <code>y</code> avec la valeur <code>3</code>.</li> <li><code>z = x * y;</code> Calcule <code>5 * 3</code> et stocke le résultat dans <code>z</code>.</li> <li><code>print(z);</code> Affiche la valeur de <code>z</code>.</li> <li><code>x = z + 10;</code> Met à jour <code>x</code> avec la valeur <code>15 + 10</code>.</li> <li><code>print(x);</code> Affiche la valeur de <code>x</code>.</li> </ul> <strong>Résultat attendu dans la console :</strong> <pre> 15 25 </pre> </li> 


<h3>Structure des Fichiers</h3>

<<<<<<< HEAD
 <p>Voici un aperçu de la structure des fichiers utilisés dans le projet :</p> <img width="402" alt="image" src="https://github.com/user-attachments/assets/b2b64434-2cb1-4e20-83f4-c16c122bc8d4"> 

<h3>Installation</h3>

<p>- Compilez le projet avec : <code>mingw32-make</code></p> <p>- Exécutez le programme : <code>.\interpreter.exe</code>
</p>




=======
<img width="402" alt="image" src="https://github.com/user-attachments/assets/b2b64434-2cb1-4e20-83f4-c16c122bc8d4">
>>>>>>> 9117680c215b87669d35ee7d9bbbfcc6eaa212c1



<<<<<<< HEAD
=======
<p>- Compilez le projet avec : mingw32-make</p>
<p>- Exécutez le grogramme: .\interpreter.exe </p>
>>>>>>> 9117680c215b87669d35ee7d9bbbfcc6eaa212c1

<h3>Structure des Fichiers</h3>

<img width="402" alt="image" src="https://github.com/user-attachments/assets/b2b64434-2cb1-4e20-83f4-c16c122bc8d4">


<h3>Installation </h3>

<p>- Compilez le projet avec : mingw32-make</p>
<p>- Exécutez le grogramme: .\interpreter.exe </p>
