#include "register_types.h"
#include "Controls.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_register(ModuleInitializationLevel p_level){
    
    if(p_level != MODULE_INITIALIZATION_LEVEL_SCENE) return;

    ClassDB::register_class<Controls>();

}

void unitialize_register(ModuleInitializationLevel p_level){

    if(p_level != MODULE_INITIALIZATION_LEVEL_SCENE) return;
    
}

extern "C"{
    GDExtensionBool GDE_EXPORT hello_world_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization){
        
        GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        init_obj.register_initializer(initialize_register);
        init_obj.register_terminator(unitialize_register);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}