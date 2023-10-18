extends Area2D


@export_enum("Colldown", "HitOnce", "DisableHitBox") var HurtBoxType = 0

@onready var collision = $CollisionShape2D
@onready var disableTimer = $DisableTimer

signal hurt(damage)

func _on_area_entered(area):
	if area.is_in_group("attack"):
		if not area.get("damage") == null:
			match HurtBoxType:
				0: #cooldown
					collision.call_deferred_thread_group("set", "disabled", true)
					disableTimer.start()
				1: #hitonce
					pass
				2: #DisabledHitBox
					if area.has_method("tempdisable"):
						area.tempdisable()
			var damage = area.damage
			emit_signal("hurt", damage)
			


func _on_disable_timer_timeout():
	collision.call_deferred_thread_group("set", "disabled", false)
