# Receta: Ticket de compra

<!-- Escribe aquí tus recetas en pseudocódigo, ANTES de programar.
     Primero la receta del programa principal (main) y después una receta corta para cada módulo que vas a escribir tú.
     El primer paso de main es solo un ejemplo del formato; el resto es tuyo.
     Si las corriges después de probarlas a mano, deja aquí la versión final. -->

## Receta del programa principal (`main`)

<!-- Debe leerse casi igual que tu árbol de análisis descendente (sección 6 del README). -->

```text
1. MOSTRAR "Bienvenido a mi programa"
2. Pedir los datos usando los módulos de lectura
   nombreProducto <- leerCadena("Nombre del producto: ")
   precio <- leerPrecioValido()
   cantidad <- leerCantidadValida()
   porcentajeDescuento <- leerDescuentoValido()
3. Calcular los importes
   subtotal <- calcularSubtotal(precio, cantidad)
   montoDescuento <- calcularDescuento(subtotal, porcentajeDescuento)
   montoIVA <- calcularIVA(baseConDescuento, TASA_IVA)
   total <- baseConDescuento + montoIVA
4. MOSTRAR imprimirTicket(nombreProducto, precio, cantidad, subtotal,
                         montoDescuento, montoIVA, total,
                         NOMBRE_ATIENDE)

```

## Recetas de los módulos

<!-- Para cada módulo: qué recibe, qué hace y qué devuelve. -->

### `calcularIVA`

```text
MODULO calcularIVA(baseConDescuento, tasaIVA)
     iva <- baseConDescuento * tasaIVA / 100
     DEVOLVER iva
FIN MODULO
```

### `imprimirTicket`

```text
MODULO imprimirTicket(nombreProducto, precio, cantidad, subtotal,
                           montoDescuento, montoIVA, total,
                           nombreDeQuienAtiende)
     MOSTRAR el nombre del producto, precio y cantidad
     MOSTRAR subtotal, monto del descuento y monto del IVA
     MOSTRAR total a pagar
     MOSTRAR el nombre de quien atendio
FIN MODULO
```

### `calcularPorcentaje` (Fase 4)

```text
MODULO calcularPorcentaje(base, porcentaje)
     monto <- base * porcentaje / 100
     DEVOLVER monto
FIN MODULO
```

### Otros módulos que agregues (por ejemplo, para tu reto)

MODULO mostrarBienvenida()
     MOSTRAR "Bienvenido al programa de ticket de compra"
FIN MODULO

MODULO leerPrecioValido()
     REPETIR
          precio <- leerDecimal("Precio: ")
          SI precio <= 0 ENTONCES
               MOSTRAR "El precio debe ser mayor que cero."
          FIN SI
     HASTA QUE precio > 0
     DEVOLVER precio
FIN MODULO

MODULO calcularSubtotal(precio, cantidad) (ya existe en ticket.h)
     subtotal <- precio * cantidad
     DEVOLVER subtotal
FIN MODULO
```
