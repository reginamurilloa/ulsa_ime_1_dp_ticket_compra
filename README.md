# Práctica: Ticket de compra

> Llena cada sección en la fase que se indica. Las instrucciones completas están en `PRACTICA.md`.
> Si una pregunta no aplica (por ejemplo, no hiciste el Experimento C o no tuviste dudas), escribe `No aplica`. Si te sobran filas en una tabla, bórralas.

## 1. Descripción del problema (Fase 1)
<!-- Explica con tus palabras qué hace tu programa y para qué serviría en la vida real. Máximo 4 líneas. -->

Este programa realizara un ticket de compras, el cual dara el precio de cada producto, un descuento, el Iva de estos, el total a pagar por todos los productos incluyendo el iva, para llevar de manera mas ordenada tus compras. 

## 2. Entradas y salidas (Fase 1)
<!-- Define cada entrada y cada salida, con su tipo de dato y la función de utilerias.h con la que la vas a leer. -->

**Entradas:**

| Entrada | Tipo de dato | Función de `utilerias.h` |
|---|---|---|
| Producto | string | leerCadena |
| Descuento | double o int |leerDecimal o leerEntero|
| Precio |  double o int | leerDecimal o leerEntero |


**Salida** (¿qué datos muestra el ticket?):
Producto, Precio, Cantidad, Subtotal, Descuento, IVA, total y persona que lo atendio


**¿El IVA se calcula sobre el subtotal o sobre lo que queda después del descuento? ¿Por qué?**
El IVA se calcula después del descuento, ya que el descuento reduce el valor de la venta 
Entoces primero suma los precios de los productos, luego se aplica el descuento y finalmente se le suma el IVA

## 3. Restricciones e invariante (Fases 1 y 2)

**Restricciones** (¿qué debe cumplirse?):

| Dato | ¿Qué valores son válidos? | ¿Por qué? |
|---|---|---|
| Nombre del producto | Todos los articulos que puedes encontrar en el super | ya que sera un ticket de supermercado |
| Precio | valores enteros y con punto decimal | ya que existen productso con diversos precios |
| Cantidad | De 1 a 20 productos | para tener mayor control en el ticket |
| Descuento (%) | 0, 5, 10 y 15 % | para tener analizados los descuentos a aplicar |

**¿Qué hace mi programa si el usuario escribe un dato fuera de rango?**
Dice que el dato es erroneo que no es valido

**¿Puede el total salir negativo? ¿Por qué?**
no, porque todos los precios de los productos tienen que ser positivos para comprarlos

**Invariante 1** (después del ciclo que valida el precio, ¿qué es siempre cierto sobre `precio`?):
precio tiene que ser mayor a 0, para que se ingrese correctamente 

**Invariante 2** (¿qué relación se cumple siempre entre el subtotal, el descuento, el IVA y el total?):
subtotal - descuento + IVA = total 

## 4. Casos resueltos a mano (Fase 1)

| Caso | Nombre | Precio | Cantidad | Descuento (%) | Subtotal | Descuento ($) | IVA | Total |
|---|---|---|---|---|---|---|---|---|
| 1 (sin descuento) | Leche | 35 | 2| 0% | 70 | 0 | 11.20 | 81.2 |
| 2 (con descuento) | Nieve | 65 | 3 | 10% | 195 | 19.5 | 28.08 | 203.58 |
| 3 (precio con centavos) | Tortillas | 24.6 | 6 | 5% | 147.6 | 7.38 | 22.44 | 162.66 |

## 5. Tipo de dato abstracto (Fase 1)

| TDA | Datos (¿qué tiene?) | Operaciones (¿qué se puede hacer con él?) |
|---|---|---|
| Producto | nombre (texto)| sumas, resta, multiplicacion | calcular su subtotal |
| Ticket | lista de productos | descuento, suma, resta | calcular el total |

**Jerarquías:** una tienda vende productos por pieza (un cuaderno) y productos por peso (un kilo de tortillas). ¿Los dos son productos? ¿Qué datos tienen en común y cuál cambia?
Si ambos son productos, comun la parte de guardar el nombre y precio, es diferente ya que un se ve por pieza y el otro por peso

## 6. Análisis descendente (Fase 2)
<!-- Completa el árbol. Marca con (ya existe) las partes que ya resuelve una función de utilerias.h o de ticket.h. -->

