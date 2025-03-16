#include "coin.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/object.hpp>
#include "player.h"

void Coin::_ready(){

    godot::Object::connect("body_entered",godot::create_custom_callable_function_pointer(this,&Coin::_body_entered));

}

Player *player2;

void Coin::_body_entered(godot::Node2D *body){

    player2 = cast_to<Player>(body);

    if (body->get_name() == godot::StringName("Player")){

        this->godot::Node::queue_free();
        player2->moedas++;
        
    }

}