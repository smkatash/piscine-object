
struct Vector2
{
    float X;
    float Y;
    Vector2(float x, float y) : X(x), Y(y) {}
    bool operator==(const Vector2& other) const {
        return X == other.X && Y == other.Y;
    }
};
