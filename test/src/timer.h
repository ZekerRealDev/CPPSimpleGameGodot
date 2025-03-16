
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/timer.hpp>

using namespace godot;

class timerr : public Node{
    GDCLASS(timerr, Node);

    public:


        void await(float seconds,  Callable function);
        
        static timerr* get_time(Node *_node){
            return _node->get_node<timerr>("/root/timer");
        };
    protected:

        static void _bind_methods(){};
};