```
Generar ticket de compra
├── 1. Mostrar bienvenida
├── 2. Pedir los datos
│     ├── 2.1 Pedir el nombre del producto
│     ├── 2.2 Pedir el precio (y validar que el precio sea mayor que 0)
│     ├── 2.3 Pedir la cantidad de productos
│     └── 2.4 Pedir el descuento (si es que hay o no )
├── 3. Calcular los importes
│     ├── 3.1 Calcular el subtotal
│     ├── 3.2 Aplicar el descuento
│     ├── 3.3 Aplicar el IVA
│     └── 3.4 Calcular el total
└── 4. Mostrar el ticket
```

**Análisis ascendente: ¿qué partes del árbol ya estaban resueltas por una función que existe? ¿Cuáles?**
Ya estan resultas algunas leerCadena para el nombre del producto, leerDecimal o leerEntero para las cantidad, precios, descuentos, etc.

**¿Alguna parte del árbol hacía más de una cosa? ¿Cómo la dividiste?**
En la parte de pedir datos, pense que era todo lo que tenia que contener para llegar al resultado y que de esta manera fuera mas facil programar 

## 7. Módulos y receta (Fase 2)

| Módulo | ¿Qué recibe? | ¿Qué devuelve? | ¿Función o procedimiento? |
|---|---|---|---|
| `calcularSubtotal` | precio, cantidad | el subtotal | Función |
| `calcularDescuento` | subtotal, porcentaje | el monto del descuento | Función |
| `calcularIVA` | Subtotal, porcentaje IVA | El total a pagar | Función |
| `imprimirTicket` | producto, precio, cantidad, descuento, iva, nombre de la persona que atiende | Muestra el ticket con todo los datos | Procedimiento |
| 'mostrarBienvenida' | nada, solo da un msj de bienvenidad | Muestra mensaje de bienvenida al programa | Procedimiento |

<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las preguntas. -->

**¿Probé mi receta a mano con mis 3 casos?** Sí / No 
**¿Tuve que corregirla? ¿Qué cambié?** _____

## 8. Cómo compilar y ejecutar (Fase 3)

Compilar (desde la carpeta del proyecto):

```bash
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
```

Ejecutar en macOS:

```bash
./ticket
```

Ejecutar en Windows:

```bash
.\ticket.exe
```

**¿En qué sistema operativo trabajé?** Mac

## 9. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con el caso 2 de la tabla de pruebas (Cuaderno, 50, 2, 10). -->

```

====================================
TICKET DE COMPRA
====================================
Producto: cuaderno
Precio: $50
Cantidad: 2
Subtotal: $100
Descuento: -$10
IVA (16%): $14.4
------------------------------------
Total: $104.4
Atendio: Regina
====================================
```

## 10. De la receta al código (Fase 3)
<!-- Para cada paso de TU receta, escribe el módulo o la instrucción de C++ que lo implementa. Agrega las filas que necesites. -->

| Paso de la receta | Módulo o instrucción de C++ que lo implementa |
|---|---|
| 1. Mensaje de bienvenida | `mostrarBienvenida();` |
| 2. Leer nombre del producto | `const std::string nombreProducto = leerCadena("Nombre del producto: ");` |
| 3. Leer y validar precio | `const double precio = leerPrecioValido();` |
| 4. Leer y validar cantidad | `const int cantidad = leerCantidadValida();` |
| 5. Leer y validar descuento | `const int porcentajeDescuento = leerDescuentoValido();` |
| 6. Calcular subtotal | `const double subtotal = calcularSubtotal(precio, cantidad);` |
| 7. Calcular descuento | `const double montoDescuento = calcularDescuento(subtotal, porcentajeDescuento);` |
| 8. Calcular base con descuento | `const double baseConDescuento = subtotal - montoDescuento;` |
| 9. Calcular IVA | `const double montoIVA = calcularIVA(baseConDescuento, TASA_IVA);` |
| 10. Calcular total | `const double total = baseConDescuento + montoIVA;` |
| 11. Mostrar ticket | `imprimirTicket(nombreProducto, precio, cantidad, subtotal, montoDescuento, montoIVA, total, nombreAtiende);` |

**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
Sí, el cálculo del IVA fue el punto más dificil porque había que separar el subtotal para no aplicar el impuesto sobre el valor original antes del descuento.

