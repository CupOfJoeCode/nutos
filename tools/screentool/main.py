import pygame as pg

pg.init()
TILE_WIDTH = 9
TILE_HEIGHT = 16


def value(channel, brightness):
    return channel * 170 + (brightness * 85)


colors = []
for i in range(16):
    rgb = i & 0b111
    r = rgb >> 2
    g = (rgb >> 1) & 1
    b = rgb & 1
    n = i >> 3
    if i == 6:
        colors.append([value(r, 0), value(0, 1), 0])
    else:
        colors.append([value(r, n), value(g, n), value(b, n)])
