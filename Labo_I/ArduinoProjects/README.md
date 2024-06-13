# Secret Code

_El código fue escrito para Arduino Uno_

El juego consiste en adivinar un patrón de colores elegidos aleatoriamente por la máquina al iniciar el juego.

El usuario o jugador ingresará a continuación 4 colores. Girando la perilla podrá elegir el color deseado que visualizará en el led y su nombre en la pantalla. 

Con el botón del centro podrá ir a la siguiente posición para colocar el siguiente color hasta completar los cuatro. Si se desea volver atrás para cambiar algún color, el jugador deberá usar el botón de la izquierda. 

Una vez completados los 4 colores, con el botón de la derecha podrá confirmar su selección. A continuación el programa mostrará en el display el resultado:

- Si el color está en posición correcta, el display mostrará `O`.
- Si el color es correcto, pero la posición no, mostrará `X`.
- Si el color no está dentro de la secuencia de colores creada por la máquina, mostrará: `-`.

Después de unos segundos, mostrará la cantidad de intentos restantes. El jugador deberá apretar el botón de continuar para ingresar una nueva combinación de colores.


## Estados
**ESTADO_INICIO**: la máquina elige el código aleatoriamente.

**ESTADO_SELECCION**: espera que el usuario ingrese los inputs (colores) y que confirme. Tiene un limite de 60 segundos o se va a considerar timeout y pasar a `ESTADO_DERROTA`

**ESTADO_CONFIRMACION**: verifica aciertos e imprime resultados. Verifica victoria.

**ESTADO_VICTORIA**: Muestra “Ganaste”. Borra pantalla. Suena Final Fantasy. El usuario debe presionar el botón de confirmación para volver a jugar.

**ESTADO_DERROTA**: Muestra “Perdiste”. Borra pantalla. Suena Marcha Imperial. El usuario debe presionar el botón de confirmación para volver a jugar. 

## Estructura de clases

Tenemos una serie de clases definidas por nosotros para poder gestionar las diferentes etapas del juego:

### RGBColor
Para representar los colores RGB del led, creamos esta clase que tiene como atributos los valores analógicos de RGB y además el nombre del color como string

### ColorFactory
Devuelve instancias de los colores deseados para que se manden fácilmente al led. También nos permite controlar los valores posibles para el código de la máquina y del jugador

### SecretCode
Clase principal que simula el juego. Se puede inicializar con colores aleatorios para la máquina y con los colores provistos por el usuario. Además de contener los códigos, tiene las funciones para comparar los resultados y decidir si se ganó o no.`SecretCode` llama a `verificar_aciertos` y `verificar_victoria` para ello.

Otras funciones útiles definidas en la clase son:

- `imprimir_resultado`: Muestra el valor de la comparación para cada color elegido por el usuario
- `printCode`: Muestra por el serial monitor el valor aleatorio del código de la máquina. Para debug
- `showCode`: Muestra en la pantalla el código de la máquina para que el usuario lo vea al ganar o perder

### Funciones

Hay además otras funciones que sirven para manejar diferentes partes del programa

`setEstado`: Setea el estado actual al estado provisto

`setColor`: Envia la señal correspondiente al led y setea el color elegido en el lugar correspondiente de la lista del usuario (segun el `selectorIndex`)

`renderColor`: Decide el color a setear según el valor del potenciómetro

`blinkScreen`: Marca titilando la posición del cursor en el momento 

`calculateCursor`: Debido a que la pantalla la dividimos en cuatro cuadrantes y el LCD es 2x16, definimos 4 índices para setear el cursor. Esta función lee el valor de `selectorIndex` y pone el cursor en el lugar correspondiente

`resetCursor`: Resetea el cursor,`selectorIndex`, y la selección del color a 0

`normalizeString`: Completa el valor del string provisto hasta lograr 8 caracteres

`renderSelection`: Muestra en pantalla el color elegido habiendo normalizado su largo

`funeralMarch`: Contiene la secuencia para la música al perder

`finalFantasy`: Contiene la secuencia para la música al ganar