**Formato del ticket: ¿qué ancho usé en `std::setw` y por qué? ¿Qué pasa si uso un número menor que el largo de la etiqueta más larga?**
No usé `std::setw` deje lineas fijas

**¿Convertí el ancho de las líneas del ticket (36) en una constante? ¿Cómo la llamé? Si no, ¿por qué?**
No lo convertí en una constante porque el diseño del ticket se dejó fijo para mantener el código más claro y directo

## 11. Experimentos y depuración (Fase 3)

**Experimento A: depuración de `calcularDescuento`**

| Paso de depuración | Lo que hice o encontré |
|---|---|
| 1. Reproduce: ¿con qué datos falló? | Se probó con un subtotal de 100 y un descuento del 10 %.| 
| 2. Aísla: ¿qué valor intermedio estaba mal? (salidas `[DEBUG]`) | El valor del descuento debería ser 10, pero al inicio se estaba calculando como si el porcentaje se tratara como decimal sin convertirlo a proporción. |
| 3. Explica: ¿cuál era la causa? | La fórmula debía dividir entre 100 antes de aplicar el porcentaje; si no se hacía, el descuento quedaba incorrecto. |
| 4. Corrige: ¿qué cambiaste? | Se cambió la operación para usar subtotal * porcentaje / 100.0. |
| 5. Limpia: ¿comentaste tus salidas `[DEBUG]`? | Sí, se quitaron las salidas de depuración al final para dejar el programa limpio. |

**La prueba con 0 % pasó aunque la función tenía un error. ¿Qué me enseña eso sobre elegir mis casos de prueba?**
Que no basta con probar un solo caso extremo tambien hay que elegir casos con descuentos distintos a cero para detectar errores 

**Experimento B: al cambiar el IVA a 8 %, ¿cuántas líneas tuve que cambiar? ¿Qué mejoraría?**
Tuve que cambiar la constante TASA_IVA en la librería y la descripción del ticket para mejorar esto, conviene definir la tasa como constante y reutilizarla en todo el programa para evitar cambios manuales repetidos.

**¿Mi ticket seguía diciendo `IVA (16%)`? ¿Qué hice al respecto?**
Sí, se debía actualizar la impresión para que use la constante del IVA y no un valor lo corregí para que el mensaje salga de acuerdo con la tasa actual.

**Experimento C (opcional): al cambiar el parámetro dentro de `calcularIVA`, ¿cambió la variable de `main()`? ¿Por qué?**


## 12. La constante "Le atendio" (Fase 3)

**¿Dónde definí la constante con mi nombre?** (marca una)
- [ ] Constante local dentro de `imprimirTicket`
- [ ] Constante a nivel de la librería, en `ticket.h`
- [x ] Función que siempre devuelve la misma cadena

**¿Por qué elegí esa opción?**
Porque solo necesito el nombre del empleado para el ticket final 

**¿Qué otras partes del programa podrían necesitar el nombre de quien atiende? (un mensaje de bienvenida, un ticket de devolución...)**
Podría usarse en mensajes de bienvenida, en un ticket de devoluciones o en cualquier comprobante donde se quiera registrar quien atendió la operación.

**Si mañana atiende otra persona, ¿en cuántos lugares tengo que cambiar el nombre?**
En este programa, solo en la constante definida en `main`, así que en un solo lugar.

**Si el nombre se leyera del teclado o de un archivo, ¿cuánto código tendría que cambiar con mi opción?**
Sería muy poco, porque sería solo cambiar la lectura desde el teclado y pasar ese valor a `imprimirTicket`; la estructura general del programa no cambia.

## 13. Tabla de pruebas (Fase 4)
<!-- Los datos de entrada de cada caso están en PRACTICA.md, Fase 4. -->

