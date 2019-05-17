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
#include <SFML/Audio.h>
#include "corewar.h"

/*
** DEFINES
*/

#define FRAMERATE_LIMIT 120
#define WINDOW_NAME "CoreFlat"

#define BACKGROUND_COLOR ((sfColor){20, 20, 20, 255})
#define SUBWINDOW_COLOR ((sfColor){30, 30, 30, 255})
#define SELECTOR_COLOR ((sfColor){70, 70, 70, 255})
#define SELECTOR_COLOR_HOVE ((sfColor){50, 50, 50, 255})
#define SELECTOR_COLOR_CLICKED ((sfColor){40, 40, 40, 255})
#define SELECTOR_MIDDLE_COLOR ((sfColor){60, 60, 60, 255})

#define DRAW_CREDITS_TEXT ("\
Development:\n    \
-  Paul BUGEON\n    \
-  Yoann LE PECH\n    \
-  Jamil ETTEL\n    \
-  Tristan BOUILLOT\n\
\n\
Music:\n    \
- Benjamin DESIGAUX (BROME)\n\n\
All code is made with <3")
#define DRAW_HELP_TEXT "To play THE Corewar :\n\n\n\
FIRST :\n       \
Press the fancy play button\n\n\
SECOND :\n       \
Choose the number of warriors/champions you \
will need for the battle\n\n\
THEN :\n       \
You can either create your own champion or\n       \
choose one of our best contestants \
(I suggest you choose one of ours)\n\n\n\
Last but not least :\n       \
Have fun, this game was made for this after all !!! <3"
#define COREWAR_TEXT "Corewar"
#define BEGIN_TEXT "Begin the war"
#define HELP_TEXT "Help"
#define CREDITS_TEXT "Credits"
#define EXIT_TEXT "Exit"
#define MAIN_MENU_TEXT "Main menu"
#define MAIN_MENU_RES_TEXT "Main Menu"
#define NEXT_TEXT "Next"
#define NEXT_CHAMP_TEXT "Next champion"
#define PAUSE_TEXT "Pause"
#define PLAY_TEXT "Play"
#define SETTINGS_TEXT "Settings"
#define EDITOR_TEXT "Editor"
#define CHANGE_TYPE_TEXT "Change type"
#define EDIT_CHAMP_TEXT "Edit Champion"
#define LOAD_TEXT "Load Champion"
#define CREATE_CHAMPION "Create Champion"

#define NBR_ICONS 4
#define NBR_VIEWS 8

#define GAME_SPEED 5

/*
** TYPEDEFS
*/

typedef struct coreflat cw_graph_t;
typedef struct window window_t;
typedef struct text text_t;
typedef struct icon icon_t;
typedef struct view view_t;
typedef struct game_settings game_settings_t;
typedef struct editor editor_t;

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
    bool (*fct)(cw_graph_t *cw_graph, champion_t **champions,
    list_t *memory);
};

struct game_settings
{
    int step;
    int champ_step;
    int corewar_launched;
    int nb_champions;
    int cycles_per_second;
    int acceleration;
    int pass_step;
    int champ_added;
    int volume;
    bool automatic_cps;
    sfColor color;
    proc_t **procs;
    champion_t **champions;
};

struct editor
{
    int step;
    bool indirect_type;
    instruction_t **instructions;
    header_t *header;
};

struct coreflat
{
    bool is_released;
    int current_view;
    window_t *window;
    icon_t **icons;
    game_settings_t g_setts;
    editor_t edit;
    text_t text;
    sfRectangleShape *interface;
    sfCircleShape *buttons;
    sfColor interface_gradient;
    sfMusic *music;
};

/*
** PROTOTYPES
*/

// init
cw_graph_t *init_cw_graph(void);
view_t **views_fcts(void);

// starting
bool game_loop(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
bool start_graphical_corewar(champion_t **champions, list_t *memory);

// instruction quiet
bool live_flat(proc_t ***procs, int i);
bool aff_flat(proc_t ***procs, int i);


// drawing
bool draw_corewar(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
bool draw_credits(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
void draw_input_bar(cw_graph_t *cw_graph, sfVector2f pos, char *str);
bool draw_winner(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
bool draw_choose(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
bool draw_help(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
void draw_checkbox(cw_graph_t *cw_graph, sfVector2f pos, bool *value);
void draw_interface(cw_graph_t *cw_graph, champion_t **champions);
void draw_icons(cw_graph_t *cw_graph, champion_t **champions);
void update_input(cw_graph_t *cw_graph, char *str, int size);
void draw_choose_cyc_per_sec(cw_graph_t *cw_graph);
void draw_choose_cyc_auto(cw_graph_t *cw_graph);
void draw_choose_champion(cw_graph_t *cw_graph);
void draw_ready_to_start(cw_graph_t *cw_graph);
void draw_background(cw_graph_t *cw_graph);
void draw_step_dots(cw_graph_t *cw_graph);
void evolve_gradient(sfColor *gradient);
void draw_pause(cw_graph_t *cw_graph);
bool draw_settings(cw_graph_t *cw_graph, champion_t **champions,
list_t *memory);
bool draw_main_menu(cw_graph_t *cw_graph, champion_t **champions,
list_t *memory);
void draw_button(cw_graph_t *cw_graph, sfVector2f pos, sfColor color,
char *text);
void draw_selector(cw_graph_t *cw_graph, sfVector2i limiter, sfVector2f pos, int
*value);
bool draw_champions_settings(cw_graph_t *cw_graph, champion_t **champions,
int *n);
bool draw_editor(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
void draw_editor_interface(cw_graph_t *cw_graph);
void draw_rect(cw_graph_t *cw_graph, sfVector2f pos, sfVector2f size, sfColor color);
void draw_registers(cw_graph_t *cw_graph);
void draw_all_instructions(cw_graph_t *cw_graph);
void draw_configuration(cw_graph_t *cw_graph);

//events
void redirection(cw_graph_t *cw_graph, char *to);
void manage_events(cw_graph_t *cw_graph);
void is_released(cw_graph_t *cw_graph);

//utils
void draw_text(cw_graph_t *cw_graph, char *name, int size, sfVector2f pos);
bool is_in_rect(cw_graph_t *cw_graph, sfVector2f pos, sfVector2f size);
int count_process(proc_t **procs, int i);
char *int_to_str(int nb);
void free_end(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);

// champions
bool load_all_champions(char *path, champion_t ***champions);
bool auto_pre_game(cw_graph_t *cw_graph, list_t *memory);
champion_t *champion_dup(champion_t *dup);
void set_proc_owner(proc_t **procs);



#endif /* !COREFLAT_H_ */
