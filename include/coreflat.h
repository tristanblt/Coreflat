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
FIRST:\n       \
Press the play button\n\n\
SECOND:\n       \
Choose the number of warriors/champions you \
will need for the battle\n\n\
THEN:\n       \
Choose between automatic and manual cycles per second\n       \
(Automatic will give you a 1 minute fight)\n\n\
FINALLY:\n        \
Choose you champions and their color\n\n\n\
And most importantly, have fun!!! <3"
#define AUTO_COMMENT "Champion created by the CoreFlat tool."
#define COREWAR_TEXT "Corewar"
#define BEGIN_TEXT "Begin the war"
#define HELP_TEXT "Help"
#define CREDITS_TEXT "Credits"
#define EXIT_TEXT "Exit"
#define MAIN_MENU_TEXT "Main menu"
#define MAIN_MENU_TEXT_B "Main menu "
#define MAIN_MENU_RES_TEXT "Main Menu"
#define MAIN_MENU_RES2_TEXT "Main Menu "
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
#define VALIDATE_CHAMPION "Validate choice"
#define SAVE_TEXT "Save"
#define VISUALISER_TEXT "Visualiser"
#define VISUALISE_TEXT "Visualise"

#define NBR_ICONS 4
#define NBR_VIEWS 9

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
typedef struct visualiser visualiser_t;

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
    int selected;
    instruction_t **instructions;
    header_t *header;
    int cursor;
    int register_selected;
    int number_selected;
    char *buffer;
};

struct visualiser
{
    int selected;
    int step;
    fct_t *fct;
    int speed;
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
    visualiser_t visualiser;
};

/*
** PROTOTYPES
*/

// init
cw_graph_t *init_cw_graph(void);
view_t **views_fcts(void);
bool init_edition(cw_graph_t *cw_graph);

// starting
bool game_loop(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
bool start_graphical_corewar(champion_t **champions, list_t *memory);

// instruction quiet
bool live_flat(proc_t ***procs, int i);
bool aff_flat(proc_t ***procs, int i);


// drawing
bool draw_corewar(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
bool draw_credits(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
void draw_input_bar(cw_graph_t *cw_graph, sfVector2f pos, char *);
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
void draw_rect(cw_graph_t *cw_graph, sfVector2f pos, sfVector2f size,
sfColor color);
void draw_registers(cw_graph_t *cw_graph);
bool draw_all_instructions(cw_graph_t *cw_graph);
void draw_configuration(cw_graph_t *cw_graph);
bool draw_create_champion(cw_graph_t *cw_graph);
bool draw_select_champion(cw_graph_t *cw_graph, champion_t **champions);
void draw_champion_select(cw_graph_t *cw_graph, char *name, int i,
bool is_select);
void draw_champ_instructions(cw_graph_t *cw_graph);
void draw_labels(cw_graph_t *cw_graph);
void draw_input_bar_nb(cw_graph_t *cw_graph, sfVector2f pos, char *str);
void draw_text_no_color(cw_graph_t *cw_graph, char *name, int size,
sfVector2f pos);
void draw_header(cw_graph_t *cw_graph);
void draw_subwindows(cw_graph_t *cw_graph);
sfColor find_color(champion_t **champions, list_t *memory);
void draw_block(cw_graph_t *cw_graph, int col, int line, sfColor color);
char *my_strcat(char *first, char *second);
void draw_arg_instr(cw_graph_t *, int, instruction_t *, int);
void draw_label_instr(cw_graph_t *cw_graph, int i, instruction_t *instruction);
void draw_args_instr(cw_graph_t *cw_graph, int i,
instruction_t *instruction);
int draw_one_instruction_champ(cw_graph_t *, int, instruction_t *);
void update_input_nb(cw_graph_t *cw_graph, char *str, int size);
void save_to_file(cw_graph_t *cw_graph);
void draw_input_dir_ind(cw_graph_t *cw_graph);
void compute_instructions_sizes(instruction_t **insts);
void draw_args_instr(cw_graph_t *cw_graph, int i,
instruction_t *instruction);

//events
void redirection(cw_graph_t *cw_graph, char *to);
void manage_events(cw_graph_t *cw_graph);
void is_released(cw_graph_t *cw_graph);
instruction_t **push_instruction(instruction_t **arr, instruction_t *add);

//utils
void draw_text(cw_graph_t *cw_graph, char *name, int size, sfVector2f pos);
bool is_in_rect(cw_graph_t *cw_graph, sfVector2f pos, sfVector2f size);
int count_process(proc_t **procs, int i);
char *int_to_str(int nb);
void free_end(cw_graph_t *cw_graph, champion_t **champions, list_t *memory);
char *int_to_str_reg(int nb);

// champions
bool load_all_champions(char *path, champion_t ***champions);
bool auto_pre_game(cw_graph_t *cw_graph, list_t *memory);
champion_t *champion_dup(champion_t *dup);
void set_proc_owner(proc_t **procs);
instruction_t *parse_instruction_from_file(char *file, int *i, int size);
bool encode_instructions_to_file(char *file_name, instruction_t **instructions,
header_t *header);

//visualisor
bool draw_visualiser(cw_graph_t *cw_graph, champion_t **champs, list_t *memory);

#endif /* !COREFLAT_H_ */
