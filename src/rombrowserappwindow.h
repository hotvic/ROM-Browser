#ifndef __ROMBROWSERAPPWINDOW_H
#define __ROMBROWSERAPPWINDOW_H

#include <gtk/gtk.h>
#include "rombrowserapp.h"


#define ROMBROWSER_APP_WINDOW_TYPE (rombrowser_app_window_get_type ())
#define ROMBROWSER_APP_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ROMBROWSER_APP_WINDOW_TYPE, RomBrowserAppWindow))


typedef struct _RomBrowserAppWindow         RomBrowserAppWindow;
typedef struct _RomBrowserAppWindowClass    RomBrowserAppWindowClass;


GType                rombrowser_app_window_get_type    (void);
RomBrowserAppWindow *rombrowser_app_window_new         (RomBrowserApp *app);
void                 rombrowser_app_window_open        (RomBrowserAppWindow *win,
                                                        GFile            *file);


#endif /* __ROMBROWSERAPPWINDOW_H */

