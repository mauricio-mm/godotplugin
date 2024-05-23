#include "terrain.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>

#include <godot_cpp/classes/array_mesh.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/sphere_mesh.hpp>
#include <godot_cpp/classes/fast_noise_lite.hpp>

using namespace godot;

void Terrain::_bind_methods(){            
    ClassDB::bind_method(D_METHOD("get_size"), &Terrain::get_size);
    ClassDB::bind_method(D_METHOD("set_size", "size"), &Terrain::set_size);

    ClassDB::bind_method(D_METHOD("get_scale"), &Terrain::get_scale);
    ClassDB::bind_method(D_METHOD("set_scale", "scale"), &Terrain::set_scale);

    ClassDB::bind_method(D_METHOD("get_height"), &Terrain::get_height);
    ClassDB::bind_method(D_METHOD("set_height", "height"), &Terrain::set_height);

    ClassDB::add_property("Terrain", PropertyInfo(Variant::VECTOR3, "size"), "set_size", "get_size");    
    ClassDB::add_property("Terrain", PropertyInfo(Variant::FLOAT, "scale"), "set_scale", "get_scale");    
    ClassDB::add_property("Terrain", PropertyInfo(Variant::FLOAT, "height"), "set_height", "get_height");    
}

Terrain::Terrain(){
    if(Engine::get_singleton()->is_editor_hint())
    {                    
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
    }
    UtilityFunctions::print("Terrain.cpp Loaded!");
}

Terrain::~Terrain(){

}

void Terrain::generate(){

    PackedVector3Array vertices;  
    FastNoiseLite noise;
    PackedInt32Array triangles;
    int counter = 0;
    float y;
    
    noise.set_noise_type(FastNoiseLite::NoiseType::TYPE_PERLIN);
    for(int z = 0;z < this->zSize;z++){
        for(int x = 0;x < this->xSize;x++){                            
            y = noise.get_noise_2d(x*this->scale , z*this->scale);
            vertices.push_back(Vector3(x, (y*this->height), z));
        }
    }    


    for(int z = 0;z < (this->zSize - 1) ;z++){
        
        for(int x = 0;x < (this->xSize - 1) ;x++){

            triangles.push_back( x + counter);
            triangles.push_back( x + 1 + counter);
            triangles.push_back( x + this->xSize + counter);

            triangles.push_back( x + 1 + counter);
            triangles.push_back( x + this->xSize + 1 + counter);
            triangles.push_back( x + this->xSize + counter);

        }

        counter += this->xSize;
    }    

    // Create a ArrayMesh.
    Ref<ArrayMesh> arr_mesh = memnew(ArrayMesh);

    //Init the ArrayMesh.
    Array arrays;
    arrays.resize(Mesh::ARRAY_MAX);
    arrays[Mesh::ARRAY_VERTEX] = vertices;
    arrays[Mesh::ARRAY_INDEX] = triangles;

    //Create the mesh.
    arr_mesh->add_surface_from_arrays(Mesh::PRIMITIVE_TRIANGLES, arrays);

    //Create a mesh instance and define the mesh.
    
    this->mesh->set_mesh(arr_mesh);

    //Add mesh
    add_child(this->mesh);
    //draw_points(vertices, 0.1);

}

Vector3 Terrain::get_size(){
    return Vector3(this->xSize, this->ySize, this->zSize);
}

void Terrain::set_size(Vector3 size){
    this->xSize = size.x;
    this->ySize = size.y;
    this->zSize = size.z;
}

float Terrain::get_scale(){
    return this->scale;
}

void Terrain::set_scale(float scale){
    this->scale = scale;
}

float Terrain::get_height(){
    return this->height;
}

void Terrain::set_height(float height){
    this->height = height;
}

void Terrain::draw_points(PackedVector3Array vertices, float radius){
    
    for (int i = 0; i < vertices.size(); i++) {
        // Crie uma nova instância de MeshInstance
        MeshInstance3D* sphere = memnew(MeshInstance3D);

        // Crie uma nova instância de SphereMesh
        Ref<SphereMesh> sphere_mesh = memnew(SphereMesh);
        
        // Defina o raio da esfera
        sphere_mesh->set_radius(radius); // Ajuste o valor do raio conforme necessário

        // Defina a malha da instância da esfera para a esfera que acabamos de criar
        sphere->set_mesh(sphere_mesh);

        // Defina a transformação da esfera para a posição do ponto            
        Transform3D transform = sphere->get_transform();
        transform.basis.scale(Vector3(1, 2.5*radius, 1)); 
        transform.origin = vertices[i];
        // Ajuste a escala para as dimensões desejadas
        sphere->set_transform(transform);

        // Adicione a esfera à cena
        this->add_child(sphere);
    }
}

void Terrain::_ready(){               
    
    generate();        

}