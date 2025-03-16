#include "menu.h"
#include "timer.h"


void Menu::_ready(){

    b1 = cast_to<godot::TextureButton>(get_node<godot::TextureButton>("TextureButton"));

    b1->connect("pressed",callable_mp(this,&Menu::b1_pressed));
}

void Menu::_process(float delta){



}

void Menu::b1_pressed(){

    timerr::get_time(this)->timerr::await(1,callable_mp(this,&Menu::b1_pressed2));
    

}

void Menu::b1_pressed2(){

    get_tree()->change_scene_to_file("res://Mundo.tscn");

}