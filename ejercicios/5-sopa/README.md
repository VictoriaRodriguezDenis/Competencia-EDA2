# Ejercicio 5 - Sopa de letras

**Táctica sugerida:** backtracking.

## Problema

Hay un tablero de letras y una palabra. Se quiere saber si la palabra **se puede
formar** en el tablero.

**Atención: no es la sopa de letras clásica.** Acá la palabra **no** tiene que
estar en línea recta. La palabra se forma con un **camino** de celdas, y el
camino **puede girar** todas las veces que quiera, en cualquier sentido (también
hacia arriba o hacia la izquierda).

Las reglas del camino son:

- El camino empieza en **cualquier** celda.
- De una celda se pasa a una **vecina**: arriba, abajo, izquierda o derecha.
  **No** vale moverse en diagonal.
- La primera celda del camino tiene la primera letra de la palabra, la segunda
  celda tiene la segunda letra, y así hasta el final.
- **No se puede usar dos veces la misma celda** en el mismo camino.

Por ejemplo, en este tablero la palabra `ABCCED` **sí** se puede formar. El
camino es el que marcan los números (1 es la primera letra, 2 la segunda...):

```
tablero        camino de ABCCED

A B C E        1 2 3 .        A → B → C
                                      ↓
S F C S        . . 4 .                C
                                      ↓
A D E E        . 6 5 .            D ← E
```

El camino va a la derecha, después baja y después vuelve a la izquierda: gira
dos veces.

En el mismo tablero, estas palabras **no** se pueden formar:

```
ABCB           AFC

1 2 3 .        1 . . .
. . . .        . 2 . .
. . . .        . . . .
```

- `ABCB`: después de `A`, `B`, `C` haría falta otra `B` vecina de esa `C`. La
  única `B` del tablero es la celda 2, que ya se usó.
- `AFC`: la `F` está en diagonal de la `A`, no es vecina.

Alcanza con que exista **un** camino. No se pide decir cuál es.

## Qué hay que programar

En `main.cpp`, escribir el programa completo: **leer la entrada** (por `cin`),
resolver cada caso e **imprimir la salida** (por `cout`), con el formato que se
describe más abajo.

El `main` solo trae dos líneas que hacen más rápida la lectura (no las borren). Pueden agregar todas las funciones que necesiten.

- El tablero y la palabra tienen solo letras mayúsculas (`A` a `Z`).
- La misma letra puede estar en varias celdas.

Una forma simple de guardar el tablero es un array de `string`, uno por fila:

```cpp
string tablero[6];
cin >> tablero[f];   // lee una fila completa
tablero[f][c]        // letra de la fila f, columna c (empiezan en 0)

string palabra;
cin >> palabra;      // lee la palabra
palabra.length()     // largo de la palabra
```

## Orden pedido

No se pide un orden: el tablero es chico y hay que **probar los caminos**. Lo que
sí se pide es que la búsqueda **corte** un camino apenas una letra no coincide.

## Formato de entrada

La primera línea tiene `P`, la cantidad de casos. Cada caso tiene:

```
F C
fila_1
fila_2
...
fila_F
palabra
```

`F` es la cantidad de filas y `C` la cantidad de columnas. Cada fila es un texto
de `C` letras, sin espacios.

Límites (los de tamaños y largos son para **cada** caso):

- `1 <= P <= 3.000`
- `1 <= F, C <= 6`
- `1 <= largo de la palabra <= 14`

## Formato de salida

Una línea por caso: `SI` si la palabra se puede formar, `NO` si no se puede.
Las dos respuestas van en mayúsculas y sin tilde.

## Ejemplo

Entrada:

```
5
3 4
ABCE
SFCS
ADEE
ABCCED
3 4
ABCE
SFCS
ADEE
SEE
3 4
ABCE
SFCS
ADEE
ABCB
3 4
ABCE
SFCS
ADEE
ABFDA
3 4
ABCE
SFCS
ADEE
AFC
```

Salida:

```
SI
SI
NO
SI
NO
```

Explicación (los cinco casos usan el mismo tablero):

- **Caso 1.** `ABCCED`: es el camino del dibujo de arriba.
- **Caso 2.** `SEE`: la `S` de la última columna, la `E` que tiene abajo y la
  `E` que está a la izquierda de esa.

  ```
  . . . .
  . . . 1
  . . 3 2
  ```
- **Caso 3.** `ABCB`: se llega a `ABC`, pero la única `B` vecina de esa `C` es
  la que ya se usó.
- **Caso 4.** `ABFDA`: empieza en la `A` de arriba y termina en la `A` de abajo.
  Son dos celdas distintas, entonces vale. La letra se puede repetir; la celda
  no.

  ```
  1 2 . .
  . 3 . .
  5 4 . .
  ```
- **Caso 5.** `AFC`: la `F` solo está en diagonal de las `A`, y en diagonal no
  vale.

## Cómo probarlo

Desde la raíz del repositorio:

```bash
# Compila este ejercicio y lo corre contra sus archivos de prueba.
./probar.sh -e 5
```
