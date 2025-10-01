# 🐸 Frogger con Mochilero (OOP Console Game)

Este proyecto es una adaptación del clásico **Frogger**, diseñado para practicar **Programación Orientada a Objetos (POO)** en consola. El objetivo es aprender a diseñar clases, usar herencia y, sobre todo, lograr una comunicación efectiva entre objetos a través de métodos.

---

## 📦 Estructura de Clases y Comunicación

### 1. `GameObject` (Abstracto)
- **Atributos:**
  - `nombre : string` — Identificador del objeto (Moneda, Fruta, Estrella).
  - `posX, posY : int` — Posición en el mapa.
  - `puntos : int` — Puntos que otorga.
- **Métodos:**
  - `Mostrar()` — Imprime tipo y posición.

### 2. `Recolectable` (hereda de `GameObject`)
- **Atributos:**
  - `activo : bool` — Si está disponible.
- **Métodos:**
  - `Recolectar()` — Marca como inactivo.

### 3. Clases Concretas de Recolectables
- **`Moneda`**: `puntos = 10`.
- **`Fruta`**: `puntos = 50`.
- **`Estrella`**: `puntos = 100`, otorga +1 vida, se mueve horizontalmente.

### 4. `Mochilero`
- **Atributos:**
  - `items : List<GameObject>` — Objetos recolectados.
  - `puntosTotales : int` — Suma de puntos.
- **Métodos:**
  - `AgregarObjeto(GameObject obj)` — Agrega objeto y suma puntos.
  - `MostrarContenido()` — Lista objetos y puntos.

### 5. `Personaje` (Abstracto)
- **Atributos:**
  - `nombre : string`
  - `vidas : int`
  - `posX, posY : int`
- **Métodos:**
  - `MoverHorizontal(direccion)` — Cambia X.
  - `MoverVertical(sentido)` — Cambia Y (carretera a carretera).
  - `MostrarEstado()` — Imprime posición, vidas y puntos.

### 6. `Rana` (hereda de `Personaje`)
- **Atributos:**
  - `mochilero : Mochilero`
- **Métodos:**
  - `RecolectarObjeto(GameObject obj)` — Añade al mochilero, suma vida si es estrella.
  - `MostrarInventario()` — Imprime mochila y puntos.

### 7. `Escenario`
- **Atributos:**
  - `ancho, alto : int`
  - `rana : Rana`
  - `objetos : List<GameObject>`
- **Métodos:**
  - `MostrarMapa()` — Imprime estado general.
  - `MoverEstrellas()` — Actualiza posición de estrellas.
  - `DetectarColisiones()` — Si rana coincide con objeto, lo recolecta.

---

## 🔗 Comunicación entre Clases

El diseño fuerza la interacción entre objetos mediante **métodos públicos**:

- `Escenario` detecta colisión y llama a `Rana.RecolectarObjeto(obj)`.
- `Rana` llama a `Mochilero.AgregarObjeto(obj)`.
- Si el objeto es `Estrella`, `Rana` incrementa sus vidas.
- `Estrella` puede mover su posición cada turno llamando a su propio método.

**Ejemplo de flujo:**

```cpp
// En Escenario:
if (rana.posX == obj.posX && rana.posY == obj.posY && obj.activo) {
    rana.RecolectarObjeto(obj);
    obj.Recolectar();
}

// En Rana:
void RecolectarObjeto(GameObject* obj) {
    mochilero.AgregarObjeto(obj);
    if (obj->nombre == "Estrella") vidas++;
}

// En Mochilero:
void AgregarObjeto(GameObject* obj) {
    items.push_back(obj);
    puntosTotales += obj->puntos;
}
```

---

## 🧑‍💻 Buenas Prácticas OOP en el Proyecto

- **Encapsulamiento:** atributos privados/protegidos, acceso por métodos.
- **Herencia:** para evitar duplicidad y facilitar extensión.
- **Polimorfismo:** métodos virtuales (como `Mostrar()`).
- **Bajo acoplamiento:** las clases interactúan por métodos, no acceden directamente a atributos de otras.

---

## 🕹️ Ejemplo de Juego en Consola

```txt
>>> Nueva partida iniciada
Rana creada en posición (0,0) con 3 vidas

>>> Mover derecha
Rana ahora en posición (1,0)

>>> Rana encontró una Moneda en (1,0)
+10 puntos agregados al mochilero

>>> Mostrar inventario
Mochila contiene: [Moneda]
Puntos Totales: 10
Vidas: 3

>>> Mover vertical arriba
Rana ahora en (1,1) → Nueva carretera

>>> Rana encontró una Estrella en (1,1)
+100 puntos y +1 vida

>>> Estado actual
Posición: (1,1)
Puntos: 110
Vidas: 4
```

---

## 📚 Objetivos de Aprendizaje

- Diseñar jerarquías de clases.
- Implementar herencia y polimorfismo.
- Encapsular atributos y exponer solo lo necesario.
- Comunicar objetos mediante métodos, no atributos.
- Aplicar buenas prácticas de OOP en un proyecto real.

---
