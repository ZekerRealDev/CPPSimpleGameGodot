#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/canvas_layer.hpp>







class HUD : public godot::CanvasLayer{
    GDCLASS(HUD, godot::CanvasLayer);

    public:
    void _ready();
    void _process(float delta);

    protected:
    static void _bind_methods(){};


};