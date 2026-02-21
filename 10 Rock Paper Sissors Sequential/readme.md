# Guía de Práctica: Simulación de Juego en C++
## Proyecto: Piedra, Papel o Tijera

Este documento describe la metodología para el desarrollo de un algoritmo en lenguaje C++ que simula el juego de "Piedra, Papel o Tijera" mediante la captura de datos numéricos y su posterior procesamiento lógico.

---

## 1. Descripción del Problema
El objetivo es construir un programa que determine el ganador de una contienda entre dos jugadores. El sistema debe recibir dos valores enteros, asociarlos a una representación gráfica específica y aplicar las reglas de juego tradicionales para emitir un veredicto.

### Especificaciones de Interfaz
Se debe utilizar la siguiente nomenclatura para la entrada y salida de datos:

| Opción | Representación | Significado |
| :--- | :---: | :--- |
| **1** | `()` | Piedra |
| **2** | `[]` | Papel |
| **3** | `8<` | Tijera |

---

## 2. Pautas de Resolución Secuencial

Para una implementación exitosa, el estudiante deberá seguir los siguientes pasos de forma estructurada:

### Paso 1: Definición de Variables y Entrada
* Declarar variables de tipo entero corto (`short`) para almacenar las opciones de los jugadores (`j1`, `j2`).
* Implementar mensajes de salida (`cout`) que soliciten al usuario el ingreso de datos.
* Capturar las entradas mediante el flujo estándar (`cin`).

### Paso 2: Procesamiento de Símbolos
* Antes de realizar la comparación lógica, el algoritmo debe determinar qué símbolo corresponde a cada número ingresado.
* Se recomienda el uso de estructuras de control `switch` o `if-else` anidados para asignar la cadena de texto correspondiente (ej. `()` para el valor 1) a variables de tipo `string`.

### Paso 3: Evaluación de la Jugada
* **Condición de Empate:** El programa debe verificar primero si ambos valores de entrada son idénticos.
* **Condición de Victoria:** Se deben evaluar las tres combinaciones posibles donde el Jugador 1 resulta ganador:
    1. Piedra (1) vence a Tijera (3).
    2. Papel (2) vence a Piedra (1).
    3. Tijera (3) vence a Papel (2).
* **Condición por Defecto:** Si no existe empate y no se cumplen las condiciones de victoria del Jugador 1, el sistema debe declarar ganador al Jugador 2.

### Paso 4: Salida de Resultados
* El programa debe imprimir en pantalla la confrontación visual siguiendo el formato: `[Símbolo J1] VS [Símbolo J2]`.
* Finalmente, se debe mostrar el mensaje con el resultado definitivo (EMPATE, GANO EL JUGADOR 1 o GANO EL JUGADOR 2).

---

## 3. Ejemplo de Ejecución Esperada

**Entrada:**
```text
Introduzca la opcion del jugador 1: 1
Introduzca la opcion del jugador 2: 3
```
**Salida:**
```text
()  VS  8<
GANO EL JUGADOR 1
```