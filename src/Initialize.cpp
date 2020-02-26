#include "config.hpp"
#include "main.h"




/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	// static bool pressed = false;
	// pressed = !pressed;
	// if (pressed) {
	// 	pros::lcd::set_text(2, "I was pressed!");
	// } else {
	// 	pros::lcd::clear_line(2);
	// }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
 #define CANVAS_WIDTH  200
 #define CANVAS_HEIGHT  150

 		// static lv_disp_buf_t disp_buf2;
   //  lv_disp_buf_init(&disp_buf2, dbuf2, NULL, 100*50);
	 //
   // /*Create an other display*/
   //  lv_disp_drv_init(&disp_drv);            /*Basic initialization*/
   //  disp_drv.hor_res = 100;
   //  disp_drv.ver_res = 50;
   //  disp_drv.buffer = &disp_buf2;
   //  disp_drv.flush_cb = my_disp_flush;
   //  lv_disp_t * disp2 = lv_disp_drv_register(&disp_drv);
	 //
   //  lv_disp_set_default(disp2);
	 //
   //  lv_obj_t * label = lv_label_create(lv_scr_act(), NULL);
   //  lv_obj_set_pos(label, 10, 10);
	 //
		// lv_lable_set_text(lable, "#0000ff Juul# #ff0000 Boy#")
	 //
   //  lv_refr_now();
   //  lv_disp_remove(disp2);
	 //
   //  lv_obj_t * canvas = lv_canvas_create(lv_scr_act(), NULL);
   //  lv_canvas_set_buffer(canvas, dbuf2, 100, 50, LV_IMG_CF_TRUE_COLOR);

	 void lv_ex_label_1(void)
{
		static lv_style_t style_big;
		style_big.text.font = &lv_font_symbol_20;
		style_big.text.color = LV_COLOR_RED;

    lv_obj_t * label1 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_long_mode(label1, LV_LABEL_LONG_BREAK);     /*Break the long lines*/
    lv_label_set_recolor(label1, true);                      /*Enable re-coloring by commands in the text*/
    lv_label_set_align(label1, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
    lv_label_set_text(label1, "#ff0000 Maaaanithaa#");
    lv_obj_set_width(label1, 750);
    lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, -30);
}

void initialize() {

	okapi::MotorGroup intakes({15, 17});
	lv_ex_label_1();
	// pros::lcd::initialize();
	// pros::lcd::set_text(1, "Juul Boy");
	//
	// pros::lcd::register_btn1_cb(on_center_button);
}
