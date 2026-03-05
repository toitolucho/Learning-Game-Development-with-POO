# 🎮 Ejercicio: Movimiento de Sprites y Personalización en Unity

En esta práctica, aprenderás a crear un script modular en C# que controla el movimiento en 2D y la orientación visual de un objeto. El objetivo principal es comprender cómo los **Campos Serializados** (Serialized Fields) en el Inspector de Unity permiten definir comportamientos únicos para diferentes objetos utilizando un mismo código base.

## 🎯 Objetivos de Aprendizaje
* Implementar la lógica de movimiento 2D mediante vectores.
* Gestionar el intercambio de *Sprites* y la propiedad *Flip* según la dirección del movimiento.
* Configurar múltiples GameObjects con velocidades y apariencias personalizadas desde el Editor.

## 🛠 Configuración del Proyecto
1.  Crea un nuevo proyecto en Unity usando la plantilla **2D Core**.
2.  Importa al menos dos sprites diferentes para tu personaje: uno para la vista horizontal (derecha) y otro para la vista vertical (arriba).
3.  Crea un nuevo script de C# llamado `PlayerController.cs`.

## 📝 Descripción del Script
El script `PlayerController.cs` se encarga de tres tareas fundamentales:

1.  **Variables de Control:** * `speed`: Controla la rapidez del desplazamiento.
    * `horizontalSprite` / `verticalSprite`: Almacenan las referencias visuales del personaje.
2.  **Función Move():** * Calcula el desplazamiento del objeto multiplicando la dirección por la velocidad y el tiempo transcurrido (Time.deltaTime). Esto asegura que el movimiento sea fluido independientemente de los FPS de la computadora.
3.  **Función ChangeSprite():** * Detecta hacia dónde se mueve el jugador.
    * Si se mueve horizontalmente, asigna el sprite de lado y usa la propiedad `flipX` para mirar a la izquierda.
    * Si se mueve verticalmente, asigna el sprite vertical y usa `flipY` para mirar hacia abajo.

## 🚀 Instrucciones para el Estudiante
1.  **Asigna** el script a un GameObject que tenga un componente `SpriteRenderer`.
2.  **Configura** los sprites en las ranuras correspondientes del Inspector (arrastra y suelta tus imágenes).
3.  **Crea Variaciones:** Crea tres GameObjects distintos en tu escena (por ejemplo: un "Tanque" lento y un "Fantasma" muy rápido). 
    * Configura cada uno con diferentes velocidades y sprites para comprobar la versatilidad del script.

## ⚖️ Criterios de Evaluación
* El objeto debe moverse correctamente en los 4 ejes (W, A, S, D o flechas).
* El sprite debe cambiar de orientación de forma coherente con la dirección.
* Uso correcto de `Time.deltaTime` para un movimiento estable.
* Personalización de al menos 2 objetos con diferentes velocidades y sprites.