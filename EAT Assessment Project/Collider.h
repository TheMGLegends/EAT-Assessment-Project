#pragma once

enum class ColliderType
{
	None,

	Rect,
	Circle
};

class Collider
{
protected:
	ColliderType colliderType;

public:
	Collider();

	/// <summary>
	/// Used for drawing an outline of the collider
	/// for debugging purposes
	/// </summary>
	virtual void DrawCollider() {}

	/// <summary>
	/// Getter for the Colliders' Type
	/// </summary>
	/// <returns>The type of collider that is on the object</returns>
	ColliderType GetColliderType() const { return colliderType; }

	/// <summary>
	/// Setter for the Colliders' Type
	/// </summary>
	/// <param name="type">: The type of collider</param>
	void SetColliderType(ColliderType type) { colliderType = type; }
};

