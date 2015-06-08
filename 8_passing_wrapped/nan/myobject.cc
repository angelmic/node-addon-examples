#include <node.h>
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
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

    tpl->SetClassName(NanNew("MyObject"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    NanAssignPersistent(constructor, tpl->GetFunction());
}

NAN_METHOD(MyObject::New) 
{
    NanScope();

    MyObject* obj = new MyObject();
    obj->m_val    = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();

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

double MyObject::Val() const 
{ 
    return m_val; 
}


