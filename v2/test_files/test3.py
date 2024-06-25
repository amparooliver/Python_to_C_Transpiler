# Ejemplo de FOR
a = 1
b = 2

for x in range(5):
    b = b * 2  # Multiplica b por 2 en cada iteración
    if a == 1:
        a = a + x  # Incrementa a por el valor de x
    else:
        a = a - 1  # Decrementa a por 1

