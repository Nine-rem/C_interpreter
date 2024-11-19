<h1>Création d’un Interpréteur de Langage de Programmation</h1> <h3>Description :</h3> <p>Ce projet consiste à développer un interpréteur simple de langage de programmation en C. L'interpréteur est capable de traiter des expressions arithmétiques, des affectations de variables, des chaînes de caractères, et d'exécuter des instructions depuis des fichiers ou directement via un mode interactif (REPL).</p>
<h3>Fonctionnalités Principales :</h3> 
<ul> <li><strong>Analyse Lexicale (Lexer) :</strong> Conversion de l'entrée utilisateur en une séquence de tokens, représentant les unités lexicales telles que les variables, les opérateurs, et les mots-clés (<code>while</code>, <code>print</code>, etc.).</li> <li><strong>Analyse Syntaxique (Parser) :</strong> Construction d'un arbre syntaxique abstrait (AST) pour valider et structurer les instructions.</li>
<li><strong>Évaluation des Expressions :</strong> Calcul des expressions mathématiques et logiques imbriquées.</li> <li><strong>Gestion des Boucles :</strong> Exécution des structures de contrôle comme <code>while</code>.</li> <li><strong>Affectation de Variables :</strong> Déclaration et mise à jour des variables avec la prise en charge des portées locales et globales.</li> <li><strong>Exemple : Calcul de la somme de deux nombres :</strong> <ul> <li><code>a = 10;</code> Initialise la variable <code>a</code> avec la valeur <code>10</code>.</li> <li><code>b = 20;</code> Initialise la variable <code>b</code> avec la valeur <code>20</code>.</li> 
  <li><code>result = a + b;</code> Calcule la somme de <code>a</code> et <code>b</code> et stocke le résultat dans <code>result</code>.</li> <li><code>print(result);</code> Affiche la valeur de <code>result</code>.</li> </ul> <strong>Résultat attendu dans la console :</strong> <pre>30</pre> </li> <li><strong>Exemple : Multiplication et affichage intermédiaire :</strong> <ul> <li><code>x = 5;</code> Initialise <code>x</code> avec la valeur <code>5</code>.</li> <li><code>y = 3;</code> Initialise <code>y</code> avec la valeur <code>3</code>.</li> <li><code>z = x * y;</code> Calcule <code>5 * 3</code> et stocke le résultat dans <code>z</code>.</li>
<li><code>print(z);</code> Affiche la valeur de <code>z</code>.</li> <li><code>x = z + 10;</code> Met à jour <code>x</code> avec la valeur <code>15 + 10</code>.</li> <li><code>print(x);</code> Affiche la valeur de <code>x</code>.</li> </ul> <strong>Résultat attendu dans la console :</strong> <pre>15 25</pre> </li> </ul>
<h3>Structure des Fichiers</h3> <p>Voici un aperçu de la structure des fichiers utilisés dans le projet :</p> <img width="402" alt="image" src="https://github.com/user-attachments/assets/b2b64434-2cb1-4e20-83f4-c16c122bc8d4">
<h3>Modules Principaux et Fonctions Clés :</h3> 
<h4>1. Lexer (Analyse Lexicale)</h4> <ul> <li><strong>`add_token(TokenType type, int value, char var_name)` :</strong> Ajoute un nouveau token à la liste </li> <li><strong>`lexer(const char* input)` :</strong> Analyse l'entrée utilisateur et convertit chaque caractère en token en identifiant les variables, mots-clés, opérateurs, ...</li> </ul> 
<h4>2. Parser (Analyse Syntaxique)</h4> <ul> <li><strong>`parse_expression(Scope *scope)` :</strong> Analyse les expressions mathématiques et logiques.</li> <li><strong>`parse_assignment(Scope *scope)` :</strong> Gère les affectations de variables et les blocs de code comme les boucles <code>while</code>.</li> <li><strong>`parse_factor(Scope *scope)` :</strong> Identifie les unités de base d'une expression (nombres, variables, ou sous-expressions).</li> 
<li><strong>`parse_term(Scope *scope)` :</strong> Analyse les termes qui impliquent la multiplication ou la division.</li><li><strong>`void print(Scope *scope)` :</strong> - Role : Gère l'instruction <code>print()</code>. - Fonctionnement : Verifie si l'argument est une variable ou une chaîne, et affiche la valeur ou le texte correspondant. - Exemple c print(a); // Affiche la valeur de la variable 'a' print("Hello"); // Affiche la chaîne "Hello"  </li></ul> <h4>3. Évaluateur</h4> <ul> <li><strong>`eval_expression(ASTNode* node, Scope *scope)` :</strong> Évalue une expression mathématique ou logique en parcourant l'AST.</li> </ul> <h4>4. Scope (Portée)</h4> <ul> <li><strong>`set_variable(Scope *scope, char var_name, int value)` :</strong> Définit ou met à jour une variable dans le scope actuel.</li> <li><strong>`get_variable(Scope *scope, char var_name)` :</strong> Recherche et retourne la valeur d'une variable dans le scope local ou globale</li> </ul>
<h3>Installation</h3> <p>- Compilez le projet avec : <code>mingw32-make</code></p> <p>- Exécutez le programme : <code>.\interpreter.exe</code></p>
