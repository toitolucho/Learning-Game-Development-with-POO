# 🎲 Cara o Cruz (Simulación en POO)

Este proyecto consiste en desarrollar un pequeño programa que simule el clásico juego de **"Cara o Cruz"** usando **Programación Orientada a Objetos (POO)**.  
El objetivo es que el programa permita a dos jugadores elegir una cara de la moneda y, mediante un lanzamiento aleatorio, determine cuál jugador inicia el juego.  

La simulación debe usar **valores aleatorios** para que los resultados sean realistas y no predecibles.

---

## 🎯 Objetivos de Aprendizaje
- Practicar el diseño de **clases y objetos** en POO.
- Implementar **atributos** y **métodos** de forma correcta.
- Usar **aleatoriedad** para simular resultados reales.
- Separar la lógica del juego en clases independientes.

---

## 🛠️ Estructura de Clases

### **Clase `Moneda`**
| Atributo / Método | Descripción |
|-------------------|-------------|
| `Valor` *(int)* | Representa el resultado del lanzamiento. <br> `1` → Cara, `0` → Cruz |
| `Randomizar()` | Asigna aleatoriamente `1` o `0` al atributo `Valor`. |
| `RenderizarHTML()` | Muestra una representación gráfica de la moneda en HTML. |
| `Print()` | Imprime el resultado de forma legible en consola. |

---

### **Clase `Jugador`**
| Atributo / Método | Descripción |
|-------------------|-------------|
| `Nombre` *(string)* | Nombre del jugador. |
| `Opcion` *(int)* | Elección del jugador: `1` → Cara, `0` → Cruz. |

---

### **Clase `Juego`**
| Atributo / Método | Descripción |
|-------------------|-------------|
| `Jugador1`, `Jugador2` | Instancias de la clase `Jugador`. |
| `Moneda` | Instancia de la clase `Moneda`. |
| `PedirDatos()` | Solicita al usuario los datos de los jugadores y sus elecciones. |
| `IdentificarGanador()` | Determina qué jugador inicia el juego según el lanzamiento de la moneda. |

---

## 📜 Representación Visual de la Moneda

```text
    $$$$              $$$$
  $$    $$          $$    $$
$$        $$      $$   \/   $$
$$        $$      $$   /\   $$
  $$    $$          $$    $$
    $$$$              $$$$
	Cara              Cruz
     1                  0
