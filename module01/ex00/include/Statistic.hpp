#ifndef STATISTIC_HPP
#define STATISTIC_HPP

struct Statistic
{
    int level;
    int exp;

    Statistic(int level, int exp): level(level), exp(exp) {};
    Statistic(int level) {
        this->level = level;
        this->exp = level * 0.02;
    };
};

#endif
