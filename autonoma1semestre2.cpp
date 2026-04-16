#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definimos la estructura Libro
struct Libro {
    string titulo;
    string autor;
    int anio;
};

// Función para mostrar los libros
void mostrarLibros(const vector<Libro>& repositorio) {
    cout << " Lista de Libros ";
    for (const auto& libro : repositorio) {
        cout << "Titulo: " << libro.titulo
             << " Autor: " << libro.autor
             << "  Año: " << libro.anio << endl;
    }
}

// Función para eliminar un libro por título
void eliminarLibro(vector<Libro>& repositorio, const string& titulo) {
    auto it = remove_if(repositorio.begin(), repositorio.end(),
                        [&](const Libro& l){ return l.titulo == titulo; });
    if (it != repositorio.end()) {
        repositorio.erase(it, repositorio.end());
        cout << "Libro eliminado correctamente.";
    } else {
        cout << "No se encontró el libro con ese titulo.";
    }
}

// Función para ordenar por año
void ordenarPorAnio(vector<Libro>& repositorio) {
    sort(repositorio.begin(), repositorio.end(),
         [](const Libro& a, const Libro& b){ return a.anio < b.anio; });
    cout << "Libros ordenados por año.";
}

int main() {
    vector<Libro> repositorio;

    // Ingreso de al menos 3 libros
    for (int i = 0; i < 3; i++) {
        Libro libro;
        cout << "Ingrese titulo del libro: ";
        getline(cin, libro.titulo);
        cout << "Ingrese autor del libro: ";
        getline(cin, libro.autor);
        cout << "Ingrese anio de publicacion: ";
        cin >> libro.anio;
        cin.ignore(); // limpiar buffer
        repositorio.push_back(libro);
    }

    mostrarLibros(repositorio);

    // Agregar un libro adicional
    Libro nuevo;
    cout << "Agregar un nuevo libro ";
    cout << "Titulo: ";
    getline(cin, nuevo.titulo);
    cout << "Autor: ";
    getline(cin, nuevo.autor);
    cout << "Anio: ";
    cin >> nuevo.anio;
    repositorio.push_back(nuevo);

    mostrarLibros(repositorio);

    // Eliminar un libro por título
    string tituloEliminar;
    cout << "Ingrese el titulo del libro a eliminar: ";
    cin.ignore();
    getline(cin, tituloEliminar);
    eliminarLibro(repositorio, tituloEliminar);

    mostrarLibros(repositorio);

    // Ordenar por año
    ordenarPorAnio(repositorio);
    mostrarLibros(repositorio);

    return 0;
}
