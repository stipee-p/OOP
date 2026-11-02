// Vjezba 5, zadatak 1: napisite klasu Volume iznad main.

#include <cassert>
#include <iostream>

// ovdje napisite klasu Volume
class Volume {
    int level;
    int before_mute;

    static int lvl(int l) {
        if (l < 0)
            return 0;
        if (l > 100)
            return 100;
        return l;
    }
private:
    bool valid() const {
        return level >= 0 && level <= 100;
    }

public:
    Volume(int l) : level(lvl(l)), before_mute(50) {
    assert(valid());
    }

    Volume() : Volume(50) {}

    int get(){
        return level;
    }

    void up(int step = 10) {
        level = lvl(level + step);
        before_mute = level;
        assert(valid());
    }

    void down(int step = 10)
    {
        level = lvl(level - step);
        before_mute = level;
        assert(valid());
    }

    void mute() {
        if (level != 0) {
            before_mute = level;
        }
        level = 0;
        assert(valid());
    }

    void unmute() {
        level = before_mute;
        assert(valid());
    }
};


int main()
{
    Volume v;
    std::cout << v.get() << '\n';
    v.up();
    v.up(60);
    std::cout << v.get() << '\n';
    v.mute();
    std::cout << v.get() << '\n';
    v.unmute();
    std::cout << v.get() << '\n';
    Volume w(-20);
    w.down();
    std::cout << w.get() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    50
    100
    0
    100
    0
*/
