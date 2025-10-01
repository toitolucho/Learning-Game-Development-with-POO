// Solución en C++ para el examen de POO: Persona, Estudiante, Cuenta
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// --- Persona ---
class Persona {
protected:
    int ci;
    string codigoProcedencia;
    string nombres;
    string apellidos;
public:
    Persona()
    {
        ci = 0;
        codigoProcedencia = "";
        nombres = "";
        apellidos = "";
    }
    Persona(int _ci, string _codigo, string _nombres, string _apellidos)
    {
        ci = _ci;
        codigoProcedencia = _codigo;
        nombres = _nombres;
        apellidos = _apellidos;
    }   

    int getCi() { return ci; }
    void setCi(int _ci) { ci = _ci; }
    string getCodigoProcedencia() { return codigoProcedencia; }
    void setCodigoProcedencia(string _codigo) { codigoProcedencia = _codigo; }
    string getNombres() { return nombres; }
    void setNombres(string _nombres) { nombres = _nombres; }
    string getApellidos() { return apellidos; }
    void setApellidos(string _apellidos) { apellidos = _apellidos; }

    string ObtenerNombreCompleto() {
        return nombres + " " + apellidos;
    }
    void VerDatos() {
        cout<<"CI: "<<ci<<"\nNombre Completo: "<<ObtenerNombreCompleto()<<"\nProcedencia: "<<ObtenerProcedencia()<<endl;
    }
    string ObtenerProcedencia() {
        if (codigoProcedencia == "Pt") return "Potosí";
        if (codigoProcedencia == "Or") return "Oruro";
        if (codigoProcedencia == "Co") return "Cochabamba";
        if (codigoProcedencia == "Ta") return "Tarija";
        if (codigoProcedencia == "Ch") return "Chuquisaca";
        if (codigoProcedencia == "LP") return "La Paz";
        if (codigoProcedencia == "SC") return "Santa Cruz";
        if (codigoProcedencia == "Be") return "Beni";
        if (codigoProcedencia == "Pa") return "Pando";
        return "Desconocido";
    }
    string ObtenerRegion() {
        string dep = ObtenerProcedencia();
        if (dep == "Potosí" || dep == "Oruro" || dep == "La Paz") return "Altiplano";
        if (dep == "Cochabamba" || dep == "Chuquisaca" || dep == "Tarija") return "Valles";
        if (dep == "Santa Cruz" || dep == "Beni" || dep == "Pando") return "Llanos";
        return "Desconocido";
    }
};

// --- Estudiante ---
class Estudiante : public Persona {
protected:
    string cu; // Carnet universitario
    string carrera;
public:
    Estudiante()
    {
        ci = 0;
        codigoProcedencia = "";
        nombres = "";
        apellidos = "";
        cu = "";
        carrera = "";
    }
    Estudiante(
        int _ci,
        string _codigo,
        string _nombres,
        string _apellidos,
        string _cu,
        string _carrera
    )
    {
        ci = _ci;
        codigoProcedencia = _codigo;
        nombres = _nombres;
        apellidos = _apellidos;
        cu = _cu;
        carrera = _carrera;
    }
    string getCu() { return cu; }
    void setCu(string _cu) { cu = _cu; }
    string getCarrera() { return carrera; }
    void setCarrera(string _carrera) { carrera = _carrera; }
    void VerDatos() {
        Persona::VerDatos();
        cout<<"CU: "<<cu<<"\nCarrera: "<<carrera<<endl;
    }
    bool EsCompaneroDe(const Estudiante& otro) {
        return carrera == otro.carrera;
    }
};

// --- Cuenta ---
class Cuenta {
private:
    int nroCuenta;
    double saldoActual;
    Estudiante propietario;
public:
    Cuenta() : nroCuenta(0), saldoActual(0.0), propietario() {}
    Cuenta(int _nro, double _saldo, Estudiante _prop) : nroCuenta(_nro), saldoActual(_saldo), propietario(_prop) {}
    int getNroCuenta() { return nroCuenta; }
    void setNroCuenta(int _nro) { nroCuenta = _nro; }
    double getSaldoActual() { return saldoActual; }
    void setSaldoActual(double _saldo) { saldoActual = _saldo; }
    Estudiante getPropietario() { return propietario; }
    void setPropietario(Estudiante _prop) { propietario = _prop; }
    void Depositar(double monto) {
        saldoActual += monto;
    }
    bool Retirar(double monto) {
        if (monto <= saldoActual) {
            saldoActual -= monto;
            return true;
        }
        return false;
    }
    bool Transferir(Cuenta &destino, double monto) {
        if (propietario.EsCompaneroDe(destino.propietario) && Retirar(monto)) {
            destino.Depositar(monto);
            cout<<fixed<<setprecision(2);
            cout<<"Se transfirió "<<monto<<" de la cuenta de: "<<propietario.ObtenerNombreCompleto()
                <<" a la cuenta de: "<<destino.propietario.ObtenerNombreCompleto()<<endl;
            return true;
        }
        return false;
    }
    bool TransferirPromocion(Cuenta &destino, double porcentajeIncremento, double monto) {
        if (propietario.ObtenerRegion() == destino.propietario.ObtenerRegion() && Retirar(monto)) {
            destino.Depositar(monto);
            // Incrementar ambos saldos por el porcentaje
            Depositar(saldoActual * porcentajeIncremento / 100.0);
            destino.Depositar(destino.saldoActual * porcentajeIncremento / 100.0);
            cout<<fixed<<setprecision(2);
            cout<<"Se transfirió (promoción) "<<monto<<" de la cuenta de: "<<propietario.ObtenerNombreCompleto()
                <<" a la cuenta de: "<<destino.propietario.ObtenerNombreCompleto()<<endl;
            return true;
        }
        return false;
    }
    void VerDatos() {
        cout<<"Nro Cuenta: "<<nroCuenta<<"\nSaldo Actual: "<<saldoActual<<endl;
        propietario.VerDatos();
    }
};

// --- Ejemplo de uso ---
int main() {
    Estudiante e1(123, "LP", "Juan", "Pérez", "2021001", "Sistemas");
    Estudiante e2(456, "LP", "Ana", "García", "2021002", "Sistemas");
