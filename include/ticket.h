
#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include "utilerias.h"
#include "utilerias.h"

const double TASA_IVA = 16.0;
const int CANTIDAD_MINIMA = 1;
const int CANTIDAD_MAXIMA = 20;
const int ANCHO_LINEA = 36;


void mostrarBienvenida() {
    std::cout << "Bienvenido al programa de ticket de compra\n";
}

double leerPrecioValido() {
    double precio = 0.0;
    do {
        precio = leerDecimal("Precio del producto: $");
        if (precio <= 0.0) {
            std::cout << "El precio debe ser mayor que cero.\n";
        }
    } while (precio <= 0.0);
    return precio;
}

int leerCantidadValida() {
    int cantidad = 0;
    do {
        cantidad = leerEntero("Cantidad (1 a 20): ");
        if (cantidad < CANTIDAD_MINIMA || cantidad > CANTIDAD_MAXIMA) {
            std::cout << "La cantidad debe estar entre 1 y 20.\n";
        }
    } while (cantidad < CANTIDAD_MINIMA || cantidad > CANTIDAD_MAXIMA);
    return cantidad;
}

int leerDescuentoValido() {
    int porcentaje = -1;
    do {
        porcentaje = leerEntero("Descuento (0, 5, 10 o 15 %): ");
        if (porcentaje != 0 && porcentaje != 5 &&
            porcentaje != 10 && porcentaje != 15) {
            std::cout << "El descuento debe ser 0, 5, 10 o 15 %.\n";
        }
    } while (porcentaje != 0 && porcentaje != 5 &&
             porcentaje != 10 && porcentaje != 15);
    return porcentaje;
}

double calcularSubtotal(double precio, int cantidad) {
    return precio * cantidad;
}

double calcularDescuento(double subtotal, double porcentaje) {
    return subtotal * porcentaje / 100.0;
}

double calcularIVA(double baseConDescuento, double tasaIVA) {
    return baseConDescuento * tasaIVA / 100.0;
}

void imprimirTicket(const std::string& nombreProducto,
                           double precio,
                           int cantidad,
                           double subtotal,
                           double montoDescuento,
                           double montoIVA,
                           double total,
                           const std::string& nombreAtiende) {
    std::cout << '\n' << std::string(ANCHO_LINEA, '=') << '\n';
    std::cout << "TICKET DE COMPRA\n";
    std::cout << std::string(ANCHO_LINEA, '=') << '\n';
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left << std::setw(20) << "Producto:" << nombreProducto << '\n';
    std::cout << std::left << std::setw(20) << "Precio:" << "$" << precio << '\n';
    std::cout << std::left << std::setw(20) << "Cantidad:" << cantidad << '\n';
    std::cout << std::left << std::setw(20) << "Subtotal:" << "$" << subtotal << '\n';
    std::cout << std::left << std::setw(20) << "Descuento:" << "-$" << montoDescuento << '\n';
    std::cout << std::left << std::setw(20) << "IVA (16%):" << "$" << montoIVA << '\n';
    std::cout << std::string(ANCHO_LINEA, '-') << '\n';
    std::cout << std::left << std::setw(20) << "Total:" << "$" << total << '\n';
    std::cout << std::left << std::setw(20) << "Atendio:" << nombreAtiende << '\n';
    std::cout << std::string(ANCHO_LINEA, '=') << '\n';
}

