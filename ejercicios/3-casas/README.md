# Ejercicio 3 - ¿Cuánto me llevo?

**Táctica sugerida:** programación dinámica.

## Problema

Sos un ladrón que planea robar casas a lo largo de una calle. Hay `N` casas en
fila, y cada casa tiene una cantidad de pesos en efectivo.

La única restricción es que **no podés robar dos casas adyacentes** en la misma
noche: tienen las alarmas conectadas y se dispararían.

Se quiere saber la **máxima cantidad de plata** que podés llevarte en una noche.

Dos casas son adyacentes si están una al lado de la otra en la fila (la casa `i`
y la casa `i + 1`). Podés robar todas las casas que quieras, mientras no haya dos
adyacentes. Por ejemplo, con `2 7 9 3 1`:

```
plata:   2   7   9   3   1
robar:   x       x       x      2 + 9 + 1 = 12   (vale, y es lo máximo)
robar:       x   x              7 + 9            (NO vale: son adyacentes)
```

## Qué hay que programar

En `main.cpp`, escribir el programa completo: **leer la entrada** (por `cin`),
resolver cada caso e **imprimir la salida** (por `cout`), con el formato que se
describe más abajo.

El `main` solo trae dos líneas que hacen más rápida la lectura (no las borren). Pueden agregar todas las funciones que necesiten.

- Una casa puede tener 0 pesos.

## Orden pedido

`O(N)` en tiempo.

La recursión "pura" (sin guardar resultados) es exponencial y no pasa los casos
medianos ni los grandes.

## Formato de entrada

La primera línea tiene `P`, la cantidad de casos. Cada caso tiene dos líneas:

```
N
plata_1 plata_2 ... plata_N
```

Límites (los de `N`, valores y largos son para **cada** caso):

- `1 <= P <= 1.000`
- `1 <= N <= 200.000`
- `0 <= plata_i <= 10.000`

Con estos límites el resultado siempre entra en un `int`.

## Formato de salida

Una línea por caso, con la máxima cantidad de plata.

## Ejemplo

Entrada:

```
4
5
2 7 9 3 1
4
2 1 1 2
6
5 5 10 100 10 5
1
3
```

Salida:

```
12
4
110
3
```

Explicación:

Las casas se numeran desde 1, igual que en el formato de entrada.

- **Caso 1.** Casas 1, 3 y 5: `2 + 9 + 1 = 12`.
- **Caso 2.** Casas 1 y 4: `2 + 2 = 4`. Fíjense que **no** alcanza con elegir
  "una sí, una no": a veces conviene saltearse dos casas.
- **Caso 3.** Casas 1, 4 y 6: `5 + 100 + 5 = 110`.
- **Caso 4.** Hay una sola casa.

## Cómo probarlo

Desde la raíz del repositorio:

```bash
# Compila este ejercicio y lo corre contra sus archivos de prueba.
./probar.sh -e 3
```
