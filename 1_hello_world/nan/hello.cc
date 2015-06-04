#include <nan.h>

using namespace v8;

NAN_METHOD(Method) 
{
	NanScope();
	NanReturnValue(NanNew("world"));
}

void Init(Handle<Object> exports) 
{
	exports->Set(NanNew("hello"), NanNew<FunctionTemplate>(Method)->GetFunction());
	// 
	// {
	//    "hello": function() { return "world"; }
	// }
}

NODE_MODULE(hello, Init)
