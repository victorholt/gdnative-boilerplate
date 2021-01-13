//
// GameSencha, LLC 1/08/2021.
// Godot Project Boilerplate
// License: MIT License
//
#include "Projectile.hpp"
using namespace godot;

void Projectile::_ready()
{
    _life_timer = Timer::_new();
    add_child(_life_timer);

    _life_timer->connect("timeout", this, "on_projectile_remove");
    _life_timer->set_wait_time(3.f);
    _life_timer->start();

    if (_sprite) {
        add_child(_sprite);
    }
}

void Projectile::_physics_process(float delta)
{
    // Ensure we have a player object created.
    if (!_sprite || !is_inside_tree()) {
        return;
    }

    auto vel = _dir * (_speed * delta);
    translate(vel);
}

void Projectile::on_projectile_remove()
{
    _life_timer->stop();
    queue_free();
}

