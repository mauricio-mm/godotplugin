#include "Terrain.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>

#include <godot_cpp/classes/array_mesh.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/pool

using namespace godot;

void Terrain::_bind_methods(){            
   
}

Terrain::Terrain(){

}

Terrain::~Terrain(){

}

void _process(double delta){
   // Cria um ArrayMesh.
    Ref<ArrayMesh> arr_mesh = memnew(ArrayMesh);

    // Define os vértices do triângulo.
    PoolVector3Array vertices;
    vertices.push_back(Vector3(0, 1, 0));
    vertices.push_back(Vector3(1, 0, 0));
    vertices.push_back(Vector3(0, 0, 1));

    // Inicializa o ArrayMesh.
    Array arrays;
    arrays.resize(Mesh::ARRAY_MAX);
    arrays[Mesh::ARRAY_VERTEX] = vertices;

    // Cria a malha.
    arr_mesh->add_surface_from_arrays(Mesh::PRIMITIVE_TRIANGLES, arrays);

    // Cria uma instância de malha e define a malha.
    MeshInstance3D *m = memnew(MeshInstance3D);
    m->set_mesh(arr_mesh);

    // Adiciona a instância de malha à árvore de cena.
    this->add_child(m);

}