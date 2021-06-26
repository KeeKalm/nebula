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
     * @param func      ����Ҫִ�еĺ����������Ϊ���⣬�䷵��ֵ 0 Ϊ����ִ������,
     * ������ֵ���0�����˳���ʱ��
     * @param params    ����Ҫִ�еĺ����Ĳ���
     */
    KTimer(int (*func)(void*), void* params = nullptr) {
        func_    = func;
        params_  = params;
        running_ = false;
    }

    /**
     * @brief ִ��
     * @return -128, ��Ҫִ�еĺ���ָ��Ϊ��, ����!0�ķ���Ϊ��ִ�еĺ����ķ���ֵ
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