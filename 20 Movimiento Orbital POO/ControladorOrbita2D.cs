using UnityEngine;

public class ControladorOrbita2D : MonoBehaviour
{
    [Header("Configuración Orbital")]
    public Transform objetivoCentral;
    public float velocidadRotacion = 50f;

    [Header("Configuración de Elipse")]
    public float factorElipseX = 2.0f;
    public float factorElipseY = 1.0f;

    // Variables privadas para el cálculo absoluto
    private float anguloActual = 0f;
    private float radioInicial = 0f;
    private float zOriginal = 0f;

    void Start()
    {
        if (objetivoCentral != null)
        {
            // 1. Calculamos el vector de distancia inicial
            Vector3 vectorRelativo = transform.position - objetivoCentral.position;

            // 2. Guardamos el radio (la distancia real inicial)
            radioInicial = new Vector2(vectorRelativo.x, vectorRelativo.y).magnitude;

            // 3. Calculamos en qué ángulo se encuentra el objeto al iniciar el juego
            // Mathf.Atan2 nos da el ángulo en radianes basado en X e Y
            anguloActual = Mathf.Atan2(vectorRelativo.y, vectorRelativo.x);

            // Guardamos la profundidad Z para no alterarla
            zOriginal = vectorRelativo.z;
        }
    }

    void Update()
    {
        Orbitar();
    }

    private void Orbitar()
    {
        if (objetivoCentral != null)
        {
            // PASO A: Incrementar el ángulo absoluto con el tiempo
            anguloActual += velocidadRotacion * Time.deltaTime * Mathf.Deg2Rad;

            // PASO B: Calcular la posición en un círculo perfecto usando el radio inicial fijo
            float x = radioInicial * Mathf.Cos(anguloActual);
            float y = radioInicial * Mathf.Sin(anguloActual);

            // PASO C: Aplicar la deformación de la elipse
            // Como x e y se calculan desde cero en cada fotograma basados en el radio fijo,
            x *= factorElipseX;
            y *= factorElipseY;

            Vector3 vectorRotado = new Vector3(x, y, zOriginal);

            // PASO D: Traslación Final
            transform.position = objetivoCentral.position + vectorRotado;
        }
    }
}