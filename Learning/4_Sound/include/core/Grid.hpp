#pragma once

class Grid
{
protected:
    int m_width;
    int m_height;

    int index(int x, int y) const
    {
        return y * m_width + x;
    }

public:
    int width() const { return m_width; }
    int height() const { return m_height; }
};
