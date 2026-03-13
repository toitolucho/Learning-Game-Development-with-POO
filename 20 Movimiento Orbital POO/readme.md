# Laboratorio: Simulación Orbital Paramétrica en 2D

Este repositorio contiene la implementación base para simular sistemas orbitales bidimensionales en Unity. El objetivo de esta práctica es comprender la aplicación de la trigonometría (seno y coseno) para el cálculo de trayectorias, así como la diferencia crítica entre sistemas de posicionamiento relativo y paramétrico.

## 1. Descripción Formal del Desafío

El reto consiste en programar un script en C# que permita a un `GameObject` (ej. un planeta) orbitar alrededor de otro (ej. una estrella) de forma perpetua. 

Inicialmente, el movimiento circular se puede lograr calculando vectores diferenciales en cada fotograma. Sin embargo, el desafío de ingeniería radica en **introducir deformaciones geométricas (órbitas elípticas)**. Si escalamos un vector relativo en cada iteración del ciclo `Update`, los valores sufrirán un crecimiento exponencial, resultando en un desbordamiento matemático (`-Infinity`).

Para resolver esto, la solución implementa un **enfoque paramétrico (absoluto)**:
1. Se captura el radio y el ángulo iniciales en la función `Start()`.
2. Se incrementa una variable de ángulo absoluto con el paso del tiempo.
3. Se calcula la posición en cada fotograma desde cero utilizando las ecuaciones paramétricas del círculo: $x = r \cos(\theta)$ e $y = r \sin(\theta)$.
4. Se aplican los factores de achatamiento (elipse) sobre este nuevo cálculo seguro, antes de trasladar el objeto a su posición global final.

---

## 2. Diagrama de Clases

La solución se encapsula en una única clase reutilizable. A continuación, se presenta su estructura:

```text
+-------------------------------------------------------+
|                 ControladorOrbita2D                   |
+-------------------------------------------------------+
| + objetivoCentral : Transform                         |
| + velocidadRotacion : float                           |
| + factorElipseX : float                               |
| + factorElipseY : float                               |
| - anguloActual : float                                |
| - radioInicial : float                                |
| - zOriginal : float                                   |
+-------------------------------------------------------+
| + Start()                                             |
| + Update()                                            |
| - Orbitar()                                           |
+-------------------------------------------------------+
```

## 3. Atributos Expuestos (Configuración en el Inspector)

Para garantizar la reutilización del código, la clase expone variables públicas que permiten configurar cada instancia (planetas, lunas, escudos) directamente desde el editor de Unity sin alterar el código fuente:

* **objetivoCentral (Transform):** Es la referencia al objeto alrededor del cual se calculará la rotación. Define el centro (0,0) de nuestro cálculo vectorial antes de la traslación final.
* **velocidadRotacion (float):** Determina la rapidez del movimiento en grados por segundo. Valores positivos generan una rotación antihoraria, mientras que valores negativos invierten el sentido a horario.
* **factorElipseX (float):** Multiplicador para el eje horizontal. Un valor de 1.0 mantiene la proporción circular. Valores mayores a 1.0 estiran la órbita horizontalmente.
* **factorElipseY (float):** Multiplicador para el eje vertical. Permite achatar o estirar la trayectoria en el eje Y de manera independiente al eje X.

## 4. Análisis del Código (Paso a Paso)

Para comprender cómo la matemática se traduce en instrucciones para el motor, analizaremos el script dividiéndolo en sus tres componentes principales: las variables de estado, la inicialización y el ciclo de actualización.

### 4.1. Contexto de Declaración de Variables

El script divide sus variables en dos categorías fundamentales, separando la interfaz de diseño de la lógica interna:

1. **Variables Públicas (Interfaz del Editor):** Las variables como `objetivoCentral`, `velocidadRotacion` y los factores de elipse (`factorElipseX`, `factorElipseY`) actúan como la API del script. Al ser públicas, permiten que el diseñador de niveles ajuste el comportamiento del objeto visualmente sin necesidad de reescribir el código.
2. **Variables Privadas (Estado Matemático):** `anguloActual`, `radioInicial` y `zOriginal` conforman la memoria paramétrica del objeto. No deben ser modificadas desde el exterior, ya que almacenan las condiciones iniciales perfectas necesarias para calcular la trayectoria sin errores acumulativos a lo largo del tiempo.

### 4.2. El Método `Start()`: Inicialización del Sistema Absoluto

