# Práctica de Programación: Piedra, Papel o Tijera (Versión POO)
## Introducción a la Programación Orientada a Objetos en C++

Este repositorio contiene la evolución del algoritmo clásico "Piedra, Papel o Tijera", migrando de un paradigma de programación estructurada hacia la **Programación Orientada a Objetos (POO)**. El objetivo principal es aplicar conceptos de encapsulamiento mediante el uso de clases, atributos privados y métodos de acceso.

---

## 📋 Descripción del Desafío

El estudiante debe reestructurar el código base del juego para que toda la información de los participantes sea gestionada a través de instancias de una clase llamada `Jugador`. El flujo del programa seguirá siendo secuencial dentro del `main()`, pero la manipulación de datos debe hacerse estrictamente mediante los métodos definidos en la clase.

### Especificaciones de la Clase `Jugador`
La clase debe presentar la siguiente estructura de visibilidad:

| Elemento | Tipo | Modificador | Descripción |
| :--- | :--- | :--- | :--- |
| `jugada` | Atributo | **Private (-)** | Almacena la opción elegida (1, 2 o 3). |
| `puntaje` | Atributo | **Public (+)** | Acumulador de partidas ganadas. |
| `getJugada()` | Método | **Public (+)** | Retorna el valor actual del atributo `jugada`. |
| `setJugada(n)` | Método | **Public (+)** | Asigna un nuevo valor al atributo `jugada`. |

---

## 🛠️ Pautas de Implementación

Para completar el programa de forma correcta, el estudiante debe seguir estas pautas secuenciales:

### 1. Definición de la Clase
Debe declarar la clase `Jugador` antes de la función principal. Asegúrese de que el atributo `jugada` sea privado para demostrar el concepto de **encapsulamiento**.



### 2. Instanciación y Captura
En el `main()`, se deben crear dos objetos: `j1` y `j2`. Al solicitar las jugadas al usuario, los valores ingresados no pueden asignarse directamente a los objetos. Se debe utilizar una variable auxiliar y luego enviarla a través del método `setJugada()`.

```cpp
short aux;
cout << "Jugador 1, elija su jugada: ";
cin >> aux;
j1.setJugada(aux);