/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** bucket
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
// STACK

static vec2i stack[MAX_STACK_SIZE];
static int stackIndex;

///////////////////////////////////////////////////////////////////////////////
/// \brief Pushes a point onto the stack.
///
/// \param p The point to be pushed onto the stack.
///
/// This function pushes the specified point onto the stack if the stack is not
/// full.
///
///////////////////////////////////////////////////////////////////////////////
static void push(vec2i p)
{
    if (stackIndex < MAX_STACK_SIZE)
        stack[INC1(stackIndex)] = p;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Pops a point from the stack.
///
/// \return The point popped from the stack.
///
/// This function pops a point from the stack if the stack is not empty. If the
/// stack is empty, it returns a point with coordinates (-1, -1).
///
///////////////////////////////////////////////////////////////////////////////
static vec2i pop(void)
{
    if (stackIndex > 0)
        return (stack[DEC1(stackIndex)]);
    return ((vec2i){-1, -1});
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Checks if the stack is empty.
///
/// \return True if the stack is empty, false otherwise.
///
/// This function returns true if the stack is empty, indicating that it does
/// not contain any points.
///
///////////////////////////////////////////////////////////////////////////////
static bool stack_is_empty(void)
{
    return (stackIndex == 0);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Checks if two colors are equal.
///
/// \param a The first color.
/// \param b The second color.
/// \return True if the colors are equal, false otherwise.
///
/// This function compares two colors and returns true if they are equal, and
/// false otherwise.
///
///////////////////////////////////////////////////////////////////////////////
static bool colors_equal(sfColor a, sfColor b)
{
    return ((a.r == b.r) && (a.g == b.g) && (a.b == b.b) && (a.a == b.a));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Performs flood fill algorithm on the canvas.
///
/// \param x The x-coordinate of the starting point.
/// \param y The y-coordinate of the starting point.
/// \param targetColor The color to be replaced.
/// \param fillColor The color to fill with.
///
/// This function performs the flood fill algorithm starting from the specified
/// point (x, y) on the canvas. It replaces the targetColor with the fillColor.
///
///////////////////////////////////////////////////////////////////////////////
static void flood_fill(int x, int y, sfColor targetColor, sfColor fillColor)
{
    vec2i current;
    canvas_t *c = Tool->canva;

    push((vec2i){x, y});
    while (!stack_is_empty()) {
        current = pop();
        x = current.x;
        y = current.y;
        if (x >= 0 && x < (int)c->width && y >= 0 && y < (int)c->height &&
            colors_equal(getpixel(x, y), targetColor)) {
            setpixel(x, y, fillColor);
            push((vec2i){x + 1, y});
            push((vec2i){x - 1, y});
            push((vec2i){x, y + 1});
            push((vec2i){x, y - 1});
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Handles filling using the bucket tool.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void use_bucket_tool(void)
{
    canvas_t *c = Tool->canva;
    vec2f pos = VEC2(Tool->canva->position.x - ((c->width * c->scale.x) / 2),
        c->position.y - ((c->height * c->scale.y) / 2));
    vec2f mouse = Vec2.divide(Vec2.subtract(TV2(Tool->mousePos), pos),
        c->scale.x);
    int x = (int)mouse.x;
    int y = (int)mouse.y;
    sfColor targetColor = getpixel(x, y);

    stackIndex = 0;
    RETURN(colors_equal(targetColor, Tool->color), (void)0);
    flood_fill(x, y, targetColor, Tool->color);
    Tool->mousePressed = false;
}
