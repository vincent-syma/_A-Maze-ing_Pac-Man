#pragma once

#include "IRenderer.hpp"

class SDLRenderer : public IRenderer
{
public:
    void clear() override;
    void present() override;
    void drawMap(const Map&) override;
};
