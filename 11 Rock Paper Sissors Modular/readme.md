# Guía de Práctica: Programación Modular en C++
## Proyecto: Piedra, Papel o Tijera (Versión Evolucionada)

Esta segunda versión del proyecto tiene como objetivo aplicar el paradigma de **programación modular**. El estudiante deberá dividir la lógica del juego en funciones específicas, permitiendo que el programa sea más organizado, fácil de depurar y escalable.

---

## 1. Arquitectura del Programa
El desarrollo se basa en la creación de una serie de funciones que procesan datos de entrada y devuelven resultados específicos. A continuación, se detallan los módulos requeridos:

### A. Función de Evaluación Lógica
**Firma:** `short evaluar(short op1, short op2)`
* **Propósito:** Comparar las jugadas y retornar un código numérico de estado.
* **Retornos:**
    * `0` : Indica un **Empate**.
    * `1` : Indica que el **Jugador 1 ganó**.
    * `-1` : Indica que el **Jugador 1 perdió** (Gana Jugador 2).

### B. Función de Traducción Visual
**Firma:** `string traducir(short op)`
* **Propósito:** Convertir el valor entero (1, 2 o 3) en su representación gráfica (`()`, `[]`, `8<`).
* **Nota:** Debe manejar un caso `default` para entradas incorrectas.

### C. Función de Interfaz de Jugada
**Firma:** `void imprimir(short op1, short op2)`
* **Propósito:** Mostrar en pantalla el duelo visual (ej. `[] vs ()`).
* **Dependencia:** Esta función debe llamar internamente a la función `traducir()`.

### D. Función de Veredicto
**Firma:** `void detGanador(short resultado)`
* **Propósito:** Recibir el código de retorno de `evaluar()` y mostrar el mensaje final (Ej: "GANO EL JUGADOR 1").

---

## 2. Flujo de Ejecución (Diagrama de Modularidad)

El programa principal (`main`) debe actuar únicamente como un director de orquesta, siguiendo este orden:
1. Lectura de datos.
2. Llamada a `imprimir(op1, op2)` para mostrar el duelo.
3. Llamada a `detGanador(evaluar(op1, op2))` para mostrar el resultado.



---

## 3. Matriz de Casos de Prueba (Lógica Modular)

El estudiante debe verificar que la función `evaluar()` retorne los valores correctos según la siguiente tabla:

| Jugador 1 | Jugador 2 | Valor de Retorno | Veredicto Final |
| :---: | :---: | :---: | :--- |
| 1 | 3 | `1` | GANO EL JUGADOR 1 |
| 2 | 2 | `0` | EMPATE |
| 1 | 2 | `-1` | GANO EL JUGADOR 2 |
| 3 | 2 | `1` | GANO EL JUGADOR 1 |
| 2 | 3 | `-1` | *Completar por el estudiante* |

---

## 4. Pseudocódigo Modular

```text
FUNCION traducir(op) : Cadena
    SEGUN op HACER
        1: RETORNAR "()"
        2: RETORNAR "[]"
        3: RETORNAR "8<"
        OTRO: RETORNAR "Error"
    FIN SEGUN
FIN FUNCION

FUNCION imprimir(op1, op2)
    ESCRIBIR traducir(op1), " vs ", traducir(op2)
FIN FUNCION

FUNCION evaluar(op1, op2) : Entero
    SI op1 == op2 ENTONCES RETORNAR 0
    SI (op1==1 Y op2==3) O (op1==2 Y op2==1) O (op1==3 Y op2==2) ENTONCES
        RETORNAR 1
    SINO
        RETORNAR -1
    FIN SI
FIN FUNCION

ALGORITMO Principal
    LEER op1, op2
    imprimir(op1, op2)
    detGanador(evaluar(op1, op2))
FIN