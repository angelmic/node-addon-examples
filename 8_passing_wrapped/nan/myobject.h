#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <nan.h>

#define dlog(fmt, arg...) printf("%s(%d): " fmt, __func__, __LINE__, ##arg)

class MyObject : public node::ObjectWrap 
{
    public:
        static void Init();
        static v8::Local<v8::Object> NewInstance(v8::Local<v8::Value> arg);
        double Val() const;

    private:
        MyObject();
        ~MyObject();

        static NAN_METHOD(New);

    private:
        static v8::Persistent<v8::Function>    constructor;
        double                                 m_val;
};

#endif
