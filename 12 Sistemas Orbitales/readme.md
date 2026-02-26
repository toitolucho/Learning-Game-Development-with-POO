# Guía de Laboratorio: Simulación de Sistemas Orbitales en 2D

En esta práctica exploraremos cómo manipular la posición y rotación de objetos en un motor de videojuegos utilizando programación orientada a objetos. Construiremos un Sistema Solar en 2D y aprenderemos a reutilizar un mismo script para generar comportamientos complejos.

## 1. Descripción del Desafío y Preparación

El objetivo principal es crear una simulación de un sistema solar bidimensional utilizando un único script que será reutilizado por todos los cuerpos celestes. Se evaluará la comprensión de variables expuestas, el ciclo de actualización del motor y las matemáticas de transformación espacial.

**Requisitos Previos:**
* Seleccionar un motor de desarrollo (Unity o Unreal Engine).
* Buscar o diseñar *sprites* (imágenes 2D) propios para representar una estrella central (Sol), al menos dos planetas y una luna.
* Importar los *sprites* al motor y ubicarlos inicialmente en la escena de juego.

---

## 2. Diseño de la Solución (Diagrama de Clases)



Para resolver este problema de forma eficiente, aplicaremos el principio de reutilización de código. No crearemos un script específico para cada planeta. En su lugar, diseñaremos una única clase llamada `ControladorOrbita`. Cada cuerpo celeste será una instancia de esta clase.

**Atributos de la Clase:**
* `Objetivo Central`: Almacena la referencia espacial del objeto alrededor del cual se va a rotar (por ejemplo, el Sol).
* `Velocidad de Rotacion`: Un valor numérico decimal que define la rapidez del movimiento orbital.
* `Eje de Rotacion`: Un vector tridimensional que define la dirección del giro. En un entorno 2D estándar, este giro ocurre sobre el eje Z.

**Métodos de la Clase:**
* `Update()` (Unity) o `Tick()` (Unreal): Método nativo del ciclo de vida del motor que se ejecuta en cada fotograma.
* `Orbitar()`: Función personalizada que contendrá la lógica matemática del movimiento y será invocada constantemente desde el método de actualización.

---

## 3. Fundamento Matemático: Vectores y Rotación



En el espacio bidimensional, rotar un punto $(x, y)$ alrededor de un origen $(0,0)$ por un ángulo $\theta$ requiere el uso de trigonometría básica, específicamente las funciones Seno y Coseno. La transformación matemática pura se define con las siguientes ecuaciones:

$$x' = x \cos(\theta) - y \sin(\theta)$$
$$y' = x \sin(\theta) + y \cos(\theta)$$

**La Simplificación del Motor:**
Calcular estas transformaciones manualmente, sumar la posición del origen y multiplicarlo por el tiempo en cada fotograma resulta ineficiente. Los motores de videojuegos modernos procesan esta matemática (utilizando matrices de transformación y cuaterniones) a través de funciones de alto nivel altamente optimizadas:

* **En Unity:** El motor proporciona el método `Transform.RotateAround(Vector3 punto, Vector3 eje, float angulo)`.
* **En Unreal Engine:** Se maneja a través de nodos como `RotateAngleAxis` (en Blueprints) o modificando la rotación de un `SpringArmComponent` o `SceneComponent` que actúe como pivote central.

---

## 4. Implementación Guiada (Paso a Paso)

Implementaremos el código en fases para comprender la comunicación entre el script y la interfaz visual del editor.

### Paso 4.1: Declaración de Variables
El primer paso es definir los atributos asegurando que sean visibles, accesibles y editables directamente desde el editor visual del motor, sin necesidad de modificar el código posteriormente.

**Estructura en Pseudocódigo:**
```text
Clase ControladorOrbita:
    Variable Expuesta: Objetivo (Tipo: Referencia a Objeto Espacial)
    Variable Expuesta: Velocidad (Tipo: Decimal) = 20.0
    Variable Expuesta: Eje (Tipo: Vector 3D) = (0, 0, 1) // Representa el Eje Z