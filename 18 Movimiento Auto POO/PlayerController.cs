using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public enum Direction { North, South, East, West }

    [Header("Configuración")]
    public Direction movementDirection;
    public float speed = 3.0f;

    [Header("Assets Visuales")]
    public Sprite horizontalSprite;
    public Sprite verticalSprite;

    private SpriteRenderer _spriteRenderer;
    private Vector2 _moveVector;
    private bool _isMoving = false;

    void Start()
    {
        _spriteRenderer = GetComponent<SpriteRenderer>();

        // Configuración lógica y visual según el enumerador
        switch (movementDirection)
        {
            case Direction.North:
                _moveVector = Vector2.up;
                _spriteRenderer.sprite = verticalSprite;
                _spriteRenderer.flipY = false;
                break;
            case Direction.South:
                _moveVector = Vector2.down;
                _spriteRenderer.sprite = verticalSprite;
                _spriteRenderer.flipY = true;
                break;
            case Direction.East:
                _moveVector = Vector2.right;
                _spriteRenderer.sprite = horizontalSprite;
                _spriteRenderer.flipX = false;
                break;
            case Direction.West:
                _moveVector = Vector2.left;
                _spriteRenderer.sprite = horizontalSprite;
                _spriteRenderer.flipX = true;
                break;
        }
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            _isMoving = true;
        }

        if (_isMoving)
        {
            Move();
        }
    }

    void Move()
    {
        transform.Translate(_moveVector * speed * Time.deltaTime);
    }
}