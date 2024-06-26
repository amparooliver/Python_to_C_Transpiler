# Estructura anidada

# Inicialización de variables
i = 0
limite_externo = 3
limite_interno = 5
resultado = 1
stmt = 1

# Bucle while externo
while i < limite_externo:
    # Condición if dentro del while
    if i == 0:    
        # Condición if dentro del if
        if i != 0:
            # Bucle for dentro del segundo if
            for j in range(limite_interno):
                if j == 5:
                    stmt = 2
                else:
                    stmt = 3
                # dedentación
            stmt2 = "O podria marcar la dedentacion con otro statement"
        # dedentación
    # Incrementar la variable del bucle while
    i = i + 1  
# Resultado final almacenado en la lista
resultado_final = resultado
