/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** configuration
*/

#ifndef CONFIGURATION_H_
    #define CONFIGURATION_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "paint/types.h"
    #include "paint/dependencies.h"

///////////////////////////////////////////////////////////////////////////////
// WINDOW CONFIGURATION

    #define WIN_WIDTH 1920
    #define WIN_HEIGHT 1080
    #define WIN_BITS 32
    #define WIN_MODE ((sfVideoMode){WIN_WIDTH, WIN_HEIGHT, WIN_BITS})
    #define WIN_STYLE (sfClose)
    #define WIN_TITLE "MyPaint"
    #define WIN_FPS 60
    #define WIN_CENTERED true
    // (ASSETS_PATH "icon.png")
    #define WIN_ICON NULL

    #define WIN_MIN_WIDTH 800
    #define WIN_MIN_HEIGHT 600
    #define WIN_MAX_WIDTH 1920
    #define WIN_MAX_HEIGHT 1080

    #define VIEW_WIDTH 512
    #define VIEW_HEIGHT 288

    #define TXT_NW "New...                       "
    #define TXT_OP "Open...                     "
    #define TXT_SV "Save                         "
    #define TXT_SA "Save as                 > "
    #define TXT_EA "Export as             > "

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ASSETS CONFIGURATION

    // DEFAULT ASSETS LOCATION
    #define ASSETS_PATH "assets/"

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// CANVA CONFIGURATION

    #define CANVA_MAX_ZOOM 64.0f
    #define CANVA_MIN_ZOOM 1 / 128.0f
    #define MAX_STACK_SIZE 10000000
    #define ZOOM_SPEED 20

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// COLOR CONFIGURATION

    #define RGB sfColor_fromRGB
    #define RGBA sfColor_fromRGBA

    #define COLOR_BASE RGB(71, 71, 71)
    #define COLOR_BG_PANEL RGB(37, 37, 37)
    #define COLOR_BG_CANVA RGB(37, 37, 37)
    #define COLOR_BG_INPUT RGB(37, 37, 37)
    #define COLOR_BG_BTN RGB(93, 93, 93)
    #define COLOR_BG_BTN_HOVER RGB(106, 106, 106)
    #define COLOR_BORDER RGB(37, 37, 37)
    #define COLOR_TEXT RGB(213, 213, 213)
    #define COLOR_BORDER_LIGHT RGBA(255, 255, 255, 0.15)
    #define COLOR_BORDER_DARK RGBA( 0, 0, 0, 0.6)
    #define COLOR_ACCENT RGB(52, 130, 246)
    #define COLOR_SH RGBA(0, 0, 0, 0.45)

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// SIZE CONFIGURATION

    #define UI_TOOLBAR_W 60
    #define UI_PAD MID(60, 46)
    #define UI_CONTEXT_W WIN_WIDTH
    #define UI_CONTEXT_H 42
    #define UI_TOOL_W 46
    #define UI_TOOL_H 46
    #define UI_TOOL_ICON_W 32
    #define UI_TOOL_ICON_H 32
    #define UI_TOOLBAR_H (WIN_HEIGHT - UI_TOOL_H - UI_CONTEXT_H)
    #define UI_LAYERS_W 300
    #define UI_LAYERS_H UI_TOOLBAR_H
    #define UI_DROPDOWN_W 200

///////////////////////////////////////////////////////////////////////////////

#endif /* !CONFIGURATION_H_ */
