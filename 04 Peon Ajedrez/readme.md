# ♟ Ejercicio: Peón en Camino a Coronación

## Descripción
Este programa simula el avance de un **peón de ajedrez** en un tablero, determinando cuántos movimientos le faltan para coronarse, considerando su posición inicial y la dirección de avance.  

El peón puede avanzar hacia **arriba (U)** o hacia **abajo (D)**, y el cálculo se realiza en función de la fila inicial y la dirección.

---

## Ejemplos de Entrada y Salida

| Entrada  | Salida |
|----------|--------|
| `2 1 U`  | `6`    |
| `7 1 D`  | `6`    |
| `7 1 U`  | `1`    |

**Interpretación:**
- La entrada está compuesta por:
  1. **Fila inicial (`f`)** – posición del peón en el eje vertical (1 a 8).
  2. **Columna (`c`)** – posición en el eje horizontal (1 a 8) *(no influye en el cálculo de avance)*.
  3. **Dirección (`dir`)** – `U` para arriba o `D` para abajo.

---

## Diseño en POO

### Clase `Peon`
**Atributos:**
- `fila` → posición inicial del peón en filas.
- `columna` → posición inicial en columnas.
- `direccion` → sentido de avance (`U` o `D`).

**Métodos:**
1. `calcular_celdas_faltantes()` → retorna el número de movimientos restantes para coronarse.
2. `es_posicion_coronacion()` → determina si el peón ya está en la fila de coronación.
3. `mostrar_celdas_restantes()` → imprime un mensaje indicando cuántas celdas faltan.

---

## Lógica de Cálculo

- Si el peón se mueve hacia **arriba (`U`)**, la coronación ocurre en la fila `8`.
- Si el peón se mueve hacia **abajo (`D`)**, la coronación ocurre en la fila `1`.
- Los movimientos restantes se calculan como:
  - `8 - fila` si `U`
  - `fila - 1` si `D`

---

## Ejemplo de Ejecución

