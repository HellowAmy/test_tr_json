
#ifndef TTR_JSON_H
#define TTR_JSON_H

#include <iostream>
#include <fstream>

#include "Tconfig.h"
#include "json.hpp"

using namespace Tconf;
using njson = nlohmann::json;


class Ttr_json
{
public:
    Ttr_json() {}
    ~Ttr_json() {}

    bool init_tr_json(cstr file,bool create = false)
    {
        _is_create_null = create;
        _file_sjson = file;

        try {
            std::ifstream fs(file);
            _json = njson::parse(fs);
            return true;
        } 
        catch(...){}

        if(_is_create_null)
        {
            return make_template_json();
        }

        return false;
    }

    QString Ttr(cstr s,cstr c = "")
    {
        str tr;
        try {
            if(c == "") tr = _json["general"][s];
            else tr = _json["specials"][s][c];
        }
        catch(...){}

        if(tr == "") 
        {
            tr = s;

            if(_is_create_null)
            {
                if(c == "") 
                {
                    _json["general"][s] = "";
                }
                else 
                {
                    njson json = _json["specials"][s];
                    json[c] = "";
                    _json["specials"][s] = json;
                }
            }
        }
        return stoqs(tr);
    }

    str to_string(bool format = true)
    {
        if(format) return _json.dump(4);
        else return _json.dump();
    }

    njson &get_json()
    {
        return _json;
    }

    bool make_template_json()
    {
        try {
            _json = 
R"({
    "general":{
        "#source":"#translate"
    },
    "specials":{
        "#source":{
            "#comment-1":"#translate-1",
            "#comment-2":"#translate-2"
        }
    }
})"_json;
            return true;
        }
        catch(...){}
        return false;
    }

    bool save_file()
    {
        if(_is_create_null)
        {
            std::ofstream fs(_file_sjson);
            if(fs.is_open())
            {
                str sjson = _json.dump(4);
                fs << sjson;
                return fs.good();
            }
        }
        return false;
    }

protected:
    bool _is_create_null = false;
    str _file_sjson;
    njson _json;
};

typedef Tsingle_d<Ttr_json> Ttrs;

#define TTRS(s) Ttrs::get()->Ttr(s)
#define TTRSC(s,c) Ttrs::get()->Ttr(s,c)


#endif // TTR_JSON_H
