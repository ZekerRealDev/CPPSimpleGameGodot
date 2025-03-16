#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/label.hpp>

class Coin : public godot::Area2D{
    GDCLASS(Coin, godot::Area2D);

    public:
    void _body_entered(godot::Node2D *body);
    void _ready();
    protected:
    static void _bind_methods(){};
};