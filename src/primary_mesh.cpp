#include "primary_mesh.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>

#include <godot_cpp/classes/array_mesh.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>

using namespace godot;

void PrimaryMesh::_bind_methods(){            
   
}

PrimaryMesh::PrimaryMesh(){
    if(Engine::get_singleton()->is_editor_hint())
    {                    
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
    }
    UtilityFunctions::print("PrimaryMesh.cpp Loaded!");
}

PrimaryMesh::~PrimaryMesh(){

}

void PrimaryMesh::_ready(){
    
    // Create a ArrayMesh.
    Ref<ArrayMesh> arr_mesh = memnew(ArrayMesh);

    // Define the vertices of the triangle.
    PackedVector3Array vertices;
    vertices.push_back(Vector3(0, 0, 0));
    vertices.push_back(Vector3(1, 0, 0));
    vertices.push_back(Vector3(0, 0, 1));

    //Init the ArrayMesh.
    Array arrays;
    arrays.resize(Mesh::ARRAY_MAX);
    arrays[Mesh::ARRAY_VERTEX] = vertices;

    //Create the mesh.
    arr_mesh->add_surface_from_arrays(Mesh::PRIMITIVE_TRIANGLES, arrays);

    //Create a mesh instance and define the mesh.
    MeshInstance3D *mesh = memnew(MeshInstance3D);
    mesh->set_mesh(arr_mesh);

    //Add mesh
    add_child(mesh);

}

void PrimaryMesh::_process(double delta){

}