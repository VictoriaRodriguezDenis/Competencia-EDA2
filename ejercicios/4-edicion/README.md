# Ejercicio 4 - Mao meno parecidas

**Táctica sugerida:** programación dinámica.

## Problema

Un corrector ortográfico necesita saber qué tan parecidas son dos palabras. Para
eso calcula la **cantidad mínima de cambios** necesaria para transformar la
primera palabra (`origen`) en la segunda (`destino`).

Hay tres cambios posibles, y cada uno cuenta como **1**:

- **Insertar** una letra en cualquier posición.
- **Borrar** una letra.
- **Reemplazar** una letra por otra.

Por ejemplo, para transformar `kitten` en `sitting` alcanzan 3 cambios, y no se
puede con menos:

```
kitten
sitten     reemplazar k por s
sittin     reemplazar e por i
sitting    insertar g al final
```

No se pide decir cuáles son los cambios: solo **cuántos** son.

## Qué hay que programar

En `main.cpp`, escribir el programa completo: **leer la entrada** (por `cin`),
resolver cada caso e **imprimir la salida** (por `cout`), con el formato que se
describe más abajo.

El `main` solo trae dos líneas que hacen más rápida la lectura (no las borren). Pueden agregar todas las funciones que necesiten.

- Las palabras tienen solo letras minúsculas (`a` a `z`) y nunca son vacías.

Lo único que hace falta saber de `string`:

```cpp
string origen;
cin >> origen;    // lee una palabra
origen.length()   // largo de la palabra
origen[i]         // letra en la posición i (la primera es la 0)
```

## Orden pedido

`O(N · M)` en tiempo, siendo `N` y `M` los largos de las dos palabras.

La recursión "pura" (sin guardar resultados) es exponencial y no pasa los casos
medianos ni los grandes.

## Formato de entrada

La primera línea tiene `P`, la cantidad de casos. Cada caso tiene dos líneas:

```
origen
destino
```

Límites (los de tamaños y largos son para **cada** caso):

- `1 <= P <= 1.000`
- `1 <= largo de cada palabra <= 2.000`

> **Ojo con la memoria.** Las variables locales de una función tienen poco
> espacio: unos 8 MB en total. Una matriz de 2001 × 2001 enteros ocupa 16 MB.
> Si la declaran como variable local, el programa se cae apenas arranca y el
> script muestra `ERROR EN EJECUCION`:
>
> ```cpp
> int tab[2001][2001];   // MAL: no entra, el programa se cae
> ```
>
> Las matrices grandes se crean con `new`, que no tiene ese límite:
>
> ```cpp
> int **tab = new int *[filas];
> for (int i = 0; i < filas; i++)
> {
>     tab[i] = new int[columnas];
> }
> ```

## Formato de salida

Una línea por caso, con la cantidad mínima de cambios.

## Ejemplo

Entrada:

```
4
forth
porth
kitten
sitting
casa
casa
sol
luna
```

Salida:

```
1
3
0
4
```

Explicación:

- **Caso 1.** Reemplazar `f` por `p`.
- **Caso 2.** `kitten` → `sitten` (reemplazar `k` por `s`) → `sittin`
  (reemplazar `e` por `i`) → `sitting` (insertar `g` al final).
- **Caso 3.** Las palabras son iguales.
- **Caso 4.** `sol` → `lol` → `lul` → `lun` → `luna`: tres reemplazos y una
  inserción. Las palabras comparten la `l`, pero no conviene aprovecharla: para
  dejarla en su lugar hay que borrar `s` y `o` e insertar `u`, `n` y `a`, que
  son 5 cambios.

## Cómo probarlo

Desde la raíz del repositorio:

```bash
# Compila este ejercicio y lo corre contra sus archivos de prueba.
./probar.sh -e 4
```
