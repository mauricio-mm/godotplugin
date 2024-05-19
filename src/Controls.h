#ifndef CONTROLS_H
#define CONTROLS_H

#include <godot_cpp/classes/node3d.hpp>

namespace godot {
    class Controls : public Node3D{
        GDCLASS(Controls, Node3D);

        private:            
            double speed;
            Vector3 position;
        
        protected:
            static void _bind_methods();
        
        public:
            Controls();
            ~Controls();            
            void set_speed(double speed);
            double get_speed();
            void _process(double delta);
    };

}

#endif