# Unity: Movable Object with Target Point and Shooting

## Overview
This project demonstrates how to implement a movable object in Unity that can:
- Move towards a target point
- Rotate to face the target
- Indicate when it reaches the target
- Shoot projectiles in the direction of movement

The goal is to practice component-based design, communication between methods, and the use of Unity's math and physics systems.

---

## Main Class: `MovableShooter`

### Attributes
- `Vector3 position` — Current position of the object (managed by Transform).
- `Vector3 targetPoint` — The point the object moves towards.
- `bool shouldMove` — Indicates if the object should move.
- `float speed` — Movement speed.
- `float rotationSpeed` — How quickly the object rotates to face the target.
- `float stoppingDistance` — Minimum distance to consider the target reached.
- `GameObject projectilePrefab` — Prefab for the projectile to shoot.

### Methods
- `SetTargetPoint(Vector3 newTarget)` — Updates the target point.
- `StartMoving()` — Sets `shouldMove` to true.
- `Update()` — Handles movement, rotation, and target detection each frame.
- `Shoot()` — Instantiates a projectile in the current forward direction.

---

## Functionality & Communication
- `SetTargetPoint()` is used to change the destination dynamically (can be called from other scripts or UI).
- `StartMoving()` begins the movement process.
- `Update()` checks if movement is active, moves the object with `Vector3.MoveTowards`, rotates with `Quaternion.LookRotation`, and checks arrival using `Vector3.Distance`.
- When the target is reached, prints a message and calls `Shoot()`.

---

## Math Concepts Used
- **Distance Calculation:**
  - Uses `Vector3.Distance(position, targetPoint)` to check if the object has arrived.
- **Movement:**
  - `Vector3.MoveTowards(position, targetPoint, speed * Time.deltaTime)` for smooth movement.
- **Direction & Rotation:**
  - Calculates direction: `Vector3 direction = (targetPoint - position).normalized`
  - Rotates with `Quaternion.LookRotation(direction)` and optionally `Quaternion.Slerp` for smooth rotation.
- **Projectile Firing:**
  - Instantiates a projectile and applies force or velocity in the object's forward direction.

---

## Detailed Movement & Rotation Flow
1. **Direction Calculation:**
   - `Vector3 direction = (targetPoint - transform.position).normalized`
2. **Rotation:**
   - `Quaternion targetRotation = Quaternion.LookRotation(direction)`
   - `transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, rotationSpeed * Time.deltaTime)`
3. **Movement:**
   - `transform.position = Vector3.MoveTowards(transform.position, targetPoint, speed * Time.deltaTime)`
4. **Arrival Check:**
   - If `Vector3.Distance(transform.position, targetPoint) < stoppingDistance`, stop movement, print a message, and shoot.

---

## Example Usage
```csharp
// Setting the target from another script or UI:
movableShooter.SetTargetPoint(new Vector3(5, 0, 10));
movableShooter.StartMoving();
```

---

## Extension Ideas
- Allow multiple targets in sequence
- Add visual feedback for rotation and shooting
- Implement cooldowns for shooting

---

**This pattern is ideal for AI agents, turrets, or any entity that needs to move and interact with the world dynamically.**
