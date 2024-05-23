#ifndef PRIMARY_MESH_H
#define PRIMARY_MESH_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>

namespace godot {
    class Terrain: public Node3D{
        GDCLASS(Terrain, Node3D);

        private:
        
        protected:
            static void _bind_methods();

        public:
            
            float xSize = 100;
            float zSize = 100;
            float ySize = 1;
            
            float scale = 1;
            float height = 50;            

            MeshInstance3D *mesh = memnew(MeshInstance3D);

            Terrain();
            ~Terrain();

            void generate();            

            Vector3 get_size();
            void set_size(Vector3 size);

            float get_scale();
            void set_scale(float scale);

            float get_height();
            void set_height(float height);
            
            void draw_points(PackedVector3Array vertices, float radius);
            
            void _ready();            
            //void _process(float delta);

    };
}

#endif