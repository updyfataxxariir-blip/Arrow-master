/**
 * Arrow Master - C++ Interactive Archery Engine & Console Edition
 * Compile: g++ -std=c++17 main.cpp -O2 -o arrow_master
 */

#include "ArrowPhysics.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace ArrowMaster;

void printBanner() {
    std::cout << "\n============================================\n";
    std::cout << "          🏹 ARROW MASTER (C++ EDITION)     \n";
    std::cout << "       Master Your Aim in C++ & Web Canvas   \n";
    std::cout << "============================================\n\n";
}

void renderScene(double targetX, double arrowX, bool isShooting, double wind) {
    const int WIDTH = 40;
    std::string track(WIDTH, ' ');

    int tPos = static_cast<int>((targetX / 400.0) * (WIDTH - 1));
    if (tPos >= 0 && tPos < WIDTH) track[tPos] = 'O';

    std::cout << " [TARGET LANE] |" << track << "|\n";

    if (isShooting) {
        std::string arrowTrack(WIDTH, ' ');
        int aPos = static_cast<int>((arrowX / 400.0) * (WIDTH - 1));
        if (aPos >= 0 && aPos < WIDTH) arrowTrack[aPos] = '^';
        std::cout << " [ARROW FLIGHT]|" << arrowTrack << "|\n";
    }

    std::cout << " Wind: " << std::fixed << std::setprecision(1) << wind 
              << (wind > 0.2 ? " -> (Right)" : wind < -0.2 ? " <- (Left)" : " (Calm)") << "\n\n";
}

int main() {
    printBanner();

    int totalScore = 0;
    int coins = 100;
    int level = 1;
    int arrowsRemaining = 5;
    int combo = 0;

    Target target(200.0, 120.0, 45.0, 15.0, 50.0, 350.0);
    double wind = 1.2;

    std::cout << "Level " << level << " Started! You have " << arrowsRemaining << " arrows.\n";
    std::cout << "Rules: Enter your aim position (0 to 400).\n\n";

    while (arrowsRemaining > 0) {
        target.update();
        renderScene(target.x, 0, false, wind);

        std::cout << "Arrows Left: " << arrowsRemaining 
                  << " | Score: " << totalScore 
                  << " | Coins: " << coins 
                  << " | Combo: x" << (combo > 0 ? combo : 1) << "\n";

        std::cout << "Enter Aim X (0 - 400, Target is near " << static_cast<int>(target.x) << "): ";
        double userAim;
        if (!(std::cin >> userAim)) {
            break;
        }

        double arrowImpactX = userAim + (wind * 15.0);
        renderScene(target.x, arrowImpactX, true, wind);

        HitResult result = PhysicsSimulation::calculateHit(arrowImpactX, target.x, target.radius, combo);

        std::cout << ">> " << result.message << "\n";

        if (result.zone != HitZone::MISS) {
            totalScore += result.score;
            coins += result.coins;
            combo++;
            std::cout << ">> + " << result.score << " PTS | Total: " << totalScore << "\n";
        } else {
            combo = 0;
            std::cout << ">> Missed! Combo reset.\n";
        }

        arrowsRemaining--;
        std::cout << "--------------------------------------------\n";
    }

    std::cout << "\n🎯 ROUND COMPLETE!\n";
    std::cout << "Final Score: " << totalScore << "\n";
    std::cout << "Coins Earned: " << coins << "\n";
    std::cout << "Thanks for playing Arrow Master!\n";

    return 0;
}