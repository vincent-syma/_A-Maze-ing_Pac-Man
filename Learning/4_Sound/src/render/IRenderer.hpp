#pragma once

class Map;

class IRenderer
{
public:
    virtual ~IRenderer(){}

    virtual void clear() = 0;
    virtual void present() = 0;
    virtual void drawMap(const Map&) = 0;
};