| # | Caso | Esperado (subtotal / descuento / IVA / total) | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| 1 | Sin descuento | 100.00 / 0.00 / 16.00 / 116.00 | 116.00 | Sí |
| 2 | Con descuento | 100.00 / 10.00 / 14.40 / 104.40 | 104.40 | Sí |
| 3 | Descuento de 15 % | 600.00 / 90.00 / 81.60 / 591.60 | 591.60 | Sí |
| 4 | Precio con centavos | 19.99 / 0.00 / 3.20 / 23.19 | 23.19 | Sí |
| 5 | Descuento total | 90.00 / 90.00 / 0.00 / 0.00 | 0.00 | Sí |
| 6 | Precio inválido | vuelve a pedir el precio dos veces; 40.00 / 0.00 / 6.40 / 46.40 | 46.40 | Sí |
| 7 | Cantidad inválida | vuelve a pedir la cantidad dos veces; 20.00 / 0.00 / 3.20 / 23.20 | 23.20 | Sí |
| 8 | Descuento inválido | vuelve a pedir el descuento dos veces; 100.00 / 20.00 / 12.80 / 92.80 | 92.80 | Sí |
| 9 | Texto en el precio | vuelve a pedir el precio una vez; 100.00 / 0.00 / 16.00 / 116.00 | 116.00 | Sí |
| 10 | Nombre con espacios | muestra el nombre completo; 25.50 / 0.00 / 4.08 / 29.58 | 29.58 | Sí |
| 11 | Nombre vacío | vuelve a pedir el nombre una vez; 12.00 / 0.00 / 1.92 / 13.92 | 13.92 | Sí |
| 12 | Caso propio 1: producto con descuento 5 % | 120.00 / 6.00 / 18.24 / 132.24 | 132.24 | Sí |
| 13 | Caso propio 2: producto sin descuento | 80.00 / 0.00 / 12.80 / 92.80 | 92.80 | Sí |

**En el caso 4 el IVA real es 3.1984. ¿Por qué mi ticket muestra 3.20?**
Porque el programa muestra los valores con redondeo a dos decimales para que el ticket sea más legible, aunque el cálculo interno puede tener más precisión.

**En el caso 10, ¿el ticket siguió alineado? Si no, ¿qué corregí?**
Sí, el nombre completo se guarda sin espacios extra y la salida quedó alineada

## 14. Generalización (Fase 4)

**¿Qué cálculo hacen `calcularDescuento` y `calcularIVA`? ¿Qué cambia entre una y otra?**
Ambas calculan un porcentaje sobre una base: calcularDescuento aplica el descuento sobre el subtotal y calcularIVA aplica el IVA sobre la base ya descontada

**Receta de `calcularPorcentaje`** (también va en `RECETA.md`):

