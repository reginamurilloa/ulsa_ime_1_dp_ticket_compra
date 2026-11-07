// Práctica: Ticket de compra
// main() solo coordina: pide los datos, llama a los módulos y muestra el ticket.
// Deja el comentario "// Paso N" sobre cada bloque, con la numeración de TU receta.
//
// Compilar (desde la carpeta del proyecto):
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
// Ejecutar:
//   macOS:   ./ticket
//   Windows: .\ticket.exe

// ¿Recuerdas qué hace iostream?
#include <iostream>
#include <string>

#include "utilerias.h"
#include "ticket.h"

int main() {
    // Paso 1: mensaje de bienvenida
    mostrarBienvenida();

    // Paso 2: pedir y validar los datos
    const std::string nombreProducto = leerCadena("Nombre del producto: ");
    const double precio = leerPrecioValido();
    const int cantidad = leerCantidadValida();
    const int porcentajeDescuento = leerDescuentoValido();

    // Paso 3: calcular los importes
    const double subtotal = calcularSubtotal(precio, cantidad);
    const double montoDescuento = calcularDescuento(subtotal, porcentajeDescuento);
    const double baseConDescuento = subtotal - montoDescuento;
    const double montoIVA = calcularIVA(baseConDescuento, TASA_IVA);
    const double total = baseConDescuento + montoIVA;

    // Paso 4: imprimir el ticket
    const std::string nombreAtiende = "Caja 1";
    imprimirTicket(nombreProducto, precio, cantidad, subtotal,
                   montoDescuento, montoIVA, total, nombreAtiende);

    return 0;
}
