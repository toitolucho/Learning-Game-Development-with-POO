# 🔦 Simulación de una Linterna Recargable

Este proyecto consiste en desarrollar un programa que simule el funcionamiento de una **linterna recargable** con diferentes niveles de brillo y consumo de energía.  
El objetivo es practicar conceptos básicos de **Programación Orientada a Objetos (POO)** como **clases**, **constructores**, **métodos** y **encapsulamiento**.

---

## 🎯 Objetivos de Aprendizaje
- Modelar un objeto del mundo real mediante clases.
- Implementar constructores para inicializar atributos.
- Utilizar métodos para modificar y consultar el estado de un objeto.
- Aplicar reglas de negocio simples para simular un comportamiento.

---

## 🛠️ Requisitos de Funcionamiento

### Configuración Inicial
La linterna tendrá los siguientes datos configurables:
- **Consumo de energía en nivel bajo** (unidades por segundo).
- **Consumo de energía en nivel medio** (unidades por segundo).
- **Consumo de energía en nivel alto** (unidades por segundo).

### Estado Inicial
El usuario debe ingresar:
- **Nivel actual de energía de la batería** (en unidades).
- **Estado inicial** (`apagada` o `encendida`).
- **Nivel de brillo actual** (`bajo`, `medio`, `alto`).

### Estado en Consumo
El Usuario puede cambiar el 
- **nivel de brillo** que desea configura

El usuario puede ingresar el **tiempo** que utilizar la linterna en ese estado

---

## ⚙️ Reglas de Funcionamiento
- Si la linterna está **apagada**, el usuario puede encenderla eligiendo un nivel de brillo.
- El encendido solo es posible si la batería tiene energía suficiente para al menos **1 segundo** de funcionamiento en el nivel elegido.
- Cuando la linterna está encendida, el usuario puede:
  - Cambiar el nivel de brillo (si hay energía suficiente para el nuevo nivel).
  - Apagarla para ahorrar energía.
- Si la energía llega a **cero**, la linterna se apaga automáticamente.

---

## 📥 Entrada de Ejemplo
```text
Consumo en nivel bajo: 1
Consumo en nivel medio: 3
Consumo en nivel alto: 5
Energía inicial: 10
