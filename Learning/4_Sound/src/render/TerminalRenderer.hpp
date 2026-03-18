#pragma once

#include "IRenderer.hpp"

class TerminalRenderer : public IRenderer
{
public:
    void clear() override;
    void present() override;
    void drawMap(const Map& map) override;
};
