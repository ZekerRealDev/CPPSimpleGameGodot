#include "end.h"
#include "player.h"
#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <HUD.h>
#include <godot_cpp/classes/color_rect.hpp>
#include <godot_cpp/classes/tween.hpp>
#include <godot_cpp/classes/property_tweener.hpp>
#include "timer.h"
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/scene_tree.hpp>

Player *playerend;
godot::AnimatedSprite2D *AnimatedSprite2D2;
godot::ColorRect *hudzin;


void End::_ready(){

    hudzin = get_node<godot::ColorRect>("../HUD/ColorRect");
    AnimatedSprite2D2 = cast_to<godot::AnimatedSprite2D>(get_node<godot::AnimatedSprite2D>("AnimatedSprite2D"));
    godot::Object::connect(godot::StringName("body_entered"),godot::create_custom_callable_function_pointer(this,&End::_body_entered));

}

void End::_body_entered(godot::Node2D *body){

    playerend = cast_to<Player>(body);
    if (body->get_name() == godot::StringName("Player") && playerend->moedas == 5 && fim == false){

        godot::UtilityFunctions::print("Fim");
        AnimatedSprite2D2->play("fim");
        fim = true;

        timerr::get_time(this)->timerr::await(1.8,callable_mp(this, &End::finzin));
    }

}

void End::finzin() {

    create_tween()->set_trans(godot::Tween::TransitionType::TRANS_LINEAR)->tween_property(hudzin, "color", godot::Color(0, 0, 0, 1), 0.5);
    timerr::get_time(this)->timerr::await(1,callable_mp(this, &End::final_screen));
}


void End::final_screen(){

    get_tree()->change_scene_to_file("res://Mundo.tscn");

}