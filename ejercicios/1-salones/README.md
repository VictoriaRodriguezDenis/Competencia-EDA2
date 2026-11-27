# Ejercicio 1 - Salones de Bedelía

**Táctica sugerida:** greedy.

## Problema

Bedelía recibió todas las solicitudes de cursos para el próximo semestre y tiene
que asignar un salón a cada uno. Cada curso tiene un momento de inicio y un
momento de fin. Un mismo salón se puede usar para varios cursos, siempre que sus
horarios **no se superpongan**.

Se quiere saber la **cantidad mínima de salones** necesaria para dictar todos
los cursos.

Los horarios se miden en minutos desde el comienzo del semestre. Por ejemplo, un
curso con inicio `480` y fin `600` ocupa un salón desde el minuto 480 hasta el
minuto 600.

No se pide decir qué salón le toca a cada curso: solo **cuántos** salones hacen
falta.

> **Importante:** si un curso termina en el minuto `X` y otro empieza en el
> minuto `X`, **no** se superponen: pueden usar el mismo salón.

## Qué hay que programar

En `main.cpp`, escribir el programa completo: **leer la entrada** (por `cin`),
resolver cada caso e **imprimir la salida** (por `cout`), con el formato que se
describe más abajo.

El `main` solo trae dos líneas que hacen más rápida la lectura (no las borren). Pueden agregar todas las funciones que necesiten.

- Los cursos **no vienen ordenados**.

## Orden pedido

`O(N log N)` en tiempo, siendo `N` la cantidad de cursos.

Una solución `O(N²)` no pasa los casos grandes.

## Formato de entrada

La primera línea tiene `P`, la cantidad de casos. Cada caso tiene tres líneas:

```
N
inicio_1 inicio_2 ... inicio_N
fin_1 fin_2 ... fin_N
```

La segunda línea tiene los inicios de los `N` cursos y la tercera tiene los
fines, **en el mismo orden**: el curso `i` va de `inicio_i` a `fin_i`.

Límites (los de `N`, valores y largos son para **cada** caso):

- `1 <= P <= 1.000`
- `1 <= N <= 200.000`
- `0 <= inicio_i < fin_i <= 1.000.000.000`

## Formato de salida

Una línea por caso, con la cantidad mínima de salones.

## Ejemplo

Entrada:

```
3
5
480 540 600 660 720
600 660 720 780 840
3
0 30 60
30 60 90
4
100 50 200 120
300 150 250 130
```

Salida:

```
2
1
3
```

Explicación:

- **Caso 1.** Los cursos son `[480,600]`, `[540,660]`, `[600,720]`, `[660,780]`
  y `[720,840]`. Nunca hay más de dos cursos al mismo tiempo. Un salón puede
  tener los cursos 1, 3 y 5, y otro salón los cursos 2 y 4.
- **Caso 2.** Los tres cursos están encadenados (uno termina justo cuando
  empieza el siguiente). Alcanza con un salón.
- **Caso 3.** Los cursos son `[100,300]`, `[50,150]`, `[200,250]` y `[120,130]`.
  En el minuto 125 hay tres cursos a la vez: `[100,300]`, `[50,150]` y
  `[120,130]`. Nunca hay cuatro: `[200,250]` empieza cuando `[50,150]` y
  `[120,130]` ya terminaron. Entonces 3 salones alcanzan.

## Cómo probarlo

Desde la raíz del repositorio:

```bash
# Compila este ejercicio y lo corre contra sus archivos de prueba.
./probar.sh -e 1
```
