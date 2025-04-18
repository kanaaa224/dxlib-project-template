//////////////////////////////////////////////////
// コリジョン
// 作成: Kanato Shimabukuro
//////////////////////////////////////////////////

#include "Collision.h"
#include <math.h>

Collision::Collision() :
    is_blocking(false),
    box_size(0.0f),
    pivot(0.0f),
    object_type(eObjectType::none),
    hit_object_type(),
    position(0.0f) {}

Collision::~Collision() {}

void Collision::SetPosition(const Vector2D& pos) {
    position = pos;
}

const Vector2D& Collision::GetPosition() const {
    return position;
}

void Collision::SetSize(const float& width, const float& height) {
    box_size.x = width;
    box_size.y = height;
}

Vector2D Collision::GetSize() {
    return box_size;
}

void Collision::SetObjectType(const eObjectType& FUNC_objecttype) {
    object_type = FUNC_objecttype;
}

void Collision::SetHitObjectType(const std::vector<eObjectType>& FUNC_hitobjecttype) {
    hit_object_type = FUNC_hitobjecttype;
}

bool Collision::IsCheckHitTarget(eObjectType FUNC_hitobject) const {
    for (eObjectType type : hit_object_type) {
        if (type == FUNC_hitobject) return true;
    }

    return false;
}

bool Collision::CheckCollision(const Collision& other) const {
    Vector2D A_min = position - (box_size / 2) + pivot;
    Vector2D A_max = position + (box_size / 2) + pivot;

    Vector2D B_min = other.position - (other.box_size / 2) + other.pivot;
    Vector2D B_max = other.position + (other.box_size / 2) + other.pivot;

    if (A_min.x < B_max.x &&
        A_max.x > B_min.x &&
        A_min.y < B_max.y &&
        A_max.y > B_min.y) {
        return true;
    }

    return false;
}