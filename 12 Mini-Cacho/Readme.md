# Ejercicio: Puntuación de Dados (Mini-Cacho) 🎲

Este repositorio contiene la tarea práctica para desarrollar un sistema de puntuación de un juego de dados simplificado. El objetivo es aplicar los conceptos de **programación modular** y **estructuras de repetición**, creando funciones específicas que colaboran dentro de un ciclo de juego.

## 📌 Reglas del Juego

El jugador lanzará 3 dados (valores del 1 al 6) ordenados de menor a mayor ($d_1 \le d_2 \le d_3$). Los puntajes por ronda se calculan así:
1. **Trío:** 3 dados iguales (ej. 4, 4, 4) = **50 puntos**.
2. **Escalera:** 3 dados consecutivos (ej. 2, 3, 4) = **25 puntos**.
3. **Suma simple:** Cualquier otra combinación = **suma de los 3 dados**.

---

## ⚙️ Especificaciones de las Funciones Módulo

Debes implementar las siguientes funciones:

### 1. `bool EsTrio(int d1, int d2, int d3)`
Evalúa si los tres dados tienen el mismo valor.

### 2. `bool EsEscalera(int d1, int d2, int d3)`
Evalúa si los tres dados son números consecutivos.

### 3. `int CalcularPuntaje(int d1, int d2, int d3)`
Determina el puntaje de la ronda. **Debe llamar** a `EsTrio()` y `EsEscalera()`. Retorna el puntaje de esa jugada específica.

### 4. `void ImprimirMarcador(int ronda, int puntosRonda, int puntosAcumulados)`
Muestra por consola el resumen de la ronda actual.
*Ejemplo:* `Ronda 1 | Puntos ganados: 25 | Total acumulado: 25`

---

## 🔄 El Ciclo de Juego (Nueva Implementación)

### 5. Función `void JugarPartida(int cantidadRondas)`
Esta es la función que controla el flujo del juego utilizando un ciclo (`for` o `while`). 
* **Lógica:** 1. Inicializa una variable `puntajeTotal` en 0.
  2. Inicia un ciclo que se repetirá la cantidad de veces indicada por `cantidadRondas`.
  3. **Dentro del ciclo (por cada ronda):**
     * Solicita al usuario ingresar los 3 dados (recordando que deben estar ordenados).
     * Llama a `CalcularPuntaje` para obtener los puntos de esa tirada.
     * Suma esos puntos al `puntajeTotal`.
     * Llama a `ImprimirMarcador` para mostrar el estado actual.
  4. **Al salir del ciclo:** Imprime un mensaje final con el `puntajeTotal` definitivo de la partida.

## 🚀 Programa Principal (`main`)
Tu función `main` debe ser sumamente limpia. Solo debe:
1. Dar la bienvenida al juego.
2. Preguntar al usuario: *"¿Cuántas rondas deseas jugar?"*
3. Leer ese número y pasarlo como parámetro a la función `JugarPartida(cantidadRondas)`.