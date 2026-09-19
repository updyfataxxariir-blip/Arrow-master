#ifndef ARROW_PHYSICS_HPP
#define ARROW_PHYSICS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <memory>

namespace ArrowMaster {

struct Vector2D {
    double x;
    double y;

    Vector2D(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}
};

enum class HitZone {
    MISS,
    OUTER,
    INNER,
    BULLSEYE,
    PERFECT,
    OBSTACLE
};

struct HitResult {
    HitZone zone;
    int score;
    int coins;
    bool isBullseye;
    bool isPerfect;
    std::string message;
};

class Target {
public:
    double x;
    double y;
    double radius;
    double speed;
    int direction;
    double minX;
    double maxX;

    Target(double _x = 200.0, double _y = 120.0, double _r = 45.0, double _spd = 2.0, double _minX = 60.0, double _maxX = 340.0)
        : x(_x), y(_y), radius(_r), speed(_spd), direction(1), minX(_minX), maxX(_maxX) {}

    void update() {
        x += speed * direction;
        if (x >= maxX) {
            x = maxX;
            direction = -1;
        } else if (x <= minX) {
            x = minX;
            direction = 1;
        }
    }
};

class PhysicsSimulation {
public:
    static constexpr double GRAVITY = 0.04;

    static HitResult calculateHit(double arrowX, double targetX, double targetRadius, int currentCombo = 0) {
        double dist = std::abs(arrowX - targetX);
        HitResult result;
        result.zone = HitZone::MISS;
        result.score = 0;
        result.coins = 0;
        result.isBullseye = false;
        result.isPerfect = false;

        double perfectRadius = targetRadius * 0.12;
        double bullseyeRadius = targetRadius * 0.28;
        double innerRadius = targetRadius * 0.62;
        double outerRadius = targetRadius * 1.0;

        if (dist <= perfectRadius) {
            result.zone = HitZone::PERFECT;
            result.score = 200 + (currentCombo * 30);
            result.coins = 20;
            result.isBullseye = true;
            result.isPerfect = true;
            result.message = "PERFECT DEAD-CENTER! +200";
        } else if (dist <= bullseyeRadius) {
            result.zone = HitZone::BULLSEYE;
            result.score = 100 + (currentCombo * 20);
            result.coins = 10;
            result.isBullseye = true;
            result.message = "BULLSEYE! +100";
        } else if (dist <= innerRadius) {
            result.zone = HitZone::INNER;
            result.score = 50 + (currentCombo * 10);
            result.coins = 5;
            result.message = "GREAT HIT! +50";
        } else if (dist <= outerRadius) {
            result.zone = HitZone::OUTER;
            result.score = 20;
            result.coins = 2;
            result.message = "HIT! +20";
        } else {
            result.zone = HitZone::MISS;
            result.score = 0;
            result.coins = 0;
            result.message = "MISS!";
        }

        return result;
    }
};

} // namespace ArrowMaster

#endif // ARROW_PHYSICS_HPP