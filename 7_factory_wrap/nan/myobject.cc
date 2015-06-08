#include <nan.h>
#include "myobject.h"

using namespace v8;

Persistent<Function> MyObject::constructor;

MyObject::MyObject() 
{

}

MyObject::~MyObject() 
{

}

void MyObject::Init() 
{
    NanScope();

    // Prepare constructor template
    //Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(NewGG);

    tpl->SetClassName(NanNew("MyObject"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    
    // Prototype
    //tpl->PrototypeTemplate()->Set(NanNew("plusOne"), NanNew<FunctionTemplate>(PlusOne)->GetFunction());
    NODE_SET_PROTOTYPE_METHOD(tpl, "plusOne", PlusOne);

    NanAssignPersistent(constructor, tpl->GetFunction());
}

NAN_METHOD(MyObject::New) 
{
    NanScope();

    MyObject* obj  = new MyObject();
    obj->m_counter = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
    
    obj->Wrap(args.This());

    NanReturnValue(args.This());
}


Local<Object> MyObject::NewInstance(Local<Value> arg) 
{
    NanEscapableScope();

    const unsigned argc     = 1;
    Local<Value> argv[argc] = { arg };
    Local<Function> cons    = NanNew<Function>(constructor);
    Local<Object> instance  = cons->NewInstance(argc, argv);

    return NanEscapeScope(instance);
}

// use lesson 6 way to do construct
NAN_METHOD(MyObject::NewGG) 
{
    NanScope();

    if (args.IsConstructCall()) 
    {

        // Invoked as constructor: `new MyObject(...)`
        MyObject* obj  = new MyObject();
        obj->m_counter =  args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
        obj->Wrap(args.This());

        NanReturnValue(args.This());
    } 
    else 
    {
        // Invoked as plain function `MyObject(...)`, turn into construct call.
        const int argc          = 1;
        Local<Value> argv[argc] = { args[0] };
        Local<Function> cons    = NanNew<Function>(constructor);

        NanReturnValue(cons->NewInstance(argc, argv));
    }
}

NAN_METHOD(MyObject::PlusOne) 
{
    NanScope();

    MyObject* obj   = ObjectWrap::Unwrap<MyObject>(args.This());
    obj->m_counter += 1;

    NanReturnValue(NanNew(obj->m_counter));
}
