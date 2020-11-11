// node-addon-api: 
// header-only C++ wrapper classes which simplify the use of the C-based N-API.

#include <napi.h>

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "world");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"),
              Napi::Function::New(env, Method));
  return exports;
}

// 所有的 Node.js 插件必须导出一个如下模式的初始化函数
// hello 是最终的二进制名， Init 是初始化函数名
NODE_API_MODULE(hello, Init)
