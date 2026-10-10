#include <raylib.h>
#include <cmath>

struct Planet
{
    float szog;
    float palyaSugar;
    float sebesseg;
    float sugar;
    Color szin;
};

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1300, 900, "Mini Solar System");
    SetWindowMinSize(800, 700);
    SetTargetFPS(60);

    bool szunet = false;
    float idoSzorzo = 1.0f;
    float kozepX = GetScreenWidth() / 2.0f;
    float kozepY = GetScreenHeight() / 2.0f;

    Planet fold{0.0f, 135.0f, 0.8f, 10.0f, SKYBLUE};
    Planet mars{0.0f, 170.0f, 0.6f, 7.0f, RED};
    Planet merkur{0.0f, 70.0f, 1.6f, 5.0f, GRAY};
    Planet venus{0.0f, 100.0f, 1.2f, 9.0f, GOLD};
    Planet uranus{0.0f, 285.0f, 0.18f, 12.0f, BLUE};
    Planet neptune{0.0f, 320.0f, 0.12f, 12.0f, DARKBLUE};
    Planet jupiter{0.0f, 210.0f, 0.35f, 18.0f, ORANGE};
    Planet saturn{0.0f, 250.0f, 0.25f, 15.0f, BEIGE};

    

    while (!WindowShouldClose())
    {
        kozepX = GetScreenWidth() / 2.0f;
        kozepY = GetScreenHeight() / 2.0f;
        float elteltIdo = GetFrameTime();

        if (IsKeyPressed(KEY_UP))
        {
            idoSzorzo *= 2.0f;
            if (idoSzorzo > 16.0f)
                idoSzorzo = 16.0f;
        }

        if (IsKeyPressed(KEY_DOWN))
        {
            idoSzorzo /= 2.0f;
            if (idoSzorzo < 0.125f)
                idoSzorzo = 0.125f;
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            szunet = !szunet;
        }

        if (!szunet)
        {
            float szimlacioIdo = elteltIdo * idoSzorzo;
            fold.szog += fold.sebesseg * szimlacioIdo;
            mars.szog += mars.sebesseg * szimlacioIdo;
            merkur.szog += merkur.sebesseg * szimlacioIdo;
            venus.szog += venus.sebesseg * szimlacioIdo;
            uranus.szog += uranus.sebesseg * szimlacioIdo;
            neptune.szog += neptune.sebesseg * szimlacioIdo;
            jupiter.szog += jupiter.sebesseg * szimlacioIdo;
            saturn.szog += saturn.sebesseg * szimlacioIdo;
        }

        Vector2 foldPozicio{
            kozepX + std::cos(fold.szog) * fold.palyaSugar,
            kozepY + std::sin(fold.szog) * fold.palyaSugar
        };

        Vector2 marsPozicio{
            kozepX + std::cos(mars.szog) * mars.palyaSugar,
            kozepY   + std::sin(mars.szog) * mars.palyaSugar
        };

        Vector2 merkurPozicio{
            kozepX + std::cos(merkur.szog) * merkur.palyaSugar,
            kozepY   + std::sin(merkur.szog) * merkur.palyaSugar
        };

        Vector2 venusPozicio{
            kozepX + std::cos(venus.szog) * venus.palyaSugar,
            kozepY   + std::sin(venus.szog) * venus.palyaSugar
        };

        Vector2 uranusPozicio{
            kozepX + std::cos(uranus.szog) * uranus.palyaSugar,
            kozepY   + std::sin(uranus.szog) * uranus.palyaSugar
        };

        Vector2 neptunePozicio{
            kozepX + std::cos(neptune.szog) * neptune.palyaSugar,
            kozepY   + std::sin(neptune.szog) * neptune.palyaSugar
        };

        Vector2 jupiterPozicio{
            kozepX + std::cos(jupiter.szog) * jupiter.palyaSugar,
            kozepY   + std::sin(jupiter.szog) * jupiter.palyaSugar
        };

        Vector2 saturnPozicio{
            kozepX + std::cos(saturn.szog) * saturn.palyaSugar,
            kozepY   + std::sin(saturn.szog) * saturn.palyaSugar
        };

        BeginDrawing();
        ClearBackground(Color{8, 12, 25, 255});

        DrawCircleLines(kozepX, kozepY, fold.palyaSugar, DARKGRAY);
        DrawCircleLines(kozepX, kozepY, mars.palyaSugar, DARKGRAY);
        DrawCircleLines(kozepX, kozepY, merkur.palyaSugar, DARKGRAY);
        DrawCircleLines(kozepX, kozepY, venus.palyaSugar, DARKGRAY);
        DrawCircleLines(kozepX, kozepY, uranus.palyaSugar, DARKGRAY);
        DrawCircleLines(kozepX, kozepY, neptune.palyaSugar, DARKGRAY);
        DrawCircleLines(kozepX, kozepY, jupiter.palyaSugar, DARKGRAY);
        DrawCircleLines(kozepX, kozepY, saturn.palyaSugar, DARKGRAY);

        DrawCircle(kozepX, kozepY, 45, GOLD);
        DrawCircleV(foldPozicio, fold.sugar, fold.szin);
        DrawCircleV(marsPozicio, mars.sugar, mars.szin);
        DrawCircleV(merkurPozicio, merkur.sugar, merkur.szin);
        DrawCircleV(venusPozicio, venus.sugar, venus.szin);
        DrawCircleV(uranusPozicio, uranus.sugar, uranus.szin);
        DrawCircleV(neptunePozicio, neptune.sugar, neptune.szin);
        DrawCircleV(jupiterPozicio, jupiter.sugar, jupiter.szin);
        DrawCircleV(saturnPozicio, saturn.sugar, saturn.szin);

        DrawText(
            szunet ? "SZUNET | SPACE: continue" : "SPACE: pause",
            20, 20, 20, WHITE
        );
        DrawText(
            TextFormat("Ido: %.3fx | UP / DOWN: speed", idoSzorzo),
            20, 50, 20, WHITE
        );

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
