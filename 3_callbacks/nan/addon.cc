#include <nan.h>
#define dlog(fmt, arg...) printf("%s(%d): " fmt, __func__, __LINE__, ##arg)

using namespace v8;

NAN_METHOD(RunCallback) 
{
    NanScope();
    dlog("\n");
    Local<Function> cb = args[0].As<Function>();
    
    //const unsigned argc = 1;
    //Local<Value> argv[argc] = { NanNew("hello world") };

    // Method_01
    //const unsigned argc = 1;
    //Local<Array> array = NanNew<Array>(4);
    //array->Set(0, NanNew("1111111111"));
    //array->Set(1, NanNew("2222222222"));
    //Local<Value> argv[1] = { array };

 	// Method_02
 	const unsigned argc = 2;
 	Local<Value> argv[argc];
 	argv[0] = NanNew("hello world");
 	argv[1] = NanNew("hello world22222222222222");
 	///////

    NanMakeCallback(NanGetCurrentContext()->Global(), cb, argc, argv);
    dlog("\n");
    NanReturnUndefined();
    dlog("\n");
}

NAN_METHOD(DD)
{
	NanScope();
	dlog("\n");

	Local<Function> cb = args[0].As<Function>();
    
    //const unsigned argc = 1;
    //Local<Value> argv[argc] = { NanNew("hello world") };

    // Method_01
    //const unsigned argc = 1;
    //Local<Array> array = NanNew<Array>(4);
    //array->Set(0, NanNew("1111111111"));
    //array->Set(1, NanNew("2222222222"));
    //Local<Value> argv[1] = { array };

 	// Method_02
 	const unsigned argc = 2;
 	Local<Value> argv[argc];
 	argv[0] = NanNew("hello world");
 	argv[1] = NanNew("hello world22222222222222");
 	///////

    NanMakeCallback(NanGetCurrentContext()->Global(), cb, argc, argv);
    dlog("\n");
    NanReturnUndefined();
    dlog("\n");
}

NAN_METHOD(GG)
{
	NanScope();
	dlog("\n");


	// *** on nan 1.7.0 NanMakeCallback was replaced by NanCallback
	Local<Function> cb = args[0].As<Function>();
	NanCallback *nancb = new NanCallback(cb);
    
    //const unsigned argc = 1;
    //Local<Value> argv[argc] = { NanNew("hello world") };

    // Method_01
    //const unsigned argc = 1;
    //Local<Array> array = NanNew<Array>(4);
    //array->Set(0, NanNew("1111111111"));
    //array->Set(1, NanNew("2222222222"));
    //Local<Value> argv[1] = { array };

 	// Method_02
 	const unsigned argc = 2;
 	Local<Value> argv[argc];
 	argv[0] = NanNew("pppppppp");
 	argv[1] = NanNew("ggggggggggggggggggggggg");


    //NanMakeCallback(NanGetCurrentContext()->Global(), cb, argc, argv);
    nancb->Call(argc, argv);
    

    dlog("\n");
    NanReturnUndefined();


    delete nancb;
    dlog("\n");
}

//void Init(Handle<Object> exportyyffff, Handle<Object> module) 
void Init(Handle<Object> module) 
{
	dlog("\n");
    //NODE_SET_METHOD(module, "exports", RunCallback);
    NODE_SET_METHOD(module, "dd", DD);
    NODE_SET_METHOD(module, "gg", GG);
    dlog("\n");
}

NODE_MODULE(addon, Init)
