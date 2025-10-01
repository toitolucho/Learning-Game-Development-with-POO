# Cuentas Bancarias

Este proyecto define un sistema de clases en **Programación Orientada a Objetos (POO)** que permite modelar personas, estudiantes y cuentas bancarias, aplicando los conceptos de **herencia, composición y encapsulamiento**.  

---

## 📌 Clases a implementar  

### Clase `Persona`  
Representa a una persona con información básica.  

**Atributos:**  
- `Ci : entero` → Número de cédula de identidad.  
- `CodigoProcedencia : cadena` → Código de dos caracteres que representa el departamento de procedencia. Valores posibles:  
  - `Pt` → Potosí  
  - `Or` → Oruro  
  - `Co` → Cochabamba  
  - `Ta` → Tarija  
  - `Ch` → Chuquisaca  
  - `LP` → La Paz  
  - `SC` → Santa Cruz  
  - `Be` → Beni  
  - `Pa` → Pando  
- `Nombres : cadena` → Nombres de la persona.  
- `Apellidos : cadena` → Apellidos de la persona.  

**Métodos:**  
- `ObtenerNombreCompleto() : Cadena`  
  - Concatena los nombres y apellidos con un espacio y devuelve la cadena resultante.  
- `VerDatos()`  
  - Imprime todos los datos de la clase.  
- `ObtenerProcedencia() : Cadena`  
  - Determina el **departamento** al que corresponde a partir del código de procedencia.  

---

### Clase `Estudiante` (Hereda de `Persona`)  
Representa a un estudiante universitario.  

**Atributos adicionales:**  
- `Cu : cadena` → Carnet universitario.  
- `Carrera : cadena` → Carrera que estudia (ejemplo: Sistemas, Diseño, Telecomunicaciones, TI, Ciencias de la Computación).  

**Métodos adicionales:**  
- `VerDatos()`  
  - Sobrescribe el método de la clase padre e imprime además los datos específicos de estudiante.  
- `EsCompañeroDe(Estudiante) : bool`  
  - Retorna **true** si el estudiante actual y el recibido como parámetro pertenecen a la misma carrera.  

---

### Clase `Cuenta`  
Representa una cuenta bancaria asociada a una persona.  

**Atributos:**  
- `NroCuenta : entero` → Identificador único de la cuenta.  
- `SaldoActual : real` → Monto disponible en la cuenta.  
- `Propietario : Persona` → Persona dueña de la cuenta (puede ser estudiante o no).  

**Métodos:**  
- `Depositar(monto : real)`  
  - Incrementa el saldo actual en el monto indicado.  
- `Retirar(monto : real)`  
  - Realiza el retiro si existe saldo suficiente.  
- `Transferir(cuenta : Cuenta, monto : real)`  
  - Permite transferir dinero de una cuenta a otra **únicamente si ambos propietarios son estudiantes compañeros de carrera**.  
  - Debe imprimir un mensaje como el siguiente:  
    ```
    Se transfirió [monto] de la cuenta de [NombreCompletoOrigen] a la cuenta de [NombreCompletoDestino]
    ```  
- `TransferirPromocion(cuenta : Cuenta, monto : real, porcentajeIncremento : real)`  
  - Permite realizar una transferencia entre cuentas cuando los propietarios pertenezcan a la **misma región geográfica**:  
    - **Altiplano** → La Paz, Oruro, Potosí  
    - **Valles** → Cochabamba, Chuquisaca, Tarija  
    - **Llanos** → Santa Cruz, Beni, Pando  
  - Se transfiere el monto y además se **incrementa el saldo de ambas cuentas** en un porcentaje adicional (`porcentajeIncremento`) como promoción del banco.  

---

## 📝 Notas adicionales  
- La relación entre `Cuenta` y `Persona` es de **composición** (una cuenta siempre tiene un propietario).  
- La herencia se aplica en `Estudiante`, que extiende a `Persona`.  
- En las transferencias se deben usar los métodos
