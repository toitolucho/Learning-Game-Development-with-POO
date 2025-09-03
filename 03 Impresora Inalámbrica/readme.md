# 🖨️ Simulación de una Impresora Inalámbrica con Batería

Este proyecto consiste en desarrollar un programa que simule el funcionamiento de una **impresora inalámbrica** que funciona con batería y tinta negra. 
Es un proyecto para aprender los conceptos de POO.
El objetivo es practicar conceptos básicos de **Programación Orientada a Objetos (POO)** como **clases**, **constructores**, **métodos** y **encapsulamiento**, sin necesidad de listas o estructuras de datos complejas.

---

## 🎯 Objetivos de Aprendizaje
- Modelar una impresora con atributos y métodos propios.
- Implementar constructores para inicializar estados iniciales.
- Aplicar métodos para simular acciones reales.
- Validar condiciones antes de realizar operaciones.

---

## 🛠️ Requisitos de Funcionamiento

### Parámetros Configurables (Documento)
Al inicio del programa, el usuario debe ingresar:
- **Consumo de tinta por palabra** (`x` unidades).
- **Cantidad promedio de palabras por hoja**.
- **Cantidad de hojas del documento**.
- **Texto Documento**

### Estado Inicial de la Impresora
- **Nivel de tinta actual**.
- **Nivel de energía de la batería**.
- **Número de hojas disponibles en la bandeja**.
- - **Consumo de energía por hoja** (`t` unidades). (Configurable en el constructor)

---

## ⚙️ Reglas de Funcionamiento
1. Antes de imprimir un documento, se debe verificar:
   - Que haya suficiente tinta para todas las palabras.
   - Que haya suficiente energía para todas las hojas.
   - Que haya suficientes hojas en la bandeja.
2. La impresora imprimirá hoja por hoja, reduciendo:
   - El nivel de tinta según el número de palabras.
   - El nivel de batería según el consumo por hoja.
   - El número de hojas disponibles.
3. Si durante la impresión alguno de los recursos se agota:
   - El proceso se detiene y se notifica el motivo.
4. No se deben permitir valores negativos en los recursos.

---

## 📥 Entrada de Ejemplo
```text
Consumo de tinta por palabra: 0.5
Consumo de energía por hoja: 2
Palabras por hoja: 100
Hojas del documento: 5
Tinta inicial: 300
Batería inicial: 20
Hojas en bandeja: 10
