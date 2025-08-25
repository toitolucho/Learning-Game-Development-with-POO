# 🚌 Simulación de un AutoBus con Pasajeros y Combustible

Este ejercicio consiste en diseñar e implementar una **clase AutoBus** que modele el funcionamiento básico de un autobús real, gestionando **combustible**, **asientos**, **pasajeros** y **tarifa por persona**.

El objetivo es practicar conceptos de **Programación Orientada a Objetos (POO)**: clases, objetos, atributos, métodos, constructores, validaciones e invariantes.

---

## 🎯 Objetivos de Aprendizaje
- **Modelar una clase** con atributos y métodos coherentes con el dominio.
- **Implementar múltiples constructores** (por defecto y parametrizados).
- **Aplicar invariantes** (p. ej., límites y no-negatividad).
- **Distinguir consultas** (métodos que devuelven valores) de **comandos** (métodos con efectos).
- **Validar precondiciones** antes de modificar el estado.

---

## 🛠️ Requisitos de Funcionamiento

### Atributos del AutoBus
- `combustible` (double): cantidad de combustible actual. Límite máximo: **100 unidades**.
- `asientos` (int): número total de asientos del autobús.
- `tarifa` (double): precio por pasajero que sube al autobús.
- `pasajeros` (int): número de pasajeros actualmente a bordo.

### Constructores
- **Constructor por defecto**: inicializa un autobús válido (p. ej., 0 combustible, 50 asientos, tarifa 1.0, 0 pasajeros).
- **Constructor con combustible**: permite configurar el bus con un valor inicial de combustible (respetando el límite de 100).
- (Opcional) **Constructor completo**: permite fijar `combustible`, `asientos`, `tarifa`.

---

## ⚙️ Reglas de Funcionamiento
1. El **combustible** no puede ser negativo ni superar **100** unidades.
2. Los **pasajeros** no pueden superar el número de **asientos**.
3. No se permiten valores negativos en entradas de métodos.
4. Los métodos deben **validar precondiciones** y mantener las **invariantes** de la clase.

---

## 📦 Operaciones Requeridas
- `recogerPasajeros(nroPasajeros)`: valida disponibilidad de asientos e incrementa los pasajeros actuales.
- `recargarGasolina(cantidad)`: incrementa el combustible sin exceder el máximo permitido (100).
- `calcularCantidadAsientosDisponibles()`: devuelve la cantidad de asientos libres.
- `hayEspacio()`: devuelve `true` si aún hay asientos disponibles.
- `estaVacio()`: devuelve `true` si no hay pasajeros a bordo.
- `calcularMontoRecaudado()`: devuelve el monto total recaudado (`pasajeros * tarifa`).

> Nota: Puedes agregar operaciones complementarias como `bajarPasajeros(n)` si lo consideras útil para las pruebas.

---

## 📥 Ejemplo de Entrada
```text
Asientos: 40
Tarifa por persona: 2.50
Combustible inicial: 50

Operaciones:
- recogerPasajeros(15)
- calcularCantidadAsientosDisponibles()
- hayEspacio()
- recargarGasolina(20)
- calcularMontoRecaudado()
```

## 📤 Ejemplo de Salida Esperada
```text
Asientos disponibles: 25
¿Hay espacio?: Sí
Combustible actual: 70
Monto recaudado: 37.50
```

---

## ✅ Criterios de Validación
- No se permite **combustible > 100**.
- No se permite **combustible < 0**, **asientos <= 0**, **tarifa < 0**.
- No se permite **pasajeros + nuevosPasajeros > asientos**.
- Todos los métodos deben preservar las invariantes de la clase.

---

## 🧠 Sugerencias de Diseño POO
- Mantén los atributos como `private` y expón sólo lo necesario mediante métodos.
- Separa **consultas** (no modifican estado) de **comandos** (modifican estado).
- Usa **const** en métodos de consulta (si implementas en C++).
- Define constantes para límites (p. ej., `MAX_COMBUSTIBLE = 100`).

---

## 🧪 Pruebas sugeridas
- Intentar recoger más pasajeros de los asientos disponibles (debe fallar/validar).
- Intentar recargar combustible por encima del máximo (debe fallar/validar).
- Verificar `hayEspacio()` y `estaVacio()` en estados distintos.
- Validar que `calcularMontoRecaudado()` coincide con `pasajeros * tarifa`.

