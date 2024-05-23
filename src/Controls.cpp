#include "controls.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>

using namespace godot;

void Controls::_bind_methods(){                
    ClassDB::bind_method(D_METHOD("get_speed"), &Controls::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), &Controls::set_speed);
    ClassDB::add_property("Controls", PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");    
}

Controls::Controls(){
    if(Engine::get_singleton()->is_editor_hint())
    {                    
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
    }
    UtilityFunctions::print("Controls.cpp Loaded!");
}

Controls::~Controls(){
    
}

void Controls::set_speed(double speed){
    this->speed = speed;
}

double Controls::get_speed(){
    return this->speed;
}

void Controls::_process(double delta){
        
    position = Vector3(0.0f, 0.0f, 0.0f);

    Input *inputSingleton = Input::get_singleton();        

    if(inputSingleton->is_action_pressed("d"))
        position.x += 1.0f;
    
    if(inputSingleton->is_action_pressed("a"))
        position.x -= 1.0f;

    if(inputSingleton->is_action_pressed("s"))
        position.z += 1.0f;

    if(inputSingleton->is_action_pressed("w"))
        position.z -= 1.0f;        
    
    if(inputSingleton->is_action_pressed("q"))
        position.y += 1.0f;        

    if(inputSingleton->is_action_pressed("e"))
        position.y -= 1.0f;        
    
    set_position(get_position() + (position * speed * delta));    
}
