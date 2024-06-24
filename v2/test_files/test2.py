# Estructura anidada

puntaje = 91  # NOTA DEL ESTUDIANTE
nota_final = "No sacaste cinco"
le_quiero_al_alumno = "No"
# DETERMINAMOS SU NOTA FINAL
if puntaje >= 90:
    if le_quiero_al_alumno == "Si":
        nota_final = "FELICIDADES!! Sacaste un 5!!"
    else:
        nota_final = "Sacaste un 5 Juan, chau, no te quiero ver mas"
