#pragma once

class Game
{
public:
    virtual ~Game() {}

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};