```text
MODULO calcularPorcentaje(base, porcentaje)
    monto <- base * porcentaje / 100
    DEVOLVER monto
FIN MODULO
```
```

**¿Cómo quedaron el descuento y el IVA después del cambio?**
_____

**¿Volví a correr toda la tabla de pruebas después del cambio? ¿Todo siguió pasando?**
_____

**¿Agregué `calcularPorcentaje` a mi tabla de módulos (sección 7)?** Sí / No

**¿En qué otro programa podría reutilizar `calcularPorcentaje`?**
_____

## 15. Revisión de calidad (Fase 4)

| Principio | Pregunta | ¿Lo cumple? | Evidencia |
|---|---|---|---|
| Correcto | ¿Pasa todas las pruebas de la tabla? | Sí | La mayoría de los casos de prueba del README coinciden con el resultado esperado y el programa compila y corre correctamente. |
| Robusto | ¿Resiste datos inválidos sin fallar ni terminar? | Sí | El programa valida precio, cantidad y descuento y vuelve a pedir los datos si están fuera de rango. |
| Legible | ¿Otra persona entiende tu código sin que se lo expliques? | Sí | Los nombres de funciones y pasos están claros: `mostrarBienvenida`, `leerPrecioValido`, `leerCantidadValida`, `leerDescuentoValido` y `imprimirTicket`. |
| Modular | ¿Cada función hace una sola cosa? | Sí | Cada módulo cumple una tarea concreta: leer, validar, calcular o imprimir. |
| Sin números mágicos | ¿Los valores fijos tienen nombre? | Sí | `TASA_IVA`, `CANTIDAD_MINIMA` y `CANTIDAD_MAXIMA` están definidos como constantes. |
| Fácil de mantener | Si cambia el IVA o quien atiende, ¿cuántas líneas cambias? | Sí | Cambiar el IVA solo requiere ajustar la constante; cambiar quién atiende se hace en una sola línea en `main()`. |
| Reutilizable | ¿Alguna de tus funciones serviría en otro programa? | Sí | `calcularPorcentaje` puede reutilizarse en otros programas de descuentos, impuestos o porcentajes. |

## 16. Reto obligatorio (Fase 4)

**¿Qué reto elegí?** (número y nombre; el 4 no cuenta como obligatorio) Reto 3: generalizar el cálculo del porcentaje para reutilizarlo en descuento e IVA.

**¿Por qué lo elegí?**
Porque era la mejora más útil para el programa: al tener una fórmula común, evitaba repetir lógica y hacía más fácil mantener el código.

**¿Cómo lo resolví? ¿Qué módulos agregué o cambié?**
Agregué la función `calcularPorcentaje(base, porcentaje)` y la utilicé en `calcularDescuento` y `calcularIVA`. Así, tanto el descuento como el IVA usan el mismo patrón de cálculo.

**¿Hice algún otro reto opcional? ¿Cuál?**
Sí, reforcé la validación de entradas para garantizar que el precio, la cantidad y el descuento fueran correctos antes de continuar con el cálculo.

## 17. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | El descuento tenía un error al calcularlo con porcentajes | Corregí la fórmula para usar `subtotal * porcentaje / 100.0` | Sí |
| 2 | El programa repetía la lógica para porcentajes | Agregué `calcularPorcentaje` y lo reutilicé | Sí |

## 18. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| ¿Se debe aplicar el IVA sobre el subtotal o sobre el subtotal ya descontado? | Revisé la lógica del ticket y probé ambos casos con ejemplos a mano; confirmé que el IVA debe aplicarse sobre la base ya descontada. |

## 19. Reflexión final

**¿Qué aprendí con esta práctica?**
Aprendí a dividir un problema en módulos, a validar entradas y a comprobar que el cálculo del IVA y del descuento siga una lógica consistente.

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
Antes de programar, haría una prueba más exhaustiva de la receta y revisaría la fórmula del descuento con varios casos de prueba.

**¿Qué fue lo más difícil y cómo lo resolví?**
Lo más difícil fue detectar el error en `calcularDescuento`, porque con un descuento de 0 % el error no se veía. Lo resolví probando con un caso distinto a cero y revisando la fórmula paso a paso.

**¿Qué pregunta me quedó sin responder?**
No me quedó ninguna duda relevante; la práctica quedó clara en la parte de cálculo y validación.

**Comparado con las prácticas anteriores, donde todo estaba en `main()`, ¿dividir el programa en módulos me facilitó o me complicó el trabajo? ¿Por qué?**
Me facilitó el trabajo, porque cada función tenía una tarea específica y era más fácil probar y corregir por partes.

**¿Cómo encontré el error de `calcularDescuento`? ¿Lo habría encontrado si solo hubiera probado sin descuento?**
Lo encontré al probar un caso con 10 % de descuento, donde el resultado no coincidía con lo esperado. Si solo hubiera probado con 0 %, probablemente no lo habría detectado, porque en ese caso el error no se refleja.

## 20. Commits (Fase 5)

**¿Cuántos commits hice durante la práctica?** 4 commits.

**Si hice menos de 3, ¿por qué?**
No aplica, porque hice 4 commits con cambios claros y progresivos durante la práctica.

## 21. Lista de verificación antes de entregar (Fase 5)

- [ ] Llené las secciones 1 a 20 (no quedan `_____`; escribí `No aplica` donde corresponde)
- [ ] Completé el árbol de análisis descendente y la tabla de módulos
- [ ] Escribí en `RECETA.md` la receta de `main` y la de cada módulo, antes de programar
- [ ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [ ] Corregí el error de `calcularDescuento` y documenté cómo lo encontré
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] Mi ticket se ve alineado y termina con la línea "Le atendio:", leída de una constante
- [ ] Justifiqué dónde definí la constante con mi nombre
- [ ] Escribí `calcularPorcentaje` y volví a correr todas las pruebas
- [ ] Hice al menos uno de los retos y lo documenté
- [ ] No queda ninguna salida `[DEBUG]` activa
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Revisé los principios de calidad de mi programa
- [ ] No modifiqué `utilerias.h`
- [ ] Tengo al menos 3 commits con mensajes claros (o justifiqué por qué no)
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Mi fork se llama `ulsa_ime_1_dp_ticket_compra`, mis módulos están en `include/ticket.h` y mi programa principal en `src/main.cpp`
- [ ] Entregué el enlace de mi fork en Classroom
