extends Node2D

onready var GameController = preload("res://libs/GameController.gdns")
onready var player_scene = load("res://scenes/player.tscn")
onready var projectile_scene = load("res://scenes/projectile.tscn")
onready var camera : Camera2D = $Camera2D

var controller = null

# Called when the node enters the scene tree for the first time.
func _ready():
    controller = GameController.new()
    controller.startup(camera.position, player_scene, projectile_scene)
    add_child(controller)
