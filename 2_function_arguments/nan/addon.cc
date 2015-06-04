#include <nan.h>

#define dlog(fmt, arg...) printf("%s(%d): " fmt, __func__, __LINE__, ##arg)

using namespace v8;

NAN_METHOD(Add)
{
    dlog("\n");
    NanScope();

    if (args.Length() < 2) 
    {
        NanThrowTypeError("Wrong number of arguments");
        NanReturnUndefined();
    }

    if (!args[0]->IsNumber() || !args[1]->IsNumber())
    {
        NanThrowTypeError("Wrong arguments");
        NanReturnUndefined();
    }

    dlog("\n");

    double sum = 0.0;
    for (int i=0; i<args.Length(); i++)
    {
        Local<Value> t1 = args[i];
        dlog("args[%d] = %.2f\n", i, t1->NumberValue());

        sum += t1->NumberValue();
    }


    //double arg0 = args[0]->NumberValue();
    //double arg1 = args[1]->NumberValue();

    Local<Number> num = NanNew(sum);

    NanReturnValue(num);
}

void Init(Handle<Object> exports)
{
    dlog("heheh\n");
    exports->Set(NanNew("add"), NanNew<FunctionTemplate>(Add)->GetFunction());
}

NODE_MODULE(addon, Init)
