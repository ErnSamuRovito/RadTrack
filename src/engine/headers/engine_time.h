#pragma once

namespace RadTrack  {
    class Time {
        public:
            Time() = delete;

            static float GetCurrentTime();
            static float GetDeltaTime();
            static float GetFPS();
            static void Update(float newTime);
        private:
            static float currentTime;
            static float deltaTime;
            static float lastFrame;
    };
}