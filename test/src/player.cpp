#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/gpu_particles2d.hpp>
#include <godot_cpp/classes/scene_tree.hpp>

#include "player.h"
#include "end.h"

void Player::_physics_process(double delta){
    moviment();
    glide();
    particle();
    adjustment();

    godot::CharacterBody2D::move_and_slide();
}




int speed = 256;
int gravity = 25;
int jump_force = 440;
int fall_speed = 300;
int movimento;

godot::AnimatedSprite2D *AnimatedSprite2D;
End *final;

void Player::_ready(){

    AnimatedSprite2D = cast_to<godot::AnimatedSprite2D>(get_node<godot::AnimatedSprite2D>("AnimatedSprite2D"));
    final = cast_to<End>(get_node<godot::Area2D>("../End"));
}



void Player::moviment(){
    if (godot::Input::get_singleton()->is_action_pressed("direita")){

        movimento = 1;
        

        AnimatedSprite2D->set_scale(godot::Vector2(1,1));

    }else if(godot::Input::get_singleton()->is_action_pressed("esquerda")){

        
        movimento = 2;
        AnimatedSprite2D->set_scale(godot::Vector2(-1,1));

    }else{

        movimento = 0;

    }   

    if(godot::CharacterBody2D::is_on_floor()){

        if (movimento == 1){

        velocity.x = speed;
        AnimatedSprite2D->play(godot::StringName("walk"));


        }else if (movimento == 2){

        velocity.x = -speed;
        AnimatedSprite2D->play(godot::StringName("walk"));

        }else{

        velocity.x = 0;
        AnimatedSprite2D->play(godot::StringName("idle"));
        }
    }else{

        if (fall_speed <= 100){
            if (movimento == 1){

            velocity.x = speed;
            AnimatedSprite2D->play(godot::StringName("glide"));


            }else if (movimento == 2){

            velocity.x = -speed;
            AnimatedSprite2D->play(godot::StringName("glide"));

            }else{

            velocity.x = 0;
            AnimatedSprite2D->play(godot::StringName("glide"));

            }
        }else{

            if (movimento == 1){

            velocity.x = speed;
            AnimatedSprite2D->play(godot::StringName("jump"));


            }else if (movimento == 2){

            velocity.x = -speed;
            AnimatedSprite2D->play(godot::StringName("jump"));

            }else{

            velocity.x = 0;
            AnimatedSprite2D->play(godot::StringName("jump"));

            }

        }
    
        if (!godot::CharacterBody2D::is_on_floor()){
      
          velocity.y += gravity;


        if(velocity.y > fall_speed){
        
        velocity.y = fall_speed;

        }
      
        }else{

        velocity.y = 0;

        }

        if (velocity.y < 0){

            AnimatedSprite2D->play(godot::StringName("jump"));
        
        }
    

    }

    if (godot::CharacterBody2D::is_on_floor() && godot::Input::get_singleton()->is_action_pressed("pulo")){

        velocity.y = -jump_force;

    }

    godot::CharacterBody2D::set_velocity(velocity);
}


void Player::glide(){

    if (!godot::CharacterBody2D::is_on_floor()){
        if(godot::Input::get_singleton()->is_action_pressed("planar") && velocity.y > 1){

            fall_speed = 100;
            AnimatedSprite2D->play(godot::StringName("glide"));

        }else{

            fall_speed = 300;
            
        }
    }
}


void Player::adjustment(){
    if (get_global_position().y > 312){
        get_tree()->reload_current_scene();
    }
}


void Player::particle(){

    this->get_node<godot::GPUParticles2D>("GPUParticles2D")->set_emitting(godot::CharacterBody2D::is_on_floor() && velocity.x != 0);


}

