#include <HUD.h>
#include <godot_cpp/variant/utility_functions.hpp>
#include "player.h"


Player *player;

godot::Label *label;

void HUD::_ready(){

    player = cast_to<Player>(godot::Node::get_node<godot::CharacterBody2D>("../Player"));
    label = cast_to<godot::Label>(godot::Node::get_node<godot::Label>("Label"));

}

void HUD::_process(float delta){

   // label -> godot::Label::set_text(godot::UtilityFunctions::str(moedas));
    label -> godot::Label::set_text(godot::UtilityFunctions::str(player->moedas,"/5"));

}