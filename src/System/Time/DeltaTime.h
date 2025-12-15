#pragma once

#include "chrono"

class DeltaTime
{
public:
    using clock = std::chrono::steady_clock;

    DeltaTime()
        : lastTime(clock::now()), delta(0.0)
    {
    }

    // フレーム先頭で呼ぶ
    void Update()
    {
        auto now = clock::now();
        delta = std::chrono::duration<double>(now - lastTime).count();
        lastTime = now;
    }

    // 秒単位のデルタタイム
    double GetSeconds() const
    {
        return delta;
    }

private:
    clock::time_point lastTime;
    double delta;
};