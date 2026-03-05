# Guía de Práctica: Programación Orientada a Objetos Avanzada
## Proyecto: Player vs Player - Sistema de Duelo Automatizado

En esta cuarta etapa, evolucionamos hacia un modelo donde la clase `Player` posee autonomía. Ya no es el `main` quien realiza la lógica de comparación, sino que los objetos tienen la capacidad de **evaluar a sus contrincantes** y gestionar su propia eficiencia.

---

## 🏛️ Estructura de la Clase `Player`

El estudiante deberá implementar la clase siguiendo estrictamente el siguiente diseño de miembros:

| Miembro | Tipo | Modificador | Descripción |
| :--- | :--- | :--- | :--- |
| `opcionJugada` | Atributo (short) | **Private (-)** | Selección (1: Piedra, 2: Papel, 3: Tijera). |
| `puntaje` | Atributo (int) | **Private (-)** | Acumulador de victorias. |
| `nombre` | Atributo (string) | **Public (+)** | Identificador del jugador. |
| **Constructor** | Método | **Public (+)** | Por defecto e inicializador de puntaje. |
| `seleccionar()` | Método | **Public (+)** | Captura la jugada desde consola. |
| `traducir()` | Método (string) | **Public (+)** | Retorna `()`, `[]` o `8<`. |
| `evaluar(Player)` | Método (int) | **Private (-)** | Compara la jugada propia contra otro objeto. |
| `jugar(Player)` | Método | **Public (+)** | Orquesta el duelo, traduce e incrementa puntaje. |
| `obtenerEficiencia(n)`| Método (float) | **Public (+)** | Calcula el % de éxito según partidas. |

```mermaid
classDiagram
    class Player {
        - short opcionJugada
        - int puntaje
        + string nombre
        + Player()
        + Player(int puntajeInicial)
        + seleccionar() void
        + traducir() string
        - evaluar(Player contrario) int
        + jugar(Player contrario) void
        + obtenerEficiencia(int n) float
    }