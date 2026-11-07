
#pragma once

#include <iostream>
#include <string>
#include "utilerias.h"

const double TASA_IVA = 16.0;
const int CANTIDAD_MINIMA = 1;
const int CANTIDAD_MAXIMA = 20;


void mostrarBienvenida() {
    std::cout << "Bienvenido al programa de ticket de compra\n";
}

double leerPrecioValido() {
    double precio = 0.0;
    while (precio <= 0.0) {
        precio = leerDecimal("Precio del producto: $");
        if (precio <= 0.0) {
            std::cout << "El precio debe ser mayor que cero.\n";
        }
    }
    return precio;
}

int leerCantidadValida() {
    int cantidad = 0;
    while (cantidad < CANTIDAD_MINIMA || cantidad > CANTIDAD_MAXIMA) {
        cantidad = leerEntero("Cantidad (1 a 20): ");
        if (cantidad < CANTIDAD_MINIMA || cantidad > CANTIDAD_MAXIMA) {
            std::cout << "La cantidad debe estar entre 1 y 20.\n";
        }
    }
    return cantidad;
}

int leerDescuentoValido() {
    const std::string mensaje = "Descuento (0, 5, 10 o 15 %): ";
    int porcentaje = leerEntero(mensaje);
    while (porcentaje < 0 || porcentaje > 15 || porcentaje % 5 != 0) {
        if (porcentaje < 0 || porcentaje > 15 || porcentaje % 5 != 0) {
            std::cout << "El descuento debe ser 0, 5, 10 o 15 %.\n";
        }
        porcentaje = leerEntero(mensaje);
    }
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
    std::cout << "\n====================================\n";
    std::cout << "TICKET DE COMPRA\n";
    std::cout << "====================================\n";
    std::cout << "Producto: " << nombreProducto << '\n';
    std::cout << "Precio: $" << precio << '\n';
    std::cout << "Cantidad: " << cantidad << '\n';
    std::cout << "Subtotal: $" << subtotal << '\n';
    std::cout << "Descuento: -$" << montoDescuento << '\n';
    std::cout << "IVA (16%): $" << montoIVA << '\n';
    std::cout << "------------------------------------\n";
    std::cout << "Total: $" << total << '\n';
    std::cout << "Atendio: " << nombreAtiende << '\n';
    std::cout << "====================================\n";
}

