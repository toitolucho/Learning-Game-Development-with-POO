# 🚌 AutoBus v2: Paradas, Ciclos y Consumo de Combustible por Persona

Esta es una versión extendida del ejercicio del **AutoBus**. Además de los atributos y operaciones de la versión original, ahora el sistema modela **paradas** (estaciones), **ciclos de ruta**, **monto recaudado acumulado** y **consumo de combustible** por persona y por parada.

El objetivo es reforzar conceptos de **POO**: encapsulamiento, invariantes, constructores, métodos con retorno/sin retorno y validaciones en secuencias de operaciones.

---

## 🎯 Objetivos de Aprendizaje
- Diseñar una clase con **estado ampliado** y reglas de negocio más ricas.
- Implementar **constructores apropiados** que oculten (encapsulen) propiedades críticas.
- Distinguir **métodos booleanos (consultas)**, **métodos con retorno** y **métodos `void`** con efectos (mostrar o calcular y aplicar cambios).
- Gestionar **ciclos de paradas** y **reinicio** del recorrido.

---

## 🧩 Atributos (además de la v1)
- `montoRecaudado` (double): se incrementa por cada persona que ingresa al bus, según la `tarifa` vigente.
- `numberOfStopStation` (int): cantidad total de paradas del recorrido (≥ 1).
- `currentStop` (int): índice de la parada actual (por ejemplo, 1..numberOfStopStation).
- `consumoCombustiblePorPersonaPorParada` (double, constante): consumo de combustible fijo por cada persona y por cada parada recorrida.

Atributos heredados/conocidos de v1:
- `combustible` (double): cantidad de combustible actual, con límite máximo (p. ej., 100).
- `asientos` (int), `tarifa` (double), `pasajeros` (int).

---

## ⚙️ Reglas y Comportamiento
1. **Inicio del recorrido**: el bus parte en la **parada 1** con **cero pasajeros**.
2. **Última parada**: en la **última parada** (=`numberOfStopStation`), **todos los pasajeros deben bajar** del bus.
3. **Ciclo**: al llegar a la última parada, el recorrido **se reinicia** y el bus vuelve a la parada 1 (si aún hay combustible).
4. **Movimiento condicionado por combustible**: sólo se puede avanzar a la siguiente parada si hay **combustible suficiente**.
5. **Consumo de combustible por persona**: avanzar de una parada a la siguiente consume combustible según:
   \[ consumo = consumoCombustiblePorPersonaPorParada \times pasajerosActuales \]
   (Esta constante es **fija para todo el recorrido**.)
6. **nexStop()**: en cada parada, antes de avanzar, se consulta cuántos pasajeros **suben** y cuántos **bajan**. Debe validar:
   - Al inicio (parada 1 del primer ciclo) el bus está vacío, por lo que **nadie puede bajar**.
   - En la **última parada**, **todos deben bajar** (pasajeros → 0).
   - En cualquier parada, **no pueden bajar más personas** de las que hay a bordo;
     y **no pueden subir más** de los asientos disponibles.
   - **montoRecaudado** aumenta por cada persona que sube: `montoRecaudado += suben * tarifa`.
7. **Invariantes**: nunca valores negativos; `pasajeros <= asientos`; `0 <= combustible <= MAX`.

---

## 🛠️ Operaciones Requeridas (v2)

- `nexStop()` (void):
  - Pregunta/recibe cuántos pasajeros **suben** y cuántos **bajan** en la parada actual.
  - Aplica validaciones e **incrementa `montoRecaudado`** por los que suben.
  - Verifica si hay **combustible suficiente** para llegar a la próxima parada según la regla de consumo por persona.
  - Si hay combustible suficiente, avanza a la **siguiente parada** y descuenta el combustible.
  - Si se está en la **última parada**, fuerza la **bajada de todos** y **reinicia** `currentStop` a 1 (si continúa el recorrido) o se detiene si no hay combustible.

