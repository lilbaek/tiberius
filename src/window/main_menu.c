#include <stdio.h>
#include "main_menu.h"

#include "assets/assets.h"
#include "core/calc.h"
#include "core/string.h"
#include "editor/editor.h"
#include "game/game.h"
#include "game/system.h"
#include "graphics/generic_button.h"
#include "graphics/graphics.h"
#include "graphics/image.h"
#include "graphics/image_button.h"
#include "graphics/lang_text.h"
#include "graphics/panel.h"
#include "graphics/text.h"
#include "graphics/screen.h"
#include "graphics/window.h"
#include "sound/music.h"
#include "window/cck_selection.h"
#include "window/config.h"
#include "window/file_dialog.h"
#include "window/new_career.h"
#include "window/plain_message_dialog.h"
#include "window/popup_dialog.h"
#include "ui/nuklear.h"
#include "ui/ui_window.h"
#include "platform/renderer.h"

#define MAX_BUTTONS 6

static void button_click(int type, int param2);

static struct {
    int focus_button_id;
    int logo_image_id;
} data;

static void draw_version_string(void) {
    uint8_t version_string[100] = "tiberius v";
    int version_prefix_length = string_length(version_string);
    int text_y = screen_height() - 54;

    string_copy(string_from_ascii(system_version()), version_string + version_prefix_length, 99);

    int text_width = text_get_width(version_string, FONT_NORMAL_WHITE);
    int width = calc_value_in_step(text_width + 20, 16);

    text_draw_centered(version_string, 20, text_y + 11, width, FONT_NORMAL_WHITE, 0);
}

static void draw_background(void) {
    graphics_reset_dialog();
    graphics_reset_clip_rectangle();
    image_draw_fullscreen_background(assets_get_image_id("mainmenu", "start-screen"));
    draw_version_string();
}

static void draw_foreground(void) {
    graphics_in_dialog();
    struct nk_context *ctx = ui_context();
    ui_font_large_bold();
    if (nk_begin(ctx, "", nk_recti(screen_dialog_offset_x() + 192, screen_dialog_offset_y() + 70, 260, 303),
                 NK_WINDOW_BORDER | NK_WINDOW_NO_SCROLLBAR)) {
        nk_layout_row_begin(ctx, NK_STATIC, 45, 1);
        {
            float width = 247;
            nk_layout_row_push(ctx, width);
            if (nk_button_label(ctx, "Start new career")) {
                button_click(1, 0);
            }
            nk_layout_row_push(ctx, width);
            if (nk_button_label(ctx, "Load saved game")) {
                button_click(2, 0);
            }
            nk_layout_row_push(ctx, width);
            if (nk_button_label(ctx, "Play scenario")) {
                button_click(3, 0);
            }
            nk_layout_row_push(ctx, width);
            if (nk_button_label(ctx, "Map editor")) {
                button_click(4, 0);
            }
            nk_layout_row_push(ctx, width);
            if (nk_button_label(ctx, "Options")) {
                button_click(5, 0);
            }
            nk_layout_row_push(ctx, width);
            if (nk_button_label(ctx, "Exit")) {
                button_click(6, 0);
            }
        }
        nk_layout_row_end(ctx);
    }
    nk_end(ctx);
    ui_font_standard();

    graphics_reset_dialog();
}

static void handle_input(const mouse *m, const hotkeys *h) {
    if (h->escape_pressed) {
        hotkey_handle_escape();
    }
    if (h->load_file) {
        window_file_dialog_show(FILE_TYPE_SAVED_GAME, FILE_DIALOG_LOAD);
    }
}

static void confirm_exit(int accepted, int checked) {
    if (accepted) {
        system_exit();
    }
}

static void button_click(int type, int param2) {
    if (type == 1) {
        window_new_career_show();
    } else if (type == 2) {
        window_file_dialog_show(FILE_TYPE_SAVED_GAME, FILE_DIALOG_LOAD);
    } else if (type == 3) {
        window_cck_selection_show();
    } else if (type == 4) {
        if (!editor_is_present() || !game_init_editor()) {
            window_plain_message_dialog_show(
                    TR_NO_EDITOR_TITLE, TR_NO_EDITOR_MESSAGE, 1);
        } else {
            sound_music_play_editor();
        }
    } else if (type == 5) {
        window_config_show(CONFIG_FIRST_PAGE, 1);
    } else if (type == 6) {
        window_popup_dialog_show(POPUP_DIALOG_QUIT, confirm_exit, 1);
    }
}

void window_main_menu_show(int restart_music) {
    if (restart_music) {
        sound_music_play_intro();
    }
    window_type window = {
            WINDOW_MAIN_MENU,
            draw_background,
            draw_foreground,
            handle_input
    };
    window_show(&window);
}
