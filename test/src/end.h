#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/node2d.hpp>


class End : public godot::Area2D{
    GDCLASS(End,godot::Area2D);


    public:
    bool fim = false;
    void _ready();
    void _body_entered(godot::Node2D *body);
    void finzin();
    void final_screen();
    protected:
    static void _bind_methods(){};
};