# Proyecto: Simulador de Saltos Temporales (Validador de Fechas)

## Descripcion del Sistema

El estudiante debera desarrollar un simulador de consola en el cual el usuario opera una maquina del tiempo. Para realizar un salto temporal exitoso, el sistema debe recibir una fecha de destino (dia, mes y ano) y verificar matematicamente si dicha fecha es valida dentro del calendario gregoriano. 

El objetivo academico central de esta practica es la implementacion estricta del paradigma de programacion modular. Se evaluara la capacidad del estudiante para disenar funciones con responsabilidades unicas que se comunican entre si mediante el paso de parametros y retornos.



## Arquitectura de Funciones Requeridas

El estudiante tiene estrictamente prohibido centralizar la logica en el programa principal. Se requiere la implementacion exacta de los siguientes modulos con sus respectivas firmas:

### 1. Funcion EsBisiesto
* **Firma:** `bool EsBisiesto(int anio)`
* **Requerimiento:** Retorna verdadero si el ano es divisible por 4, pero no por 100, a menos que tambien sea divisible por 400. Retorna falso en cualquier otro caso.

### 2. Funcion ObtenerDiasDelMes
* **Firma:** `int ObtenerDiasDelMes(int mes, int anio)`
* **Requerimiento:** Retorna el numero maximo de dias del mes indicado. 
* **Dependencia Estricta:** Si el mes es febrero (2), el estudiante tiene la obligacion de invocar a la funcion `EsBisiesto(anio)` dentro de este modulo para determinar si debe retornar 28 o 29 dias.

### 3. Funcion EsFechaValida
* **Firma:** `bool EsFechaValida(int dia, int mes, int anio)`
* **Requerimiento:** Verifica que el mes este en el rango [1, 12]. Posteriormente, debe invocar a `ObtenerDiasDelMes(mes, anio)` para verificar que el dia ingresado se encuentre dentro de los limites de ese mes especifico. Retorna verdadero si la fecha es correcta.

### 4. Funcion EjecutarSimulacion
* **Firma:** `void EjecutarSimulacion(int cantidadRondas)`
* **Requerimiento:** Controla el ciclo principal del simulador. Por cada ronda iterada:
    1. Lee los tres enteros (dia, mes, ano).
    2. Invoca a `EsFechaValida(dia, mes, anio)`.
    3. Imprime el resultado de la operacion.
    4. Acumula el conteo de exitos.
    5. Al terminar el ciclo, imprime el resumen final.

### 5. Programa Principal (main)
* **Requerimiento:** Punto de entrada exclusivo. Solo debe leer la cantidad de rondas iniciales, invocar a `EjecutarSimulacion(cantidadRondas)` y retornar 0.

---

## Formato de Entrada y Salida

Para garantizar la validacion automatica del codigo, el programa debe procesar la entrada estandar estrictamente bajo el siguiente formato:

* **Entrada:** La primera linea contendra un entero `N` que representa la cantidad de saltos (rondas). Las siguientes `N` lineas contendran tres enteros separados por un espacio, representando el `dia`, `mes` y `ano`.
* **Salida:** Por cada ronda, el programa imprimira exactamente la cadena `"Salto temporal completado"` si la fecha es valida, o `"Falla catastrofica: Fecha inexistente"` si es invalida. Al finalizar todas las iteraciones, imprimira una unica linea con el formato `"Saltos exitosos: X / N"`.

---

## Casos de Prueba para Verificacion del Estudiante

El estudiante debe utilizar los siguientes casos para verificar que su logica e integraciones modulares funcionan correctamente antes de realizar el commit final.

### Caso de Prueba 1: Fechas estandar y limite basico
**Entrada:**
```text
3
15 8 1995
31 4 2020
31 12 2099
```

**Entrada:**
```text
Salto temporal completado
Falla catastrofica: Fecha inexistente
Salto temporal completado
Saltos exitosos: 2 / 3
```

### Caso de Prueba 2: Validacion de Anos Bisiestos

**Entrada:**
```text
4
29 2 2024
29 2 2023
28 2 2023
29 2 1900
```

**Entrada:**
```text
Salto temporal completado
Falla catastrofica: Fecha inexistente
Salto temporal completado
Falla catastrofica: Fecha inexistente
Saltos exitosos: 2 / 4
```