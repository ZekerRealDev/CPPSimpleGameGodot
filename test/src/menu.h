#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/texture_button.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/scene_tree.hpp>




class Menu : public godot::Control{
    GDCLASS(Menu, godot::Control)

    public:

    godot::TextureButton *b1;


    void _ready();
    void _process(float delta);
    void b1_pressed();
    void b1_pressed2();


    protected:

    static void _bind_methods(){};

};
