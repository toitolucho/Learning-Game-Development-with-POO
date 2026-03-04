# Asignación Práctica Simulación Estocástica - Lanzamiento de Moneda

## Descripción General
Implementación de un script en el motor gráfico (Unity o Unreal Engine) para simular el lanzamiento de una moneda. El objetivo principal es gestionar recursos gráficos dinámicos, capturar eventos de entrada del usuario y comprender cómo múltiples instancias de un mismo script reaccionan de manera independiente a un único evento.

## Resultado Esperado
(Reemplace el siguiente enlace con la URL de su imagen de referencia)

![Imagen de Referencia del Resultado Esperado](URL_DE_LA_IMAGEN_AQUI)

## Material de Apoyo
Consulte los siguientes recursos en video para revisar los conceptos necesarios para esta implementación

 Parte 1 [Insertar Título del Video 1](URL_DEL_VIDEO_1_AQUI)
 Parte 2 [Insertar Título del Video 2](URL_DEL_VIDEO_2_AQUI)

## Especificaciones Técnicas

### 1. Estructura y Referencias
 Crear un script que controle el comportamiento lógico y visual del objeto principal.
 Declarar dos variables accesibles y asignables desde la interfaz del editor del motor. Estas almacenarán las referencias a los recursos gráficos correspondientes a los estados Cara y Cruz.

### 2. Captura de Eventos
 Utilizar el método de actualización continua del motor (`Update` en Unity o `Tick` en Unreal) para mantener una escucha activa de las entradas del usuario.
 Implementar una condicional que detecte la pulsación de una tecla específica para iniciar la simulación.

### 3. Lógica de Aleatoriedad y Despliegue
 Al detectarse la pulsación de la tecla, ejecutar una función que genere un valor aleatorio con probabilidad equiparable (50% para cada posible resultado).
 Modificar el componente de renderizado del objeto en tiempo de ejecución para mostrar el recurso gráfico correspondiente al valor aleatorio obtenido.

### 4. Prueba de Instanciación
 Posicionar múltiples objetos dentro de la escena y asignarles el mismo script desarrollado.
 Ejecutar la simulación y verificar que, al presionar la tecla asignada, todos los objetos reaccionen de manera simultánea, calculando y mostrando su propio resultado individual de forma independiente.