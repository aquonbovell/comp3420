//
//  main.cpp
//  Project-01
//
//  Created by Aquon Bovell on 06/02/2024.
//
// 417002714.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This is a program that creates a space scene using the pngwriter library.
// The scene consists of a space ship, stars, planets, and buildings.
// The space ship is a triangle with a smoke trail. The stars are white diamonds.
// The planets are images of Saturn, a half moon, and a shooting star.
// The buildings are rectangles with windows.
// The space floor is a bezier curve with a fill color.
// I have used 38 functions from the pngwriter library to create the image.
// setgamma
// getheight
// getwidth
// filledsquare
// filleddiamond
// readfromfile
// scale_k
// dread
// plot
// dreadCMYK
// plotCMYK_blend
// flood_fill
// line
// polygon
// triangle
// square
// circle
// filledarrow
// plot_text_utf8
// filledtriangle
// diamond
// flood_fill_blend
// polygon_blend
// bezier
// line_blend
// plot_blend
// dreadHSV
// plotHSV
// scale_kxky
// settext
// pngwriter_rename
// plot_text_blend
// setcompressionlevel
// write_png
// plot_text
// filledsquare_blend
// boundary_fill
// filledcircle
#pragma warning (disable : 4996)
#include <pngwriter.h>

int main(int argc, const char * argv[])
{
    int height, width;
    pngwriter *dest = new pngwriter(786, 576, 1.0, "assignment-1.png");
    dest->setgamma(0.40);
    height = dest->getheight();
    width = dest->getwidth();

    double red = 29.0 / 255.0;
    double green = 39.0 / 255.0;
    double blue = 59.0 / 255.0;

    dest->filledsquare(1, 1, 786, 576, red, green, blue);

    // stars
    int offset = 0;
    for (int i = 0; i < 10; i++)
    {
        dest->filleddiamond(20, 550 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(50, 500 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(100, 520 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(150, 530 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(200, 510 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(250, 540 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(300, 510 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(350, 530 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(400, 520 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(450, 540 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(500, 510 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(550, 530 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(600, 520 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(650, 540 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(700, 510 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(750, 530 - offset, 1, 1, 1.0, 1.0, 1.0);
        dest->filleddiamond(780, 520 - offset, 1, 1, 1.0, 1.0, 1.0);
        offset += 40;
    }

    pngwriter *source = new pngwriter();

    source->readfromfile("saturn.png");
    source->scale_k(0.65);
    height = source->getheight();
    width = source->getwidth();
    for (int i = 1; i <= width; i++)
    {
        for (int j = 1; j <= height; j++)
        {
            red = source->dread(i, j, 1);
            green = source->dread(i, j, 2);
            blue = source->dread(i, j, 3);
            dest->plot(i + 250, j + 100, red, green, blue);
        }
    }
    source->close();

    source->readfromfile("shooting-stars.png");
    source->scale_k(0.15);
    height = source->getheight();
    width = source->getwidth();
    for (int i = 1; i <= width; i++)
    {
        for (int j = 1; j <= height; j++)
        {
            red = source->dreadCMYK(i, j, 1);
            green = source->dreadCMYK(i, j, 2);
            blue = source->dreadCMYK(i, j, 3);
            if (red == 0.0)
            {
                dest->plotCMYK_blend(i + 10, j + 455, 0.9, red, green, blue, 0.15);
            }
        }
    }
    source->close();

    source->readfromfile("ufo.png");
    source->scale_k(0.25);
    height = source->getheight();
    width = source->getwidth();
    for (int i = 1; i <= width; i++)
    {
        for (int j = 1; j <= height; j++)
        {
            red = source->dreadCMYK(i, j, 1);
            green = source->dreadCMYK(i, j, 2);
            blue = source->dreadCMYK(i, j, 3);
            dest->plotCMYK_blend(i + 10, j + 300, 0.9, red, green, blue, 0.15);
        }
    }
    source->close();

    source->readfromfile("half-moon.png");
    source->scale_k(0.35);
    height = source->getheight();
    width = source->getwidth();
    for (int i = 1; i <= width; i++)
    {
        for (int j = 1; j <= height; j++)
        {
            red = source->dreadCMYK(i, j, 1);
            green = source->dreadCMYK(i, j, 2);
            blue = source->dreadCMYK(i, j, 3);
            dest->plotCMYK_blend(i + 250, j + 405, 0.9, red, green, blue, 0.15);
        }
    }
    source->close();

    dest->filleddiamond(350, 530 - 0, 1, 1, 1.0, 1.0, 1.0);
    dest->filleddiamond(400, 520 - 0, 1, 1, 1.0, 1.0, 1.0);
    
    // fill in the planet background color
    red = 29.0 / 255.0;
    green = 39.0 / 255.0;
    blue = 59.0 / 255.0;

    dest->flood_fill(251, 130, red, green, blue);
    dest->flood_fill(400, 101, red, green, blue);
    dest->flood_fill(12, 302, red, green, blue);
    dest->flood_fill(12, 412, red, green, blue);
    dest->flood_fill(401, 521, red, green, blue);

    // stars
    dest->filleddiamond(300, 510 - 120, 1, 1, 1.0, 1.0, 1.0);
    dest->filleddiamond(350, 530 - 120, 1, 1, 1.0, 1.0, 1.0);
    dest->filleddiamond(450, 540 - 120, 1, 1, 1.0, 1.0, 1.0);
    dest->filleddiamond(500, 510 - 120, 1, 1, 1.0, 1.0, 1.0);
    dest->filleddiamond(20, 550 - 240, 1, 1, 1.0, 1.0, 1.0);
    dest->filleddiamond(20, 550 - 200, 1, 1, 1.0, 1.0, 1.0);
    dest->filleddiamond(20, 550 - 160, 1, 1, 1.0, 1.0, 1.0);

    // antenna for the cicrle building
    for (int i = 0; i < 3; i++)
    {
        // globe 1
        dest->line(72 + i, 192, 72 + i, 220, .75, .0, .25);
        dest->line(72 + i, 220, 72 + i, 225, .35, .0, .25);
        dest->line(62 + i, 192, 62 + i, 205, .75, .0, .25);
        dest->line(62 + i, 205, 62 + i, 210, .35, .0, .25);
        // globe 2
        dest->line(676 + i, 330, 676 + i, 338, .75, .0, .25);
        dest->line(676 + i, 338, 676 + i, 342, .35, .0, .25);
        dest->line(670 + i, 330, 670 + i, 342, .75, .0, .25);
        dest->line(670 + i, 342, 670 + i, 346, .35, .0, .25);
        // globe 3
        dest->line(727 + i, 210, 727 + i, 240, .75, .0, .25);
        dest->line(727 + i, 240, 727 + i, 245, .35, .0, .25);
        dest->line(720 + i, 210, 720 + i, 220, .75, .0, .25);
        dest->line(720 + i, 220, 720 + i, 235, .35, .0, .25);
    }

    // ===== Buildings =====
    // building colors
    red = 44.0 / 255.0;
    green = 14.0 / 255.0;
    blue = 40.0 / 255.0;

    // building 4
    dest->filledsquare(227, 94, 267, 320, red, green, blue);
    offset = 0;
    for (int i = 0; i < 32; i++)
    {
        int offsetX = 0;
        for (int j = 0; j < 6; j++)
        {
            dest->filleddiamond(230 + offsetX, 100 + offset, 3, 3, 101.0 / 255.0, 148.0 / 255.0, 222.0 / 255.0);
            offsetX += 7;
        }
        offset += 7;
    }
    dest->filledsquare(230, 321, 264, 326, red, green, blue);
    dest->filledsquare(230, 327, 264, 328, .75, .0, .25);

    // building 3
    int points[10] = { 186, 94, 226, 94, 226, 280, 186, 250, 186, 94 };
    dest->polygon(points, 5, red - .175, green, blue);
    dest->flood_fill(207, 200, red - .75, green, blue);
    dest->filledsquare(190, 240, 210, 242, 59.0 / 255.0 , 215.0 / 255.0 , 255.0 / 255.0);
    dest->filledsquare(218, 240, 220, 242, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(209, 200, 220, 202, 59.0 / 255.0 , 215.0 / 255.0 , 255.0 / 255.0);
    dest->filledsquare(199, 200, 205, 202, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(189, 160, 198, 162, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(200, 160, 224, 162, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(189, 120, 191, 122, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(210, 120, 212, 122, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);

    // building 2
    dest->filledsquare(116, 94, 156, 230, red, green, blue);
    offset = 0;
    for (int i = 0; i < 22; i++)
    {
        int offsetX = 0;
        for (int j = 0; j < 6; j++)
        {
            dest->filleddiamond(119 + offsetX, 100 + offset, 3, 3, 101.0 / 255.0, 148.0 / 255.0, 222.0 / 255.0);
            offsetX += 7;
        }
        offset += 6;
    }
    dest->filledsquare(119, 231, 153, 236, red, green, blue);
    dest->filledsquare(119, 237, 153, 238, .75, .0, .25);
    // globe 1
    dest->circle(70, 162, 30, red - 1, green, blue);
    dest->flood_fill(71, 162, red - 1, green, blue);
    dest->square(65, 120, 75, 138, red - 1.25, green, blue);
    dest->flood_fill(70, 130, red - 1.25, green, blue);

    // building 1 - small // sign Welcome
    dest->square(40, 94, 105, 120, red, green, blue);
    dest->flood_fill(50, 110, red, green, blue);
    dest->filledarrow(50, 113, 95, 113,9, 0.5236, 194.0/ 255.0 , 16.0 / 255.0, 180.8/ 255.0);
    std::string text = "Welcome";
    std::string font = "FiraCodeNerdFontPropo-SemiBold.ttf";
    char* textPath = new char[text.size() + 1];
    char* fontPath = new char[font.size() + 1];
    std::strcpy(textPath, text.c_str());
    std::strcpy(fontPath, font.c_str());
    //dest->plot_text_utf8(fontPath, 8, 50, 100, 0.0, textPath, 194.0 / 255.0, 16.0 / 255.0, 180.8 / 255.0);

    // building 5
    dest->filledsquare(280, 94, 320, 300, red - .1, green, blue);
    dest->filledsquare(282, 290, 310, 292, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(315, 290, 318, 292, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(290, 220, 306, 222, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(285, 260, 300, 262, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(300, 200, 310, 202, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(290, 160, 224, 162, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(282, 120, 308, 122, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(286, 140, 306, 142, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);

    // building 6
    dest->filledsquare(310, 94, 360, 250, red, green, blue);
    dest->filledsquare(310, 251, 360, 251, .75, .0, .25);
    offset = 0;
    for (int i = 0; i < 25; i++)
    {
        int offsetX = 0;
        for (int j = 0; j < 7; j++)
        {
            dest->filleddiamond(313 + offsetX, 100 + offset, 3, 3, 101.0 / 255.0, 148.0 / 255.0, 222.0 / 255.0);
            offsetX += 7;
        }
        offset += 6;
    }

    // building 7
    dest->filledsquare(360, 94, 390, 200, red + .1, green, blue);
    dest->filledsquare(363, 176, 379, 178, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(382, 176, 388, 178, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(363, 136, 370, 138, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(372, 136, 388, 138, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);

    // building 8
    dest->filledsquare(395, 94, 430, 330, red - .05, green, blue);
    dest->filledtriangle(395, 330, 430, 330, 430, 350, red - .05, green, blue);
    dest->filledtriangle(429, 353, 405, 368, 405, 338, red - .05, green, blue);
    dest->filledtriangle(405, 371, 418, 362, 418, 378, red - .05, green, blue);
    dest->filledsquare(397, 326, 402, 328, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(406, 326, 408, 328, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(416, 326, 428, 328, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(400, 286, 418, 288, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(397, 226, 418, 228, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(397, 151, 418, 153, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(397, 146, 418, 148, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);

    // building 10
    dest->filledsquare(450, 94, 490, 200, red - .05, green, blue);
    dest->filledsquare(473, 190, 485, 192, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(453, 143, 487, 145, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);

    // building 9
    dest->filledsquare(411, 94, 460, 296, red, green, blue);
    dest->filledsquare(414, 297, 457, 302, red, green, blue);
    dest->filledsquare(414, 303, 457, 304, .75, .0, .25);
    offset = 0;
    for (int i = 0; i < 33; i++)
    {
        int offsetX = 0;
        for (int j = 0; j < 7; j++)
        {
            dest->filleddiamond(414 + offsetX, 100 + offset, 3, 3, 101.0 / 255.0, 148.0 / 255.0, 222.0 / 255.0);
            offsetX += 7;
        }
        offset += 6;
    }

    // building 11
    dest->filledsquare(490, 94, 530, 300, red, green, blue);
    dest->filledtriangle(490, 300, 490, 320, 530, 300, red, green, blue);
    dest->filledsquare(493, 290, 527, 292, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(510, 250, 520, 252, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(493, 250, 507, 252, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(520, 200, 527, 202, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(496, 150, 517, 152, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(509, 146, 527, 148, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);

    // building 12
    dest->filledsquare(530, 94, 570, 250, red + .06, green, blue);
    dest->filledtriangle(530, 250, 530, 280, 570, 250, red + .06, green, blue);
    dest->filledsquare(533, 250, 541, 252, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(538, 250, 557, 252, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(553, 200, 567, 202, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(556, 150, 562, 152, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(533, 146, 557, 148, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(545, 112, 555, 114, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);

    // building 13
    dest->filledsquare(590, 94, 650, 195, red, green, blue);
    dest->filledsquare(593, 188, 611, 190, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
    dest->filledsquare(618, 188, 647, 190, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(613, 148, 627, 150, 252.0 / 255.0, 33.0 / 255.0, 97.0 / 255.0);
    dest->filledsquare(633, 108, 647, 110, 59.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);

    // globe 2
    dest->filledcircle(673, 300, 30, red, green, blue);
    dest->filledsquare(670, 94, 676, 280, red, green, blue);

    // globe 3
    dest->filledcircle(724, 170, 40, red - 1.5, green, blue);
    dest->filledsquare(720, 94, 728, 160, red - 1.5, green, blue);

    // ===== GlobeWindows =====

    // globe 1
    red = 101.0 / 255.0;
    green = 148.0 / 255.0;
    blue = 222.0 / 255.0;

    offset = 0;
    for (int i = 0; i < 8; i++)
    {
        dest->diamond(43 + offset, 165, 5, 5, red, green, blue);
        dest->flood_fill(43 + offset, 165, red, green, blue);
        offset += 8;
    }

    // globe 2
    offset = 0;
    for (int i = 0; i < 7; i++)
    {
        dest->diamond(650 + offset, 305, 5, 5, red, green, blue);
        dest->flood_fill(650 + offset, 305, red, green, blue);
        offset += 8;
    }

    offset = 0;
    for (int i = 0; i < 6; i++)
    {
        dest->diamond(654 + offset, 298, 5, 5, red, green, blue);
        dest->flood_fill(654 + offset, 298, red, green, blue);
        offset += 8;
    }

    // globe 3
    offset = 0;
    for (int i = 0; i < 9; i++)
    {
        dest->diamond(693 + offset, 180, 5, 5, red, green, blue);
        dest->flood_fill(693 + offset, 180, red, green, blue);
        offset += 8;
    }

    offset = 0;
    for (int i = 0; i < 9; i++)
    {
        dest->diamond(693 + offset, 170, 5, 5, red, green, blue);
        dest->flood_fill(693 + offset, 170, red, green, blue);
        offset += 8;
    }

    // roof
    red = 58.0 / 255.0;
    green = 218.0 / 255.0;
    blue = 255.0 / 255.0;

    for (int i = 0; i < 4; i++)
    {
        dest->line(226, 280 - i, 186, 250 - i, red, green, blue);
        dest->line(430, 353 - i, 395, 334 - i, red, green, blue);
        dest->line(430, 353 - i, 405, 370 - i, red, green, blue);
        dest->line(405, 373 - i, 418, 379 - i, red, green, blue);
        dest->line(530, 303 - i, 490, 323 - i, red, green, blue);
        dest->line(530, 283 - i, 570, 253 - i, red, green, blue);
    }

    // space ship
    dest->triangle(70, 448, 85, 438, 85, 454, 0.0, 0.0, 0.0);
    dest->boundary_fill(72, 448, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    dest->flood_fill_blend(72, 448, 0.40, 1.0, 0.0, 0.0);
    points[0] = 86;
    points[1] = 453;
    points[2] = 86;
    points[3] = 439;
    points[4] = 140;
    points[5] = 430;
    points[6] = 140;
    points[7] = 460;
    points[8] = 86;
    points[9] = 453;

    // smoke trail
    dest->polygon_blend(points, 5,.6, red * 56, green, blue);
    dest->flood_fill_blend(138, 453, .6, red * 56, green, blue);

    red = 54.0 / 255.0;
    green = 54.0 / 255.0;
    blue = 79.0 / 225.0;

    // space floor
    dest->filledsquare_blend(1, 1, 786, 90, .8, red, green, blue);

    red = 29.0 / 255.0;
    green = 39.0 / 255.0;
    blue = 59.0 / 255.0;

    dest->bezier(1, 9, 60, 40, 786, 9, 726, 40, red, green, blue);
    dest->bezier(1, 46, 80, 60, 786, 46, 706, 60, red, green, blue);
    dest->line_blend(1, 20, 96, 90, .6, red, green, blue);
    dest->line_blend(786, 20, 690, 90, .6, red, green, blue);
    dest->line_blend(90, 1, 206, 90, .6, red, green, blue);
    dest->line_blend(696, 1, 576, 90, .6, red, green, blue);
    dest->line_blend(215, 1, 280, 90, .6, red, green, blue);
    dest->line_blend(571, 1, 506, 90, .6, red, green, blue);
    dest->line_blend(330, 1, 370, 90, .6, red, green, blue);
    dest->line_blend(456, 1, 416, 90, .6, red, green, blue);

    // space mist
    red = 217.0 / 255.0;
    green = 13.0 / 255.0;
    blue = 75.0 / 255.0;

    for (int j = 1; j <= 93; j++)
    {
        double blender = static_cast<double>(j) / 93; // Adjust blender based on the current row
        for (int i = 1; i < dest->getwidth(); i++)
        {
            dest->plot_blend(i, j, blender, red, green, blue);
        }
    }

    for (int j = 0; j <= 180; j++)
    {
        double blender = static_cast<double>(j) / 180; // Adjust blender based on the current row
        for (int i = 1; i < dest->getwidth(); i++)
        {
            dest->plotHSV_blend(i, j + 93,1 - blender, 345.429, 0.958824, 0.843137);
        }
    }
    text = "City In Space";
    font = "FiraCodeNerdFontPropo-SemiBold.ttf";
    textPath = new char[text.size() + 1];
    fontPath = new char[font.size() + 1];
    std::strcpy(textPath, text.c_str());
    std::strcpy(fontPath, font.c_str());
    //dest->plot_text(fontPath, 18, 50, 536, 0.0, textPath, 0,0,0);
    source->readfromfile("rocket-ship.png");
    source->scale_kxky(.45, .3);
    height = source->getheight();
    width = source->getwidth();
    for (int i = 1; i <= width; i++)
    {
        for (int j = 1; j <= height; j++)
        {
            red = source->dreadHSV(i, j, 1);
            green = source->dreadHSV(i, j, 2);
            blue = source->dreadHSV(i, j, 3);
            if (green != 0.0)
            {
                dest->plotHSV(i + 500, j + 375, red, green, blue);
            }
        }
    }
    dest->pngwriter_rename("417002714.png");
    dest->settext("Space City", "Aquon Bovell", "The is my abstract space city", "PngWriter");
    text = "Aquon Bovell";
    textPath = new char[text.size() + 1];
    std::strcpy(textPath, text.c_str());
    //dest->plot_text_blend(fontPath, 16, 1, 4, 0.0, textPath, 0.8, 0.5, 0.5, 0.5);
    text = "417002714";
    textPath = new char[text.size() + 1];
    std::strcpy(textPath, text.c_str());
    dest->plot_text_blend(fontPath, 16, 650, 4, 0.0, textPath, 0.8, 0.5, 0.5, 0.5);
    dest->setcompressionlevel(9);
    dest->write_png();
    dest->close();
    return 0;
}
