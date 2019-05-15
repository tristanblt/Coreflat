/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** coreflat
*/

#ifndef COREFLAT_H_
#define COREFLAT_H_

/*
** INCLUDES
*/

#include <string.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "corewar.h"

/*
** DEFINES
*/

#define FRAMERATE_LIMIT 120
#define WINDOW_NAME "CoreFlat"

#define BACKGROUND_COLOR (sfColor) {20, 20, 20, 255}
#define SUBWINDOW_COLOR (sfColor) {30, 30, 30, 255}

#define CREDITS_TEXT "Credits"
#define DRAW_CREDITS_TEXT ("\
Development:\n    \
-  Paul BUGEON\n    \
-  Yoann LE-PECH\n    \
-  Jamil ETTEL\n    \
-  Tristan BOUILLOT\n\
\n\
Music:\n\
    - Benjamin DESIGAUX (BROME)")
#define COREWAR_TEXT "Corewar"

#define NBR_ICONS 3

/*
** TYPEDEFS
*/

typedef struct coreflat cw_graph_t;
typedef struct window window_t;
typedef struct text text_t;
typedef struct icon icon_t;

/*
** STRUCTS
*/

struct window
{
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
};

struct text
{
    sfFont *font;
    sfText *text;
};

struct icon
{
    sfSprite *sprite;
    sfTexture *texture;
};


struct coreflat
{
    window_t *window;
    sfRectangleShape *interface;
    sfCircleShape *buttons;
    icon_t **icons;
    sfColor interface_gradient;
    text_t text;
    bool is_released;
    int current_view;
};

/*
** PROTOTYPES
*/

// init
cw_graph_t *init_cw_graph(void);

// starting
bool start_graphical_corewar(champion_t **champions, list_t *memory);
bool game_loop(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);

// drawing
void draw_interface(cw_graph_t *cw_graph, champion_t **champions);
void evolve_gradient(sfColor *gradient);
void draw_button(cw_graph_t *cw_graph, sfVector2f pos, sfColor color, char *text);
void draw_icons(cw_graph_t *cw_graph, champion_t **champions);
void draw_credits(cw_graph_t *cw_graph);
bool draw_corewar(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);

//events
void manage_events(cw_graph_t *cw_graph);
void is_released(cw_graph_t *cw_graph);

//utils
char *int_to_str(int nb);


#endif /* !COREFLAT_H_ */
