# examen04

Task 1
Implementación:
Descripción: Crear una clase que gestione el contenido disponible en el sistema, agrupado por categorías. Debe permitir agregar contenido a una categoría y recuperar el contenido según la categoría solicitada.
Crear la clase ContentManager con un unordered_map que mapea cada categoría a un conjunto de contenidos.
Implementar métodos para agregar contenido y obtener contenido por categoría.
Requisitos:
Método addContent para agregar contenido a una categoría.
Método getContentByCategory para obtener contenidos en función de una categoría.
Archivos:
ContentManager.h
ContentManager.cpp
Task 2 


Descripción: Crear la clase UserManager para almacenar los intereses de los usuarios (categorías de contenido) y permitir agregar o consultar intereses.
Implementación:
Utilizar un unordered_map que mapea cada usuario a un conjunto de categorías de interés.
Implementar métodos para agregar un interés a un usuario y obtener los intereses de un usuario.
Requisitos:
Método addUser para agregar un nuevo usuario.
Método addInterest para asociar intereses a un usuario.
Método getInterests para obtener los intereses de un usuario dado.
Archivos:
UserManager.h
UserManager.cpp
Task 3 

Descripción: Implementar un algoritmo BFS dentro de la clase Graph para explorar el grafo de relaciones de amistad de un usuario. La búsqueda debe devolver todos los amigos directos e indirectos del usuario.
Implementación:
Agregar un método bfs en la clase Graph que recorra las relaciones de amistad usando una cola.
El método debe devolver un conjunto de amigos encontrados.
Requisitos:
Método addEdge para agregar una conexión entre dos usuarios.
Método bfs para realizar una búsqueda en amplitud y devolver todos los amigos de un usuario.
Archivos:
Graph.h
Graph.cpp
Task 4

Descripción: Crear la clase RecommendationSystem que integrará el grafo de usuarios, sus intereses y el contenido disponible para recomendar contenido basado en los intereses de los amigos de un usuario.
Implementación:
Crear métodos en RecommendationSystem para agregar usuarios, agregar contenido, agregar amigos, y recomendar contenido.
Utilizar BFS para obtener los intereses de los amigos y recomendar contenido basado en esos intereses.
Requisitos:
Método addUser para delegar la creación de un usuario a UserManager.
Método addContent para delegar la adición de contenido a ContentManager.
Método addFriend para delegar la creación de conexiones en el grafo.
Método recommendContent que:
Use BFS en el grafo para obtener amigos de un usuario.
Obtenga los intereses de esos amigos.
Genere una lista de contenido recomendada basada en los intereses obtenidos.
Archivos:
RecommendationSystem.h
RecommendationSystem.cpp
main.cpp (para probar el sistema)
 

Taks 5

Descripción: Crear un menú interactivo en consola que permita a un usuario realizar varias acciones, como agregar usuarios, agregar amigos, agregar intereses y obtener recomendaciones de contenido basadas en los intereses de los amigos.
Implementación:
El menú debe mostrar una lista de opciones disponibles para el usuario.
El usuario debe poder seleccionar entre las siguientes opciones:
Agregar un nuevo usuario.
Agregar un amigo a un usuario existente.
Agregar un interés a un usuario.
Obtener recomendaciones de contenido basadas en los intereses de los amigos.
Las opciones deben estar disponibles en un bucle hasta que el usuario decida salir.
Utilizar las clases previamente creadas (Graph, UserManager, ContentManager, y RecommendationSystem).
Archivo:
Menu.cpp (contendrá la implementación del menú)
main.cpp (donde se inicia el programa y se llama al menú interactivo)
 
