#include "myobject.h"

using namespace v8;

Persistent<Function> MyObject::constructor;
//Persistent<Function> constructor;

MyObject::MyObject(double value) : m_value(value) 
{
    dlog("\n");
}

MyObject::~MyObject() 
{
    dlog("\n");
}

void MyObject::Init(Handle<Object> exports) 
{
    NanScope();

    dlog("\n");
    // Prepare constructor template
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(NewGG);

    dlog("\n");
    tpl->SetClassName(NanNew("MyObject"));

    // Rich: http://stackoverflow.com/questions/16600735/what-is-an-internal-field-count-and-what-is-setinternalfieldcount-used-for
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // Prototype
    NODE_SET_PROTOTYPE_METHOD(tpl, "plusOne", PlusOne);

    exports->Set(NanNew("MyObject"), tpl->GetFunction());

    // Rich: Assign a Local handle to a Persistent handle
    NanAssignPersistent(constructor, tpl->GetFunction());
    dlog("\n");
    
}

NAN_METHOD(MyObject::NewGG) 
{
    NanScope();

    dlog("\n");
    if (args.IsConstructCall()) 
    {
        dlog("\n");

        // Invoked as constructor: `new MyObject(...)`
        double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();

        MyObject* obj = new MyObject(value);
        dlog("[obj: %x]\n", obj);

        obj->Wrap(args.This());
        NanReturnValue(args.This());
    } 
    else 
    {
        // Invoked as plain function `MyObject(...)`, turn into construct call.
        dlog("\n");
        const int argc          = 1;
        Local<Value> argv[argc] = { args[0] };
        Local<Function> cons    = NanNew<Function>(constructor);

        NanReturnValue(cons->NewInstance(argc, argv));
    }
}

NAN_METHOD(MyObject::PlusOne) 
{
    NanScope();
    
    dlog("\n");
    
    MyObject* obj = ObjectWrap::Unwrap<MyObject>(args.Holder());
    dlog("[obj: %x] obj->value: %.2f\n", obj, obj->m_value);
    
    obj->m_value += 1;

    NanReturnValue(NanNew(obj->m_value));
}
