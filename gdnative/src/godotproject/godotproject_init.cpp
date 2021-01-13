//
// GameSencha, LLC 1/8/2021.
// Godot Project Boilerplate
// License: MIT License
//

#include <Godot.hpp>
#include "controllers/GameController.hpp"
#include "entity/Projectile.hpp"

/** GDNative Initialize **/
extern "C" void GDN_EXPORT godotproject_gdnative_init(godot_gdnative_init_options *o)
{
    godot::Godot::gdnative_init(o);
}

/** GDNative Terminate **/
extern "C" void GDN_EXPORT godotproject_gdnative_terminate(godot_gdnative_terminate_options *o)
{
    godot::Godot::gdnative_terminate(o);
}

/** NativeScript Initialize **/
extern "C" void GDN_EXPORT godotproject_nativescript_init(void *handle)
{
    godot::Godot::nativescript_init(handle);

    godot::register_class<GameController>();
    godot::register_class<Projectile>();
}
