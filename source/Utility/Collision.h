//////////////////////////////////////////////////
// コリジョン
// 作成: Kanato Shimabukuro
//////////////////////////////////////////////////

#pragma once

#include "Vector2D.h"
#include <vector>

enum class eObjectType : unsigned char {
    none,

    wall,
    ground,

    item,

    player,
    enemy
};

class Collision {
public:
    bool is_blocking;

    Vector2D box_size;
    Vector2D pivot;

    eObjectType object_type;
    std::vector<eObjectType> hit_object_type;

private:
    Vector2D position;

public:
    Collision();
    ~Collision();

    void SetPosition(const Vector2D& pos);
    const Vector2D& GetPosition() const;

    void SetSize(const float& width, const float& height);
    Vector2D GetSize();

    void SetObjectType(const eObjectType& objectType);
    void SetHitObjectType(const std::vector<eObjectType>& hitObjectType);
    bool IsCheckHitTarget(eObjectType hitObject) const;
    bool CheckCollision(const Collision& target) const;
};