#pragma once
#include <thread>
#include <chrono>

namespace nebula {
class KTimer {
public:
private:
    int (*func_)(void*);
    void* params_;
    bool  running_;

public:
    /**
     * @brief KTimer
     * @param func      所需要执行的函数，其参数为任意，其返回值 0 为函数执行正常,
     * 如果接手到非0，则退出定时器
     * @param params    所需要执行的函数的参数
     */
    KTimer(int (*func)(void*), void* params = nullptr) {
        func_    = func;
        params_  = params;
        running_ = false;
    }

    /**
     * @brief 执行
     * @return -128, 需要执行的函数指针为空, 其余!0的返回为所执行的函数的返回值
     */
    int Run(long long ms) {
        int ret = NULL;
        if (nullptr == func_)
            return -128;
        running_ = true;

        std::thread([this, ms]() {
            int ret = NULL;
            while (NULL == ret) {
                if (false == running_)
                    return ret;
                std::this_thread::sleep_for(std::chrono::microseconds(ms));
                ret = func_(params_);
            }
            return ret;
        }).detach();

        return ret;
    }
    int Stop() {
        running_ = false;
        return 0;
    }
};

}  // namespace nebula