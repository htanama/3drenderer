#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

typedef enum cull_method {
    CULL_NONE,
    CULL_BACKFACE,
	CULL_FRONTFACE
}CullMethod;

// Declare the variable (only a declaration, not a definition)
extern CullMethod cull_method;

typedef enum render_method {
    RENDER_WIRE,
    RENDER_WIRE_VERTEX,
    RENDER_FILL_TRIANGLE,
    RENDER_FILL_TRIANGLE_WIRE,
    RENDER_TEXTURED,
    RENDER_TEXTURED_WIRE
}RenderMethod;

extern RenderMethod render_method;

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern uint32_t* color_buffer;
extern SDL_Texture* color_buffer_texture;
extern int window_width;
extern int window_height;

bool initialize_window(void);
void draw_grid(void);
void draw_pixel(int x, int y, uint32_t color);
void draw_line(int x0, int y0, int x1, int y1, uint32_t color);
void draw_rect(int x, int y, int width, int height, uint32_t color);
void render_color_buffer(void);
void clear_color_buffer(uint32_t color);
void destroy_window(void);

#endif
