#ifndef WIDGET_H
#define WIDGET_H
#include <QProcess>
#include <QWidget>
#include <QString>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class About; }
QT_END_NAMESPACE

class About : public QWidget
{
    Q_OBJECT

public:
    About(QWidget *parent = nullptr);
    ~About();

private:
    Ui::About *ui;
    void disPlay();
    void mate_about_run();
    QLabel *label_logo;
    QLabel *label_info;
    QLabel *label_copyright;
    QLabel *label_website;


        const char* program_name = "Kylin";
        const char* icon = "/usr/share/mate-about/logo.png";
        const char* desktop_icon = "desktop";
        const char* website = "http://www.kylinos.cn/";


        const char* copyright =  ""
            "Copyright © 1997-2011 GNOME developers\n"
            "Copyright © 2011 Perberos\n"
            "Copyright © 2012-2015 MATE developers";

        /* Increment comments_count if you add other comments. This will be
         * used to choose a random comment. */
//        const int comments_count = 6;
//        const char* comments_array[] = {
//            N_("Kylin 4.0\n"
//                   "Build 141231")
//        };

//        const char* authors[] = {
//            "Ubuntu Kylin Members",
//                NULL
//        };

//        // documentation
//        const char* documenters[] = {
//            NULL
//        };
//        // artists
//        const char* artists[] = {
//            NULL
//        };

        // widget for mate-about window
//        MateAboutDialog* mate_about_dialog = FALSE;

//        #if GTK_CHECK_VERSION(3, 0, 0)
//            GtkApplication* mate_about_application;
//        #else
//            GApplication* mate_about_application;
//        #endif

//        /**
//         * If this value is set to TRUE, then mate_about_dialog will not be called
//         * on the main function.
//         */
//        gboolean mate_about_nogui = FALSE;
//        // functions
//        void mate_about_run(void);
//        void mate_about_release_version(void);

//        #if GTK_CHECK_VERSION(3, 0, 0)
//            static void mate_about_on_activate(GtkApplication* app);
//        #else
//            static void mate_about_on_activate(GApplication* app);
//        #endif

//        // arguments definitions
//        static GOptionEntry command_entries[] = {
//            {"version", 'v', 0, G_OPTION_ARG_NONE, &mate_about_nogui, "Show MATE version", NULL},
//            {NULL}



};
#endif // WIDGET_H
