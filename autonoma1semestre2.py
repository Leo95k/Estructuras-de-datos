# Definimos funciones para manejar el repositorio

def mostrar_libros(repositorio):
    print(" Lista de Libros ")
    for libro in repositorio:
        print(f"Título: {libro['titulo']} | Autor: {libro['autor']} | Anio: {libro['anio']}")

def eliminar_libro(repositorio, titulo):
    encontrado = False
    for libro in repositorio:
        if libro['titulo'] == titulo:
            repositorio.remove(libro)
            print("Libro eliminado correctamente.")
            encontrado = True
            break
    if not encontrado:
        print("No se encontró el libro con ese título.")

def ordenar_por_anio(repositorio):
    repositorio.sort(key=lambda l: l['anio'])
    print("Libros ordenados por anio.")

# Programa principal
repositorio = []

# Ingreso de al menos 3 libros
for i in range(3):
    titulo = input("Ingrese titulo del libro: ")
    autor = input("Ingrese autor del libro: ")
    anio = int(input("Ingrese anio de publicacion: "))
    repositorio.append({"titulo": titulo, "autor": autor, "anio": anio})

mostrar_libros(repositorio)

# Agregar un libro adicional
print("Agregar un nuevo libro")
titulo = input("Titulo: ")
autor = input("Autor: ")
anio = int(input("Anio: "))
repositorio.append({"titulo": titulo, "autor": autor, "anio": anio})

mostrar_libros(repositorio)

# Eliminar un libro por título
titulo_eliminar = input("Ingrese el título del libro a eliminar: ")
eliminar_libro(repositorio, titulo_eliminar)

mostrar_libros(repositorio)

# Ordenar por año
ordenar_por_anio(repositorio)
mostrar_libros(repositorio)
