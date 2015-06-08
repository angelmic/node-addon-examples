#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <nan.h>

#define dlog(fmt, arg...) printf("%s(%d): " fmt, __func__, __LINE__, ##arg)

class MyObject : public node::ObjectWrap 
{
    public:
        static void Init(v8::Handle<v8::Object> exports);

    private:
        explicit MyObject(double value = 0);
        ~MyObject();

        static NAN_METHOD(NewGG);

        static NAN_METHOD(PlusOne);

    private:
        static v8::Persistent<v8::Function>     constructor;
        double                                  m_value;

};

#endif
