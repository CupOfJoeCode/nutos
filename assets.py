import pygame as pg

pg.init()


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

icon = pg.image.load("assets/icon.png")
out_c = "unsigned char splash_icon[] = { "

for y in range(25):
    for x in range(25):
        rgb = icon.get_at((x, y))[:3]
        alpha = icon.get_at((x, y))[3]
        if alpha < 128:
            out_c += "255, "
            continue
        lowest_dif = 9999
        lowest_index = 0
        for i in range(16):
            total_dif = 0
            for real, c in zip(rgb, colors[i]):
                total_dif += abs(real - c)
            if total_dif < lowest_dif:
                lowest_dif = total_dif
                lowest_index = i
        out_c += f"{lowest_index}, "

with open("src/splash.h", "w") as fp:
    fp.write(out_c + "};")
