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
#define WINDOW_NAME "xXx_KEr3llE_xXx"

#define BACKGROUND_COLOR (sfColor) {20, 20, 20, 255}
#define SUBWINDOW_COLOR (sfColor) {30, 30, 30, 255}
#define SELECTOR_COLOR (sfColor) {70, 70, 70, 255}
#define SELECTOR_COLOR_HOVER (sfColor) {50, 50, 50, 255}
#define SELECTOR_COLOR_CLICKED (sfColor) {40, 40, 40, 255}
#define SELECTOR_MIDDLE_COLOR (sfColor) {60, 60, 60, 255}

#define DRAW_CREDITS_TEXT ("\
Development:\n    \
-  Paul BUGEON\n    \
-  Yoann LE espace PECH\n    \
-  Jamil ETTEL\n    \
-  Tristan BOUILLOT\n\
\n\
Music:\n\
    - Benjamin DESIGAUX (BROME)\n\n\
All code is made with <3")
#define DRAW_HELP_TEXT "To play THE Corewar :\n\n\n\
FIRST :\n       \
Press the fancy play button\n\n\
SECOND :\n       \
Choose the number of warrior/champion you \
will need for the battle\n\n\
THEN :\n       \
You can either create your own champion or\n       \
choose one of our best contestant \
(I suggest you choose one of ours)\n\n\n\
Last but not the least :\n       \
Have fun, this game was made for this after all !!! <3"
#define COREWAR_TEXT "Corewar"
#define BEGIN_TEXT "Begin the war"
#define HELP_TEXT "Help"
#define CREDITS_TEXT "Credits"
#define EXIT_TEXT "Exit"
#define MAIN_MENU_TEXT "Main menu"
#define NEXT_TEXT "Next"

#define NBR_ICONS 3
#define NBR_VIEWS 6

/*
** TYPEDEFS
*/

typedef struct coreflat cw_graph_t;
typedef struct window window_t;
typedef struct text text_t;
typedef struct icon icon_t;
typedef struct view view_t;
typedef struct game_settings game_settings_t;

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

struct view
{
    int view;
    bool (*fct)(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
};

struct game_settings
{
    int step;
    int corewar_launched;
    int nb_champions;
    int cycles_per_second;
    int pass_step;
    bool automatic_cps;
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
    game_settings_t g_setts;
};

/*
** PROTOTYPES
*/

// init
cw_graph_t *init_cw_graph(void);
view_t **views_fcts(void);

// starting
bool start_graphical_corewar(champion_t **champions, list_t *memory);
bool game_loop(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);

// drawing
void draw_interface(cw_graph_t *cw_graph, champion_t **champions);
void evolve_gradient(sfColor *gradient);
void draw_button(cw_graph_t *cw_graph, sfVector2f pos, sfColor color, char *text);
void draw_icons(cw_graph_t *cw_graph, champion_t **champions);
bool draw_corewar(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
bool draw_credits(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
void draw_pause(cw_graph_t *cw_graph);
bool draw_winner(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
bool draw_choose(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
bool draw_main_menu(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
bool draw_help(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
void draw_background(cw_graph_t *cw_graph);

//events
void manage_events(cw_graph_t *cw_graph);
void is_released(cw_graph_t *cw_graph);
void redirection(cw_graph_t *cw_graph, char *to);

//utils
char *int_to_str(int nb);
bool is_in_rect(cw_graph_t *cw_graph, sfVector2f pos, sfVector2f size);

// champions
bool load_all_champions(char *path, champion_t ***champions);



#endif /* !COREFLAT_H_ */
