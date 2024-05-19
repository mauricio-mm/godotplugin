#ifndef PRIMARY_MESH_H
#define PRIMARY_MESH_H

#include <godot_cpp/classes/node3d.hpp>

namespace godot {
    class PrimaryMesh: public Node3D{
        GDCLASS(PrimaryMesh, Node3D);

        private:
        
        protected:
            static void _bind_methods();

        public:
            PrimaryMesh();
            ~PrimaryMesh();
            void _ready();
            void _process(double delta);

    };
}

#endif