#include <QApplication>
#include <QWidget>

#include <iostream>

#include "window/main_window.h"

#include "Ttr_json.h"
#include "Tvlog.h"

using namespace std;



void test_tr_json()
{
    str file = "/home/cong/open/test_qt/test_tr_json/config/language/cn/window2.json";
    bool ok = Ttrs::get()->init_tr_json(file,true);
    auto sjson = Ttrs::get()->to_string();

    vlogd($(ok)$(sjson));

    Ttrs::get()->Ttr("Main Windows");
    QString s1 = TTRS("Sub Windows");
    QString s2 = TTRSC("Sub Windows","test1");
    QString s3 = TTRSC("Sub Windows","test2");

    vlogd($Q(s1)$Q(s2)$Q(s3));

    {
        QString ss = TTRS("Main Windows");
        vlogd($Q(ss));
    }
    {
        QString ss = TTRS("Sub Windows");
        vlogd($Q(ss));
    }
    {
        QString ss = TTRSC("Change Size","size of object");
        vlogd($Q(ss));
    }
    {
        QString ss = TTRSC("Change Size","measuring ruler");
        vlogd($Q(ss));
    }
    {
        QString ss = TTRS("Change Title");
        vlogd($Q(ss));
    }
    {
        bool ok = Ttrs::get()->save_file();
        auto sjson = Ttrs::get()->to_string();
        vlogd($(ok)$(sjson));
    }


}


void load_tr_json()
{
    str file = "/home/cong/open/test_qt/test_tr_json/config/language/cn/window.json";
    bool ok = Ttrs::get()->init_tr_json(file,true);
    vlogd($(ok));
}


int run_main_app(int argc, char *argv[])
{
    QApplication a(argc,argv);

    main_window w;
    w.show();

    return a.exec();
}

int exit_main_app(int run_value)
{
    cout<<"exit run value : "<<run_value<<endl;
    
    Ttrs::get()->save_file();

    return run_value;
}

int perse_arg(int argc, char *argv[])
{
    cout<<"perse_arg : "<<argc<<endl;
    for(int i=0;i<argc;i++)
    {
        cout<<"arg: "<<string(argv[i])<<endl;
    }
    return argc;
}

int main(int argc, char *argv[])
{
    Tvlogs::get()->set_level(vlevel4::e_info);

#if 0
    vlogd("===== begin =====");
    test_tr_json();
    vlogd("===== end =====");
    return 0;
#endif

    load_tr_json();

    perse_arg(argc,argv);

    int run_value = run_main_app(argc,argv);

    return exit_main_app(run_value);
}