- Consultas (booleanas y con retorno):
  - `hayEspacio() -> bool`
  - `estaVacio() -> bool`
  - `getCurrentStop() -> int`
  - `getNumberOfStopStation() -> int`
  - `getMontoRecaudado() -> double`
  - `getCombustible() -> double`
  - `calcularAsientosDisponibles() -> int`
  - `puedeAvanzarSiguienteParada() -> bool` (en función de `pasajeros` y combustible requerido)

- Comandos (`void`, con efecto):
  - `recargarGasolina(cantidad)` (respetando el máximo permitido)
  - `recogerPasajeros(n)` (validando asientos disponibles; no se usa en última parada)
  - `bajarPasajeros(n)` (validando no exceder `pasajeros`)

---

## 🧱 Constructores (encapsulando propiedades críticas)
Se solicita crear constructores que **oculten/encapsulen** propiedades importantes, forzando estados válidos:

- `AutoBusV2(int numberOfStopStation, double tarifa, int asientos, double consumoPorPersonaParada)`
  - Inicializa: `currentStop = 1`, `pasajeros = 0`, `montoRecaudado = 0`.
  - Valida: `numberOfStopStation >= 1`, `asientos > 0`, `tarifa >= 0`, `consumoPorPersonaParada >= 0`.
  - `combustible` inicia en 0 (o parametrizable con segundo constructor) y siempre `<= MAX`.

- (Opcional) `AutoBusV2(double combustibleInicial, int numberOfStopStation, double tarifa, int asientos, double consumoPorPersonaParada)`
  - Valida todo lo anterior + límite de combustible.

> La constante `MAX_COMBUSTIBLE` se debe definir en la clase. `consumoCombustiblePorPersonaPorParada` es inmutable tras construcción.

---

## 📥 Ejemplo de Flujo (conceptual)
```text
Paradas totales: 3
Tarifa: 2.00
Asientos: 10
Combustible inicial: 50
Consumo por persona/parada: 0.2

Inicio: currentStop=1, pasajeros=0, recaudado=0, combustible=50

Parada 1: suben 4, bajan 0 -> recaudado=8.0, pasajeros=4
¿Puede avanzar? consumo=4 * 0.2 = 0.8 -> sí; combustible=49.2; currentStop=2

Parada 2: suben 3, bajan 1 -> recaudado=14.0, pasajeros=6
¿Puede avanzar? consumo=6 * 0.2 = 1.2 -> sí; combustible=48.0; currentStop=3

Parada 3 (última): todos bajan -> pasajeros=0
Ciclo completo -> currentStop=1 (reinicio), combustible=48.0
```

---

## 📤 Salidas Esperadas (ejemplos)
- Mensajes/estados después de cada `nexStop()`:
  - Parada actual, pasajeros suben/bajan, asientos disponibles
  - Monto recaudado acumulado
  - Combustible restante y si puede avanzar o no
  - Reinicio de ciclo al finalizar última parada

---

## ✅ Criterios de Validación
- No permitir bajar pasajeros si el bus está vacío (especialmente al inicio del recorrido).
- En la **última parada**, todos los pasajeros deben bajar (no pueden quedar a bordo).
- Verificar **combustible suficiente** antes de avanzar.
- Mantener invariantes: `0 <= combustible <= MAX`, `0 <= pasajeros <= asientos`.
- El **monto recaudado** debe coincidir con la suma de entradas de pasajeros multiplicadas por tarifa.

---

## 🧠 Sugerencias POO
- Mantén propiedades críticas como `private` y usa `const` en consultas (en C++).
- Expón constructores que **prevengan estados inválidos** desde el origen.
- Separa **consultas** (boolean/retornos) de **comandos** (`void`).
- Considera lanzar **excepciones** ante violaciones de reglas (p. ej., gasolina insuficiente si decides forzar avance, o invalidación de operación si decides bloquear avance).

---

## 🧪 Pruebas sugeridas
- Intentar bajar pasajeros en el inicio del recorrido (debe fallar/validar).
- En la última parada, verificar que el sistema fuerce bajar a todos.
- Verificar que `nexStop()` no permita avanzar sin combustible suficiente.
- Simular varios ciclos y corroborar reinicio correcto de `currentStop` y preservación de invariantes.
- Validar que `montoRecaudado` acumula correctamente tras múltiples paradas.

