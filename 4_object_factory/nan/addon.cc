#include <nan.h>

using namespace v8;

Local<String> g_name = NanNew<String>();

NAN_METHOD(Fn_GG) 
{
    NanScope();

    NanReturnValue(NanNew("I am GG"));
}

NAN_METHOD(CreateObject) 
{
    NanScope();

    Local<Object> obj = NanNew<Object>();

    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(Fn_GG);
    
    Local<Function> fn = tpl->GetFunction();

    obj->Set(NanNew("msg"), args[0]->ToString());
    obj->Set(NanNew("num"), args[1]->ToUint32());
    obj->Set(NanNew("FnGG"), fn);

    NanReturnValue(obj);
}

void Init(Handle<Object> moduleDotexports, Handle<Object> module) 
{
    //module->Set(NanNew("exports"), NanNew<FunctionTemplate>(CreateObject)->GetFunction());
    NODE_SET_METHOD(module, "exports", CreateObject);
}

NODE_MODULE(addon, Init)
