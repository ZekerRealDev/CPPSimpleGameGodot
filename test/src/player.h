#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/sprite2d.hpp>


class Player : public godot::CharacterBody2D{
    GDCLASS(Player, godot::CharacterBody2D);

    godot::Vector2 velocity = godot::CharacterBody2D::get_velocity();

    
    
    
    public:
    int moedas = 0;
        void _physics_process(double delta);
        void _ready();
        void glide();
        void particle();
        void adjustment();
    protected:
        static void _bind_methods(){};
        void moviment();
        
};