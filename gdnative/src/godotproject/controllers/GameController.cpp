//
// GameSencha, LLC 1/08/2021.
// Godot Project Boilerplate
// License: MIT License
//
#include <InputEventMouseButton.hpp>
#include "GameController.hpp"
#include "../entity/Projectile.hpp"
using namespace godot;

void GameController::startup(Vector2 spawn_pos, Ref<PackedScene> player_scene, Ref<PackedScene> projectile_scene)
{
    _spawn_pos = spawn_pos;

    // This is not necessary, but you can save the player scene for later use.
    _player_scene = player_scene;

    // Used for creating multiple projectiles.
    _projectile_scene = projectile_scene;
}

void GameController::_ready()
{
    Godot::print("GameController is now ready!");

    if (_player_scene.is_valid()) {
        _player = Object::cast_to<Sprite>(_player_scene->instance());
        add_child(_player);

        _player->set_global_position(_spawn_pos);

        _cooldown_timer = Timer::_new();
        add_child(_cooldown_timer);

        _cooldown_timer->set_wait_time(0.06f);
        _cooldown_timer->connect("timeout", this, "on_projectile_cooldown_finished");
    }
}

void GameController::_physics_process(float delta)
{
    // Ensure we have a player object created.
    if (!_player || !_player->is_inside_tree()) {
        return;
    }

    auto vec = Vector2();
    if (Input::get_singleton()->is_action_pressed("ui_left")) {
        vec.x -= _player_speed;
    }
    if (Input::get_singleton()->is_action_pressed("ui_right")) {
        vec.x += _player_speed;
    }
    if (Input::get_singleton()->is_action_pressed("ui_up")) {
        vec.y -= _player_speed;
    }
    if (Input::get_singleton()->is_action_pressed("ui_down")) {
        vec.y += _player_speed;
    }

    _player->global_translate(vec);
}

void GameController::_input(Ref<InputEvent> event)
{
    if (event->is_action_pressed("ui_click")) {
        fire_projectile(event);
    }
}

void GameController::fire_projectile(Ref<InputEvent> event)
{
    if (!event->is_class("InputEventMouseButton")) {
        return;
    }

    if (!_projectile_scene.is_valid() || !_can_fire_projectile) {
        return;
    }
    _can_fire_projectile = false;
    _cooldown_timer->start();

    // create our projectile in the world.
    auto mouse_pos = Object::cast_to<InputEventMouseButton>(event.ptr())->get_position();
    auto dir = (mouse_pos - _player->get_global_position()).normalized();

    auto proj = Projectile::_new();
    auto sprite = _projectile_scene->instance();

    proj->set_dir(dir);
    proj->set_sprite(Object::cast_to<Sprite>(sprite));
    add_child(proj);

    proj->set_global_position(_player->get_global_position());
}

void GameController::on_projectile_cooldown_finished()
{
    _can_fire_projectile = true;
    _cooldown_timer->stop();
}

