#ifndef POSITION_HPP
#define POSITION_HPP

struct Position
{
    int x;
    int y;
    int z;
    Position(int x, int y, int z): x(x), y(y), z(z) {};
    ~Position() {
        std::cout << "Position is destroyed.\n";
    }
};

#endif
