![blabla](https://user-images.githubusercontent.com/29018157/130927243-6b48716e-3160-4562-a060-73ea370c14f9.png)

# calculs_fraction
addition, soustraction et multiplication de fractions sous forme simplifiée

### Pour compiler
```
g++ -g main.cpp src/*.cpp -std=c++20 -I include -o main -Wall -Wextra -O2
```

### Remarque : 
* ne pas taper d'espace
* les calculs ne portent que sur des entiers

### Exemples
* Calcul de : 8x9+9/8
<pre>$ ./main
Entrer fractions
8/1*9/1+9/8
--------------------------
Multiplication
72/1+9/8
--------------------------
--------------------------
Addition - Soustraction
585/8
--------------------------
--------------------------
Résultat final :
8/1*9/1+9/8 est égal à
585/8
--------------------------
</pre>

* Calcul de : 9+8/5
<pre>$ ./main
Entrer fractions
9/1+8/5
--------------------------
Addition - Soustraction
53/5
--------------------------
--------------------------
Résultat final :
9/1+8/5 est égal à
53/5
--------------------------
</pre>

* Calcul de : 456/8975-9/6x15/2+1/2+5863/45-125/15
<pre>$ ./main
Entrer fractions
456/8975-9/6*15/2+1/2+5863/45-125/15
--------------------------
Multiplication
456/8975-135/12+1/2+5863/45-125/15
--------------------------
--------------------------
Addition - Soustraction
-402051/35900+1/2+5863/45-125/15
--------------------------
--------------------------
Addition - Soustraction
-384101/35900+5863/45-125/15
--------------------------
--------------------------
Addition - Soustraction
38639431/323100-125/15
--------------------------
--------------------------
Addition - Soustraction
35946931/323100
--------------------------
--------------------------
Résultat final :
456/8975-9/6*15/2+1/2+5863/45-125/15 est égal à
35946931/323100
--------------------------
</pre>