La función `Start()` se ejecuta una única vez al instanciar el objeto. Su propósito es "leer" cómo el diseñador ubicó el planeta en la escena y registrar esas condiciones iniciales para usarlas como anclas matemáticas.

* **Captura del Radio:** Restamos la posición del centro a la posición del planeta para obtener un vector relativo. La magnitud (longitud) de los ejes X e Y de este vector se convierte en nuestro `radioInicial` constante.
* **Captura del Ángulo (Evitando saltos bruscos):** Si asumiéramos que el ángulo inicial es 0, el planeta se teletransportaría al iniciar el juego. Para evitarlo, utilizamos la función arcotangente (`Mathf.Atan2(y, x)`), la cual nos devuelve en radianes el ángulo exacto en el que el diseñador colocó el planeta respecto al centro.
* **Preservación 2D:** Guardamos la posición Z en `zOriginal` para asegurar que el cálculo orbital no empuje al objeto hacia la profundidad de la cámara.

### 4.3. El Método `Orbitar()` y su Fundamento Matemático

Este método se invoca en cada fotograma desde el `Update()`. Aquí es donde la geometría analítica se aplica en tiempo real para resolver la posición del objeto siguiendo un enfoque paramétrico de cuatro pasos:

**Paso A: El Avance del Tiempo (Incremento Angular)**
```csharp
anguloActual += velocidadRotacion * Time.deltaTime * Mathf.Deg2Rad;
```
En lugar de aplicar una rotación a la posición anterior, simplemente hacemos crecer nuestro ángulo absoluto acumulado. Multiplicamos por `Time.deltaTime` para independizar la velocidad del movimiento de los fotogramas por segundo (FPS) del procesador. Finalmente, multiplicamos por la constante `Mathf.Deg2Rad` debido a que las funciones trigonométricas de C# operan estrictamente en radianes, no en grados.

**Paso B: La Ecuación Paramétrica del Círculo y su Demostración**
```csharp
float x = radioInicial * Mathf.Cos(anguloActual);
float y = radioInicial * Mathf.Sin(anguloActual);
```
Aquí aplicamos la matemática pura para definir el movimiento circular. La posición de cualquier punto en el espacio 2D que gira alrededor de un origen se rige por las funciones trigonométricas derivadas de la circunferencia unitaria.

**Demostración Matemática:**
Si trazamos una línea desde el centro hasta la posición del objeto orbital, obtenemos la hipotenusa de un triángulo rectángulo, cuya longitud es el radio $r$. El ángulo de giro acumulado es $\theta$. 

Aplicando las definiciones trigonométricas fundamentales para aislar las coordenadas X e Y:
* Para el eje horizontal (Cateto Adyacente): $\cos(\theta) = \frac{x}{r} \implies x = r \cos(\theta)$
* Para el eje vertical (Cateto Opuesto): $\sin(\theta) = \frac{y}{r} \implies y = r \sin(\theta)$

Al recalcular estas coordenadas en cada fotograma partiendo de un `radioInicial` constante, garantizamos la estabilidad absoluta del sistema. A diferencia de un sistema diferencial (donde el error de precisión decimal se acumula en cada ciclo), el cálculo paramétrico asegura que la órbita jamás se encogerá ni crecerá de forma errática.

**Paso C: La Deformación Elíptica**
```csharp
x *= factorElipseX;
y *= factorElipseY;
```
Una vez obtenidas las coordenadas (x, y) que describen un círculo perfecto centrado en un origen abstracto (0,0), procedemos a escalar sus ejes de forma independiente. Dado que esta multiplicación geométrica se aplica únicamente sobre los valores paramétricos calculados para el fotograma actual, evitamos la retroalimentación de datos y prevenimos crecimientos exponenciales que resultarían en un desbordamiento de memoria o errores de valor infinito (`Infinity`).

**Paso D: La Traslación Vectorial (Espacio Global)**
```csharp
Vector3 vectorRotado = new Vector3(x, y, zOriginal);
transform.position = objetivoCentral.position + vectorRotado;
```
Hasta la ejecución del Paso C, toda la trayectoria (el círculo y su deformación elíptica) ocurre en un espacio local. Para situar el objeto orbital en el universo del motor gráfico, debemos ejecutar una suma de vectores. Se toma la posición global actual del objeto padre (`objetivoCentral.position`) y se le suma nuestro vector direccional y de distancia (`vectorRotado`). Esta suma vectorial garantiza que, si el objeto central se desplaza por la escena, su satélite lo acompañará instantáneamente manteniendo intacta la simulación matemática de su órbita.