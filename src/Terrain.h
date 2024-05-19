#ifndef TERRAIN_H
#define TERRAIN_H

#include <godot_cpp/classes/node3d.hpp>

namespace godot {
    class Terrain: public Node3D{
        GDCLASS(Terrain, Node3D);

        private:
        
        protected:
            static void _bind_methods();

        public:
            Terrain();
            ~Terrain();
            void _process(double delta);

    };
}

#endif