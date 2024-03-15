/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** event
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Parses mouse events and updates the state accordingly.
///
/// \param evt The SFML event to be parsed.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void parse_mouse_events(sfEvent evt)
{
    DOIF(evt.type == sfEvtClosed, sfRenderWindow_close(Win->self));
    if (evt.type == sfEvtMouseButtonPressed) {
        DOIF(evt.mouseButton.button == sfMouseLeft,
            EQ2(Tool->mousePressed, true));
        Tool->focus = NULL;
    }
    if (evt.type == sfEvtMouseButtonReleased)
        DOIF(evt.mouseButton.button == sfMouseLeft,
            EQ2(Tool->mousePressed, 0));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Parses keyboard events and updates the state accordingly.
///
/// \param evt The SFML event to be parsed.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void parse_keyboard_events(sfEvent evt)
{
    input_t *i = Tool->focus ? Tool->focus->input : NULL;
    sfKeyCode c = evt.key.code;
    bool shift = PRESSED(sfKeyLShift) || PRESSED(sfKeyRShift);

    RETURN(evt.type != sfEvtKeyPressed || i == NULL, (void)0);
    if (c >= sfKeyNum0 && c <= sfKeyNum9)
        my_buffchar(i->content, c - sfKeyNum0 + '0');
    if (c >= sfKeyNumpad0 && c <= sfKeyNumpad9)
        my_buffchar(i->content, c - sfKeyNumpad0 + '0');
    if (c == sfKeySlash)
        my_buffchar(i->content, shift ? '/' : ':');
    if ((c >= sfKeyA && c <= sfKeyZ) && i->type == e_input_alphanum)
        my_buffchar(i->content, shift ? c - sfKeyA + 'A' : c - sfKeyA + 'a');
    if ((c == sfKeyDelete || c == sfKeyBack) && i->content->size != 0) {
        i->content->content = my_realloc(i->content->content,
            i->content->size);
        i->content->size--;
        i->content->content[i->content->size] = '\0';
    }
    Tool->focus->onInput(Tool->focus);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculates the new scale factor based on the given zoom delta.
///
/// This function computes the new scale factor for a canvas based on the
/// provided zoom delta, current scale, and predefined zoom limits. The zoom
/// factor is applied to both the X and Y axes independently.
///
/// \param delta The zoom delta indicating the change in zoom level.
/// \param scale The current scale of the canvas.
/// \return The new scale factor after applying the zoom delta.
///
///////////////////////////////////////////////////////////////////////////////
vec2f get_scale_factor(float delta, vec2f scale)
{
    float zoomFactor = 1.0f + delta / 10.0f;
    float newScaleX = CLAMP(scale.x * zoomFactor, CANVA_MIN_ZOOM,
        CANVA_MAX_ZOOM);
    float newScaleY = CLAMP(scale.y * zoomFactor, CANVA_MIN_ZOOM,
        CANVA_MAX_ZOOM);

    return (VEC2(newScaleX, newScaleY));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Parses the mouse wheel scroll event to handle zooming and scrolling.
///
/// This function is responsible for interpreting the mouse wheel scroll event
/// and adjusting the canvas scale and position accordingly for zooming and
/// scrolling. It takes into account modifier keys (Ctrl and Alt) for different
/// behaviors.
///
/// \param scroll The mouse wheel scroll event.
///
///////////////////////////////////////////////////////////////////////////////
static void parse_scroll(sfMouseWheelScrollEvent scroll)
{
    canvas_t *c = Tool->canva;
    bool ctrl = PRESSED(sfKeyLControl) || PRESSED(sfKeyRControl);
    bool alt = PRESSED(sfKeyLAlt) || PRESSED(sfKeyRAlt);
    vec2f mousePosition = TV2(scroll);
    vec2f canvasMousePosition = Vec2.subtract(mousePosition,
        Tool->canva->position);
    vec2f newScale = get_scale_factor(scroll.delta, c->scale);

    if (alt && scroll.wheel == 0) {
        c->position = Vec2.subtract(mousePosition,
            Vec2.multiply(canvasMousePosition, newScale.x / c->scale.x));
        c->scale = newScale;
    }
    RETURN(alt, (void)0);
    if ((scroll.wheel == 0 && ctrl) || (scroll.wheel == 1 && !ctrl))
        Tool->canva->position.x += scroll.delta * ZOOM_SPEED;
    else
        Tool->canva->position.y += scroll.delta * ZOOM_SPEED;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Handles various events, updating the tool state.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void events(void)
{
    sfEvent evt;

    Tool->oldMousePos = Tool->mousePos;
    Tool->mousePos = sfMouse_getPositionRenderWindow(Win->self);
    while (sfRenderWindow_pollEvent(Win->self, &evt)) {
        parse_mouse_events(evt);
        parse_keyboard_events(evt);
        DOIF(evt.type == sfEvtMouseWheelScrolled && !Win->cursorOnWidget,
            parse_scroll(evt.mouseWheelScroll));
    }
}
