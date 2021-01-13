//
// GameSencha, LLC 1/12/2021.
//
#pragma once

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Sprite.hpp>
#include <Timer.hpp>
using namespace godot;

// This doesn't have to inherit Node2D. Using it
// for the callbacks to the process method.
class Projectile : public Node2D {
    GODOT_CLASS(Projectile, Node2D);

    Timer* _life_timer;
    Sprite* _sprite = nullptr;

    float _speed = 100.f;
    Vector2 _dir;

public:
    void _init() {}

    void _ready();
    void _physics_process(float delta);

    void on_projectile_remove();

    inline void set_sprite(Sprite* sprite) { _sprite = sprite; }
    inline void set_dir(Vector2 dir) { _dir = dir; }

    //! Registers methods for Godot.
    static void _register_methods()
    {
        register_method((char*) "_init", &Projectile::_init);
        register_method((char*) "_ready", &Projectile::_ready);
        register_method((char*) "_physics_process", &Projectile::_physics_process);

        register_method((char*) "on_projectile_remove", &Projectile::on_projectile_remove);
    }
};
