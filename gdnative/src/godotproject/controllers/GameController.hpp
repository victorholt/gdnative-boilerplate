//
// GameSencha, LLC 1/08/2021.
// Godot Project Boilerplate
// License: MIT License
//
#pragma once

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Sprite.hpp>
#include <PackedScene.hpp>
#include <Input.hpp>
#include <InputEvent.hpp>
#include <Timer.hpp>
using namespace godot;

class GameController : public Node2D
{
    GODOT_CLASS(GameController, Node2D);

private:
    Ref<PackedScene> _player_scene;
    Ref<PackedScene> _projectile_scene;

    Sprite* _player = nullptr;
    Sprite* _projectile = nullptr;

    Vector2 _spawn_pos;

    float _player_speed = 1.0f;

    Timer* _cooldown_timer = nullptr;
    int _max_projectiles = 100;
    bool _can_fire_projectile = true;

public:
    void _init() {}

    //! Starts up the game controller scene.
    //! \param spawn_pos
    //! \param player_scene
    //! \param projectile_scene
    void startup(Vector2 spawn_pos, Ref<PackedScene> player_scene, Ref<PackedScene> projectile_scene);

    void _ready();
    void _physics_process(float delta);
    void _input(Ref<InputEvent> event);

    void fire_projectile(Ref<InputEvent> event);
    void on_projectile_cooldown_finished();

    //! Registers methods for Godot.
    static void _register_methods()
    {
        register_method((char*) "_init", &GameController::_init);
        register_method((char*) "_ready", &GameController::_ready);
        register_method((char*) "_physics_process", &GameController::_physics_process);
        register_method((char*) "_input", &GameController::_input);

        register_method((char*) "startup", &GameController::startup);
        register_method((char*) "on_projectile_cooldown_finished", &GameController::on_projectile_cooldown_finished);
    }
};
